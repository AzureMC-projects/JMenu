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
    registerHack({"speedhack", "Speedhack", "Global",
        "Changes local gameplay speed. Use only in offline/practice contexts.", false, true});
    registerHack({"noclip-p1", "Noclip P1", "Player",
        "Disables selected player collision checks; can invalidate completion.", false, true});
    registerHack({"show-layout", "Show Layout", "Display/Labels",
        "Hides selected decoration for visual inspection.", false, false});
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
        // Safe Mode deliberately refuses gameplay-advantage toggles.
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
