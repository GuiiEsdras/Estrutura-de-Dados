package main

import "fmt"

type Usuario struct {
	ID                int
	Nome, Localizacao string
}

func (u User) Saudacoes() string {
	return fmt.Sprintf("Olá %s de %s", u.Nome, u.Localizacao)
}

type Jogador struct {
	u      Usuario
	GameID int
}

func SaudacoesParaJogador(p Jogador) string {
	return p.u.Saudacoes()
}
