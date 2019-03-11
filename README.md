# FaceDetector-Base-Yolov3-spp

## FLYL Demo



# Content

## Deep Face Detection

[TOC]

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

- detail,please check here 

3、Download the training set (`Widerface`) and place it in *`darknet/build/darknet/x64/data/voc`*



4、go to *darknet/build/darknet/x64/data/voc/*

```
python  voc_label.py
```

5、start train,into `./train`

sh train



## Pretrained Models

- Please check here

## Evaluation

- Test on widerFace

  ​

- Test on FDDB

## Face Detection system

- Please check here.

## Contact

```
[Chen Jinshan](jinshanchen@jmu.edu.cn)
```

-

