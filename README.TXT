O que foi feito 

  Basico -

    -O codigo feito gera um arquivo PMM de uma montanha baseado nos parametros "-d" e "-o"

  Extras -

    -Parametro "-s" que define o tamanho da imagem por exemplo: "-s 257". valor deve seguir a formula 2^n + 1.

    -Geracao de contorno na montanha

    -ceu estrelado e com gradiente

    -mar ao fundo (raro de aparecer)

    -Lava subterranea com contorno e gradiente (metade do deslocamento)

  O que seria feito diferentemente - 

    Corrigir o parametro "-s" que so funciona com numeros conveninentes caso contrario gera bug
  Como compilar o projeto

    - primeiro: gcc functions.c main.c -o program -g -w

    - segundo: ./program 

      parametros(opcionais)
      
      > -d = deslocamento aleatorio maximo
      > -o = nome do arquivo com a extensao
      > -s = altura e comprimento da imagem para gerar uma imagem quadrada

Feito individualmente e no replit.com