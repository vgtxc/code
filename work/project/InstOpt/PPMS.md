//lastEdit=>2024.04.01
#### PPMS操作
    实验室:2014
	大门密码:061338
	电脑用户: user:caochuan, pwd:yuan910227
###### 01.刷卡上机
- "DSM"模式注册
###### 02.制样放样
- 样品位于样品台"35mm"刻度处;
###### 03.测试
- 03.01.确定状态: "Install/Remove Sample->skip"
- 03.02.设置文件夹: "Browser->文件夹(path:D:/zhangTianJing)"
- 03.03.升磁: "Linear"(线性)升磁"1000Oe", 速率100Oe;
- 03.04.扫描样品偏移量
    - (01)扫描偏移量: "Scan for sample offset"->样品在35mm左右;
    - (02)偏移量有误: 不是35mm, 手动输入35mm;
- 03.05.退磁: "Oscillate"(震荡)退磁"0Oe", 速率200Oe;
- 03.06.关舱,抽真空
    - (01)关舱: **Close Chaber**;
    - (02)等待气压状态为**Purged**;
- 03.07.设置测试程序
    - (01)脚本打开方式: "file->open->sequese";
    - (02)脚本路径: "D:/zhangTianJing/Sequese/M-H.seq";
    - (03)修改脚本: 数据路径, 磁场范围, 升降磁场速率;
- 03.08.扫描测试
    - (01)运行: "Run";
    - (02)查看实时扫描数据: "VSM面板->View Data";
    - (03)修改横坐标单位为Oe: "Data File->View->右键Data Selection";
    - (04)调整扫描图像显示: "Auto Scale All Plots";
- 03.09.保存数据
- 03.10.开舱: **open Chaber**;
###### 04.取样
###### 05.数据格式转换
###### 06.邮箱发送数据
###### 07.PC关机,放回样品杆,样品台