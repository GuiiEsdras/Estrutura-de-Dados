<!-- Título do Respositório -->
# C Room
<!-- -->

<!-- Badges -->
<p align="center">
    <img src="https://img.shields.io/badge/made%20with-C-blue.svg?style=flat&colorB=4614ff" alt="Linguagem C">
</p>
<!-- -->

<!-- Msg de boas vindas -->
<p align="center">Bem-vindo ao meu repositório de <strong>Estrura de Dados</strong> em</p>
<!-- -->

<!-- Logo -->
<p align="center">
    <img src="Imagens\c-programming.png" alt="C" height="100">
</p>
<!-- -->

<!-- Links Principais-->
<p align="center">
    <a href="https://devdocs.io/c/" target="_blank"><strong>Documentação da linguagem »</strong></a>
    <br/>
    <a href="https://pt.wikipedia.org/wiki/C_(linguagem_de_programa%C3%A7%C3%A3o)" target="_blank"><strong>Página no Wikipedia »</strong></a>
    <br/>
    <a href="https://www.cprogramming.com/" target="_blank"><strong>Site »</strong></a>
    <br/>
</p>
<!-- -->

<!-- Links do Repositório -->
<p align="center">
    <a href="Exercícios Resolvidos">Exercícios Resolvidos</a>
    ·
    <a href="Programas">Programas</a>
    ·
    <a href="Projetos">Projetos</a>
</p>
<!-- -->

<!-- Language Preview-->
<p align="center">
    <img align="center" src="Imagens\c-code-example.jpg" alt="C Preview" width="500">
</p>
<!-- -->

---

