#!/usr/bin/env bash
cd ..
NETWORK="yolov3-spp-face"
MODELDIR="./test/test-$NETWORK"
mkdir -p "$MODELDIR"
iter="34400"
LOGFILE="$MODELDIR/log-iter-$iter-$NETWORK-`date +%Y-%m-%d-%H-%M-%S`.log"
# test
./darknet detector map  cfg/face_focal_loss.data cfg/yolov3-spp-focal_loss-test.cfg  backup_focal_loss/yolov3-spp-focal_loss_$iter.weights -out "" -thresh 0.5 2>&1 | tee $LOGFILE
