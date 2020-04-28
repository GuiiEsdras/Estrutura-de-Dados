# Mutabilidade
Esta seção discute a mutabilidade e como usá-la com a ajuda de ponteiros em Go

Em Go, apenas *constantes* são imutáveis. No entanto, como os argumentos são passados ​​por valor, uma função que recebe um argumento de valor e o modifica, não modifica o valor original.

```go
package main

import "fmt"

type Artista struct {
	Nome, Genero string
	Musicas      int
}

func novoLancamento(um Artista) int { // passando um Artista por valor
	um.Musicas++
	return um.Musicas
}

func main() {
	eu := Artista{Nome: "Guilherme", Genero: "Electro", Musicas: 50}
	fmt.Printf("%s lancou sua %dº música\n", eu.Nome, novoLancamento(eu))
	fmt.Printf("%s tem um total de %d músicas", eu.Nome, eu.Musicas)
}
```
[artista_por_valor.go](Artista%20por%20valor/artista_por_valor.go)

Neste exemplo, a quantidade total de músicas no valor da variável `eu` não foi alterada. Para alterar o valor passado, precisamos passá-lo por referência, usando um ponteiro.

```go
package main

import "fmt"

type Artista struct {
	Nome, Genero string
	Musicas      int
}

func novoLancamento(um *Artista) int { // passando um Artista por referência
	um.Musicas++
	return um.Musicas
}

func main() {
	eu := &Artista{Nome: "Guilherme", Genero: "Electro", Musicas: 50}
	fmt.Printf("%s lancou sua %dº música\n", eu.Nome, novoLancamento(eu))
	fmt.Printf("%s tem um total de %d músicas", eu.Nome, eu.Musicas)
}

```
[artista_por_referencia.go](Artista%20por%20referência/artista_por_referencia.go)

A única alteração entre as duas versões é que `novoLancamento` leva um ponteiro para o valor `Artista` e, quando inicializo a variável `eu`, uso o símbolo `&` para obter um ponteiro para o valor.

Outro lugar em que você precisa ter cuidado é ao chamar métodos em valores, conforme explicado um pouco mais tarde.