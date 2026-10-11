#include <Geode/Geode.hpp>
#include <Geode/modify/CCKeyboardDispatcher.hpp>

#include "core/HackRegistry.hpp"
#include "core/SafeMode.hpp"
#include "ui/MenuController.hpp"

using namespace geode::prelude;

$on_mod(Loaded) {
    JMenu::core::HackRegistry::get().initialize();
    JMenu::core::SafeMode::get().load();
    JMenu::ui::MenuController::get().initialize();
    log::info("JMenu initialized; Safe Mode defaults to enabled.");
}

class $modify(JMenuKeyboardDispatcher, CCKeyboardDispatcher) {
    bool dispatchKeyboardMSG(enumKeyCodes key, bool down, bool repeat, double timestamp) {
        auto handled = CCKeyboardDispatcher::dispatchKeyboardMSG(key, down, repeat, timestamp);
        if (down && !repeat && key == KEY_Tab) {
            JMenu::ui::MenuController::get().toggle();
        }
        return handled;
    }
};
