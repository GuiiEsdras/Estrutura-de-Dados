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
