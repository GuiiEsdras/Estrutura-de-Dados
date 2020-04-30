package main

import (
	"fmt"
	"math/cmplx"
)

var (
	goIsFun bool       = true                 //declarando uma variável do tipo bool
	maxInt  uint64     = 1<<64 - 1            //declarando uma variável do tipo uint64
	complex complex128 = cmplx.Sqrt(-5 + 12i) //declarando uma variável do tipo complex128
)

func main() {
	const f = "%T(%v)\n"
	fmt.Printf(f, goIsFun, goIsFun)
	fmt.Printf(f, maxInt, maxInt)
	fmt.Printf(f, complex, complex)
}
