import onnxruntime as ort, sys
p = r"D:\JinPeng\MagicBullet\models\imported\m.onnx"
s = ort.InferenceSession(p, providers=["CPUExecutionProvider"])
for i in s.get_inputs():
    print("input :", i.name, i.shape, i.type)
for o in s.get_outputs():
    print("output:", o.name, o.shape, o.type)