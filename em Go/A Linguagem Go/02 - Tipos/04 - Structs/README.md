# Estruturas (Structs) <!-- omit in toc -->
Esta seção explica como definir novos tipos usando Structs

### Tópicos
- [Definição](#defini%c3%a7%c3%a3o)
- [Exemplos](#exemplos)
- [Quiz](#quiz)

## Definição
Anteriormente discutimos os tipos incorporados em Go, agora vamos ver como novos tipos podem ser definidos usando structs (estruturas). Uma estrutura é uma coleção de campos / propriedades. Você pode definir novos tipos como estruturas ou interfaces. Se você é proveniente de um plano de fundo orientado a objetos, pode pensar em uma estrutura como uma classe leve que suporta composição, mas não herança. Os métodos são discutidos detalhadamente na próxima seção.

Você não precisa definir getters e setters nos campos de uma struct, eles podem ser acessados ​​automaticamente. No entanto, observe que apenas os campos exportados (em maiúsculas) podem ser acessados ​​de fora de um pacote.

Um literal de estrutura define um valor de estrutura recém-alocado listando os valores de seus campos. Você pode listar apenas um subconjunto de campos usando a syntax "Name:" (a ordem dos campos nomeados é irrelevante ao usar esta sintaxe). O prefixo especial `&` constrói um ponteiro para uma estrutura recém-alocada.

## Exemplos
A seguir se encontra um exemplo de declaração de uma struct:

```go
package main

import (
	"fmt"
	"time"
)

type Bootcamp struct {
	// Latitude do evento
	Lat float64
	// Longitude do evento
	Lon float64
	// Data do evento
	Date time.Time
}

func main() {
	fmt.Println(Bootcamp{
		Lat:  34.012836,
		Lon:  -118.495338,
		Date: time.Now(),
	})
}
```

Declaração de literais struct:

```go
package main

import "fmt"

type Point struct {
	X, Y int
}

var (
	p = Point{1, 2}  // tem o tipo Point
	q = &Point{1, 2} // tem o tipo *Point
	r = Point{X: 1}  // Y:0 está implícito
	s = Point{}      // X:0 e Y:0
)

func main() {
	fmt.Println(p, q, r, s)
}
```

Acessando campos usando a notação de ponto:

```go
package main

import (
	"fmt"
	"time"
)

type Bootcamp struct {
	Lat, Lon float64
	Date     time.Time
}

func main() {
	event := Bootcamp{
		Lat: 34.012836,
		Lon: -118.495338,
	}
	event.Date = time.Now()
	fmt.Printf("Event on %s, location (%f, %f)",
		event.Date, event.Lat, event.Lon)

}
```

## Quiz

1. Qual das alternativas a seguir NÃO é verdadeira em relação às estruturas (structs)?
   - [ ] A) Estruturas podem ser usadas para definir tipos adicionais no Go.
   - [ ] B) Estruturas são semelhantes às classes que suportam composição.
   - [ ] C) As estruturas são semelhantes às classes que suportam herança na Programação Orientada a Objetos.
   - [ ] D) As funções Setter e Getter não são necessárias para definir no Go.