#include "func.h"

std::random_device a;
std::mt19937 b(a());
Color c[] = {BLUE, GREEN, RED, WHITE, ORANGE, PURPLE, PINK};
int random(int min, int max){
   std::uniform_int_distribution<int> ob(min, max);
    return ob(b); 
}
bool igual(Color c, Color d){
    return (c.r == d.r && c.g == d.g && c.b == d.b);
}
Color colr(){
    return c[random(0, sizeof(c) / sizeof(c[0]) - 1 )];
}