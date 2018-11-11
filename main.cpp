#include"swarm.hpp"
#include<cstdlib>
#include<iostream>
#include<cmath>

using namespace std;

const double pi = 3.14159265359;

const int sample = 20;
const int iterations = 2000;


double Fun(V2d& w){
    return w.getX()*w.getX() + w.getY()*w.getY() - 20*(cos(pi*w.getX())+cos(pi*w.getY())-2);
}

int main(){

    Area b(10,-10,-10,10);
    Swarm s1 = Swarm(20, b, 0.1, 2, 2, Fun);

    double BestTable[sample];
    double* TableOfValidators = new double[s1.getSize()];
    double* BestValidators = new double[s1.getSize()];


    for(int j = 0; j<sample; j++){

        for(int i = 0; i<10; i++){
            s1.oneStep();
            #ifdef LOUD
            cout << s1.getBest() << " at " << s1.getBestPlace().getX() << " " << s1.getBestPlace().getY() << endl;
            #endif
            for(int k = 0; k<s1.getSize(); k++){
                TableOfValidators[k] = s1[k]->getLastVal();
                BestValidators[k] = s1[k]->getBestVal();
            }
            #ifdef LOUD
            cout << i << "," << s1.getBest() << "," << mean(TableOfValidators,s1.getSize()) << "," << sqrt(variation(TableOfValidators,s1.getSize())) 
                << "," << mean(BestValidators,s1.getSize()) << "," << sqrt(variation(BestValidators,s1.getSize()))  << endl;
            #endif
        }
        #ifdef LOUD
        for(int k = 0; k<s1.getSize(); k++){
            cout << s1[k]->getBestVal() << " " << s1[k]->getLastVal() << " " << s1[k]->getPos().getX() << " " << s1[k]->getPos().getY() << endl;
        }
        #endif
        BestTable[j] = s1.getBest();
    }

    delete [] TableOfValidators;
    delete [] BestValidators;

    return 0;
}