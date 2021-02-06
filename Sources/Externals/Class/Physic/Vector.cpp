#include "../../../Headers/Class/Physic/Vector.hpp"

Vector::Vector() {

    axeX = 0;
    axeY = 0;

}

Vector::Vector(float x,float y) {

    axeX = x;
    axeY = y;

}

void Vector::Push(float x,float y) {

    axeX += x;
    axeY += y;

}

void Vector::Push(Vector v) {

    axeX += v.GetAxeX();
    axeY += v.GetAxeY();

}

