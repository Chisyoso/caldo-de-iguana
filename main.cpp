#include "raylib.h"
#include "ia.h"

Color c1 = {50, 50,50 , 255};

int main(){
    
    InitWindow(1200, 680, "sopadeiguana");
    SetTargetFPS(60);
    while(!WindowShouldClose()){
        BeginDrawing();
        DrawRectangle(40, 40, 1200- 80, 680 - 80, c1);
        ClearBackground(BLACK);
        actuar();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}