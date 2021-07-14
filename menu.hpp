#ifndef MENU_HPP
#define MENU_HPP
#include<iostream>
using namespace std;

class Menu{
    string choices[2];
    int highlight, input;

    public:
    Menu();
    void print();
    int getHighlight() const { return highlight; }
};

#endif