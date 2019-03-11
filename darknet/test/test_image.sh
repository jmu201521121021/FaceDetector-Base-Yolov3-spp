#!/usr/bin/env bash
cd ..
# test
#dar="/jmu/jmuaia.tanghaom.top/data/User/admin/home/train/Deepyx/darknet-AB-ori"
iter="33400"
image="yz314.jpg"
thresh=0.5
./darknet detector test -dont_show cfg/face_focal_loss.data cfg/yolov3-spp-focal_loss.cfg backup_focal_loss/yolov3-spp-focal_loss_$iter.weights -ext_output data/$image  -thresh $thresh
