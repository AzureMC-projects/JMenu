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
    void dispatchKeyboardMSG(enumKeyCodes key, bool down, bool repeat) {
        CCKeyboardDispatcher::dispatchKeyboardMSG(key, down, repeat);
        if (down && !repeat && key == KEY_Grave) {
            JMenu::ui::MenuController::get().toggle();
        }
    }
};
