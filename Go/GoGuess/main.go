// go mod init GoGuess
// go run main.go
// go build -o GoGuess.exe

package main

import (
	"fmt"
	"math/rand"
	"os"
)

var println = fmt.Println

func getTitle() {
	content, _ := os.ReadFile("Ascii-Art-Generator/user_data/title.txt")
	title := string(content)
	println(title)
}

func getUserInput() int {
	var data int
	fmt.Scanln(&data)
	return data
}

func main() {
	getTitle()

	println("----------------------------------------------")
	println("A random number will be generated and your objective is to guess that number.")

	print("\nHow many oportunities do you want? ")
	gameLives := getUserInput()

	println("\nYou will get two types of clues:")
	println("    - Cold: Your guess is out of close range")
	println("    - Hot: Your guess is two points lower or higher from the target number")

	println("\nCreating new number ...")
	targetNumber := rand.Intn(20) + 1 // Generate a random integer between 1 and 20
	println("----------------------------------------------\n")

	println("Game: Write your guess")

	for i := 0; i < gameLives; i++ {
		print("User: ")
		userNum := getUserInput()

		if userNum == targetNumber {
			println("You've guessed the number!")
			println("Killing program ...\n")
			fmt.Println("Press the Enter Key to stop anytime")
			fmt.Scanln()
			break
		} else if userNum < targetNumber && userNum >= targetNumber-2 || userNum <= targetNumber+2 && userNum > targetNumber {
			println("Game: Hot")
		} else {
			println("Game: Cold")
		}

		if i >= gameLives-1 {
			println("You're out of lives ...")
			fmt.Println("Press the Enter Key to stop anytime")
			fmt.Scanln()
		}
	}
}
