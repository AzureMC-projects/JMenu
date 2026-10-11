#include "HackRegistry.hpp"
#include "SafeMode.hpp"
#include <algorithm>

namespace JMenu::core {
HackRegistry& HackRegistry::get() {
    static HackRegistry instance;
    return instance;
}

void HackRegistry::initialize() {
    if (!m_hacks.empty()) return;

    // Catalog entries are metadata only until their corresponding gameplay or
    // rendering hooks are implemented. The menu must not imply otherwise.
    registerHack({"speedhack", "Speedhack", "Global",
        "Planned: local speed control for practice/offline use.", false, true});
    registerHack({"noclip-p1", "Noclip P1", "Player",
        "Planned: disable player-one collision checks; can invalidate completion.", false, true});
    registerHack({"noclip-p2", "Noclip P2", "Player",
        "Planned: disable player-two collision checks; can invalidate completion.", false, true});
    registerHack({"show-layout", "Show Layout", "Visuals",
        "Planned: hide selected decoration for visual inspection.", false, false});
    registerHack({"hitbox-viewer", "Hitbox Viewer", "Visuals",
        "Planned: draw player and object hitboxes.", false, false});
    registerHack({"hitbox-trail", "Hitbox Trail", "Visuals",
        "Planned: visualize recent player hitbox positions.", false, false});
    registerHack({"fps-counter", "FPS Counter", "HUD",
        "Planned: display frames per second.", false, false});
    registerHack({"session-timer", "Session Timer", "HUD",
        "Planned: track the current play session.", false, false});
    registerHack({"attempt-counter", "Attempt Counter", "HUD",
        "Planned: track attempts during a level session.", false, false});
    registerHack({"practice-tools", "Practice Helpers", "Practice",
        "Planned: practice reset and checkpoint quality-of-life helpers.", false, false});
    registerHack({"start-position", "Start Position Helper", "Practice",
        "Planned: quick access to saved practice start positions.", false, false});
    registerHack({"object-filter", "Object Visibility Filters", "Visuals",
        "Planned: filter selected decoration/object groups.", false, false});
}

void HackRegistry::registerHack(HackInfo info) {
    auto it = std::find_if(m_hacks.begin(), m_hacks.end(),
        [&](const HackInfo& item) { return item.id == info.id; });
    if (it == m_hacks.end()) m_hacks.push_back(std::move(info));
}

bool HackRegistry::setEnabled(const std::string& id, bool enabled) {
    auto it = std::find_if(m_hacks.begin(), m_hacks.end(),
        [&](const HackInfo& item) { return item.id == id; });
    if (it == m_hacks.end()) return false;
    if (enabled && it->affectsGameplay && SafeMode::get().isEnabled()) {
        return false;
    }
    it->enabled = enabled;
    return true;
}

bool HackRegistry::anyGameplayHackEnabled() const {
    return std::any_of(m_hacks.begin(), m_hacks.end(),
        [](const HackInfo& item) { return item.enabled && item.affectsGameplay; });
}
}
