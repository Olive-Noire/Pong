#ifndef DEF_CLASS_VECTOR_HPP
#define DEF_CLASS_VECTOR_HPP

class Vector {

    public:
    Vector();
    Vector(float x,float y);

    void Push(float x,float y);
    void Push(Vector v);

    float inline GetAxeX() const { return axeX; }
    float inline GetAxeY() const { return axeY; }

    void SetAxeX(float x) { axeX = x; }
    void SetAxeY(float y) { axeY = y; }

    protected:
    float axeX;
    float axeY;



};

#endif //DEF_CLASS_VECTOR_HPP