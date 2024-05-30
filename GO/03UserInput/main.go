package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	welcome := "Welcome to User Input"
	fmt.Println(welcome)

	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the rating for our Pizza: ")
	//comma ok // err ok
	input, _ := reader.ReadString('\n')
	// input, err := reader.ReadString('\n')
	// _, err := reader.ReadString('\n')
	fmt.Println("Thanks for reading, ", input)
	fmt.Printf("Type of this rating, %T", input)
}
