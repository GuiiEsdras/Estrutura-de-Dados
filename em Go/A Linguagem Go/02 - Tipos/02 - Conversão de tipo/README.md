# Conversão de tipo <!-- omit in toc -->
Esta seção discute os tipos de conversão de variáveis para outros tipos usando exemplo

### Tópicos
- [Convertendo valores](#convertendo-valores)
- [Exemplo](#exemplo)


## Convertendo valores
Na seção anterior, abordamos os vários tipos que uma variável em Go pode usar. Agora, discutiremos como o tipo de uma determinada variável pode ser alterado. Converter valores de um tipo para outro é bastante simples no Go. A expressão `T(v)` converte o valor `v` no tipo `T`.

## Exemplo

A seguir, são apresentados alguns exemplos de conversões numéricas:

```go
var i int = 42
var f float64 = float64(i)
var u uint = uint(f)
```

Estes podem ser colocados de forma mais simples:

```go
i := 42
f := float64(i)
u := uint(f)
```

A atribuição entre itens de tipo diferente em Go requer uma conversão explícita, o que significa que você precisa converter manualmente tipos se estiver passando uma variável para uma função que espera outro tipo.