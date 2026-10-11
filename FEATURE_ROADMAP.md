# JMenu feature plan

This file distinguishes menu entries and integrations from working implementations. A feature must not be described as implemented until its game hook is written and tested on the target Geometry Dash + Geode version.

## UI and quality-of-life
- [ ] Dear ImGui/Cocos menu renderer, draggable/resizable window
- [ ] Search, category navigation, tooltips, notifications
- [ ] Profiles, themes, per-hack keybinds, config import/export
- [ ] FPS counter, session timer, level/player information
- [ ] Practice-mode checkpoints and reset helpers

## Gameplay and visual tools (offline/practice unless explicitly allowed)
- [ ] Speedhack and speed presets
- [ ] Noclip P1/P2, hitbox display, hitbox trail
- [ ] Show Layout, object/decor visibility filters
- [ ] FPS/physics controls with compatibility checks
- [ ] Practice utilities, start-position helpers, completion statistics
- [ ] Replay/bot features only after deterministic input and compatibility testing

## Click Between Frames (CBF)
JMenu should use the existing Geode mod rather than reimplementing CBF. Install **Click Between Frames** separately from the Geode index: https://geode-sdk.org/mods/syzzi.click_between_frames. CBF's own settings and input handling remain owned by that mod. JMenu may provide a status/link and compatibility guidance; it must not pretend to toggle CBF unless a supported public API exists.

## Safety
- [ ] Safe Mode defaults on and blocks JMenu gameplay-affecting toggles
- [ ] Clear per-feature labels for practice-only / gameplay-affecting behavior
- [ ] Audit local completion/reward submission hooks and test that Safe Mode prevents unintended submissions where supported
- [ ] Avoid claiming that local checks guarantee protection against all third-party mods, servers, or leaderboard rules

## Platform support
- [ ] Verify Windows builds and runtime
- [ ] Verify Android 64-bit builds and runtime
- [ ] Verify macOS/iOS and Android 32-bit separately
- [ ] Test menu input capture, touch behavior, and hook compatibility per platform

The checkboxes above are planned work, not current functionality. CI builds the current code; a green build does not prove runtime compatibility or that planned features work.
