#ifndef APPLE_HPP
#define APPLE_HPP

#include"position.hpp"
#include"enviroment.hpp"
#include"snake.hpp"
#include<ncurses.h>

class Apple : public Position, public Enviroment{
    char c;
    public:
    Apple(int x = -1, int y = -1, char c = '@') : Position(x,y), c(c) {}
    
    bool hit(Snake& snake) ;
    void draw(WINDOW *win) { mvwprintw(win, y, x, "%c", c);}
    void reposition(Snake& snake);
};

#endif