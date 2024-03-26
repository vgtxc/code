from PIL import Image
import os

# 修改一张图片的尺寸
def resizeAImg(srcImg,aimDir,newSize=(600,800)):
    aimImg = os.path.join(aimDir,os.path.split(srcImg)[1])
    # 读取图片
    img = Image.open(srcImg)
    #修改图片尺寸
    img = img.resize(newSize)
    # 保存图片
    img = img.convert("RGB")
    img.save(aimImg)

srcFileList = list()
for root,dirs,files in os.walk("C:/Users/vnkgt/Pictures/a"):
    for file in files:
        filepath = os.path.join(root,file)
        if filepath not in srcFileList:  
            srcFileList.append(filepath)

for file in srcFileList:
    resizeAImg(file,"C:/Users/vnkgt/Pictures/b",(960,546))
    print("resize success...",file)

