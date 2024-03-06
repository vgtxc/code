package main

import (
	"fmt"
)

// 总人数
const totalNum int = 5

func main() {
	// 分数
	var arr = [totalNum+1]int{1,2,3,4,5}
	// 最大值，最小值
	var minvalu int = arr[0]
	var maxvalu int = arr[0]
	// 总分数
	var totalvalu int = 0
	// 寻找最大，最小分数
	for i := range arr {
		if i<minvalu {minvalu=i}
		if i>maxvalu {minvalu=i}
		totalvalu += i
	}
	//	减去最低最高分求平均
	rst := float64(totalvalu-minvalu-maxvalu)/float64(totalNum-2)
	fmt.Printf("result\t->%0.6f\n",rst)
}
