#pragma once
#include <string>
#include <vector>

namespace JMenu::core {
struct HackInfo {
    std::string id;
    std::string name;
    std::string category;
    std::string description;
    bool enabled = false;
    bool affectsGameplay = false;
};

class HackRegistry {
public:
    static HackRegistry& get();
    void initialize();
    void registerHack(HackInfo info);
    bool setEnabled(const std::string& id, bool enabled);
    bool anyGameplayHackEnabled() const;
    const std::vector<HackInfo>& all() const { return m_hacks; }
private:
    std::vector<HackInfo> m_hacks;
};
}
