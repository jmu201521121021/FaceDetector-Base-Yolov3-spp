#!/usr/bin/env bash
cd ..
# test
iter="35000"
./darknet detector valid  cfg/face.data cfg/yolov3-spp-test.cfg  backup/yolov3-spp_$iter.weights -out $iter-fddb -gpu 0  -thresh 0.5 
