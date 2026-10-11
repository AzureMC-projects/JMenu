# JMenu

JMenu is an original Geometry Dash utility-menu project for the Geode loader.

> **Status: early development.** The current build provides a Geode-native alert menu opened with the backtick key (`). It is not yet a complete Mega Hack-style menu and has not been approved for the official Geode index.

## Description

JMenu aims to bring together practice utilities, visual helpers, and quality-of-life tools in a clean blue-themed interface. Safe Mode is enabled by default and blocks enabling registry entries marked as gameplay-affecting. Click Between Frames (CBF) is supplied by the existing separate mod; JMenu does not reimplement CBF or control its settings.

## Current build

- Geode-native visible menu entry point, opened with ` on supported desktop keyboards
- Safe Mode setting saved through Geode
- Registry/catalog for planned tools
- Suggested dependency metadata for Click Between Frames
- Windows 64-bit and Android 64-bit build jobs in GitHub Actions

### Important limitations

Speedhack, Noclip, Show Layout, hitbox tools, FPS/session counters, practice helpers, profiles, and themes are not all implemented gameplay features. A registry entry is not a working game hook. Safe Mode does not guarantee that all reward, completion, or leaderboard paths are intercepted. An Android 64-bit CI build is not proof of compatibility with the older Android Geode 1.8.0 runtime.

## Install Click Between Frames

Install [Click Between Frames](https://geode-sdk.org/mods/syzzi.click_between_frames) separately from the Geode index. Its settings and input handling remain owned by CBF.

## Build and CI

Pushes trigger the GitHub Actions workflow for Windows 64-bit and Android 64-bit. Open the [Actions page](https://github.com/AzureMC-projects/JMenu/actions) to inspect the latest build and download its artifacts. A successful CI build confirms compilation/package creation only; it does not prove the menu behaves correctly in-game or on a physical Android device.

## Official Geode submission checklist

- [ ] Final icon and required artwork
- [ ] Test menu opening/closing and touch/input behavior on each supported platform
- [ ] Verify exact supported Geode and Geometry Dash versions
- [ ] Implement and test each advertised feature, or label it as planned
- [ ] Audit Safe Mode and completion/reward/leaderboard interactions
- [ ] Add release notes and review manifest fields
- [ ] Submit to the Geode index and address review feedback

See [CHANGELOG.md](CHANGELOG.md) and [FEATURE_ROADMAP.md](FEATURE_ROADMAP.md).
