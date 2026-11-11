import os, sys
from ultralytics import YOLO

src = r"D:\JinPeng\MagicBullet\models\yolov8n.pt"
model = YOLO(src)
out = model.export(format="onnx", imgsz=640, opset=17, simplify=False, dynamic=False, device="cpu")
print("EXPORTED:", out)
print("size MB:", round(os.path.getsize(out)/1024/1024, 2))
