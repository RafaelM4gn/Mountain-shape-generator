#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defs.h"
//funcao que gera a matriz de pixel da imagem ppm
Ppm loadMatrix(int lava[], int highs[], int sizeX, int sizeY, int layer){
    Ppm terrain;
    int stars;
    terrain.sizeX = sizeX;
    terrain.sizeY = sizeY;
    //distribui as cores na matriz
      for(int i = 0; i < sizeX; i++){
        for(int j = 0; j < sizeY; j++){
          if ( i < highs[j]){
            //Cores do ceu
            terrain.t[i][j].r = 100 + i;
            terrain.t[i][j].g = 100;
            terrain.t[i][j].b = 240;
            stars = rand() % 101;
            if (stars > 98){
              terrain.t[i][j].r = 254;
              terrain.t[i][j].g = 254;
              terrain.t[i][j].b = 254;
            }
          } else if ( i == highs[j]){
            //grama
            terrain.t[i][j].r = 100;
            terrain.t[i][j].g = 240;
            terrain.t[i][j].b = 100;
          } else if ( i > highs[j] && i < highs[j] +4 ){
            //terra
            terrain.t[i][j].r = 100;
            terrain.t[i][j].g = 50;
            terrain.t[i][j].b = 0;
          } else {
            //pedra
            terrain.t[i][j].r = 100;
            terrain.t[i][j].g = 100;
            terrain.t[i][j].b = 100;
          }

          if ( i > lava[j] ){
            //lava
            terrain.t[i][j].r = 250 ;
            terrain.t[i][j].g = 80 + i;
            terrain.t[i][j].b = 2;
          }
        }
      }
    return terrain;
}
//funcao recursiva que gera o vetor de altitudes da montanha
int * midpoint( int vetorBase[], int indStart, int indEnd, int size, int variation) {
  static int  r[800];
  for ( int i = 0; i < size; ++i) {
    r[i] = vetorBase[i];
  }
  //adiciona o novo valor no ponto media com a variacao(+ ou -)
  int indMedia = (indStart + indEnd )/2;
  r[indMedia] = (r[indStart] + r[indEnd])/2;
  r[indMedia] += rand() % (variation*2 + 1);
  r[indMedia] -= variation;
  // variação apenas para cima (ou para baixo)
  // r[indMedia] += rand() % (variation + 1);
  if (indStart < indMedia - 1) {
    variation = variation * 50 ;
    variation = (variation + (100 - 1)) / 100;
    //inicia a recursão da funcao
    midpoint(r, indStart, indMedia, size, variation);
    midpoint(r, indMedia, indEnd, size, variation);
  }
  return r;
}
// funcao que cria o arquivo pmm usando a matrix gerada em loadMatrix
int loadPmmFile (Ppm image, char filename[]){
    FILE *file = fopen(filename, "wb");
    //Imprime o cabecalho no arquivo PPM
    fprintf(file, "P3\n");
    fprintf(file, "%d %d\n", image.sizeX, image.sizeY);
    fprintf(file, "255\n");
    //imprime os pixel da imagem no arquivo PPM
    for(int i = 0; i < image.sizeX; i++){
      for(int j = 0; j < image.sizeY; j++){
        fprintf( file , "%d ", image.t[i][j].r);      
        fprintf( file , "%d ", image.t[i][j].g);      
        fprintf( file , "%d\n", image.t[i][j].b);      
      }  
    }
    fclose(file);
    return 0;
}
