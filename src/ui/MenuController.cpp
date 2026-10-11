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
    // Use Geode's native alert for a visible entry point while a custom,
    // persistent panel and its feature controls are still being developed.
    m_open = true;

    auto safeMode = JMenu::core::SafeMode::get().isEnabled();
    std::string body = "JMenu - Geometry Dash tools\n\n";
    body += safeMode
        ? "Safe Mode: ON (JMenu blocks gameplay-affecting registry toggles)\n\n"
        : "Safe Mode: OFF (use gameplay tools only where permitted)\n\n";
    body += "Integrations and planned tools:\n";
    body += "- Click Between Frames: install/configure the separate CBF mod\n";
    body += "- Speedhack, Noclip and Show Layout: registry entries only; gameplay hooks are not implemented yet\n";
    body += "- Planned: FPS/session display, hitbox viewer, practice helpers, profiles, themes and per-feature keybinds\n\n";
    body += "Early development build: a successful build does not prove in-game or mobile compatibility.";

    FLAlertLayer::create("JMenu", body.c_str(), "Close")->show();
    geode::log::info("JMenu menu opened.");
    m_open = false;
}
}
