# Exercício de Composição <!-- omit in toc -->
Aqui está um exercício que você pode resolver para testar sua compreensão!

### Tópicos
- [Pergunta](#pergunta)

## Pergunta
Olhando para o exemplo de `Usuário` / `Jogador`, você deve ter notado que compusemos `Jogador` usando `Usuário`. Isso significa que um jogador deve poder acessar os métodos definidos na struct `Usuário`. 
No código fornecido abaixo, adicione código adicional à função `SaudacoesParaJogador` para que ela use a função `Saudacoes` da struct `Usuario` para printar a sequência que a função `Saudacoes` está printando no momento:

```go
package main
import "fmt"
import "encoding/json"


type Usuario struct {
	ID                int
	Nome, Localizacao string
}

func (u User) Saudacoes() string {
	return fmt.Sprintf("Olá %s de %s", u.Nome, u.Localizacao)
}

type Jogador struct {
	u Usuario
	GameID int
}

func SaudacoesParaJogador(p Jogador) string {
  // insira o código aqui
  
  return ""; // modifique a declaração para que retorne a string pedida
}

```

[solução](Solução/solucao.go)