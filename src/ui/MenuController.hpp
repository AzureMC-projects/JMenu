#pragma once
namespace JMenu::ui {
class MenuController {
public:
    static MenuController& get();
    void initialize();
    void toggle();
    bool isOpen() const { return m_open; }
private:
    bool m_open = false;
};
}
