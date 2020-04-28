# Ponteiros <!-- omit in toc -->
Esta seção discute ponteiros e como passá-los como argumentos em Go

### Tópicos
- [Go e Ponteiros](#go-e-ponteiros)

## Go e Ponteiros
Go tem *ponteiros*, mas nenhum aritmético. Os campos *Struct* podem ser acessados ​​através de um ponteiro de struct. A indireção através do ponteiro é transparente (você pode chamar diretamente campos e métodos em um ponteiro).

Observe que, por padrão, Go passa argumentos por valor (copiando os argumentos); se você deseja passar os argumentos por referência, precisa passar ponteiros (ou usar uma estrutura usando valores de referência, como *slices* e *maps*) .

Para obter o valor de um ponteiro, use o símbolo `&` na frente do valor; para remover a referência de um ponteiro, use o símbolo `*`

Os métodos geralmente são definidos em ponteiros e não em valores (embora possam ser definidos em ambos); portanto, você costuma armazenar um ponteiro em uma variável, como no exemplo abaixo:

```
client := &http.Client{}
resp, err := client.Get("http://gobootcamp.com")
```