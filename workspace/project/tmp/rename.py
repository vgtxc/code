import os,re

def rename(path):
	actList = list()
	for root,dirs,files in os.walk(path):
		for file in files:
			reRst = re.match(r"^(FSOG\d{3,3})\[(.*)\](.*)$",file)
			if reRst:
				vidid = reRst.group(1).lower()
				vidact = reRst.group(2)
				vidext = reRst.group(3)
				if vidact not in actList:
					actList.append(vidact)
				old = os.path.join(root,file)
				new = "{vidid}-[{vidact}]-{vidext}".format(vidid=vidid,vidact=vidact,vidext=vidext)
				new = os.path.join(root,new)
				os.rename(old,new)
				print(new)
	return actList

# def sortStr(string):
# 	aimstr = re.sub(r"\[",">",string)
# 	aimstr = re.sub(r"\]",">",aimstr)
	# aimstr = re.sub(r" ","",aimstr)
	# strs = aimstr.split(">")
	# for i in strs:
	# 	print(i)


if __name__=="__main__":
	srcpath = "C:\\Users\\vgtxc\\Downloads\\Telegram Desktop"
	# acts = rename(srcpath)
	# for i in acts:
	# 	print("[%s]"%i)
	string = str()
	with open("./a.txt","r","utf-8") as f:
		string = f.read()
	print(string)