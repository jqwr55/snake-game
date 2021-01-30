#include <iostream>
#include <Input.h>
// #include <windows.h>
#include <stdlib.h>

struct Pont {
    int ykord;
    int xkord;
    char karakter;
};

void Draw (int Screenx, int Screeny, Pont* tomb, int tombmeret) {

    for (int i = 0; i < Screenx; i++) {
        for (int k = 0; k < Screeny; k++) {


            if (i == 0 || k == 0 || i == Screenx -1 || k == Screeny-1) { 
                    std::cout << '*';
            }
            else {
                    
                bool talalat = false;
                for (int t = 0; t < tombmeret; t++) {
                    if (tomb[t].xkord == i && tomb[t].ykord == k) {
                        std::cout << tomb[t].karakter;
                        talalat = true;
                        break;
                    }
                }   
                    
                if (talalat == false){
                    std::cout << ' ';
                }
            }        
    }

    std::cout << "\n";

    }
}

 void clear ()
 {
     for (int i = 0; i < 50; i++)
     {
         std::cout << "\n";
     }
    std::cout << std::endl;
 }


int main () {

    srand(time(0));
    
    Input gamey;
    
    Pont Pontok[16];
    int Kigyohossz = 1;

    Pontok[11].xkord = 10;
    Pontok[11].ykord = 20;

    Pontok[12].xkord = 10;
    Pontok[12].ykord = 21;

    for (int i = 0; i < 5; i++) {
        Pontok[i].karakter = '|';
        Pontok[i].xkord = rand() % 18 + 1;
        Pontok[i].ykord = rand() % 38 + 1;
    }

    for (int i = 5; i < 11; i++) {
        Pontok[i].karakter = '+';
        Pontok[i].xkord = rand() % 18 + 1;
        Pontok[i].ykord = rand() % 38 + 1;
    }

    for (int i = 11; i < 16; i++) {
        Pontok[i].karakter = 'X';
    }

    bool gameover = false;
    while (gameover == false) {
        clear();
        Draw (20, 40, Pontok, 12 + Kigyohossz);
        
        char bekert = gamey.GetInput();
        if (bekert == 'w')
        {
            Pontok[11].xkord--;
        }
        else if (bekert == 's')
        {
            Pontok[11].xkord++;
        }
        else if (bekert == 'a')
        {
            Pontok[11].ykord--;
        }
        else if (bekert == 'd')
        {
            Pontok[11].ykord++;
        }
        else if (bekert == 'q')
        {
            gameover = true;
        }

        for (int i = Kigyohossz + 12; i > 11; i--)
        {
            Pontok[i].xkord = Pontok[i-1].xkord;
            Pontok[i].ykord = Pontok[i-1].ykord;
        }

        for (int i = 0; i < 5; i++) {
            if ((Pontok[11].xkord == Pontok[i].xkord && Pontok[11].ykord == Pontok[i].ykord) || (Pontok[11].xkord == 0 || Pontok[11].ykord == 0 || Pontok[11].xkord == 19 || Pontok[11].ykord == 39) ) {
                gameover = true;
            }
        }

        for (int i = 5; i < 11; i++) {
            if ((Pontok[11].xkord == Pontok[i].xkord && Pontok[11].ykord == Pontok[i].ykord)) {
                Kigyohossz++;
                
                Pontok[Kigyohossz + 11].xkord = Pontok[Kigyohossz + 11 - 1].xkord;
                Pontok[Kigyohossz + 11].ykord = Pontok[Kigyohossz + 11 - 1].ykord;

                Pontok[i].karakter = ' ';
                Pontok[i].xkord = -10;
                Pontok[i].ykord = -10;
            }
        }

        gamey.Wait(175);
    }

    std::cout << "Game over! :(" << std::endl; 
    return 0;
}