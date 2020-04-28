# Printando  <!-- omit in toc -->

Esta seção explica como printar variáveis e constantes.

### Tópicos
- [Printando Constantes e Variáveis](#printando-constantes-e-vari%c3%a1veis)
- [Links úteis](#links-%c3%bateis)

## Printando Constantes e Variáveis

Embora você possa imprimir o valor de uma variável ou constante usando as funções *built-in* `print` e `println`, a maneira mais idiomática e flexível é usar o *[package](http://golang.org/pkg/fmt/)* `fmt`.

```go
package main
import "fmt"

func main() {
	cylonModel := 6
	fmt.Println(cylonModel)
}
```

`fmt.Println` imprime os valores passados ​​das variáveis ​​e acrescenta uma nova linha. `fmt.Printf` é usado quando você deseja imprimir um ou vários valores usando um especificador de formato definido ( `%d`, `%s`).

```go
package main

import "fmt"

func main() {
	nome := "Caprica-Six"
	aka := fmt.Sprintf("Número %d", 6)
	fmt.Printf("%s também conhecida como %s",
		nome, aka) // printando variáveis dentro da string
}

```
[printing.go](printing.go)

## Links úteis
- [Documentação do Pacote `fmt`](http://golang.org/pkg/fmt/#hdr-Printing)