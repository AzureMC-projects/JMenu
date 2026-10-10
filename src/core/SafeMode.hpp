#pragma once

namespace JMenu::core {
class SafeMode {
public:
    static SafeMode& get();
    void load();
    bool isEnabled() const { return m_enabled; }
    void setEnabled(bool enabled);
private:
    bool m_enabled = true;
};
}
