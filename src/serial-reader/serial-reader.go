package main

import (
	"log"
	"github.com/tarm/serial"
)

func main() {
	go transmitter();
	receiver();
}

func transmitter() {
	c := &serial.Config{Name: "/dev/ttyACM1", Baud: 9600}
	s, err := serial.OpenPort(c)
	if err != nil {
		log.Fatal(err)
	}

	for {
		buf := make([]byte, 1)
		n, err := s.Read(buf)
		if err != nil {
			log.Fatal(err)
		}
		log.Print("Sent: " + string(buf[:n]))
	}

}
func receiver() {
	c := &serial.Config{Name: "/dev/ttyACM0", Baud: 9600}
	s, err := serial.OpenPort(c)
	if err != nil {
		log.Fatal(err)
	}

	for {
		buf := make([]byte, 1)
		n, err := s.Read(buf)
		if err != nil {
			log.Fatal(err)
		}
		log.Print("Received: " + string(buf[:n]))
	}

}