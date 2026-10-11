#include "MenuController.hpp"
#include <Geode/Geode.hpp>
#include "../core/HackRegistry.hpp"
#include "../core/SafeMode.hpp"

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
    m_open = true;
    auto safeMode = JMenu::core::SafeMode::get().isEnabled();
    auto const& hacks = JMenu::core::HackRegistry::get().all();

    std::string body = "JMenu - Geometry Dash tools\n\n";
    body += safeMode
        ? "Safe Mode: ON (gameplay-affecting registry toggles are blocked)\n"
        : "Safe Mode: OFF (use gameplay tools only where permitted)\n";
    body += "Feature catalogue (planned / not yet active):\n";

    for (auto const& hack : hacks) {
        body += "- ";
        body += hack.name;
        body += " [";
        body += hack.category;
        body += "]\n";
    }

    body += "\nCBF: install/configure the separate Click Between Frames mod.\n";
    body += "Important: the entries above are a roadmap catalogue, not working gameplay hooks. A custom interactive panel is still in development.";

    FLAlertLayer::create("JMenu", body.c_str(), "Close")->show();
    geode::log::info("JMenu menu opened.");
    m_open = false;
}
}
