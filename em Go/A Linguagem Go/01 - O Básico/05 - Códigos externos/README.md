# Códigos externos <!-- omit in toc -->
Esta seção explica em detalhes como importar um código de um outro lugar usando o comando *Go get*

### Tópicos
- [Pegando o local do código](#pegando-o-local-do-c%c3%b3digo)

## Pegando o local do código
O caminho `github.com/mattetti/goRailsYourself/crypto` basicamente diz ao compilador para importar o pacote de criptografia disponível. Isso não significa que o compilador puxe automaticamente o repositório; então, onde ele encontra o código?

Você precisa baixar o código você mesmo. A maneira mais fácil é usar o comando `go get` fornecido pelo Go.

```bash
$ go get github.com/mattetti/goRailsYourself/crypto
```

Este comando irá baixar o código e colocá-lo no seu *Go path* (local onde se encontra o Go). Ao instalar o Go, configuramos a variável de ambiente `GOPATH` e é isso que é usado para armazenar binários e bibliotecas. É também aqui que você deve armazenar seu código (sua área de trabalho / workspace).

```bash
$ ls $GOPATH
bin	pkg	src
```

A pasta `bin` conterá os binários compilados em Go. Você provavelmente deve adicionar o caminho desta pasta aos caminhos do sistema.

A pasta `pkg` contém as versões compiladas das bibliotecas disponíveis para que o compilador possa vincular-se a elas sem recompilá-las.

Finalmente, a pasta `src` contém todo o código-fonte Go organizado pelo caminho de importação:

```bash
$ ls $GOPATH/src
bitbucket.org	code.google.com	github.com	launchpad.net
```

```bash
$ ls $GOPATH/src/github.com/mattetti
goblin			goRailsYourself		jet
```

Ao iniciar um novo programa ou biblioteca, recomenda-se a fazê-lo dentro da pasta `src`, usando um caminho totalmente qualificado (por exemplo: `github.com/<seu username>/<project name>`)