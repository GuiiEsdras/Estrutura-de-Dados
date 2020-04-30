/*
  O Go suporta ponteiros , permitindo que você passe referências a valores e registros dentro do seu programa.

  Mostraremos como os ponteiros funcionam em contraste com os valores com 2 funções: zeroval e zeroptr.
  zeroval tem um parâmetro inteiro, então os argumentos serão passados ​​a ele por valor.
  zeroval obterá uma cópia de ival distinta daquela na função de chamada.

  zeroptr em contraste, tem um parâmetro *int, o que significa que é necessário um ponteiro int.
  O código *iptr no corpo da função desreferencia o ponteiro do endereço de memória para o valor atual nesse
  endereço. Atribuir um valor a um ponteiro não referenciado altera o valor no endereço referenciado.

  A sintaxe &i fornece o endereço de memória de i, ou seja, um ponteiro para i.

  Os ponteiros também podem ser impressos.

  zeroval não altera a variável i no main, mas zeroptr o faz porque tem uma referência para o endereço de memória para essa variável.
*/

package main

import "fmt"

func zeroval(ival int) {
	ival = 0
}

func zeroptr(iptr *int) {
	*iptr = 0
}

func main() {
	i := 1
	fmt.Println("initial:", i)

	zeroval(i)
	fmt.Println("zeroval:", i)

	zeroptr(&i)
	fmt.Println("zeroptr:", i)

	fmt.Println("pointer:", &i)
}

/*
$ go run pointers.go
initial: 1
zeroval: 1
zeroptr: 0
pointer: 0x42131100
*/
