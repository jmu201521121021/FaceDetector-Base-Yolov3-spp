# -*- coding: UTF-8 -*-
import numpy as np
import math
import matplotlib.pyplot as plt

def get_pr_data(prediction_file,ground_truth_file,cls_name,ovthresh=0.5,use_07_metric=False):
    with open(ground_truth_file, 'r') as f:
        lines_gt = f.readlines()
    with open(prediction_file, 'r') as f:
        lines_pre = f.readlines()
    pr_data={}
    for cls_num in range(len(cls_name)):
        splitlines_gt = [x.strip().split(' ') for x in lines_gt]
        imagenames_gt = [ x[0] for x in splitlines_gt if int(x[1])==cls_num]
        BB_gt=np.array([[math.ceil(float(z)) for z in x[2:]] for x in splitlines_gt if int(x[1])==cls_num])
        class_recs = {}
        for i in range(len(imagenames_gt)):
            if not class_recs.has_key(imagenames_gt[i]):
                class_recs.update({imagenames_gt[i]:{"bbox":[],"det":[],"difficult":[]}})
            class_recs[imagenames_gt[i]]["bbox"].append(BB_gt[i])
            class_recs[imagenames_gt[i]]["det"].append(False)
            class_recs[imagenames_gt[i]]["difficult"].append(False)
        npos=len(imagenames_gt)
        
        splitlines_pre = [x.strip().split(' ') for x in lines_pre]
        image_ids = [x[0] for x in splitlines_pre]
        confidence = np.array([float(x[1]) for x in splitlines_pre ])
        BB_pre = np.array([[float(z) for z in x[2:]] for x in splitlines_pre])

        sorted_ind = np.argsort(-confidence)
        sorted_scores = np.sort(-confidence)
        BB_pre = BB_pre[sorted_ind, :]
        image_ids = [image_ids[x] for x in sorted_ind]

        nd = len(image_ids)
        tp = np.zeros(nd)
        fp = np.zeros(nd)
    
        for d in range(nd):
            R = class_recs[image_ids[d]]
            bb = np.array(BB_pre[d, :]).astype(float)
            ovmax = -np.inf
            BBGT = np.array(R['bbox']).astype(float)
            if BBGT.size > 0:
                ixmin = np.maximum(BBGT[:, 0], bb[0])
                iymin = np.maximum(BBGT[:, 1], bb[1])
                ixmax = np.minimum(BBGT[:, 2], bb[2])
                iymax = np.minimum(BBGT[:, 3], bb[3])
                iw = np.maximum(ixmax - ixmin + 1., 0.)
                ih = np.maximum(iymax - iymin + 1., 0.)
                inters = iw * ih

                uni = ((bb[2] - bb[0] + 1.) * (bb[3] - bb[1] + 1.) +
                       (BBGT[:, 2] - BBGT[:, 0] + 1.) *
                       (BBGT[:, 3] - BBGT[:, 1] + 1.) - inters)

                overlaps = inters / uni
                ovmax = np.max(overlaps)
                jmax = np.argmax(overlaps)

            if ovmax > ovthresh:
                if not R['difficult'][jmax]:
                    if not R['det'][jmax]:
                        tp[d] = 1.
                        R['det'][jmax] = 1
                    else:
                        fp[d] = 1.
            else:
                fp[d] = 1.
        fp = np.cumsum(fp)
        tp = np.cumsum(tp)
        rec = tp / float(npos)
        prec = tp / np.maximum(tp + fp, np.finfo(np.float64).eps)
        ap = voc_ap(rec, prec, use_07_metric)
        
        if not pr_data.has_key(cls_name[cls_num]):
            pr_data.update({cls_name[cls_num]:[rec,prec,ap]})
    return pr_data

def voc_ap(rec, prec, use_07_metric=False):
    if use_07_metric:
        ap = 0.
        for t in np.arange(0., 1.1, 0.1):
            if np.sum(rec >= t) == 0:
                p = 0
            else:
                p = np.max(prec[rec >= t])
            ap = ap + p / 11.
    else:
        mrec = np.concatenate(([0.], rec, [1.]))
        mpre = np.concatenate(([0.], prec, [0.]))
        for i in range(mpre.size - 1, 0, -1):
            mpre[i - 1] = np.maximum(mpre[i - 1], mpre[i])
        i = np.where(mrec[1:] != mrec[:-1])[0]
        ap = np.sum((mrec[i + 1] - mrec[i]) * mpre[i + 1])
    return ap

def draw_pr(prediction_file,prediction_algorithm,ground_truth_file,cls):
    for i in range(len(prediction_file)):
        pr_data=get_pr_data("Prediction/"+prediction_file[i],"Ground Truth/"+ground_truth_file,cls)
        for cls_name in pr_data:
            plt.plot(pr_data[cls_name][0],pr_data[cls_name][1],label=prediction_algorithm[i]+' mAP='+str(round(pr_data[cls_name][2],3)))
            title='PR Curve of '+cls_name
            plt.title(title)
            plt.xlabel('Recall')
            plt.ylabel('Precision')
            plt.ylim([0.0, 1.0])
            plt.xlim([0.0, 1.0])
            plt.grid(ls='-.')
            plt.legend()
            plt.savefig("Images/"+title+'.png', dpi=300)
    plt.close()