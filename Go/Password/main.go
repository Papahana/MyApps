// go mod init Password
// go run main.go

package main

import (
	"fmt"
)

var println = fmt.Println

func getUserInput() string {
	var data string
	fmt.Scanln(&data)
	return data
}

func main() {
	password := "1234"
	attempts := 3

	for {
		print("\nEnter the password: ")
		userInput := getUserInput()

		if userInput == password {
			println("The password is correct")
			break
		} else {
			attempts--
			if attempts > 0 {
				println("Wrong password")
			} else {
				println("Account locked!")
				break
			}
		}
	}
	println("\nEnding Program ...\n")
}
