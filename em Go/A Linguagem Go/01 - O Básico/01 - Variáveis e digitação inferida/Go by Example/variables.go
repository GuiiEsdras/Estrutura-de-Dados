/*
 Em Go, as variáveis são explicitamente declaradas e usadas pelo compilador para, por exemplo, verificar a correção de tipo das chamadas de função.
*/

package main

import "fmt"

func main() {

	var a = "initial" // var declara 1 ou mais variáveis.
	fmt.Println(a)

	var b, c int = 1, 2 // Você pode declarar várias variáveis ​​ao mesmo tempo.
	fmt.Println(b, c)

	var d = true // Go inferirá o tipo de variáveis ​​inicializadas.
	fmt.Println(d)

	var e int // Variáveis ​​declaradas sem uma inicialização correspondente têm valor zero. Por exemplo, o valor zero para um int é 0.
	fmt.Println(e)

	f := "apple" // A sintaxe := é uma abreviação para declarar e inicializar uma variável, por exemplo, var f string = "apple" neste caso.
	fmt.Println(f)
}

/*
$ go run variables.go
initial
1 2
true
0
apple
*/
