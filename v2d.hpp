#pragma once
#include"util.hpp"

/** Vector-2d class file. Vectors have two coordinates. They can be added or bounced. */

class V2d{
public:
    V2d();  //initialise with zeros
    V2d(double x, double y);    //initialise with x and y
    V2d operator+(V2d& v);      //adding vectors can be done with normal addition (overload of + operator)
    double getX() const {return x_;}        //get X coordinate. Const and inline.
    double getY() const {return y_;}        //get Y coordinate. Const and inline.
    void bounceVertical() {x_ = -x_;}       //bounces a particle of a vertical wall.
    void bounceHorizontal() {y_ = -y_;}     //bounces a particle of a horizontal wall.
private:
    double x_;   
    double y_;
};