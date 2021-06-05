#include "Swarm.h"

namespace scr{

Swarm::Swarm(){
    m_particles = new Particle[NPARTICLES];

}

Swarm::~Swarm(){
    delete[] m_particles;

}

}