/*
  As estruturas em Go são coleções de campos digitadas.
  Elas são úteis para agrupar dados e formar registros.
*/
package main

import "fmt"

/*
Este tipo de estrutura person possui campos name e age.
*/
type person struct {
	name string
	age  int
}

/*
newPerson constrói uma nova struct de uma pessoa com o nome dado.
*/
func newPerson(name string) *person {

	/*
		Você pode retornar com segurança um ponteiro para a variável local, pois uma variável local sobreviverá ao escopo da função.
	*/
	p := person{name: name}
	p.age = 42
	return &p
}

func main() {

	fmt.Println(person{"Bob", 20}) // Essa sintaxe cria uma nova estrutura.

	fmt.Println(person{name: "Alice", age: 30}) // Você pode nomear os campos ao inicializar uma estrutura.

	fmt.Println(person{name: "Fred"}) // Os campos omitidos terão valor zero.

	fmt.Println(&person{name: "Ann", age: 40}) // Um prefixo & gera um ponteiro para a estrutura.

	fmt.Println(newPerson("Jon")) // É idiomático encapsular nova criação de estrutura em funções de construtor

	s := person{name: "Sean", age: 50}
	fmt.Println(s.name) // Acesse os campos de uma struct com um ponto.

	sp := &s
	fmt.Println(sp.age) // Você também pode usar pontos com ponteiros de struct - os ponteiros são automaticamente desreferenciados.

	sp.age = 51 // Estruturas são mutáveis.
	fmt.Println(sp.age)
}

/*
$ go run structs.go
{Bob 20}
{Alice 30}
{Fred 0}
&{Ann 40}
&{Jon 42}
Sean
50
51
*/
