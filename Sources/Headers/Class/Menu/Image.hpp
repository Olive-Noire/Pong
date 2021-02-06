#ifndef DEF_CLASS_MENU_IMAGE_HPP
#define DEF_CLASS_MENU_IMAGE_HPP

#include <SDL.h>
#include <string>

#include "./Widget.hpp"

class Image : public Widget {

    public:
    Image(std::string Path);
    ~Image();

    void Update();
    void Render();

    void SetSize(int size);

    protected:

};

#endif //DEF_CLASS_MENU_IMAGE_HPP