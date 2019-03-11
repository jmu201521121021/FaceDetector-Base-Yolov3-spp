#! /usr/bin/env bash
source_dir="/jmu/jmuaia.tanghaom.top/data/User/admin/home/train/faceDetector/darknet/train_focal_loss/model-yolov3-spp-face-ori-focal-loss-2019-02-25-13/"
#log_file="log-yolov3-spp-face-ori-focal-loss-2019-02-25-13-05-21.log"
log_file="train_log.txt"
python log_parser.py --source-dir $source_dir --save-dir ./ --log-file $log_file --show false
