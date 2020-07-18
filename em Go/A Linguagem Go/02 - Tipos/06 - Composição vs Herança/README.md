# Composição vs Herança <!-- omit in toc -->
Esta seção explica os detalhes da Composição no Go e como ele pode ser usado como uma alternativa à Herança.

### Tópicos
- [Composição como alternativa à herança](#composição-como-alternativa-à-herança)
- [Composição](#composição)
- [Quiz](#quiz)
- [- [ ] B) Falso](#ul-classcontains-task-listli-classtask-list-iteminput-classtask-list-item-checkbox-disabled-typecheckbox-b-falsoliul)

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
    Nome, Localizacao   string
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
    Nome, Localizacao   string
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
    Nome, Localizacao   string
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

Ao usar um literal de estrutura com uma composição implícita, não podemos simplesmente passar os campos compostos. Em vez disso, precisamos passar os tipos que compõem a estrutura. Uma vez definidos, os campos estão diretamente disponíveis.

Como nossa estrutura é composta por outra estrutura, os métodos na estrutura Usuario também estão disponíveis para o Jogador. Vamos definir um método para mostrar esse comportamento:

```go
package main

import "fmt"

type Usuario struct {
    ID                  int
    Nome, Localizacao   string
}

func (u *Usuario) Saudacoes() string {
    return fmt.Sprintf("Hi %s from %s", u.Nome, u.Localizacao)
}

type Jogador struct {
    Usuario
    GameID int
}

func main() {
    p := Jogador{}
    p.ID = 42
    p.Nome = "Guilherme"
    p.Localizacao = "PB"
    fmt.Println(p.Saudacoes())
}
```

Como você pode ver, é uma maneira muito poderosa de criar estruturas de dados, mas é ainda mais interessante quando se pensa sobre isso no contexto de interfaces. Ao compor uma de sua estrutura com outra implementando uma determinada interface, sua estrutura implementa automaticamente a interface.

Aqui está outro exemplo, desta vez, examinaremos a implementação de uma struct `Job` que também pode se comportar como um criador de logs ([logger](http://golang.org/pkg/log/#Logger)).

Aqui está a maneira explícita:

```go
package main

import (
	"log"
	"os"
)

type Job struct {
	Command string
	Logger  *log.Logger
}

func main() {
	job := &Job{"demo", log.New(os.Stdout, "Job: ", log.Ldate)}
	// mesma coisa que
	// job := &Job{Command: "demo",
	//            Logger: log.New(os.Stderr, "Job: ", log.Ldate)}
	job.Logger.Print("teste")
}
```

Nossa struct `Job` possui um campo chamado `Logger` que é um ponteiro para outro tipo ( [log.Logger](http://golang.org/pkg/log/#Logger) )

Quando inicializamos nosso valor, configuramos o logger para que possamos chamar sua função `Print` encadeando as chamadas: `job.Logger.Print()`

Mas o Go permite ir ainda mais longe e usar a composição implícita. Podemos pular a definição do campo para nosso logger e agora todos os métodos disponíveis em um ponteiro para `log.Logger` estão disponíveis em nossa estrutura:

```go
package main

import (
	"log"
	"os"
)

type Job struct {
	Command string
	*log.Logger
}

func main() {
	job := &Job{"demo", log.New(os.Stdout, "Job: ", log.Ldate)}
	job.Print("iniciando agora...")
}
```

Observe que você ainda precisa definir o logger e esse é um bom motivo para usar um construtor (construtores personalizados são usados ​​quando você precisa definir uma estrutura antes de usar um valor). O que é realmente bom na composição implícita é que ele permite que seus structs implementem interfaces de maneira fácil e barata. Imagine que você tem uma função que aceita variáveis ​​implementando uma interface com o método `Print`. Ao adicionar `*log.Logger` à sua estrutura (e inicializá-la corretamente), sua struct agora está implementando a interface sem você escrever quaisquer métodos personalizados.

---

## Quiz

1. Verdadeiro ou falso: Ao usar um literal de estrutura com uma composição implícita, podemos passar os campos compostos.
   - [ ] A) Verdadeiro
   - [ ] B) Falso
---

Isso conclui a seção sobre como a composição funciona. A seção a seguir contém um exercício baseado neste exemplo para aprimorar ainda mais sua compreensão do conceito de composição.