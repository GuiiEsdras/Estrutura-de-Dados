# Constantes  <!-- omit in toc -->
Como declarar variáveis do tipo `const` (constantes)

### Tópicos

- [Declaração](#declara%c3%a7%c3%a3o)
- [Exemplo](#exemplo)

## Declaração

As constantes são declaradas como variáveis, mas com a palavra-chave `const`

As constantes podem ser apenas um **character**, **string**, valores **booleanos** ou **numéricos** e não podem ser declaradas usando a sintaxe `:=`. Uma constante *untyped* leva o tipo necessário para o seu contexto.

```go
const Pi = 3.14
const (
        StatusOK                   = 200
        StatusCreated              = 201
        StatusAccepted             = 202
        StatusNonAuthoritativeInfo = 203
        StatusNoContent            = 204
        StatusResetContent         = 205
        StatusPartialContent       = 206
)
```

## Exemplo

```go
package main

import "fmt"

const (
	Pi         = 3.14
	Verdadeiro = false
	Grande     = 1 << 62
	Pequeno    = Big >> 61
)

func main() {
	const Saudacao = "ハローワールド" // declarando uma constante
	fmt.Println(Saudacao)
	fmt.Println(Pi)
	fmt.Println(Verdadeiro)
	fmt.Println(Grande)
}
```
*[constantes.go](constantes.go)*

> **Nota:** O *operador de deslocamento à esquerda* (`<<`) desloca seu primeiro operando a esquerda pelo número de *bits* especificado por seu segundo operando. O tipo do segundo operando deve ser um `int` ou um tipo que tenha uma conversão numérica implícita predefinida para `int`. O *operador de deslocamento à direita* (`>>`) desloca seu primeiro operando para a direita pelo número de *bits* especificado por seu segundo operando.