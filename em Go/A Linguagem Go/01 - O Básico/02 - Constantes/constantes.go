package main

import "fmt"

const (
	Pi         = 3.14
	Verdadeiro = false
	Grande     = 1 << 62
	Pequeno    = Big >> 61
)

func main() {
	const Saudacao = "ハローワールド" // declarando uma constante
	fmt.Println(Saudacao)
	fmt.Println(Pi)
	fmt.Println(Verdadeiro)
	fmt.Println(Grande)
}
