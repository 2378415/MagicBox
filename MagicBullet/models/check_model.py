import numpy as np, onnxruntime as ort, time, onnx
p = r"D:\JinPeng\MagicBullet\models\yolov8n.onnx"
m = onnx.load(p)
print("opset:", [(o.domain, o.version) for o in m.opset_import])
for i in m.graph.input:
    print("input :", i.name, [d.dim_value or d.dim_param for d in i.type.tensor_type.shape.dim])
for o in m.graph.output:
    print("output:", o.name, [d.dim_value or d.dim_param for d in o.type.tensor_type.shape.dim])
s = ort.InferenceSession(p, providers=["CPUExecutionProvider"])
name = s.get_inputs()[0].name
x = np.random.rand(1,3,640,640).astype(np.float32)
for _ in range(3): s.run(None, {name: x})
t0 = time.perf_counter()
for _ in range(20): s.run(None, {name: x})
print("PC CPU fp32 inference: %.1f ms" % ((time.perf_counter()-t0)/20*1000))
print("output shape:", s.run(None, {name: x})[0].shape)