#!/usr/bin/env bash
cd ..
NETWORK="yolov3-spp-face-focal-loss"
MODELDIR="./train_focal_loss/model-$NETWORK-`date +%Y-%m-%d-%H`"
mkdir -p "$MODELDIR"
LOGFILE="$MODELDIR/log-$NETWORK-`date +%Y-%m-%d-%H-%M-%S`.log"
weight_file="darknet53.conv.74"
#weight_file="backup_focal_loss/yolov3-spp-focal_loss_last.weights"
#train
./darknet detector train -dont_show  cfg/face_focal_loss.data cfg/yolov3-spp-focal_loss.cfg $weight_file 2>&1 | tee $LOGFILE
#train continue
#./darknet detector train cfg/deepLesion.data cfg/yolov3-spp.cfg backup/yolov3-spp.backup  2>&1 | tee $LOGFILE
