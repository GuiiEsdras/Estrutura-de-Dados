# Declarando tipos <!-- omit in toc -->
Esta seção explica a conversão do tipo de um determinado valor para outro valor específico usando exemplos

### Tópicos
- [Introdução](#introdu%c3%a7%c3%a3o)
- [Exemplos](#exemplos)
- [Quiz](#quiz)
- [Links úteis](#links-%c3%bateis)

## Introdução 
Na seção anterior, foi abordado as conversões de tipo. Agora, discutiremos como, se você tiver um valor que deseja converter para outro ou um tipo específico (no caso de `interface{}`), poderá usar a **asserção de tipo ou declaração de tipo (Type Assertion)**. Uma asserção de tipo assume um valor e tenta criar outra versão no tipo explícito especificado.

## Exemplos 
No exemplo abaixo, a função `timeMap` assume um valor e, se puder ser declarada como um mapa de `interfaces{}` chaveadas por strings, injeta uma nova entrada chamada “updated_at” com o valor de tempo atual.

```go
package main

import (
	"fmt"
	"time"
)

func timeMap(y interface{}) {
	z, ok := y.(map[string]interface{}) //declarando y como um mapa de interfaces
	if ok {
		z["updated_at"] = time.Now() //z agora é do tipo map[string]interface 
	}
}

func main() {
	foo := map[string]interface{}{
		"Matt": 42,
	}
	timeMap(foo)
	fmt.Println(foo)
}
```
*Saída:*
```bash
map[Matt:42 updated_at:2020-04-30 21:37:17.673778422 +0000 UTC]
```

A asserção de tipo não precisa ser feita em uma interface vazia. É frequentemente usado quando você tem uma função que usa um parâmetro de uma interface específica, mas o código interno da função se comporta de maneira diferente com base no real tipo do objeto. Aqui está um exemplo:

```go
package main

import "fmt"

type Stringer interface {
	String() string
}

type fakeString struct {
	content string
}

// função usada para implementar uma interface Stringe
func (s *fakeString) String() string {
	return s.content
}

func printString(value interface{}) {
	switch str := value.(type) {
	case string:
		fmt.Println(str)
	case Stringer:
		fmt.Println(str.String())
	}
}

func main() {
	s := &fakeString{"Ceci n'est pas un string"}
	printString(s)
	printString("Hello, Gophers")

}
```
*Saída:*
```bash
Ceci n'est pas un string
Hello, Gophers
```

Outro exemplo é ao verificar se um erro é de um determinado tipo:

```go
if err != nil {
  if msqlerr, ok := err.(*mysql.MySQLError); ok && msqlerr.Number == 1062 {
    log.Println("We got a MySQL duplicate :(")
  } else {
    return err
  }
}
```

## Quiz

1. Para qual das seguintes opções é usada a asserção de tipo / declaração de tipo (Type Assertion)?
   - [ ] A) Determinando o tipo de uma variável.
   - [ ] B) Convertendo o tipo de uma variável em outro tipo específico.
   - [ ] C) Atribuindo um tipo a uma nova variável.

## Links úteis
- [Effective Go Guide - Interface Conversions](https://golang.org/doc/effective_go.html#interface_conversions)