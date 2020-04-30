# Nomes exportados <!-- omit in toc -->
Esta seção discute como referir nomes exportados (*exported names*) e como usá-los após a importação de seu respectivo pacote (*package import*)

### Tópicos
- [Como exportar](#como-exportar)
- [Links úteis](#links-%c3%bateis)

## Como exportar
Após importar um pacote, você pode consultar os nomes que ele exporta (significando variáveis, métodos e funções disponíveis fora do pacote). No Go, um nome é exportado se começar com uma letra maiúscula. `Foo` é um nome exportado, como está `FOO`. O nome `foo` não é exportado.

Veja a diferença entre:

```go
package main

import (
    "fmt"
    "math"
)

func main() {
    fmt.Println(math.pi) // nome com letra minúscula
}
```
[pi_incorreto.go](Pi%20incorreto/pi_incorreto.go)

*Saída:*
```bash
# command-line-arguments
./main.go:9: cannot refer to unexported name math.pi
./main.go:9: undefined: math.pi
```

O código acima dá um erro, pois as letras minúsculas não podem ser exportadas. Por outro lado, o código abaixo funcionará bem pois `Pi` é iniciado com uma letra maiúscula para que possa ser exportado.

```go
package main

import (
    "fmt"
    "math"
)

func main() {
    fmt.Println(math.Pi) // nome com letra maiúscula
}
```
[pi_correto.go](Pi%20correto/pi_correto.go)

*Saída:*
```bash
3.141592653589793
```

`Pi` é exportado e pode ser acessado fora do pacote, enquanto `pi` não está disponível.

Veja os [links úteis](#links-%c3%bateis) para mais informações sobre nomes exportados.

Abaixo está outro exemplo de nomes exportados:

```go
package main

import (
    "fmt"
    "net/http"
)

func main() {
    fmt.Printf("HTTP status OK uses code: %d", http.StatusOK)
}
```
[http_package.go](HTTP%20package/http_package.go)

*Saída:*
```bash
HTTP status OK uses code: 200
```


## Links úteis
- [Documentação Go](http://godoc.org/)
- [Documentação Go - Pkg](http://golang.org/pkg/)