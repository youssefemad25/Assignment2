#pragma once
class point {
private:
    float x;
    float y;

public:
    point();
    void set_x(float x);
    void set_y(float y);
    float get_x();
    float get_y();
    void display();
    float distance();

};