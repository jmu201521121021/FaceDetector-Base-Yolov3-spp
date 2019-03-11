#!/usr/bin/env bash
cd ..
# test
iter="28300"
./darknet detector valid  cfg/face_focal_loss.data cfg/yolov3-spp-focal_loss-test.cfg  backup_focal_loss/yolov3-spp-focal_loss_$iter.weights  -out FE_WD$iter -gpu 0  -thresh 0.5 
