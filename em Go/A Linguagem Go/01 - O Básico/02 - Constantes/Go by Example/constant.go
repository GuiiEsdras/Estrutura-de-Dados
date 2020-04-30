/*
O Go suporta constantes de caracteres, strings, valores booleanos e numéricos.
*/
package main

import (
	"fmt"
	"math"
)

const s string = "constant"

func main() {
	fmt.Println(s)

	const n = 500000000 // const declara um valor constante.

	// Uma declaração const pode aparecer em qualquer lugar que var possa.

	const d = 3e20 / n // Expressões constantes executam aritmética com precisão arbitrária.
	fmt.Println(d)

	fmt.Println(int64(d)) // Uma constante numérica não tem tipo até receber um, como por uma conversão explícita.

	// Um número pode receber um tipo usando-o em um contexto que requer um, como uma atribuição de variável ou chamada de função.
	// Por exemplo, aqui math.Sin espera um float64.
	fmt.Println(math.Sin(n))
}

/*
$ go run constant.go
constant
6e+11
600000000000
-0.28470407323754404
*/
