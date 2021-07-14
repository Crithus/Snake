#ifndef POSITION_HPP
#define POSITION_HPP

class Position{
    protected:
    int x,y;

    public:
    Position(int x = -1, int y = -1) : x(x), y(y) {}

    int getX() const { return x; }
    int getY() const { return y; }

    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
};

#endif