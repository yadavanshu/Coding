package main

import "fmt"

func main() {
	fmt.Println("Welcome, to Array!")
	var fruitList [4]string
	fruitList[0] = "Apple"
	fruitList[1] = "Mango"
	fruitList[3] = "Peach"
	fmt.Println("Fruit list is: ", fruitList)
	fmt.Println("Fruit list length is: ", len(fruitList))

	var vegList = [5]string{"potato", "beans", "mushroom"}
	fmt.Println("Vegetable List: ", vegList)
	fmt.Println("Vegetable List Length: ", len(vegList))
}
