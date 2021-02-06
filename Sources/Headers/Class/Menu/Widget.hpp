#ifndef DEF_CLASS_MENU_WIDGET_HPP
#define DEF_CLASS_MENU_WIDGET_HPP

#include "../Game/Element.hpp"

class Widget : public Element {

    public:
    Widget() = default;
    ~Widget();

    bool Click();

    virtual void Update();
    virtual void Render();

    protected:

};

#endif //DEF_CLASS_MENU_WIDGET_HPP