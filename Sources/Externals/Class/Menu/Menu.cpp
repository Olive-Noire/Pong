#include "../../../Headers/Class/Menu/Menu.hpp"

Menu::~Menu() {

    for (int i = 0;i < Widgets.size();i++) delete Widgets[i];
    Widgets.clear();
    delete &Widgets;
    
    //On est sûr que il reste plus rien ^^

}

void Menu::Update() { for (int i = 0;i < Widgets.size();i++) Widgets[i]->Update(); }
void Menu::Render() { for (int i = 0;i < Widgets.size();i++) Widgets[i]->Render(); }
void Menu::AddWidget(Widget* widget) { Widgets.push_back(widget); }

bool Menu::HasWidget(Widget* widget) {

    for (int i = 0;i < Widgets.size();i++) if (Widgets[i] == widget) return true; else if (i == (Widgets.size() - 1)) return false;

}
