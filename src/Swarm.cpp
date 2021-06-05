#include "Swarm.h"

namespace scr{

Swarm::Swarm(){
    m_particles = new Particle[NPARTICLES];

}
void Swarm::update(){
    	for (int i = 0; i <Swarm::NPARTICLES; i++) {
            m_particles[i].update();
		}


}

Swarm::~Swarm(){
    delete[] m_particles;

}

}