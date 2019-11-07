# AVLTree

Projeto de árvore AVL para a matéria de Tópicos em Estrutura de Dados no curso técnico do COTUCA.

## Sobre o projeto

![image](https://user-images.githubusercontent.com/18057391/68353930-caeb0000-00e9-11ea-85a5-a1fbf471ffb6.png)

O projeto tem como objetivo a implementação da classe AVLTree que representa uma árvore AVL balanceada como o exemplo da imagem acima.

### Pré-requisitos

O que você precisa para instalar e executar o software:

- g++ compiler, isto é, o comando `g++` disponível no seu terminal
- comando `make` disponível no seu terminal

#### Compilando e Executando o projeto

1. Clone esse repositório para sua máquina e acesse o diretório raiz do projeto.
```
git clone https://github.com/bartier/AVLTree.git
cd AVLTree/
```

2. No diretório raiz do projeto execute o comando `cmake` e `make` para iniciar a compilação e criar o arquivo `AVLTree` a ser executado.
```
cmake .
make
```

3. Pronto. Agora o arquivo `AVLTree` foi gerado. Basta executá-lo com o comando abaixo:
```
./AVLTree
```

Os comandos do arquivo `main.cpp` serão exibidos no seu terminal para demonstrar a manipulação da `AVLTree`. 

## main.cpp

O arquivo `main.cpp` irá instanciar um objeto da classe `AVLTree<int>` e chamar os métodos `insert`, `contains`, `remove` da classe.

## Construído com

* CLion 2018.2 (C++17)

## Agradecimentos

* [A template to make good README.md](https://gist.github.com/PurpleBooth/109311bb0361f32d87a2)
