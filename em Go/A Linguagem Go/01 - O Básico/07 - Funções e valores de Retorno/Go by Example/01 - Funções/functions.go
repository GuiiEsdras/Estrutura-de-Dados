/*
As funções são centrais no Go. Vamos aprender sobre funções com alguns exemplos diferentes.
*/
package main

import "fmt"

/*
 Aqui está uma função que leva dois ints e retorna sua soma como um int.
 Go requer retornos explícitos, ou seja, ele não retornará automaticamente o valor da última expressão.
*/
func plus(a int, b int) int {
	return a + b
}

/*
 Quando você possui vários parâmetros consecutivos do mesmo tipo,
 pode omitir o nome do tipo para os parâmetros do mesmo tipo até
 o parâmetro final que declara o tipo.
*/
func plusPlus(a, b, c int) int {
	return a + b + c
}

func main() {

	res := plus(1, 2) // Chame uma função exatamente como você esperaria, com name(args).
	fmt.Println("1+2 =", res)

	res = plusPlus(1, 2, 3)
	fmt.Println("1+2+3 =", res)
}

/*
$ go run functions.go
1+2 = 3
1+2+3 = 6
*/
