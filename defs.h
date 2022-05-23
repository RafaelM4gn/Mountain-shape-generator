typedef struct{
    int r;
    int g;
    int b;
} Pixel;

typedef struct {
  Pixel t[500][500];
  int sizeX;
  int sizeY;
} Ppm;