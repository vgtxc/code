import re,os
# 数值生成
def lenGen(num,minpec=95*0.01,maxpec=105*0.01,step=0.5*0.01):
	retList = list()
	cur = minpec
	while(cur<=maxpec):
		# round(num,place),保留place位小数
		retList.append(round(num*cur,3))
		cur+=step
	return retList

# 文件生成
def xsdGen(file,matName="",cellLenList=list(),dstDir="./tmp",minpec=95*0.01,maxpec=105*0.01,step=0.5*0.01):
	with open(file,"r") as srcF:
		srcTxt = srcF.read()
		cur = minpec
		fcur = 095.0
		while(cur<=maxpec):
			dstF = os.path.join(dstDir,"{0}-{1}Len.xsd".format(matName,fcur))
			with open(dstF,"w") as wf:
				wTxt = str(srcTxt)
				for cellLen in cellLenList:
					oldlen = str(cellLen)
					newlen = str(round(cellLen*cur,3))
					wTxt = re.sub(oldlen,newlen,wTxt)
					wTxt = re.sub(oldlen,newlen,wTxt)
					print(dstF,"\t---->\t",newlen)
				wf.write(wTxt)
				wTxt = str()
			cur+=step
			fcur+=0.5


if __name__=="__main__":
	xsdGen(file="./GaN(3.189,5.185).xsd",matName="GaN",cellLenList=[3.189,5.185],dstDir="./GaN")
	# 生成数组100*95%-100*105%,步长0.5%
	# k = lenGen(100,95,105,0.5)
	# Si
	# Si_a = 5.430
	# cur = 95
	# for i in lenGen(Si_a,95,105,0.5):
	# 	print("Si-%03.1fLen.xsd->\ta=%0.3f"%(cur,i))
	# 	cur+=0.5
	# print("\n--------------------------------------------\n")
	# # GaN
	# GaN_a = 3.189
	# GaN_c = 5.185
	# a_new = lenGen(GaN_a,95,105,0.5)
	# c_new = lenGen(GaN_c,95,105,0.5)
	# cur = 95
	# for i in range(len(a_new)):
	# 	a = a_new[i]
	# 	c = c_new[i]
	# 	print("GaN-%03.1fLen.xsd->\ta=%0.3f\tc=%0.3f"%(cur,a,c))
	# 	cur+=0.5
