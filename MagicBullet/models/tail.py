import onnx
m = onnx.load(r"D:\JinPeng\MagicBullet\models\yolov8n.onnx")
g = m.graph
print("nodes:", len(g.node))
for i, n in enumerate(g.node[-12:], start=len(g.node)-12):
    print(i, n.op_type, "| name=", n.name, "| in=", list(n.input), "| out=", list(n.output))
print("graph outputs:", [o.name for o in g.output])