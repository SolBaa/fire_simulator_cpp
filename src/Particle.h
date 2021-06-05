#pragma once

namespace scr
{

    class Particle
    {

    public:
        double m_speed;
        double m_direction;
        double m_x;
        double m_y;
        Particle();
        void update();
        ~Particle();
    };

}