# Composição vs Herança <!-- omit in toc -->
Esta seção explica os detalhes da Composição no Go e como ele pode ser usado como uma alternativa à Herança.

### Tópicos
- [Composição como alternativa à herança](#composição-como-alternativa-à-herança)
- [Composição](#composição)

## Composição como alternativa à herança

Vindo de um histórico de POO, muitos de nós estamos acostumados a herança, algo que não é suportado em Go. Em vez disso, você deve pensar em termos de composição e interfaces. Nas seções anteriores, falamos sobre as estruturas do Go, e é isso que usaremos para composição.

A equipe do Go escreveu um segmento curto, mas bom, sobre este tópico.

## Composição

Composição (ou incorporação) é um conceito bem compreendido pela maioria dos programadores de POO e o Go o suporta, aqui está um exemplo do problema que está resolvendo:

```go
package main

import "fmt"

type Usuario struct {
    ID          int
    Nome        string
    Localizacao string
}

// Tipo Jogador com um atributo adicional

type Jogador struct {
    ID          int
    Nome        string
    Localizacao string
    GameID      int
}

func main() {
    p := Jogador{}
    p.ID = 45
    p.Nome = "Guilherme"
    p.Localizacao = "PB"
    p.GameID = 90404
    fmt.Printf("%+v", p) // o valor em um formato padrão ao printar structs,
                        // o sinal de adição (%+) adiciona os nomes dos campos
}
```

*Saída:*
```bash
{ID:45 Nome:Matt Localizacao:PB GameID: 90404}
```

O exemplo acima demonstra um desafio clássico de POO, nossa struct `Jogador` possui os mesmos campos que a struct `Usuario`, mas também possui um campo `GameID`. Ter que duplicar os nomes dos campos não é grande coisa, mas pode ser simplificado compondo nossa estrutura.

```go
type Usuario struct {
    ID                  int
    Nome, localizacao   string
}

type Jogador struct {
    Usuario // usuario conterá todos os atributos requiridos
    GameID int
}
```

Nós podemos inicializar uma nome variável do tipo Jogador de duas formas diferentes.

Usando a notação de ponto para determinar os campos:

```go
package main

import "fmt"

type Usuario struct {
    ID                  int
    Nome, localizacao   string
}

type Jogador struct {
    Usuario
    GameID int
}

func main() {
    p := Jogador{} // inicializando
    p.ID = 45
    p.Nome = "Guilherme"
    p.Localizacao = "PB"
    p.GameID = 90404
    fmt.printf("%+v", p)
}
```

*Saída:*
```bash
{Usuario:{ID:45 Nome:Guilherme Localizacao:PB} GameID:90404}
```

A outra opção é usar uma estrutura literal (struct literal)

```go
package main

import "fmt"

type Usuario struct {
    ID                  int
    Nome, localizacao   string
}

type Jogador struct {
    Usuario
    GameID int
}

func main() {
    p := Jogador{
        Usuario{
            ID: 45,
            Nome: "Guilherme",
            Localizacao: "PB"
        },
        90404,
    }
    fmt.Printf(
        "ID: %d, Nome: %s, Localizacao: %s, Game ID: %d\n",
        p.ID, p.Nome, p.Localizacao, p.GameID
    )
    // Define diretamente um capo na struct do Jogador
    p.ID = 11
    fmt.Printf("%+v", p)
}
```

*Saída:*
```bash
ID: 45, Nome: Guilherme, Localizacao: PB, Game ID: 90404
{Usuario:{ID:11 Nome:Guilherme Localizacao:PB} GameID:90404}
```

