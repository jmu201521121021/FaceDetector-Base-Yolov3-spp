# FaceDetector-Base-Yolov3-spp

## FLYL Demo

![demo.jpg](https://github.com/jmu201521121021/FaceDetector-Base-Yolov3-spp/blob/master/results/face-test1.jpg)

# Content

## Deep Face Detection

## Inroduction

In this repository, we provide training data, network settings and loss designs for deep face detection.
The training data is Widerface datasets, which were already packed in darknet  format.he network backbone is darknet53, classifical loss is focal loss,which  improve 1.2%  Map onWiderface val.read focal loss and code,please check here.

This repository can help researcher/engineer to develop deep face detection  algorithms quickly by only two steps: download the dataset and run the training script.In sum,we can run a face detection system in window easily.

## Trainng Data

All Widerface data are into VOC format.Please click here to download data.

- if you want to make data into Voc format, please check `data_process/widerfaceToVoc.ipynb `

## Train

1、Clone the repository

```
git clone 
```

2、Install darknetAB with GPU surpport 

- detail,please check [here](https://github.com/AlexeyAB/darknet/blob/master/README.md) 

3、Download the training set (`Widerface`) and place it in *`darknet/build/darknet/x64/data/voc`*



4、go to *darknet/build/darknet/x64/data/voc/*

```
python  voc_label.py
```

5、start train,into `./train`

sh train



## Pretrained Models

- Please check here(soon )

## Evaluation

- Test on widerFace

  ![p-r](https://github.com/jmu201521121021/FaceDetector-Base-Yolov3-spp/blob/master/evaluation/PR%20Curve%20of%20yolov3-spp-face.png)

- Test on FDDB
  ![roc](https://github.com/jmu201521121021/FaceDetector-Base-Yolov3-spp/blob/master/evaluation/ROC-curve-final.png)

## Face Detection system

- Please check here(soon).

## Contact

```
[Chen Jinshan](jinshanchen@jmu.edu.cn)
```

-

