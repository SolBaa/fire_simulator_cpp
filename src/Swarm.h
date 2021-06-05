#ifndef SWARM_H
#define SWARM_H

#include "Particle.h"

namespace scr{
class Swarm{
private:
    Particle * m_particles;
public:
    const static int NPARTICLES = 5000;

    Swarm();
    ~Swarm();

   const Particle * const getParticles(){return m_particles;}
};

}

#endif