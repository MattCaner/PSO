#include"particle.hpp"

Particle::Particle(){
    pos_ = V2d();
    speed_ = V2d();
}

Particle::Particle(Area bounds, double maxSpeed){
    pos_ = V2d(randomDouble(bounds.left,bounds.right),randomDouble(bounds.down,bounds.up));
    speed_ = V2d(randomDouble(-1*maxSpeed,maxSpeed),randomDouble(-1*maxSpeed,maxSpeed));
    vmax_ = maxSpeed;
    bounds_ = bounds;
    bestVal_ = 1000;
}

void Particle::move(){
    pos_ = pos_ + speed_;
    
    if(pos_.getX()>bounds_.right){
        speed_.bounceVertical();
    }
    if(pos_.getX()<bounds_.left){
        speed_.bounceVertical();
    }
    if(pos_.getY()>bounds_.up){
        speed_.bounceHorizontal();
    }
    if(pos_.getY()<bounds_.down){
        speed_.bounceHorizontal();
    }
    
}

double Particle::validate(double (*Validator)(V2d& v)){
    double tmp = Validator(pos_);
    if(tmp<bestVal_){
        bestVal_ = tmp;
        bestPlace_ = pos_;
    }
    lastVal_ = tmp;
    return tmp;
}

void Particle::adjustSpeed(V2d bestPos, double c1, double c2,double omega){
    double newx = omega*(speed_.getX()+randomDouble(0,c1)*(bestPlace_.getX()-pos_.getX())+randomDouble(0,c2)*(bestPos.getX()-pos_.getX()));
    double newy = omega*(speed_.getY()+randomDouble(0,c1)*(bestPlace_.getY()-pos_.getY())+randomDouble(0,c2)*(bestPos.getY()-pos_.getY()));
    speed_ = V2d(abs(newx)>abs(vmax_)?vmax_*signum(newx):newx,abs(newy)>abs(vmax_)?vmax_*signum(newy):newy);
    //speed_ = V2d(newx,newy);
}