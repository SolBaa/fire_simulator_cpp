#pragma once

namespace scr
{

    class Particle
    {

    public:
        double m_xspeed;
        double m_yspeed;
        double m_x;
        double m_y;
        Particle();
        void update();
        ~Particle();
    };

}