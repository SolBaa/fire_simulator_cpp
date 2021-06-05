#ifndef SWARM_H
#define SWARM_H

#include "Particle.h"

namespace scr{
class Swarm{
private:
    Particle * m_particles;
public:
    const static int NPARTICLES = 1000;

    Swarm();
    void update();
    ~Swarm();

   const Particle * const getParticles(){return m_particles;}
};

}

#endif