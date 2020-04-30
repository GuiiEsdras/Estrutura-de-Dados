/*
 O Go possui suporte interno para vários valores de retorno.
 Esse recurso é usado frequentemente no Go idiomático, por exemplo, para retornar valores de resultado e erro de uma função.
*/

package main

import "fmt"

func vals() (int, int) {
	// A assinatura (int, int) nesta função mostra que a função retorna 2 ints.
	return 3, 7
}

func main() {

	a, b := vals() // Aqui, usamos os 2 valores de retorno diferentes da chamada com atribuição múltipla.
	fmt.Println(a)
	fmt.Println(b)

	_, c := vals() // Se você deseja apenas um subconjunto dos valores retornados, use o identificador em branco _.
	fmt.Println(c)
}

/*
$ go run multiple-return-values.go
3
7
7
*/ 
