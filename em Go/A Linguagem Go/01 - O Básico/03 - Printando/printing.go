package main

import "fmt"

func main() {
	nome := "Caprica-Six"
	aka := fmt.Sprintf("Número %d", 6)
	fmt.Printf("%s também conhecida como %s",
		nome, aka) // printando variáveis dentro da string
}
