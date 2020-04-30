# Ponteiros <!-- omit in toc -->
Esta seção discute ponteiros e como passá-los como argumentos em Go

### Tópicos
- [Go e Ponteiros](#go-e-ponteiros)
- [Exemplo](#exemplo)

## Go e Ponteiros
Go tem *ponteiros*, mas, ao contrário de C, nenhum aritmético. Um ponteiro guarda o endereço de memória de uma variável. Os campos de uma [*Struct*](../08%20-%20Ponteiros) podem ser acessados ​​através de um ponteiro. A indireção através do ponteiro é transparente (você pode chamar diretamente campos e métodos em um ponteiro).

Observe que, por padrão, Go passa argumentos por valor (copiando os argumentos); se você deseja passar os argumentos por referência, precisa passar ponteiros (ou usar uma estrutura usando valores de referência, como *slices* e *maps*).

O tipo `*T` é um ponteiro para um valor `T`. Seu valor zero é `nil`.

```go
var p *int
```

Para obter o valor de um ponteiro, use o símbolo `&` na frente do valor, este operador gera um ponteiro para seu operando;

```go
i := 42
p := &i
```

Para remover a referência de um ponteiro, use o símbolo `*`, este operador indica o valor subjacente do ponteiro.

```go
fmt.Println(*p) // lê-se i através do ponteiro p
*p = 21         // atribui 21 a variável i através do ponteiro p
```

Isso é conhecido como "desreferenciando" ou "indiretamente".

Os métodos geralmente são definidos em ponteiros e não em valores (embora possam ser definidos em ambos); portanto, você costuma armazenar um ponteiro em uma variável, como no exemplo abaixo:

```
client := &http.Client{}
resp, err := client.Get("http://gobootcamp.com")
```

## Exemplo

```go
package main

import "fmt"

func main() {
	i, j := 42, 2701

	p := &i         // aponta para i
	fmt.Println(*p) // lê i através do ponteiro
	*p = 21         // define i através do ponteiro
	fmt.Println(i)  // vê o novo valor de i

	p = &j         // aponta para j
	*p = *p / 37   // divide j através do ponteiro
	fmt.Println(j) // vê o novo valor de j
}
```

*Saída:*
```bash
42
21
73
```