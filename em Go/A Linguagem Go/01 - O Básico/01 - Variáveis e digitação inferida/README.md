# Variáveis e digitação inferida  <!-- omit in toc -->

O Go é frequentemente referido como uma linguagem de programação "simples", uma linguagem que pode ser aprendida em poucas horas se você estiver familiarizado com qualquer linguagem de programação básica. O Go foi projetado para parecer familiar e permanecer o mais simples possível, [toda a especificação da linguagem](https://golang.org/ref/spec) cabe em apenas algumas páginas.

### Tópicos

- [Declaração de Variáveis](#declara%c3%a7%c3%a3o-de-vari%c3%a1veis)
- [Inicialização de variável](#inicializa%c3%a7%c3%a3o-de-vari%c3%a1vel)
- [Links úteis](#links-%c3%bateis)

## Declaração de Variáveis

A declaração `var` declara uma lista de variáveis. O nome da variável vem primeiro e o tipo de variável é declarado após ela.

```go
var (
	nome        string
	idade 	    int
	localizacao string
)
```

ou até

```go
var (
	nome, localizacao string
	age               int
)
```

Variáveis também podem ser declaradas uma por uma:

```go
var nome        string
var idade       int
var localização string
```

## Inicialização de variável

Uma declaração `var` pode incluir inicializadores, um por variável.

```go
var (
	nome        string = "Príncipe Oberyn"
	idade       int    = 32
	localizacao string = "Dorne"
)
```

Se um inicializador estiver presente, o tipo poderá ser omitido, a variável assumirá o tipo do inicializador (digitação inferida).

```go
var (
	nome        = "Príncipe Oberyn"
	idade       = 32
	localizacao = "Dorne"
)
```

Você também pode inicializar várias variáveis ​​ao mesmo tempo.

```go
var (
	nome, idade, localizacao = "Príncipe Oberyn", 32, "Dorne"
)
```

Dentro de uma função, a instrução `:=` de atribuição curta pode ser usada no lugar de uma declaração `var` com tipo implícito.

```go
package main
import "fmt"

func main() {
	nome, localizacao := "Prince Oberyn", "Dorne"
	idade := 32
	fmt.Printf("%s idade %d de %s ", nome, idade, localizacao)
}
```
*[declarando_variaveis.go](declarando_variaveis.go)*

Saída:
```bash
Prince Oberyn idade 32 de Dorne
```

Uma variável pode conter qualquer tipo, incluindo funções:

```go
func main() {
	acao := func() { // acao é uma variável que contém uma função
		// faz algo
	}
}
```

Fora de uma função, cada construct começa com uma palavra-chave (var, func, e assim por diante) e a construct `:=` não está disponível.

## Links úteis
- [Go’s declaration Syntax](http://blog.golang.org/gos-declaration-syntax): para ler mais sobre a sintaxe da linguagem Go.