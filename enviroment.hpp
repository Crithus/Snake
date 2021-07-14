#ifndef ENVIROMENT_HPP
#define ENVIROMENT_HPP

#include"position.hpp"
#include<ncurses.h>

class Enviroment{
    protected: 
    const int WIDTH;
    const  int HEIGHT;

    public:
    Enviroment(int w = 40, int h = 20) : WIDTH(w), HEIGHT(h) {}

    virtual int getW() const { return WIDTH; }
    virtual int getH() const { return HEIGHT; }
    virtual void draw(WINDOW *win) { box(win,0,0); }
};


#endif