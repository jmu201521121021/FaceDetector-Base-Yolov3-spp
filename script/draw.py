# -*- coding: UTF-8 -*-
import matplotlib.pyplot as plt
from cal import *
cls=["yolov3-spp-face"] # 类别
prediction_file=["CE35000face.txt", "28300face.txt","mtcnn_widerface_val_result.txt"] # 放在Prediction里面
prediction_algorithm=["yolo3-spp-CE","yolo3-spp-FL","mtcnn"] # 对应上面的文件的算法名称
ground_truth_file="val_gt.txt" # 放在Ground Truth里面

# 绘制出了各个类别的Precision-Recall曲线
draw_pr(prediction_file,prediction_algorithm,ground_truth_file,cls)