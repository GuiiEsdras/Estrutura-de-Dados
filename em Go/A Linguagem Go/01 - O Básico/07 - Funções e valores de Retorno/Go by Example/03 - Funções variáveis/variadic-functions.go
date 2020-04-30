/*
Funções variáveis podem ser chamadas com qualquer número de argumentos à direita. Por exemplo,fmt.Printlné uma função variável comum.
*/
package main

import "fmt"

/*
Aqui está uma função que terá um número arbitrário de ints como argumentos.
*/
func sum(nums ...int) {
	fmt.Print(nums, " ")
	total := 0
	for _, num := range nums {
		total += num
	}
	fmt.Println(total)
}

func main() {

	// Funções variáveis ​​podem ser chamadas da maneira usual com argumentos individuais.
	sum(1, 2)
	sum(1, 2, 3)

	// Se você já possui vários argumentos em uma fatia, aplique-os a uma função variável usando func(slice...) assim:
	nums := []int{1, 2, 3, 4}
	sum(nums...)
}

/*
$ go run variadic-functions.go
[1 2] 3
[1 2 3] 6
[1 2 3 4] 10
*/
