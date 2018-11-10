#pragma once
#include"particle.hpp"

/** Swarm class. Swarm includes a table of particles. */

class Swarm{
public:
    Swarm(int size, Area bounds, double maxSpeed, double c1, double c2, double (*Validator)(V2d&)); /** Creates the swarm. */
    void oneStep();     /** performs one iteration of movement and validation for all particles. */
    double getBest() const {return bestValue_;}     /** returns best function value ever evaluated by swarm. */
    V2d getBestPlace() const {return bestPlace_;}   /** returns V2d representing where best function value was found. */
    ~Swarm();   /** Frees allocated space. */
private:
    double (*Validator_)(V2d&);
    double c1_;
    double c2_;
    int size_;
    Particle* swarmTable_;
    V2d bestPlace_;
    double bestValue_;
};