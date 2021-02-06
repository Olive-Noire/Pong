#ifndef DEF_CLASS_VELOCITY_HPP
#define DEF_CLASS_VELOCITY_HPP

#include "./Vector.hpp"

class Velocity : public Vector {

    public:
    Velocity() : Vector() { limit = 0; }
    Velocity(float l) : Vector() { limit = l; };
    Velocity(float x,float y,float l) : Vector(x,y) { limit = l;};

    void Udapte();

    float inline GetLimit() const { return limit; }
    void SetLimit(float l) { limit = l; }

    protected:
    float limit;

};

#endif //DEF_CLASS_VELOCITY_HPP