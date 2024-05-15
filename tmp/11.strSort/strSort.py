# lastEdit=>2024.05.12-10:30
"""
	01.读取tmp.txt文件中的内容
	02.对内容按行进行排序
	03.对排序后的内容写入tmp.txt
"""
import os

# 按行读取文件中的数据生成列表
def txt2list(filePath):
	with open(filePath,"r",encoding='utf-8') as f:
		strList = f.readlines()
	print("finish read files...")
	return strList

# 排序列表,拼接成字符串
def strSort(strList):
	strList = strList
	strList.sort()
	strTxt  = str()
	for i in strList:
		strTxt += i
	print("finish sort string list...")
	return strTxt

# 将内容写入文件
def write2txt(strTxt,filePath):
	with open(filePath,"w",encoding='utf-8') as f:
		f.write(strTxt)
	print("finish write2txt...")

def run(filePath):
	strList = txt2list(filePath)
	strTxt	= strSort(strList)
	write2txt(strTxt,filePath)
	# print(strTxt)

if __name__=="__main__":
	run("./tmp.txt")