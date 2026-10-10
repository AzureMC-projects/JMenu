#include "SafeMode.hpp"
#include <Geode/Geode.hpp>

namespace JMenu::core {
SafeMode& SafeMode::get() {
    static SafeMode instance;
    return instance;
}

void SafeMode::load() {
    m_enabled = geode::Mod::get()->getSavedValue<bool>("safe-mode", true);
}

void SafeMode::setEnabled(bool enabled) {
    m_enabled = enabled;
    geode::Mod::get()->setSavedValue("safe-mode", enabled);
    geode::log::info("JMenu Safe Mode: {}", enabled ? "ON" : "OFF");
}
}
