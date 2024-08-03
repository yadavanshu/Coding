package main

import (
	"fmt"
	"strings"
)

func main() {
	// Define predefined responses
	responses := map[string]string{
		"hello":    "Hi there!",
		"goodbye":  "See you later!",
		"how are":  "I'm doing great, thanks for asking!",
		"what is":  "I'm not sure, can you please provide more context?",
		"who are":  "I am a simple chat bot built with Go.",
		"where is": "I'm sorry, I don't have that information.",
	}

	// Main loop
	for {
		// Get user input
		var userInput string
		fmt.Print("User