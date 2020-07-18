# Inicializando <!-- omit in toc -->
Esta seção discute a inicialização de variáveis ​​usando a nova expressão em Go

### Tópicos
- [Usando a expressão `new`](#usando-a-express%c3%a3o-new)
- [Links úteis](#links-%c3%bateis)

## Usando a expressão `new`

Agora que sabemos os diferentes tipos que variáveis ​​podem assumir, examinaremos as variáveis ​​de inicialização. Go suporta a expressão `new` para alocar um valor zerado do tipo solicitado e retornar um ponteiro para ele.

```go
x := new(int)
```

Como visto na [Seção: Estruturas](../04%20-%20Structs) uma maneira comum de "inicializar" uma variável que contém uma estrutura ou uma referência a uma, é criar uma estrutura literal. Outra opção é criar um construtor. Isso geralmente é feito quando o valor zero não é bom o suficiente e você precisa definir alguns valores de campo padrão, por exemplo.

Observe que as seguintes expressões usando `new` e uma struct literal vazia são equivalentes e resultam no mesmo tipo de alocação/inicialização:

```go
package main

import (
	"fmt"
)

type Bootcamp struct {
	Lat float64
	Lon float64
}

func main() {
	x := new(Bootcamp)
	y := &Bootcamp{}
	fmt.Println(*x == *y)
}
```
*Saída:*
```bash
true
```

Observe que fatias (slices), mapas (maps) e canais (channels) geralmente são alocados usando `make` para que a estrutura de dados sobre a qual esses tipos são criados possa ser inicializada.

## Links úteis
- [Alocação usando `new` - effective Go](http://golang.org/doc/effective_go.html#allocation_new)
- [Literais compostos - effective Go](http://golang.org/doc/effective_go.html#composite_literals)
- [Alocação com `make` - effective Go](http://golang.org/doc/effective_go.html#allocation_make)