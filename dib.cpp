#include "dib.h"


void celula(int x, int y, int t, Color c){
   DrawRectangle(x - t/2, y - t/2 , t , t, c);
}