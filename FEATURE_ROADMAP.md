# JMenu feature roadmap

Items are only marked complete after the feature has an implementation and has been tested in-game on the stated target.

## Menu and settings
- [x] Visible Geode-native menu entry point
- [x] Backtick hotkey code corrected to `KEY_GraveAccent`
- [ ] Persistent custom panel with search and category tabs
- [ ] Search, tooltips, notifications, draggable/resizable layout
- [ ] Theme selector, profiles, config import/export
- [ ] Per-feature keybinds and a configurable menu key
- [ ] Mobile-friendly touch menu and on-screen toggle

## Practice and visual tools
- [ ] FPS display and session timer
- [ ] Level/player information panel
- [ ] Practice reset and checkpoint helpers
- [ ] Hitbox viewer and hitbox trail
- [ ] Show Layout and object/decor visibility filters
- [ ] Speed presets and Noclip P1/P2, with explicit practice-only labels
- [ ] Attempt counter and completion/session statistics
- [ ] Replay or bot features only after deterministic input and compatibility testing

## Click Between Frames
Use the existing Geode mod instead of reimplementing CBF: https://geode-sdk.org/mods/syzzi.click_between_frames. JMenu must not claim it can toggle CBF unless a supported public API exists.

## Safety and official release
- [ ] Audit completion/reward/leaderboard submission paths where supported
- [ ] Test Safe Mode against each gameplay-affecting feature
- [ ] Test Windows runtime and Android device behavior separately
- [ ] Confirm Geode compatibility range, including whether Android Geode 1.8.0 can load the build
- [ ] Add final icon/artwork and complete the Geode index submission requirements

A successful CI build only confirms that the code compiles and packages. It does not prove runtime behavior or official-index approval.
