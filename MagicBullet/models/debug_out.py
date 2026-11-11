import numpy as np, onnxruntime as ort, glob
from PIL import Image

SIZE=640
def pre(p):
    img = Image.open(p).convert("RGB")
    w,h = img.size
    r = min(SIZE/w, SIZE/h)
    nw,nh = int(round(w*r)), int(round(h*r))
    img = img.resize((nw,nh), Image.BILINEAR)
    c = Image.new("RGB",(SIZE,SIZE),(114,114,114)); c.paste(img,((SIZE-nw)//2,(SIZE-nh)//2))
    a = np.asarray(c,dtype=np.float32)/255.0
    return a.transpose(2,0,1)[None,...]

p_img = sorted(glob.glob(r"D:\JinPeng\MagicBullet\models\calib\**\*.jpg", recursive=True))[0]
x = pre(p_img)

for name, path in [("fp32", r"D:\JinPeng\MagicBullet\models\yolov8n.onnx"),
                   ("int8", r"D:\JinPeng\MagicBullet\models\yolov8n_int8_qdq.onnx")]:
    s = ort.InferenceSession(path, providers=["CPUExecutionProvider"])
    inp = s.get_inputs()[0]
    print(name, "input:", inp.name, inp.shape, inp.type)
    y = s.run(None, {inp.name: x})[0]
    print("  out shape", y.shape, "dtype", y.dtype)
    print("  all: min %.3f max %.3f mean %.4f" % (y.min(), y.max(), y.mean()))
    if y.shape[1] >= 84:
        boxes = y[0,:4,:]; scores = y[0,4:,:]
        print("  boxes: min %.2f max %.2f" % (boxes.min(), boxes.max()))
        print("  scores: min %.4f max %.4f  count>0.25: %d" % (scores.min(), scores.max(), (scores>0.25).sum()))