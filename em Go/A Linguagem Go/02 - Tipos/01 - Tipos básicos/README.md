# Tipos básicos <!-- omit in toc -->
Esta seção lista todos os tipos de variáveis disponíveis em Go.

### Tópicos
- [Lista de tipos incorporados](#lista-de-tipos-incorporados)
			- [Tipos comuns](#tipos-comuns)
			- [Tipos numéricos](#tipos-num%c3%a9ricos)
- [Exemplo](#exemplo)

## Lista de tipos incorporados
A seguir, são apresentados os tipos incorporados em Go.

##### Tipos comuns

| Tipo     | Descrição                |
|----------|--------------------------|
| `bool`   | verdadeiro ou falso      |
| `string` | uma matriz de caracteres |

##### Tipos numéricos

| Tipo         | Descrição                                                                                                                           |
|--------------|-------------------------------------------------------------------------------------------------------------------------------------|
| `uint`       | 32 ou 64 bits                                                                                                                       |
| `int`        | mesmo tamanho que uint                                                                                                              |
| `uintptr`    | um número inteiro não assinado (unsigned int) grande o suficiente para armazenar os bits não interpretados de uma valor de ponteiro |
| `uint8`      | o conjunto de todos os números inteiros de 8 bits não assinados (unsigned) (0 a 255)                                                |
| `uint16`     | o conjunto de todos os números inteiros de 16 bits não assinados (0 a 65535)                                                        |
| `uint32`     | o conjunto de todos os números inteiros de 32 bits não assinados (0 a 4294967295)                                                   |
| `uint64`     | o conjunto de todos os números inteiros de 64 bits não assinados (0 a 18446744073709551615)                                         |
| `int8`       | o conjunto de todos os números inteiros de 8 bits assinados (-128 a 127)                                                            |
| `int16`      | o conjunto de todos os números inteiros de 16 bits assinados (-32768 a 32767)                                                       |
| `int32`      | o conjunto de todos os números inteiros de 32 bits assinados (-2147483648 a 2147483647)                                             |
| `int64`      | o conjunto de todos os números inteiros de 64 bits assinados (-9223372036854775808 a 9223372036854775807)                           |
| `float32`    | o conjunto de todos os números IEEE-754 de ponto flutuante de 32 bits                                                               |
| `float64`    | o conjunto de todos os números IEEE-754 de ponto flutuante de 64 bits                                                               |
| `complex64`  | o conjunto de todos os números `float32` complexos com partes reais e imaginárias                                                   |
| `complex128` | o conjunto de todos os números `float64` complexos com partes reais e imaginárias                                                   |
| `byte`       | alias para `uint8`                                                                                                                  |
| `rune`       | alias para `uint32` (representa um código Unicode)                                                                                  |

## Exemplo

A seguir, são apresentados exemplos de declarações de variáveis ​​de alguns dos tipos internos:

```go
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
```

*Saída:*
```bash
bool(true)
uint64(18446744073709551615)
complex128((2+3i))
```