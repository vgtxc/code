# lastEdit=>2023.07.17-22:57
# lastEdit=>2023.07.17-22:48
"""
	1.读取warpIP.csv文件中的ip列表
	2.把每个“ip：port”转为配置文件
	3.配置文件名“ip-port.conf”
"""
import csv,re,os


def warpConfGender(warpCsvConfFile="",warpConfFmtFile=""):
	if len(warpCsvConfFile)==0 or len(warpConfFmtFile)==0:
		return None
	with open(ipCsvFile,"r") as ipFile:
		csvRead = csv.reader(ipFile)
		# 输出文件个数计数器
		outfileCounter = 1
		for row in csvRead:
			# rowStruct
			# ['IP:PORT', ' LOSS', ' DELAY']
			ip = row[0]	# ip:port
			delay = row[2]	# 延迟
			delay = re.match(r"(\d+)( ms)",delay)
			# 延迟判断
			if delay and int(delay[1])<=2000:
				# 延迟数值
				delay = delay[1]
				# 输出文件名“ip-port#delay.conf”
				outfileName = "%0.3d"%outfileCounter+"."+delay+"ms.conf"
				outfileCounter += 1
				# 输出文件路径
				outfilePath = os.path.join("./tmp",outfileName)
				# 不存在"./tmp",就创建
				if os.path.exists("./tmp")==False:
					os.mkdir("./tmp")
				with open(warpConfFmtFile,"r") as fmtFlie:
					fmtContent = fmtFlie.read()
					# 替换文件中的{ip:port字符串}
					fmtContent = re.sub(r"\{ip:port\}",ip,fmtContent)
					with open(outfilePath,"w") as outFile:
						outFile.write(fmtContent)
				print("gen---->",outfilePath)


if __name__=="__main__":
	ipList = list()
	ipCsvFile = "./warpIPGen/result.csv"
	warpFmt = "./warpConfFmt.conf"
	outDir = "./warpIPGen/tmp"
	warpConfGender(ipCsvFile,warpFmt)
