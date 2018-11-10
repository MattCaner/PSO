#include"swarm.hpp"

Swarm::Swarm(int size, Area bounds, double maxSpeed, double c1, double c2, double (*Validator)(V2d&)):
    Validator_(Validator), c1_(c1), c2_(c2),size_(size)  {
    swarmTable_ = new Particle[size];
    for(int i = 0; i<size; i++) swarmTable_[i] = Particle(bounds,maxSpeed);
    bestValue_ = 10000;
}

void Swarm::oneStep(){
    for(int i = 0; i<size_; i++){
        swarmTable_[i].move();
        double tmp = swarmTable_[i].validate(Validator_);
        if(tmp<bestValue_){
            bestValue_ = tmp;
            bestPlace_ = V2d(swarmTable_[i].getPos().getX(),swarmTable_[i].getPos().getY());
        }
    }
    for(int i = 0; i<size_; i++){
        swarmTable_[i].adjustSpeed(bestPlace_,c1_,c2_,1.0);
    }
}

Swarm::~Swarm(){
    delete [] swarmTable_;
}