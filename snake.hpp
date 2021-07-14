#ifndef SNAKE_HPP
#define SNAKE_HPP

#include"position.hpp"
#include"enviroment.hpp"
#include<ncurses.h>

enum Direction{
    STOP = 0, UP, DOWN, LEFT, RIGHT
};

class Snake: public Enviroment{
    int length, head_pos, tail_pos;
    Position *body;
    char c;
    Direction direction;
    Snake(const Snake& snake);
    Snake& operator=(const Snake& rhs);

    public:
    Snake(int len = 3, int hp = 0, int tp = 2, char c = '#', Direction dir = STOP): length(len), head_pos(hp), tail_pos(tp), c(c), direction(dir) {
        body = new Position[length];

        body[0].setX(WIDTH/2); body[0].setY(HEIGHT/2);
        body[1].setX(WIDTH/2); body[1].setY(HEIGHT/2+1);
        body[2].setX(WIDTH/2); body[2].setY(HEIGHT/2+2);
    }

    int getLen() const { return length; }
    int getHeadpos() const {return head_pos; }

    void draw(WINDOW *win);
    void move();
    void input();
    void operator++();
    bool gameover();
    Position &operator[](int i){ return body[i]; }

    ~Snake(){ delete[] body; }
};

#endif
