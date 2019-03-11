#!/usr/bin/env bash
cd ..
NETWORK="yolov3-spp-face-ori"
MODELDIR="./train/model-$NETWORK-face-`date +%Y-%m-%d-%H`"
mkdir -p "$MODELDIR"
LOGFILE="$MODELDIR/log-$NETWORK-`date +%Y-%m-%d-%H-%M-%S`.log"
weight_file="darknet53.conv.74"
#weight_file="backup/yolov3-spp_last.weights"
#train
./darknet detector train -dont_show  cfg/face.data cfg/yolov3-spp.cfg $weight_file 2>&1 | tee $LOGFILE
#train continue
#./darknet detector train cfg/deepLesion.data cfg/yolov3-spp.cfg backup/yolov3-spp.backup  2>&1 | tee $LOGFILE
