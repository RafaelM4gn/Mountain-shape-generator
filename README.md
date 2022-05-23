# Mountain shape generator in C

## Implementações basicas

O codigo gera um arquivo PMM de uma montanha com formato aleatorio com base nos parametros "-d" e "-o".

## Implementações extras

- Parametro "-s" que define o tamanho da imagem 
> "-s 257". valor deve seguir a formula 2^n + 1.

- Geração de contorno na montanha.

- Céu estrelado e com gradiente.

- Oceano ao fundo (metade da tela)

- Lava subterrânea com contorno e gradiente (metade do deslocamento)

## Possiveis melhorias

Corrigir o parametro "-s" que funciona apenas com números conveninentes caso contrário gera bug.

## Como compilar o projeto?

Para executar o projeto compile os arquivos dentro da pasta onde se encontra esse README.md usando:
              
    gcc functions.c main.c -o program -g -w

Em seguida execute o programa com:

    ./program 

parametros(opcionais)

> -d = deslocamento aleatorio maximo

> -o = nome do arquivo com a extensao

> -s = altura e comprimento da imagem para gerar uma imagem quadrada

*Feito individualmente no replit.com*
