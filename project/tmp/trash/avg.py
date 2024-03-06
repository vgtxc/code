# 总人数
totalNum = 5

# 分数
arr = [1,2,3,4,5]
# 最大值，最小值
maxvalu = arr[0]
minvalu = arr[0]
# 总分数
totalvalu = 0
for i in arr:
	if i<minvalu:
		minvalu = i
	if i>maxvalu:
		maxvalu = i
	totalvalu += i
# 减去最低最高分求平均
totalvalu = totalvalu -(maxvalu+minvalu)
rst = totalvalu/(totalNum-2)
print("result\t->%0.6f"%rst)