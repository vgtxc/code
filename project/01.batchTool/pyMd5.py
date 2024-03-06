import os,sys,time

def changeAFileMd5(file):	# 修改一个文件md5值,通过向文件未添加一个字符串来改变md5值
		try:
			ntime = time.localtime()
			ntime = "%0.4d.%0.2d.%0.2d.%0.2d.%0.2d"%(ntime.tm_year,ntime.tm_mon,ntime.tm_mday,ntime.tm_hour,ntime.tm_min)
			random_str = "-vgt-%s"%ntime
			with open(file, 'ab') as f:
				f.write(random_str.encode('utf-8'))
			print("md5 changed...")
		except:
			pass

def main():
	# 命令行参数列表，第一个:python文本文件名，第二个:其他
	cmdArg = sys.argv
	path = cmdArg[1]
	# 判断路径是否存在
	if not os.path.exists(path):
		print("err:	{0} not exsist!!!".format(path))
	# 判断是文件还是文件夹
	# 为文件夹
	if os.path.isdir(path):
		for root,dirs,files in os.walk(path):
			for file in files:
				filePath = os.path.join(root,file)
				changeAFileMd5(filePath)
				print("\t",filePath)
		return 0
	# 为文件
	changeAFileMd5(path)
	return 0
		
		

if __name__=="__main__":
	main()