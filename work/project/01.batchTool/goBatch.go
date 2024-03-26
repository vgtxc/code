package main

import(
	"fmt"
	"path/filepath"
)
// 路径遍历
func pathWalk(var dirpath string) []string{
	var files []string
    err := filepath.Walk(dirpath, func(path string, info os.FileInfo, err error) error {	files = append(files, path)	})
    return files
}

func main()error{
	path := "D:/sw"
	files := pathWalk(path)
	for _, file := range files {fmt.Println(file)}
}