from pypdf import PdfReader

p = r"D:\JinPeng\MagicBullet\ch9329.pdf"
r = PdfReader(p)
print("pages", len(r.pages))
text = "\n".join((pg.extract_text() or "") for pg in r.pages)
open(r"D:\JinPeng\MagicBullet\ch9329.txt", "w", encoding="utf-8").write(text)
print(text[:6000])
