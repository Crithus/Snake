#include"menu.hpp"
#include<ncurses.h>

Menu::Menu(){
    choices[0] = "PLAY"; choices[1] = "EXIT";
    highlight = 0;
}

void Menu::print(){
     WINDOW *menuwin = newwin(4,15,1,1);
    clear();
    refresh();
    noecho();
    keypad(menuwin, true);
    mvwprintw(menuwin,0,0, "SNAKE");
    while(1){
        for(int i = 0; i < 2; i++){
            if(i == highlight) wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i+1, 1, choices[i].c_str());
            wattroff(menuwin, A_REVERSE);
        }

        input = wgetch(menuwin);

        switch(input){
            case KEY_UP:
            highlight--; if(highlight == -1) highlight = 0;
            break;

            case KEY_DOWN:
            highlight++; if(highlight == 2) highlight = 1;
            break;

            default:
            break;
        }
        if(input == 10) break;
    }
}