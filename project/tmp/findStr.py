import os

def findAimFile(path,aimStr):
	ret = list()
	for root,dirs,files in os.walk(path):
		for file in files:
			if (aimStr in file) and (".xsd" in file):
				aimPath = os.path.join(root,file)
				ret.append(aimPath)
				print(file)
	return ret



if __name__=="__main__":
	srcpath = "C:\\Program Files (x86)\\BIOVIA\\Materials Studio 20.1\\share\\Examples"
	aimStr = "Si"
	findAimFile(srcpath,aimStr)
