1. Qual das alternativas a seguir NÃO é a maneira correta de declarar uma variável em Go?
   - [ ] A) 
        ```go
        var (
                nome        string
                idade       int
                localizacao string
        )
        ```
   - [ ] B)
        ```go
        var (
                nome, localizacao string
                idade             int
        )
        ```
   - [X] C)
        ```go
        var string nome
        var int    idade
        var string localizacao
        ```
        > **Explicação:** A instrução `var` declara uma lista de variáveis ​​com o tipo sendo declarado *por último*
   - [ ] D)
        ```go
        var nome        string
        var idade       int
        var localizacao string
        ```
2. Em Go, as funções podem retornar apenas um único valor, o "parâmetro de resultado".
   - [ ] Verdadeiro
   - [X] Falso
     > **Explicação:** Em Go, as funções podem retornar vários "parâmetros de resultado", não apenas um único valor.
3. Qual das alternativas a seguir não é verdadeira sobre constantes?
   - [ ] As constantes podem ser um *character*.
   - [X] Constantes podem ser declaradas usando sintaxe `:=`.
     > **Explicação:** As constantes não podem ser declaradas usando a sintaxe `:=`.
   - [ ] As constantes podem ser um *booleano*.
   - [ ] As constantes podem ser uma *String*.
4. Em Go, um nome é exportado se começar com uma letra maiúscula?
   - [X] Verdadeiro
     > **Explicação:** Um nome em Go é exportado se começar com letra maiúscula.
   - [ ] Falso
5. Em Go, apenas constantes são mutáveis
   - [ ] Verdadeiro
   - [X] Falso
     > **Explicação:** Em Go, apenas constantes são *imutáveis*.