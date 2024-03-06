"""
//lastEdit=>2023.08.10:15:12
//lastEdit=>2023.08.10-14:12
	适用书签:
		1.FireFox浏览器导出书签
		2.书签文件夹不超过3层
"""

import os,re

# 按目录顺序匹配书签中的title与url并输出为txt文件
def getBmStruct(bmFile=str(),outFile=str()):
	bmContent = str()
	with open(bmFile,"r",encoding="utf-8") as rf:
		bmContent = rf.read()
	# 简化书简内容
	bmContent = re.sub(r" ADD_DATE=\"\d+\"","",bmContent)
	bmContent = re.sub(r" LAST_MODIFIED=\"\d+\"","",bmContent)
	bmContent = re.sub(r" ICON_URI=\".+\"","",bmContent)
	# 替换html中的大于小于号
	bmContent = re.sub(r"&gt",">",bmContent)
	bmContent = re.sub(r"&lt","<",bmContent)
	simpleContent = str()
	simpleContent += "#root\n"
	tabNum = 1
	sondir = False 	# 子文件夹的url要多加一个制表缩进,匹配到第一个二级子文件夹就开启
	# 替换url行的格式
	for line in bmContent.split("\n"):
		# 匹配url及title
		lineMatch = re.match(r"(    )*<DT><A HREF=\"(.*)\">(.*)</A>",line)
		if lineMatch:
			# tabNum = len(lineMatch.group(1))//4+1
			tab = "\t"*(tabNum)
			tabPlus = "\t"*(tabNum+1)
			if sondir==True:
				tab = "\t"*(tabNum+1)
				tabPlus = "\t"*(tabNum+2)
			url = lineMatch.group(2)
			title = lineMatch.group(3)
			simpleContent += "{tab}|-{title}\n{tabPlus}|-{url}\n".format(tab=tab,title=title,url=url,tabPlus=tabPlus)
			continue
		# 匹配二级文件夹标题
		lineMatch = re.match(r"(    ){2,2}<DT><H3>(.*)</H3>",line)
		if lineMatch:
			tabNum = 1
			sondir = True
			tab = "\t"*(tabNum)
			tabPlus = "\t"*(tabNum+1)
			dirName = lineMatch.group(2)
			simpleContent += tab+"#"+dirName+"\n"
			continue
		# 匹配三级文件夹标题
		lineMatch = re.match(r"(    ){3,3}<DT><H3>(.*)</H3>",line)
		if lineMatch:
			tabNum = 2
			tab = "\t"*(tabNum)
			tabPlus = "\t"*(tabNum+1)
			dirName = lineMatch.group(2)
			simpleContent += tab+"#"+dirName+"\n"
			continue
	with open(outFile,"w",encoding="utf-8") as wf:
		wf.write(simpleContent)
	return "vgt"


if __name__=="__main__":
	getBmStruct(bmFile = "./bm-v2023.08.10.html",outFile = "./bm-v2023.08.10.txt")

	print("info...processing over!!!")