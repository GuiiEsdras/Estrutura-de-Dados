/*
 O Go suporta funções anônimas, que podem formar fechamentos.
 Funções anônimas são úteis quando você deseja definir uma função embutida sem precisar nomeá-la.
*/
package main

import "fmt"

/*
 Essa função intSeq retorna outra função, que definimos anonimamente no corpo de intSeq.
 A função retornada fecha sobre a variável i para formar um fechamento.
*/
func intSeq() func() int {
	i := 0
	return func() int {
		i++
		return i
	}
}

func main() {

	/*
	 Chamamos intSeq, atribuindo o resultado (uma função) a nextInt.
	 Este valor da função captura seu próprio valor i, que será atualizado sempre que chamarmos nextInt.
	*/
	nextInt := intSeq()

	// Veja o efeito do fechamento chamando nextInt algumas vezes.
	fmt.Println(nextInt())
	fmt.Println(nextInt())
	fmt.Println(nextInt())

	// Para confirmar que o estado é exclusivo para essa função específica, crie e teste um novo.
	newInts := intSeq()
	fmt.Println(newInts())
}

/*
$ go run closures.go
1
2
3
1
*/