<!-- Table of Contents -->
## Glossário
- [C Room](#c-room)
  - [Glossário](#gloss%c3%a1rio)
  - [Objetivo](#objetivo)
  - [Material Utilizado](#material-utilizado)
    - [Sistema Operacional](#sistema-operacional)
    - [Compilador](#compilador)
    - [IDE](#ide)
  - [Programando em C](#programando-em-c)
    - [Pré-Requisitos](#pr%c3%a9-requisitos)
    - [Executando .c pelo CMD ou Terminal](#executando-c-pelo-cmd-ou-terminal)
    - [Criando Árvore de Diretórios para Projeto com VSCode](#criando-%c3%81rvore-de-diret%c3%b3rios-para-projeto-com-vscode)
    - [Exemplo de Programa](#exemplo-de-programa)
  - [Links Úteis](#links-%c3%9ateis)
  - [Autor](#autor)
  - [Licença](#licen%c3%a7a)
<!-- -->

<!-- Objetivo -->
## Objetivo
Criado com a finalidade de guardar meus projetos, ideias, anotações, exercícios e programas pessoais feitos em <strong>C</strong> e também como complemento de aprendizagem para a disciplina de <strong>Estrura de Dados e Algoritmos</strong>.
<!-- -->

<!-- Material Utilizado -->
## Material Utilizado
Estes são os materiais usados por mim para desenvolver e rodar meus programas em C.
### Sistema Operacional
- [Linux Mint 19.3 Cinnamon](https://www.linuxmint.com/)
- [Kubuntu 18.04.4 LTS](https://kubuntu.org/)
- [Windows 10](https://www.microsoft.com/pt-br/windows/)
### Compilador
- [GCC](#Links-%C3%9Ateis)
### IDE
- [Visual Studio Code](https://code.visualstudio.com/)
<!-- -->

<!-- Programando em ... -->
## Programando em C
O que foi necessário para criar e rodar meus programas em C

### Pré-Requisitos
Para executar e criar programas em **C** é necessário ter o compilador GCC instalado no computador.

- Para verificar se o GCC está instalado no PC, basta executar o comando no CMD: <br/>
    `> gcc`
> - Se o comando não for reconhecido, **não está** instalado! *(ver [Links Úteis](#Links-%C3%9Ateis) para instalar o MinGW)* <br/>
> - Caso apareça o erro: `no input files`, **está** instalado! <br/>

### Executando .c pelo CMD ou Terminal
Criando e executando um programa simples em C pelo CMD ou Terminal

1. Para executar arquivos *.c* pelo CMD / terminal deve-se ter o compilador *"gcc"* devidamente configurado no PC. <br/>
   Para isso, instalar o MinGW. *(ver [Links Úteis](#Links-%C3%9Ateis))*
  
> Atenção: Caso esteja usando linux, pular para 6º passo.

2. Após certificar-se de ter instalado o *gcc/MinGW*, copiar o endereço da pasta bin do mesmo.
     - Exemplo:
     `C:\MinGW\bin`

3. Após copiar, ir até as Configurações Avançadas do Sistema *(Botão direito em cima de "Este Computador" -> Lado superior esquerdo)*
   
4. Clicar em Váriaveis de Ambiente -> PATH -> Novo -> Inserir o endereço da pasta no fim da linha das variáveis do sistema.
   
5. Finalmente, será capaz de compilar e executar programas C pelo terminal.
   
6. Geralmente (quase todas) as distros linux já vem com o gcc instalado. Porém, ainda assim, ao tentar rodar algum programa ou interagir com programas pelo VSCode, alguns erros podem acontecer como, por exemplo, não encontrar as bibliotecas padrões (stdio.h). <br/>
   Nesse caso, para solucionar o problema, basta rodar o comando: <br/>
   `> sudo apt-get install build-essentials` <br/>
   para instalar as dependências necessárias.

- Para compilar programas *".c"* e executá-los no terminal/cmd:
  - Abrir pasta onde se localiza o arquivo *.c*: <br/>
     `> cd "pasta do programa"`
  - Compilar o programa: <br/>
     `> gcc "nome do programa".c -o "nome de saída do executavel" // Será gerado um arquivo "nome de saída do executavel".exe`
  - Para executar: <br/>
     `> "nome de saída do executavel".exe (pode-se omitir a extensão .exe apenas executando o nome escolhido de saída para o exe)`
  
  - Exemplo: <br/>
     `> cd "..\C\Programa Hello World" // Para ir até a pasta do arquivo .c` <br/>
     `> gcc HelloWorld.c -o OlaMundo.exe // Para compilar um programa chamado "HelloWorld.c" e nomeá-lo como "OlaMundo.exe"` <br/>
     `> OlaMundo.exe // ou apenas: *OlaMundo*, para executar este programa no windows` <br/>
     ou <br/>
     `> ./OlaMundo // no linux`

- Caso o programa possua dependencia de bibliotecas .h e .c: <br/>
  `> gcc "Biblioteca".h "Biblioteca".c "Arquivo main principal".c -o "Arquivo final exe" // Para compilar tudo` <br/>
  `> "Aquivo final exe" // Para executar o arquivo final`
  ou


  - Exemplo: <br/>
    `> gcc UmaBiblioteca.h UmaBiblioteca.c ArquivoMain.c -o ArquivoFinal` <br/>
    `> ArquivoFinal.exe` <br/>
    ou apenas<br/>
    `> ArquivoFinal` <br/>
    ou no linux: <br/>
    `> ./ArquivoFinal`

### Criando Árvore de Diretórios para Projeto com VSCode

1. Baixar a extensão para VSCode:
   - [C/C++ Project Generator](https://marketplace.visualstudio.com/items?itemName=danielpinto8zz6.c-cpp-project-generator)
2. CTRL + SHIFT + P
3. Create C Project
4. Selecionar a pasta na qual será criada a árvore de diretórios
5. Pronto! Os arquivos do projeto terão suas respectivas pastas e ficará mais organizado.

### Exemplo de Programa
``` C
#include <stdio.h>

int main(int argc, char *argv) {
    printf("Hello Gui! =)");
    return 0;
}
```

Saída: <br/>
`> Hello Gui! =)`
<!-- -->

<!-- Links-->
## Links Úteis
- [GCC/MinGW Download](https://sourceforge.net/projects/tdm-gcc/)
<!-- -->

<!-- Autor/Contato -->
## Autor
* **Guilherme Esdras (guilherme.esdras@outlook.com)** - [GitHub Page](https://github.com/GuilhermeEsdras)
<!-- -->

<!-- Licença -->
## Licença
*Distributed under the MIT License. See LICENSE for more information.*