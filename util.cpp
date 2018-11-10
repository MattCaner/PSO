#include"util.hpp"

double randomDouble(double lowlimit,double uplimit){
    double f = (double)rand() / RAND_MAX;
    return lowlimit+f*(uplimit - lowlimit);
}

double signum(double val){
    return (val>0?1:-1);
}
