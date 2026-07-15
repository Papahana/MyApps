// The server runs in the PLC

package main

import (
	"fmt"
	"os"

	"github.com/simonvetter/modbus"
)

// This function generates a title with ASCII Art
func getTitle() {
	content, _ := os.ReadFile("title/plc_title.txt")
	title := string(content)
	fmt.Println(title)
}

func main() {
	getTitle()

	handler := &SimpleHandler{}

	// This is the server configuration
	server, _ := modbus.NewServer(&modbus.ServerConfiguration{
		URL: "tcp://0.0.0.0:5502",
	}, handler)

	// The server start with this statement
	fmt.Println("Server starting on port 5502 ...")
	_ = server.Start()
	select {}
}

type SimpleHandler struct {
	readReg uint16
}

// Read registers
func readRegister(h *SimpleHandler, req *modbus.HoldingRegistersRequest, regNum uint16) ([]uint16, error) {
	if req.Addr == regNum {
		if req.IsWrite {
			h.readReg = req.Args[0]
			fmt.Printf("Read the register %d: %d\n", regNum, h.readReg)
		}
		return []uint16{h.readReg}, nil
	}
	return nil, modbus.ErrIllegalDataAddress
}

func (h *SimpleHandler) HandleHoldingRegisters(req *modbus.HoldingRegistersRequest) (res []uint16, err error) {
	if req.Addr == 1 {
		return readRegister(h, req, 1)
	}
	if req.Addr == 2 {
		return readRegister(h, req, 2)
	}
	return nil, modbus.ErrIllegalDataAddress
}

// Write registers
func writeRegister(targetVal uint16, req *modbus.InputRegistersRequest, regNum uint16) (res []uint16, err error) {
	if req.Addr == regNum {
		mockRegister := uint16(targetVal)
		res = append(res, mockRegister)
		fmt.Printf("Write to register %d: %d\n", regNum, targetVal)
		return res, nil
	}
	return nil, modbus.ErrIllegalDataAddress
}

func (h *SimpleHandler) HandleInputRegisters(req *modbus.InputRegistersRequest) (res []uint16, err error) {
	if req.Addr == 11 {
		return writeRegister(13, req, 11)
	}
	if req.Addr == 12 {
		return writeRegister(16, req, 12)
	}
	return nil, modbus.ErrIllegalDataAddress
}

func (h *SimpleHandler) HandleCoils(req *modbus.CoilsRequest) ([]bool, error) {
	return nil, modbus.ErrIllegalFunction
}

func (h *SimpleHandler) HandleDiscreteInputs(req *modbus.DiscreteInputsRequest) ([]bool, error) {
	return nil, modbus.ErrIllegalFunction
}
