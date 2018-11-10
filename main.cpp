#include"swarm.hpp"
#include<cstdlib>
#include<iostream>
#include<cmath>

const double pi = 3.141592;

using namespace std;

double Fun(V2d& w){
    return w.getX()*w.getX() + w.getY()*w.getY() - 20*(cos(pi*w.getX())+cos(pi*w.getY())-2);
}

int main(){

    Area b(10,-10,-10,10);

    Swarm s1 = Swarm(20, b, 0.1, 2, 2, Fun);
    for(int i = 0; i<4000; i++){
        s1.oneStep();
        cout << s1.getBest() << " at " << s1.getBestPlace().getX() << " " << s1.getBestPlace().getY() << endl;
    }
    V2d t = V2d(0.0,0.0);
    cout << Fun(t) << endl;

    return 0;
}