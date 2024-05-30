package main

import (
	"fmt"
	"time"
)

func main() {
	fmt.Println("Welcome to time study of GOLang")
	presentTime := time.Now();
	fmt.Println(presentTime)
	fmt.Println(presentTime.Format("01-02-2006 15:04:05 Monday"))

	createdDate := time.Date(2020, time.April, 4, 23, 12, 0,4, time.UTC);

	fmt.Println(createdDate)
	fmt.Println(createdDate.Format("01-02-2006 15:04:05 Monday "))
}