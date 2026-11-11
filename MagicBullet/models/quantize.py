import os, glob, numpy as np
from PIL import Image
from onnxruntime.quantization import quantize_static, CalibrationDataReader, QuantFormat, QuantType, CalibrationMethod

MODEL_IN  = r"D:\JinPeng\MagicBullet\models\yolov8n.onnx"
MODEL_OUT = r"D:\JinPeng\MagicBullet\models\yolov8n_int8_qdq.onnx"
IMG_DIR   = r"D:\JinPeng\MagicBullet\models\calib"
SIZE      = 640

# the head's box coords (0..640) and class scores (0..1) land in one Concat: a shared
# scale crushes the scores, so keep the last nodes in fp32.
EXCLUDE = [
    "/model.22/Concat_3",
    "/model.22/Sigmoid",
    "/model.22/Mul_2",
]

def letterbox(img):
    w, h = img.size
    r = min(SIZE / w, SIZE / h)
    nw, nh = int(round(w * r)), int(round(h * r))
    img = img.resize((nw, nh), Image.BILINEAR)
    canvas = Image.new("RGB", (SIZE, SIZE), (114, 114, 114))
    canvas.paste(img, ((SIZE - nw) // 2, (SIZE - nh) // 2))
    return (np.asarray(canvas, dtype=np.float32) / 255.0).transpose(2, 0, 1)[None, ...]

files = sorted(glob.glob(os.path.join(IMG_DIR, "**", "*.jpg"), recursive=True))

class Reader(CalibrationDataReader):
    def __init__(self): self.i = 0
    def get_next(self):
        while self.i < len(files):
            p = files[self.i]; self.i += 1
            try: return {"images": letterbox(Image.open(p).convert("RGB"))}
            except Exception: continue
        return None

quantize_static(MODEL_IN, MODEL_OUT, Reader(),
                quant_format=QuantFormat.QDQ, per_channel=True,
                activation_type=QuantType.QUInt8, weight_type=QuantType.QInt8,
                calibrate_method=CalibrationMethod.MinMax,
                nodes_to_exclude=EXCLUDE)
print("saved", round(os.path.getsize(MODEL_OUT)/1024/1024, 2), "MB")