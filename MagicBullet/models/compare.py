import glob, os, numpy as np
from ultralytics import YOLO

fp32 = YOLO(r"D:\JinPeng\MagicBullet\models\yolov8n.onnx", task="detect")
int8 = YOLO(r"D:\JinPeng\MagicBullet\models\yolov8n_int8_qdq.onnx", task="detect")
imgs = sorted(glob.glob(r"D:\JinPeng\MagicBullet\models\calib\**\*.jpg", recursive=True))[:8]
print("test images:", len(imgs))
tot_f = tot_i = 0
maxdiff = 0.0
for p in imgs:
    rf = fp32.predict(p, imgsz=640, conf=0.25, verbose=False)[0]
    ri = int8.predict(p, imgsz=640, conf=0.25, verbose=False)[0]
    nf, ni = len(rf.boxes), len(ri.boxes)
    tot_f += nf; tot_i += ni
    if nf and ni:
        sf = np.sort(rf.boxes.conf.cpu().numpy())[::-1]
        si = np.sort(ri.boxes.conf.cpu().numpy())[::-1]
        m = min(len(sf), len(si))
        maxdiff = max(maxdiff, float(np.max(np.abs(sf[:m] - si[:m]))))
    print(os.path.basename(p), "fp32 boxes:", nf, " int8 boxes:", ni)
print("total boxes fp32=%d int8=%d  max score delta=%.4f" % (tot_f, tot_i, maxdiff))