#include"apple.hpp"
#include"enviroment.hpp"
#include"snake.hpp"
#include<stdlib.h>

bool Apple::hit(Snake& snake){
    for(int i = 0; i < snake.getLen(); i++)
        if(x == snake[i].getX() && y == snake[i].getY())
            return true;
    return false;
}

void Apple::reposition(Snake& snake){
    do{ 
    x = rand() % (WIDTH-2) + 1;
    y = rand() % (HEIGHT-2) + 1;
    }while(hit(snake) || x == -1);
}