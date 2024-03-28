import os

rootPath = "./son"

for root,dirs,files in os.walk(rootPath):
	for file in files:
		filepath = os.path.join(rootPath,file)
		newfile = os.path.splitext(file)[0]+"-out.jpg"
		newfilePath = os.path.join(root,newfile)
		cmd = "vrealgan -i %s -o %s"%(filepath,newfile)
		os.system(cmd)