<!-- Título do Respositório -->
# Here We Go
<!-- -->

<!-- Badges -->
<p align="center">
    <img src="https://img.shields.io/badge/made%20with-Go-purple.svg?style=flat&colorB=00FFFF&logo=Go" alt="Go Badge">
</p>

<!-- Screenshot -->
<p align="center">
  <img src="Screenshots/Calendario Go.png" />
</p>

<!-- Msg de boas vindas -->
<p align="center">Bem-vindo ao meu repositório de <strong>Estrutura de Dados</strong> em</p>
<!-- -->

<!-- Logo -->
<p align="center">
    <img src="https://cdn.thenewstack.io/media/2019/02/df84c958-go-logo_blue-1024x519.jpg" alt="Go Logo Txt" height="100">
    <img src="https://sdtimes.com/wp-content/uploads/2018/02/golang.sh_-490x490.png" alt="Go Logo Animal" height="100">
</p>
<!-- -->

<!-- Links Principais-->
<p align="center">
    <a href="https://golang.org/doc/" target="_blank"><strong>Documentação da linguagem »</strong></a>
    <br/>
    <a href="https://pt.wikipedia.org/wiki/Go_(linguagem_de_programa%C3%A7%C3%A3o)" target="_blank"><strong>Página no Wikipedia »</strong></a>
    <br/>
    <a href="https://golang.org/" target="_blank"><strong>Site Oficial »</strong></a>
    <br/>
</p>
<!-- -->

<!-- Links do Repositório -->
<p align="center">
    <a href="Exercícios Resolvidos">Exercícios Resolvidos</a>
    ·
    <a href="Programas">Programas Simples</a>
    ·
    <a href="Projetos">Projetos</a>
</p>
<!-- -->

<!-- Language Preview -->
<p align="center">
    <img align="center" src="https://cdn-images-1.medium.com/max/1600/1*DZJ1kMCJCPDp78ADjjbShQ.png" alt="Go Coding" width="500">
</p>
<!-- -->

---

<!-- Table of Contents -->
## Glossário
- [Here We Go](#here-we-go)
  - [Glossário](#gloss%c3%a1rio)
  - [Objetivo](#objetivo)
  - [Material Utilizado](#material-utilizado)
    - [Sistema Operacional](#sistema-operacional)
    - [Compilador](#compilador)
    - [IDE's](#ides)
  - [Programando em Go](#programando-em-go)
    - [Pré-Requisitos](#pr%c3%a9-requisitos)
    - [Executando .go pelo CMD](#executando-go-pelo-cmd)
    - [Exemplo de Hello World](#exemplo-de-hello-world)
  - [Links Úteis](#links-%c3%9ateis)
  - [Autor](#autor)
  - [Licença](#licen%c3%a7a)
<!-- -->

<!-- Objetivo -->
## Objetivo
Criado com a finalidade de guardar meus projetos, ideias, anotações, exercícios e programas pessoais feitos em <strong>Go</strong> e também como complemento de aprendizagem para a disciplina de <strong>Estrura de Dados e Algoritmos</strong>.
<!-- -->

<!-- Material Utilizado -->
## Material Utilizado
Estes são os materiais usados por mim para desenvolver e rodar meus programas em Go.
### Sistema Operacional
- [Linux Mint 19.3 Cinnamon](https://www.linuxmint.com/)
- [Kubuntu 18.04.4 LTS](https://kubuntu.org/)
- [Windows 10](https://www.microsoft.com/pt-br/windows/)
### Compilador
- [Go](#Links-%C3%9Ateis)
### IDE's
- [Visual Studio Code](https://code.visualstudio.com/)
  - Adicionais necessários para integração da linguagem com o VSCode: <br/>
   <img src="Screenshots\VSCode additionals.jpg" width="500">
- [GoLand by JetBrains](https://www.jetbrains.com/go/)
<!-- -->

<!-- Programando em ... -->
## Programando em Go
O que foi necessário para criar e rodar meus programas em Go.

### Pré-Requisitos
Para programar em Go basta baixar e instalar o pacote da linguagem pelo site oficial.

- Para verificar se o Go está instalado no PC, basta executar o comando no CMD: <br/>
    `> go`
> - Se o comando não for reconhecido: **não está** instalado! *(ver [Links Úteis](#Links-%C3%9Ateis) para instalar)* <br/>
> - Caso exiba funcionalidades e comandos da linguagem: **está** instalado! <br/>

### Executando .go pelo CMD
Criando e executando um programa simples em Go pelo CMD

1. Para executar arquivos *.go* pelo terminal deve-se ter o compilador de Go devidamente configurado no PC. <br/>
   Para isso, baixar e executar o pacote pelo site oficial. *(ver [Links Úteis](#Links-%C3%9Ateis))*

2. Após ter baixado e executado o instalador do Go, já será capaz de criar e executar programas Go no Windows.

- Para compilar programas *".go"* e executá-los no terminal/cmd:
  - Abrir pasta onde se localiza o arquivo main *.go*: <br/>
     `> cd "pasta do programa"`
  - Compilar e Executar o programa: <br/>
     `> go run "nome do programa".go`
  
  - Exemplo: <br/>
     `> cd "..\Go\Programa Hello World\main" // Para ir até a pasta do arquivo main .go` <br/>
     `> go run HelloWorld.go // Para compilar e executar um programa chamado "HelloWorld.go"`

### Exemplo de Hello World
``` Go
package main

import (
	"fmt"
)

func main() {
	fmt.Println("Hello Gui! =)")
}
```

Saída: <br/>
`> Hello Gui! =)`
<!-- -->

<!-- Links-->
## Links Úteis
- [Download](https://golang.org/dl/)
- [Começando em Go](https://go-tour-br.appspot.com/welcome/1)
<!-- -->

<!-- Autor/Contato -->
## Autor
* **Guilherme Esdras (guilherme.esdras@outlook.com)** - [GitHub Page](https://github.com/GuilhermeEsdras)
<!-- -->

<!-- Licença -->
## Licença
*Distributed under the MIT License. See LICENSE for more information.*