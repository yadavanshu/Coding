package main

import "fmt"

func main() {
	// fmt.Println("Welcome to Pointers")
	// var ptr *int
	// fmt.Println("Value of Pointer is: ", ptr)

	myNumber := 23
	var ptr = &myNumber
	// &--> mean reference
	fmt.Println("Value of Pointer is: ", ptr)
	fmt.Println("Value of Pointer is: ", *ptr)
	fmt.Println("Value of Pointer is: ", &ptr)
	fmt.Println("Value of myNumber is: ", &myNumber)
	
	*ptr = *ptr + 2;
	
	fmt.Println("New Value is: ", myNumber)
}
