"""
//lastEdit=>2023.08.07-16:51
//lastEdit=>2023.08.07-16:38
从https://hanime1.me获取信息:
	01.同人作者信息
		请求url:
		https://hanime1.me/search?type=artist&genre=%E5%90%8C%E4%BA%BA%E4%BD%9C%E5%93%81&page=1
		https://hanime1.me/search?type=artist&genre=%E5%90%8C%E4%BA%BA%E4%BD%9C%E5%93%81&page=6
		模板:
			https://hanime1.me/search?type=artist&genre=同人作品&page=6
	02.里番公司信息:
		请求url:
			https://hanime1.me/search?type=artist&genre=%E8%A3%8F%E7%95%AA&page=1
			https://hanime1.me/search?type=artist&genre=%E8%A3%8F%E7%95%AA&page=3
			模板；
				https://hanime1.me/search?type=artist&genre=裏番&page={pageNum}
"""

# 获取同人作者
def getAuthorName(initPage=1,overPage=6):
	# 发送请求
	requestHead = {
		"User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:109.0) Gecko/20100101 Firefox/111.0",
		}
	# 请求的url模板
	urlFmt = "https://hanime1.me/search?type=artist&genre=同人作品&page={pageNum}"
	# 获取一个页面内的同人作者
	def requestAUrl(pageNum=0):
		# 请求https://hanime1.me/search?type=artist&genre=同人作品&page=1
		requestUrl = urlFmt.format(pageNum=str(pageNum))
		print("info...requestUrl=>",requestUrl)
		pageResponse = requests.get(url=requestUrl,headers=requestHead,params=None)
		# 获取html内容
		pageContent = pageResponse.text.split("\n")
		# 提取html页面中所有作者的名字
		authorAPageList = list()	# 一个页面当中所有作者的名字
		for lineInfo in pageContent:
			authorMatcher = re.match(r"\t{3,3}<div class=\"card-mobile-title search-artist-title\" style=\"font-weight: normal; color: #e5e5e5;\">(.*)</div>",lineInfo)
			if authorMatcher!=None:
				authorAPageList.append(authorMatcher.group(1))	# 作者名字
		return authorAPageList
	# 请求
	# 	|-https://hanime1.me/search?type=artist&genre=同人作品&page=1
	# 	|-https://hanime1.me/search?type=artist&genre=同人作品&page=6
	retList = list()
	for pageNum in range(initPage,overPage+1):
		retList += requestAUrl(pageNum=pageNum)
	# 整理为列表,并返回里列表
	return retList

# 获取里番公司信息
def getCompanyName(initPage=1,overPage=3):
	# 发送请求
	requestHead = {
		"User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:109.0) Gecko/20100101 Firefox/111.0",
		}
	# 请求的url模板
	urlFmt = "https://hanime1.me/search?type=artist&genre=裏番&page={pageNum}"
	# 获取一个页面内的里番公司
	def requestAUrl(pageNum=0):
		# 请求https://hanime1.me/search?type=artist&genre=裏番&page=1
		requestUrl = urlFmt.format(pageNum=str(pageNum))
		print("info...requestUrl=>",requestUrl)
		pageResponse = requests.get(url=requestUrl,headers=requestHead,params=None)
		# 获取html内容
		pageContent = pageResponse.text.split("\n")
		# 提取html页面中所有作者的名字
		authorAPageList = list()	# 一个页面当中所有作者的名字
		for lineInfo in pageContent:
			authorMatcher = re.match(r"\t{3,3}<div class=\"card-mobile-title search-artist-title\" style=\"font-weight: normal; color: #e5e5e5;\">(.*)</div>",lineInfo)
			if authorMatcher!=None:
				authorAPageList.append(authorMatcher.group(1))	# 作者名字
		return authorAPageList
	# 请求
	# 	|-https://hanime1.me/search?type=artist&genre=裏番&page=1
	# 	|-https://hanime1.me/search?type=artist&genre=裏番&page=3
	retList = list()
	for pageNum in range(initPage,overPage+1):
		retList += requestAUrl(pageNum=pageNum)
	# 整理为列表,并返回里列表
	return retList

if __name__=="__main__":
	import os
	import re
	import requests
	# 设置运行时的代理
	# os.environ["http_proxy"] = "http://127.0.0.1:7890"
	# os.environ["https_proxy"] = "https://127.0.0.1:7890"
	
	# 所有同人作者信息
	autNameList = getAuthorName(initPage=1,overPage=6)
	cmpNameList = getCompanyName(initPage=1,overPage=3)
	print("info...同人作者名称列表=>",autNameList)
	print("*"*30)
	print("info...公司名称列表=>",cmpNameList)