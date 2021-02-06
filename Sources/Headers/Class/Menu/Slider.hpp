#ifndef DEF_CLASS_MENU_SLIDER_HPP
#define DEF_CLASS_MENU_SLIDER_HPP

#include "./Widget.hpp"

class Slider : public Widget {

    public:
    Slider();
    ~Slider();

    inline int GetValue() const { return value; }

    void Update();
    void Render();

    void SetValue(int v);

    protected:
    int value;
    SDL_Rect cursor;

};


#endif //DEF_CLASS_MENU_SLIDER_HPP