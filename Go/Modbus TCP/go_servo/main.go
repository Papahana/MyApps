// Servo acts as the client

package main

import (
	"fmt"
	"log"
	"os"
	"time"

	"github.com/simonvetter/modbus"
)

func getTitle() {
	content, _ := os.ReadFile("title/servo_title.txt")
	title := string(content)
	fmt.Println(title)
}

func writeRegister(regNum uint16, targetVal uint16, client *modbus.ModbusClient) {
	var err = client.WriteRegister(uint16(regNum), targetVal)
	if err != nil {
		log.Fatalf("Failed to write to register %d: %v", regNum, err)
	}
	fmt.Printf("Write to register %d: %d\n", regNum, targetVal)
}

func readRegister(regNum uint16, client *modbus.ModbusClient) {
	currentPos, err := client.ReadRegister(regNum, modbus.INPUT_REGISTER)
	if err != nil {
		log.Fatalf("Failed to read register %d: %v", regNum, err)
	}
	fmt.Printf("Read the register %d: %d\n", regNum, currentPos)
}

func main() {
	getTitle()

	// The client's settings
	client, err := modbus.NewClient(&modbus.ClientConfiguration{
		URL:     "tcp://localhost:5502",
		Timeout: 2 * time.Second,
	})
	if err != nil {
		log.Fatalf("Failed to create client config: %v", err)
	}

	// The client tries to connect to the server
	err = client.Open()
	if err != nil {
		log.Fatalf("Failed to connect to Modbus Seerver: %v. Is the server running?", err)
	}
	defer client.Close()

	fmt.Println("Connected successfully to Modbus Server!")

	// Write registers (regNum, value, client)
	writeRegister(1, 9, client)
	writeRegister(2, 5, client)

	// Read registers (regNum, client)
	readRegister(11, client)
	readRegister(12, client)
}
