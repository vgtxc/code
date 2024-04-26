//lastEdit=>2024.04.26-20:56
//lastEdit=>2024.04.24-21:06
//lastEdit=>2024.03.26-15:48

imp->文件夹目录及功能说明
根目录
	|-doc;	@->文档管理
	|-lang;	@->编程语言学习
	|-prof;	@->专业软件学习
	|-proj;	@->项目管理
	|-src;	@->资源管理
	|-tmp;	@->临时目录

imp->文件后缀名及说明
	程序源码文件
	|-clang
	|---"*.c":c语言源码
	|---"*.cpp":c++语言源码
	专业工程文件
	|-solidwork
	|---"*.step":零件
	|---"*.sldasm":装配体

imp->编程学习路径
	|-基础
	|---01.helloWord
	|---02.inpAndOut#输入输出
	|---03.dataType#数据类型
	|---|---数据的声明, 对象的创建, 对象的引用, 对象的修改;
	|---04.judgeAndloop#判断与循环
	|---05.funcAndArg#函数及参数
	|---|---函数的声明, 函数的调用;
	|---05.01.sysArg#环境参数获取
	|---05.02.sysCmd#系统命令调用
	|---06.regExp#正则表达式
	|---07.fileOpt#文件操作
	|---08.libAndpack#库与包
	|---实例
	|---demo-01.九九乘法表
	|---demo-02.猜数游戏
	|---demo-03.成绩管理系统
	|---demo-04.贪吃蛇
	|-进阶(网络)
	|---09.protocol#协议
	|---09.01.http
	|---09.02.mysql#数据库
	|---09.03.redis#数据库
	|---10.thread#多线程
	|---11.network#网络
	|---12.framework#框架

学习环境:
	clang:
		|-mingw工具集
	python
		|-conda工具集