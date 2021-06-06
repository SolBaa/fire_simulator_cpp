#pragma once

namespace scr
{

    class Particle
    {
        double m_direction;
        double m_speed;
        void init();


    public:
        double m_x;
        double m_y;
        Particle();
        void update(int interval);
        ~Particle();
    };

}