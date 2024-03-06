# lastEdit=>2023.10.03-17:07
import csv

pvaKey = "mAMPBOrn1CNH5KoLKOoBkKW4KD5TVPENpwq2TsPLT1M="
pubKey = "bmXOC+F1FxEMF9dyiK2H5/1SUtzH0JuVo51h2wPfgyo="

warpConfFmtStr01 = """
mixed-port: 7890
allow-lan: false
mode: Rule
log-level: info
external-controller: 127.0.0.1:9090
clash-for-android:
    append-system-dns: false
hosts:
  mtalk.google.com: 108.177.125.188
dns:
  enable: false
  listen: 127.0.0.1:5335
  use-hosts: true
  default-nameserver: [223.5.5.5, 119.29.29.29]
  ipv6: false
  enhanced-mode: fake-ip
  fake-ip-filter: []
  nameserver: []
  nameserver-policy: {}
  fallback: []
  fallback-filter: {}
proxies:
"""

warpConfFmtStr02Fmt = 'name: \"{0}\",type: wireguard,server: {1},port: {2},ip: 172.16.0.2,private-key: {3},public-key: {4},remote-dns-resolve: false,udp: true'
warpConfFmtStr02 = ""

warpConfFmtStr03 = """
proxy-groups:
 - { name: warp, type: select, proxies: [%s] }"""
nameList = ""
with open("./warpIPPoor.csv","r") as ipFile:
	csvRead = list(csv.reader(ipFile))[1:]
	count = 1
	for lineCont in csvRead:
		warpIP,warpPort = str(lineCont[0]).split(":")
		loss = lineCont[1]
		delay = lineCont[2]
		chosname = "id{num}".format(num="%0.4d"%count)
		nameList += "'%s'"%chosname+","
		# warpConfFmtStr02Fmt = "\t"
		# for i in warpConfFmtStr02FmtDict.keys():
		warpConfFmtStr02 += '  - {%s}\n'%warpConfFmtStr02Fmt.format(chosname,warpIP,warpPort,pvaKey,pubKey)
		count+=1

with open("./clashConf.conf","w") as f:
	f.write(warpConfFmtStr01+warpConfFmtStr02+warpConfFmtStr03%nameList)
