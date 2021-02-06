#include "../../../Headers/Class/Physic/Velocity.hpp"

void Velocity::Udapte() {

    if (axeX > limit) axeX = limit;
    if (axeY > limit) axeY = limit;

    if (axeX < -limit) axeX = -limit;
    if (axeY < -limit) axeY = -limit;

    if (axeX > 0) axeX--;
    if (axeX < 0) axeX++;

    if (axeY > 0) axeY--;
    if (axeY < 0) axeY++;

}