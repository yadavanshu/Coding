package main

import "fmt"

// numberOfUser :=30000.00 not allowed oustide the scope


//if first letter is capital then it will be public variable
const LoginToken string="lorem"

func main() {
	var username string = "goLang"
	fmt.Println(username)
	fmt.Printf("Variable is of type: %T \n", username)

	var isLoggedIn bool = false
	fmt.Println(isLoggedIn)
	fmt.Printf("Variable is of type: %T \n", isLoggedIn)

	var smallVal int = 255
	fmt.Println(smallVal)
	fmt.Printf("Variable is of type: %T \n", smallVal)


	var smallValFloat float32 = 255.54525425152525252
	fmt.Println(smallValFloat)
	fmt.Printf("Variable is of type: %T \n", smallValFloat)


	var smallValF float64 = 255.54525425152525252
	fmt.Println(smallValF)
	fmt.Printf("Variable is of type: %T \n", smallValF)

	//implicit type
	var website = "github.opentext.in";
	fmt.Println(website);

	// no var stype
	numberOfUser :=30000.00
	numberOfUser=40000.0;
	fmt.Println(numberOfUser)

	fmt.Println(LoginToken)
	fmt.Printf("Variable is of type: %T \n", LoginToken)



}
