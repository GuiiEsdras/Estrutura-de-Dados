# Funções e valores de Retorno <!-- omit in toc -->
Esta seção discute funções, valores de retorno, resultados nomeados e assinatura

### Tópicos
- [Funções](#fun%c3%a7%c3%b5es)
- [Valores de retorno](#valores-de-retorno)
- [Resultados nomeados](#resultados-nomeados)

## Funções
Ao declarar funções, o tipo vem após o nome da variável nas entradas.

O ou os tipos de retorno são então especificados após o nome da função e as entradas, antes de escrever a definição. As funções podem ser definidas para retornar qualquer número de valores e cada um deles é colocado aqui.

O código a seguir é um exemplo de definição de função:

```go
package main
import "fmt"

func add(x int, y int) int {
    return x + y
}

func main() {
    fmt.Println(add(42, 13))
}
```

No exemplo a seguir, em vez de declarar o tipo de cada parâmetro, declaramos apenas um tipo que se aplica a ambos.

```go
package main
import "fmt"

func add(x, y int) int {
    return x + y
}

func main() {
    fmt.Println(add(42, 13))
}
```

## Valores de retorno

No exemplo a seguir, a função `local` retorna duas strings.

```go
package main

import "fmt"

func local(cidade string) (string, string) {
	var regiao string
	var continente string

	switch cidade {
	case "Campina Grande", "CG", "Puxinanã":
		regiao, continente = "Paraíba", "América do Sul"
	case "São Paulo", "SP":
		regiao, continente = "São Paulo", "América do Sul"
	default:
		regiao, continente = "Desconhecido", "Desconhecido"
	}
	return regiao, continente
}

func main() {
	regiao, continente := local("Puxinanã")
	fmt.Printf("Guilherme mora em %s, %s", regiao, continente)
}
```
[exemplo_de_funcao.go](Função/exemplo_de_funcao.go)

## Resultados nomeados

Funções assumem parâmetros. Em Go, as funções podem retornar vários "parâmetros de resultado", não apenas um único valor. Eles podem ser nomeados e agir como variáveis.

Se os parâmetros do resultado forem nomeados, uma instrução de retorno sem argumentos retornará os valores atuais dos resultados.

```go
package main
import "fmt"

func local(cidade string) (regiao, continente string) {
	switch cidade {
	case "Campina Grande", "CG", "Puxinanã":
		regiao, continente = "Paraíba", "América do Sul"
	case "São Paulo", "SP":
		regiao, continente = "São Paulo", "América do Sul"
	default:
		regiao, continente = "Desconhecido", "Desconhecido"
	}
	return // retornando regiao e continente
}

func main() {
	regiao, continente := local("Puxinanã")
	fmt.Printf("Guilherme mora em %s, %s", regiao, continente)
}
```
[resultado_nomeado.go](Resultado%20nomeado/resultado_nomeado.go)
