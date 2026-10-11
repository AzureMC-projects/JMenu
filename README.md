# JMenu

An original, modular Geometry Dash utility/mod menu for the Geode loader. JMenu is designed around a **Safe Mode enabled by default**.

> **Status:** early scaffold. Most Mega Hack-style features are planned, not implemented. A successful CI build only confirms compilation/package creation; it does not confirm in-game behavior.

## Build in GitHub

Yes. The workflow in `.github/workflows/build.yml` runs on pushes, pull requests, and manual dispatch. It attempts Windows 64-bit and Android 64-bit builds using the official Geode build action. Open the repository's **Actions** tab, select **Build JMenu**, and inspect the latest run. If it succeeds, download the `JMenu-Win64` or `JMenu-Android64` artifact from that run. A failed build will show the compiler/log output to fix.

The current workflow has not yet been run/verified. Android builds in GitHub Actions do not run the game or install the mod on a device.

## Build locally

Install the Geode CLI and matching SDK, then run:

```sh
geode build
```

## Current scaffold

- Geode mod manifest and CMake project
- Basic hack registry with initial Speedhack, Noclip P1, and Show Layout entries
- Safe Mode setting enabled by default and basic gating in the registry
- Keyboard hook scaffold for the backtick menu toggle
- GitHub Actions build workflow for Windows and Android 64-bit
- Suggested dependency for the existing Click Between Frames (CBF) mod

**Important:** Speedhack/Noclip/Show Layout are registry entries only; their gameplay hooks are not implemented. The menu controller currently logs open/close state and does not render an ImGui window yet. Safe Mode currently does not guarantee that all completion, reward, or leaderboard submission paths are intercepted.

## Click Between Frames (CBF)

JMenu does not duplicate CBF. It suggests the existing Geode mod `syzzi.click_between_frames`; users can install it through the Geode index or [its Geode page](https://geode-sdk.org/mods/syzzi.click_between_frames). CBF's settings and input handling remain managed by CBF itself.

## Roadmap

See [FEATURE_ROADMAP.md](FEATURE_ROADMAP.md) for planned UI, practice tools, gameplay toggles, safety work, and platform testing.
