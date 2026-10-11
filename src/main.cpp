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
    log::info("JMenu loaded. Press ` to open the menu.");
}

class $modify(JMenuKeyboardDispatcher, CCKeyboardDispatcher) {
    bool dispatchKeyboardMSG(enumKeyCodes key, bool down, bool repeat, double timestamp) {
        auto handled = CCKeyboardDispatcher::dispatchKeyboardMSG(key, down, repeat, timestamp);
        // Geode names the backtick key KEY_GraveAccent.
        if (down && !repeat && key == KEY_GraveAccent) {
            JMenu::ui::MenuController::get().toggle();
        }
        return handled;
    }
};
