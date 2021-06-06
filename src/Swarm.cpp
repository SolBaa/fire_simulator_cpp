#include "Swarm.h"

namespace scr{

Swarm::Swarm(): lastTime(0){
    m_particles = new Particle[NPARTICLES];

}
void Swarm::update(int elapsed){
    int interval = elapsed - lastTime;
    	for (int i = 0; i <Swarm::NPARTICLES; i++) {
            m_particles[i].update(interval);
		}
        lastTime = elapsed;


}

Swarm::~Swarm(){
    delete[] m_particles;

}

}