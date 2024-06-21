package main

import (
	"fmt"
	"sort"
)

func main() {
	fmt.Println("Welcome, Slices DS")
	var fruitList = []string{"Apple", "Tomato", "Peach"}
	fmt.Printf("Type of fruitList: %T \n", fruitList)
	fruitList = append(fruitList, "Mango", "Banana")

	fmt.Println("Type of fruitList: ", fruitList)

	fruitList = append(fruitList[1:3])
	fmt.Println("Type of fruitList: ", fruitList)

	highScores := make([]int, 4)
	highScores[0] = 234
	highScores[1] = 238
	highScores[2] = 253
	highScores[3] = 985
	// highScores[4]=905

	highScores=append(highScores, 555,888,999)

	fmt.Println("highScores : ", highScores)
	fmt.Println("highScores : ", sort.IntsAreSorted(highScores))
	sort.Ints(highScores)
	fmt.Println("highScores : ", highScores)
	fmt.Println("highScores : ", sort.IntsAreSorted(highScores))

}
