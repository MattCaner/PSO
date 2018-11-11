#include"util.hpp"

double randomDouble(double lowlimit,double uplimit){
    double f = (double)rand() / RAND_MAX;
    return lowlimit+f*(uplimit - lowlimit);
}

double signum(double val){
    return (val>0?1:-1);
}

double mean(double* table, int size){
    double sum = 0;
    for(int i = 0; i<size; i++) sum+=table[i];
    return sum/size;
}

double variation(double* table, int size){
    double sum = 0;
    double amean = mean(table,size);
    for(int i = 0; i<size; i++) sum+=(table[i]-amean)*(table[i]-amean);
    return sum/(size+1);
}