# JMenu

An original, modular Geometry Dash utility/mod menu for the Geode loader. JMenu is designed around a **Safe Mode enabled by default**: gameplay-affecting features must be registered with a safety classification, and reward/completion submission must be blocked while Safe Mode is enabled and any classified hack is active.

> This repository starts as a scaffold. Geometry Dash internals and the ImGui/Cocos renderer integration must be validated against the exact installed Geode SDK before gameplay hooks are enabled. No online/server-side manipulation is included.

## Requirements

- Geode SDK for your target Geometry Dash platform/version
- CMake and a supported C++ toolchain
- An ImGui-to-Cocos2d integration compatible with your Geode SDK

## Build

From a configured Geode development environment:

```sh
geode build
```

Use the Geode CLI documentation for SDK setup and platform-specific Android toolchains.

## Initial implementation

- Persistent settings through Geode saved values
- Safe Mode policy and hack registry
- Modular source layout for core, UI, hacks and utilities
- Geode logging and lifecycle setup

The requested advanced gameplay hooks (physics bypass, noclip variants, replay bot, reward interception, editor tools, etc.) are intentionally not represented as working features until each hook is verified against the target game version. Safe Mode should not be treated as a guarantee against every third-party submission path.

## Layout

- `src/main.cpp` — mod lifecycle and bootstrap
- `src/core/` — settings, registry and Safe Mode policy
- `src/hacks/` — isolated hack implementations
- `src/ui/` — menu and theme integration
- `src/utils/` — reusable helpers
- `mod.json` — Geode package metadata
- `CMakeLists.txt` — build configuration
