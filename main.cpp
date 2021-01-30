#include <iostream>

void Clear() {
    for(int i = 0 ; i < 20 ; i++) {
        std::cout << "\n";
    }
    std::cout << std::endl;
}

void Draw( int x , int y , char player , char space ) {

    for(int k = 0; k < 10 ; k++ ) {
        
        for(int i = 0; i < 10 ; i++) {

            if( i == x && k == y ) {
                std::cout << player;
            }
            else {
                std::cout << space;
            }

        }
        std::cout << "\n";
    }

}

void Update();


int main() {


    int x = 5;
    int y = 5;
    char player = 'X';
    char space = ' ';
    char userCommand;

    bool gameOver = false;

    while( gameOver == false ) {

        Clear();
        Draw( x , y , player , space );

        //Update();
        
        userCommand = getchar();
        if( userCommand == 'w' ) {
            y--;
        }
        else if( userCommand == 's' ) {
            y++;
        }
        else if( userCommand == 'a' ) {
            x--;
        }
        else if( userCommand == 'd' ) {
            x++;
        }

    }


    return 0;
}