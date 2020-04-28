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
