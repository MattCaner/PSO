#pragma once
#include<cstdlib>

/** Utility functions file */

double randomDouble(double lowlimit,double uplimit);    /** returns random double from between lowlimit and uplimit */

double signum(double val);      /** returns +1.0 if value is positive and -1.0 if value is negative */

struct Area{        /** simple struct to store limits of a rectangle area*/
    double up, down, left, right;       /** each double represents one bound*/
    Area():                             /** default constructor (sets all bounds to 1)*/
        up(1),down(-1),left(-1),right(1) {}
    Area(double u,double d,double l,double r):      /** constructor for general use*/
        up(u),down(d),left(l),right(r) {}
};