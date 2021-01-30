#include <vector>
#include <iostream>
#include <Input.h>


struct Point {
    int x;
    int y;
    char c;
};

void Draw( int ScreenX , int ScreenY , std::vector<Point>& points , std::vector<Point>& snake ) {
    
    bool talalat = 0;
    for(int i = 0; i < ScreenY ; i++) {
        for(int k = 0; k < ScreenX ; k++) {

            if( i == 0 || k == 0 || i == ScreenY-1 || k == ScreenX-1 ) {
                std::cout << '#';
            }
            else {


                for(int j = 0 ; j < snake.size() ; j++ ) {
                    if( k == snake[j].x && i == snake[j].y ) {
                        talalat = 1;
                        std::cout << snake[j].c;
                        break;
                    }
                }

                if( !talalat ) {
                    for(int j = 0 ; j < points.size() ; j++) {
                        if( k == points[j].x && i == points[j].y ) {
                            std::cout << points[j].c;
                            talalat = 1;
                            break;
                        }
                    }
                }

                if( !talalat ) {
                    std::cout << ' ';
                }
                talalat = 0;
            }

        }
        std::cout << std::endl;
    }
}

void Clear() {
    for(int i = 0; i < 20 ; i++) {
        std::cout << std::endl;
    }
}

int main() {

    srand( time(NULL) );

    std::vector<Point> snake;
    std::vector<Point> points;

    snake.emplace_back(  (random()%38) + 1 , (random()%18) + 1 , 'H' );
    snake.emplace_back(  snake.back().x , snake.back().y + 1 , 'T' );

    for(int i = 0 ; i < 10 ; i++) {
        points.emplace_back( (random()%38) + 1 , (random()%18) + 1 , 'X' );
    }

    int score = 0;
    bool ShouldRun = true;
    char cmd;
    Input inputs;

    while( ShouldRun ) {

        Clear();
        std::cout << "Score: " << score << " snake: " << snake.size() << " points: " << points.size() << std::endl;
        Draw( 40 , 20 , points , snake );

        cmd = inputs.GetInput();

        for(int i = snake.size() - 1 ; i > 0 ; i-- ) {
            snake[i].x = snake[i - 1].x;
            snake[i].y = snake[i - 1].y;
        }

        if( cmd == 'w' ) {
            snake[0].y--;
        }
        else if(cmd == 's') {
            snake[0].y++;
        }
        else if( cmd == 'a' ) {
            snake[0].x--;
        }
        else if( cmd == 'd' ) {
            snake[0].x++;
        }
        else if( cmd == 'q' ) {
            ShouldRun = false;
        }

        for(int i = 0 ; i < points.size() ; i++) {
            if( snake[0].x == points[i].x && snake[0].y == points[i].y ) {
                score++;

                points.erase( points.begin() + i );

                Point& tail = snake.back();
                Point& tail2 = snake[ snake.size() - 2 ];

                int x = tail.x + (tail.x - tail2.x);
                int y = tail.y + (tail.y - tail2.y);
                

                snake.emplace_back(  x , y , 'T' );
            }
        }

        for(int i = 1 ; i < snake.size() ; i++) {
            if( snake[0].x == snake[i].x && snake[0].y == snake[i].y ) {
                ShouldRun = 0;
            }
        }
        
        if( snake[0].x == 0) {
            snake[0].x = 39;
        }
        else if( snake[0].y == 0) {
            snake[0].y = 19;
        }
        else if( snake[0].y == 19) {
            snake[0].y = 0;
        }
        else if( snake[0].x == 39) {
            snake[0].x = 0;
        }


        inputs.Wait(300);
    }

    std::cout << "You Died" << std::endl;

    return 0;
}
