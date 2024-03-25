import re
def findUrl(srcDict,aimStr):
	rst = dict()
	for i in range(1,len(srcDict.keys())):
		url = srcDict[str(i)]
		#	关键字筛选
		if (aimStr in url) and (url not in rst):
			rst[str(i)] = url
	return rst

def readFile(path):
	rst = dict()
	with open(path,"r") as f:
		count = 1
		line = f.readline()
		rst[str(count)] = line
		count += 1
		while line:
			line = f.readline()
			# line = re.sub(r"\n","",line)
			rst[str(count)] = line
			count += 1
	return rst

if __name__ == "__main__":
	"""
		已经尝试关键字:
			hentai
			anime
			cosplay
			cos
			moe
	"""
	import os
	srcpath = "./category-porn.txt"
	keyword = "moe"
	rst = findUrl(readFile(path=srcpath),aimStr = keyword)
	firefox = "C:/Users/vnkgt/Desktop/vFirefox.lnk {siteUrl}"
	siteUrl = str()
	for i in rst.keys():
		url = rst[i].split("\n")[0]
		print(url)
		siteUrl += " "+url
	# print(siteUrl)
	os.system(firefox.format(siteUrl=siteUrl))
		
