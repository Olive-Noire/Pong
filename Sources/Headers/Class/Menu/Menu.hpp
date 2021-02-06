#ifndef DEF_CLASS_MENU_HPP
#define DEF_CLASS_MENU_HPP

#include <vector>

#include "./Widget.hpp"

class Menu {

    public:
    Menu() = default;
    ~Menu();

    void Update();
    void Render();

    void AddWidget(Widget* widget);
    bool HasWidget(Widget* widget);

    void Clean();

    protected:
    std::vector<Widget*> Widgets;

};

#endif //DEF_CLASS_MENU_HPP