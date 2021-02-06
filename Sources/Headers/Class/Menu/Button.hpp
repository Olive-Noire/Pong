#ifndef DEF_CLASS_MENU_BUTTON_HPP
#define DEF_CLASS_MENU_BUTTON_HPP

#include "./Text.hpp"

class Button : public Widget {

    public:
    Button(std::string t,int s,Uint8 color[3]);
    ~Button();

    void Update();
    void Render();

    protected:
    Uint8 color[3];
    Text* text = nullptr;

    int size;

};

#endif //DEF_CLASS_MENU_BUTTON_HPP