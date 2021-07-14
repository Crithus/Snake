#include"snake.hpp"
#include<stdio.h>
#include<curses.h>

void Snake::draw(WINDOW *win){
    for(int i = 0; i < length; i++)
        mvwprintw(win, body[i].getY(), body[i].getX(), "%c", c );
}

void Snake::move(){
    Position &head = body[head_pos];
    Position &tail = body[tail_pos];

    switch(direction){
        case UP:
        tail.setX(head.getX()); 
        tail.setY(head.getY()-1);
        break;

        case DOWN:
        tail.setX(head.getX()); 
        tail.setY(head.getY()+1);
        break;

        case RIGHT:
        tail.setX(head.getX()+1);
        tail.setY(head.getY());
        break;
      

        case LEFT:
        tail.setX(head.getX()-1); 
        tail.setY(head.getY());
        break;

        case STOP:
        break;
    }   
    head_pos = tail_pos; 
    tail_pos != 0 ? tail_pos-- : tail_pos = length-1; 

}

void Snake::operator++(){
    Position *tmp = new Position[length+1];
    for(int i = 0; i < length+1; i++)
        tmp[i] = body[i];
    delete[] body;
    body = tmp;
    length++;
    
}

void Snake::input(){ 
    char asd = getch();
    switch(asd){
        case 'w': if(direction != DOWN) direction = UP;
        break;

        case 's': if(direction != UP) direction = DOWN;
        break;

        case 'd': if(direction != LEFT) direction = RIGHT;
        break;

        case 'a': if(direction != RIGHT) direction = LEFT;
        break;

        case ERR:
        break;
    }
}

bool Snake::gameover(){
    for(int i = 0; i < length; i++){
        if(i == head_pos) continue;
        if(body[head_pos].getX() == body[i].getX() && body[head_pos].getY() == body[i].getY())
            return true;
    }
   if(body[head_pos].getX() < 1 || body[head_pos].getX() > WIDTH -1|| body[head_pos].getY() < 1 || body[head_pos].getY() > HEIGHT-2)
        return true;
    return false;
}
