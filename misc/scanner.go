package main

import (
	"fmt"
)

func main() {
	var arr []int
	_, err := fmt.Scan(&arr)
	if err != nil {
		fmt.Printf("err", err)
	}
	fmt.Println(arr)
	//for i, j := range os.Args[1:] {
	//	fmt.Printf("%d %d", i, j)
	//}
}
