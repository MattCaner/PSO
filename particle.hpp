#pragma once
#include"v2d.hpp" 

/** Particle class file. Particles can move and adjust their speed, they can be also evaluated. */

class Particle{
public:
    Particle();     /** Default constructor */
    Particle(Area bounds, double maxSpeed); /** Constructs a particle with bounds and set maximum speed. Randomly generates speed and location */
    void move();    /** Moves particle by its speed. Checks if the particle bounces off an edge */
    double validate(double (*Validator)(V2d& v));   /** Returns validator function for the particle position */
    void adjustSpeed(V2d bestPos, double weight1, double weight2,double omega); /** Adjusts speed with weight1, weight2, omega and best location known */
    V2d getPos() const {return pos_;}   /** Gets position. Notice that function is const and inline */
    double getLastVal() const {return lastVal_;};    /** returns last validated value if needed. This prevents evaluating the same value more than one time. */
    double getBestVal() const {return bestVal_;}    /** returns best value evaluated by this particle. */
private:
    V2d pos_;
    V2d speed_;
    V2d bestPlace_;
    double bestVal_;
    double vmax_;
    Area bounds_;
    double lastVal_;
};