#include "MenuController.hpp"
#include <Geode/Geode.hpp>

namespace JMenu::ui {
MenuController& MenuController::get() {
    static MenuController instance;
    return instance;
}

void MenuController::initialize() {
    m_open = false;
    geode::log::info("JMenu menu controller ready.");
}

void MenuController::toggle() {
    m_open = !m_open;
    geode::log::info("JMenu menu {}", m_open ? "opened" : "closed");
    // Dear ImGui/Cocos rendering and input capture are an integration layer still
    // to be added and tested against the user's exact Geode SDK installation.
}
}
