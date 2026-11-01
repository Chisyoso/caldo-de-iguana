#include "ia.h"
#include "dib.h"
#include "func.h"

class cel {
    private:
    int v, s;
    public:
    int t;
    Color c;
    int x = random(40,  1200 - 40);
    int y = random(40,  680 - 40);
    int x2 = x;
    int y2 = y;
    cel(int v_, int s_, int t_, Color c_){
        v = v_;
        s = s_;
        t = t_;
        c = c_;
    }
    
    void apuntar(){
    x2 = random(40,  1200 - 40);
    y2 = random(40,  680 - 40);
    }
    
    void caminar(){
        if(x < x2 - 10){
            x += s;
        }
        else if(x > x2 + 10){
            x -= s;
        }
        
        if(y < y2 - 10){
            y += s;
        }
        else if(y > y2 + 10){
            y -= s;
        }
        if(x > x2 - 20 && x < x2 + 20  && y > y2 - 20 && y < y2 + 20 ) apuntar();
    }
    void buscar(int zise);
    void comer(int ide);
};

std::vector<cel> celul;

void cel::buscar(int zise){
    for(int i = 0; i < zise; i++){
        if(x > celul[i].x  - t && x < celul[i].x + t && y > celul[i].y  - t && y < celul[i].y + t && !igual(c , celul[i].c)) comer(i);
    }
}

void cel::comer(int ide){
    DrawText(":v", x,y, 20, WHITE);
    int r = random(0, 100);
    if(t > celul[ide].t){
        if(r < 80){
            t += celul[ide].t / 3; 
            celul.erase(celul.begin() + ide);
             
        }
        
    }
    else{
        if(r < 50){
            t += celul[ide].t / 3;
             celul.erase(celul.begin() + ide);
        }
    }
}

int gen[] = {0, 0};
void dibujar();

void nacer(Color c){
 celul.push_back({10, 2, 18, c});   
}

void actuar(){
    gen[0]++;
    if(gen[0] > gen[1]){
        celul.push_back({10, 2, random(10,20), colr()});
        gen[0] = 0;
        gen[1] = random(80, 200);
    }
    
    DrawText(TextFormat("%d", static_cast<int>(celul.size())), 10, 10, 20, WHITE);
    dibujar();
}

void dibujar(){
    int tama = static_cast<int>(celul.size());
    for(int i = 0; i < tama; i++){
        celula( celul[i].x, celul[i].y, celul[i].t, celul[i].c );
        celul[i].caminar();
        celul[i].buscar(tama);
        if(celul[i].t > 50){
            DrawText("MITOSIS", celul[i].y,celul[i].y , 20, WHITE);
            nacer(celul[i].c);
            nacer(celul[i].c);
            nacer(celul[i].c);
            celul.erase(celul.begin() + i);
        }
    }
}