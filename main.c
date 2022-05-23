#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "defs.h"
#include "functions.h"


int main (int argc, char* argv[]) {
  //tamanho da imagem PMM
  int sizeX = 257;
  int sizeY = 257;
  //Entrada Padrão
  char filename[] = "teste3.ppm";
  long tax = 50;
  //configuração dos parametros do main
  if (argc > 2){
    for(int i=1; i<argc; i++){
      //Parametro da taxa de variação da montanha(padrao: 50)
      if(strcmp(argv[i], "-d") == 0){
        tax = strtol(argv[i + 1], NULL, 10);
      }
      //Parametro do nome do arquivo(padrao: teste2.ppm)
      if(strcmp(argv[i], "-o") == 0){
        strcpy(filename, argv[i + 1]);
      }
      //Parametro do comprimento e da altura da imagem(padrao: 257)
      //necessario seguir a formula 2^n + 1
      if(strcmp(argv[i], "-s") == 0){
        sizeX = sizeY = strtol(argv[i + 1], NULL, 10);
      }
    }
  }
  // Gerando o vetor do contorno da montanha
  srand(time(NULL));
  int sizeArray = sizeY;
  int variation = tax;
  int highs[sizeArray];
  highs[0] = sizeArray/2;
  highs[sizeArray - 1] = sizeArray/2;
  int *highsPointer = midpoint(highs, 0, sizeArray - 1, sizeArray, variation);
  for (int i = 0; i < sizeArray; i++ ) {
    highs[i] = *(highsPointer + i);
  }
  // gerando o vetor do contorno da lava
  int lava[sizeArray];
  lava[0] = sizeArray -20;
  lava[sizeArray - 1] = sizeArray - 20;
  highsPointer = midpoint(lava, 0, sizeArray - 1, sizeArray, variation/2);
  for (int i = 0; i < sizeArray; i++ ) {
    lava[i] = *(highsPointer + i);
  }
  //carrega a matriz de pixel pra a imagem PPM
  Ppm image = loadMatrix(lava, highs, sizeX, sizeY, 1);
  //Gera o Arquivo PPM
  loadPmmFile(image, filename);
  //FIM
   return 0;
}