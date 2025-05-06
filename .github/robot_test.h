#ifndef ROBOT_TEST_H
#define ROBOT_TEST_H

class Robot {
private:
    int x, y;

public:
    Robot() { x = -1; y = -1; }

    void setPosition(int newX, int newY) {
        x = newX;
        y = newY;
    }

    int getX() { return x; }
    int getY() { return y; }
};

#endif
