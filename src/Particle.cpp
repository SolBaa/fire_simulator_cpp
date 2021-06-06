#include "Particle.h"
#include <math.h>
#include <stdlib.h>

namespace scr
{

    Particle::Particle():m_x(0),m_y(0)
    {
        
        m_speed =(0.0001 *   rand() )/ RAND_MAX;
        m_direction = (2 * M_PI * rand())/ RAND_MAX;
    }

    void Particle::update(int interval )
    {
        double xspeed = m_speed * cos(m_direction);
        double yspeed = m_speed * sin(m_direction);

        m_y += yspeed * interval;
        m_x += xspeed * interval;

    }
    Particle::~Particle()
    {
    }

}