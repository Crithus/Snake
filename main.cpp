#include<curses.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include"enviroment.hpp"
#include"apple.hpp"
#include"snake.hpp"
#include"menu.hpp"

int main(){
    initscr();
    srand(time(NULL));

    Menu menu;

    while(1){
        menu.print();
        if(menu.getHighlight()==1) break;
        FILE *f = fopen("highscore.txt", "r"); int highscore; 
        f != NULL ? fscanf(f, "%d", &highscore) : highscore = 0;

        Enviroment enviroment;
        Snake snake;
        Apple apple; 

        WINDOW *win = newwin(enviroment.getH(), enviroment.getW(), 1, 1);
        refresh();
        noecho();
        halfdelay(1);

        mvprintw(0, 15, "Highscore: %d", highscore);
        apple.reposition(snake);

        while(!snake.gameover()){
            wclear(win);
            snake.input();
        
            if(apple.hit(snake)){ snake.operator++(); apple.reposition(snake); }

            snake.move();
            enviroment.draw(win);
            snake.draw(win);
            apple.draw(win);
            mvprintw(0,2, "Score: %d", snake.getLen()-3);

            wrefresh(win);
        }
        if(snake.getLen()-3 > highscore) {  f = fopen("highscore.txt", "w"); fprintf(f, "%d", snake.getLen()-3); fclose(f); }

        wclear(win);
        clear();
        cbreak();
        mvprintw(5,5, "GAME OVER!");
        refresh();
        sleep(2);
    }
    endwin();
    return 0;
}
