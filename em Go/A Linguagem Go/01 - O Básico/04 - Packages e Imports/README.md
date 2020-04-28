# Packages e Imports <!-- omit in toc -->

Esta seção explica como importar diferentes bibliotecas e *packages* (pacotes) em Go.

### Tópicos

- [Packages (Pacotes)](#packages-pacotes)
- [Exemplos de instruções import](#exemplos-de-instru%c3%a7%c3%b5es-import)
- [Links úteis](#links-%c3%bateis)

## Packages (Pacotes)

Todo programa em Go é feito de pacotes. Programas iniciam rodando no pacote `main`.

```go
package main
import "fmt"

func main() {
	fmt.Printf("Hello, World!\n")
}
```
Se você estiver escrevendo um código executável (versus uma biblioteca), precisará definir um pacote `main` e uma função `main()` que será o ponto de entrada para o seu software.

Por convenção, o nome do pacote é o mesmo que o último elemento do caminho de importação. Por exemplo, o pacote "math/rand" compreende arquivos que começam com o pacote de instruções rand.

## Exemplos de instruções import

```go
import "fmt"
import "math/rand"
```

ou agrupados:

```go
import (
    "fmt"
    "math/rand"
)
```

Veja os [links úteis](#links-%c3%bateis) para mais informações sobre `packages` e `imports` em Go.

Abaixo estão dois exemplos mostrando como usar cada uma dessas importações.

```go
package main

import (
	"fmt"
	"math/rand"
)

func main() {
	fmt.Println("Meu número favorito é", rand.Intn(10))
}
```
[import math - rand.go](math%20-%20rand/import%20math%20-%20rand.go)

Abaixo, há outro exemplo para ajudar a entender melhor como os pacotes importados podem ser usados.

```go
package main

import (
	"fmt"
	"math/rand"
)

func main() {
	fmt.Println("Meu número favorito é", rand.Intn(10))
}
```
[import math.go](math/import%20math.go)

Geralmente, pacotes lib externos são espaçados por nomes usando uma URL da web. Por exemplo, existe alguma lógica Rails portada para o GO, incluindo o código de criptografia usado no Rails 4. O código fonte está hospedado no GitHub contendo alguns pacotes, no seguinte repositório: http://github.com/mattetti/goRailsYourself

Para importar o pacote de criptografia, você precisará usar a seguinte instrução de importação:

```go
import "github.com/mattetti/goRailsYourself/crypto"
```

## Links úteis
- [Go Tour: Packages](https://tour.golang.org/basics/1)
- [Go Tour: Imports](https://tour.golang.org/basics/2)