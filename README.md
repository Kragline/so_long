# So Long

_And thanks for all the fish!_ 🐬🐟

This project is about creating a small **2D game** using the **MiniLibX** graphics library.  
The goal is to build a simple yet fun game while learning about window management, textures, sprites, events, and map parsing in C.

---

## Overview

In **So Long**, you create a game where the player must:
- Collect all collectibles on the map.
- Reach the exit and escape the level.
- Avoid walls and navigate through the map.

The theme is flexible — the subject mentions a dolphin escaping Earth after eating fish, but you can create **your own world, characters, and tiles**.  
Maps are provided in `.ber` files, and the player moves using `WASD` (or arrow keys).

---

## Features

### Mandatory
- A **2D top-down or side-view world** built from maps.
- Player movement in 4 directions (up, down, left, right).
- Collectibles that must be picked up before exiting.
- Exit door that becomes available after collecting everything.
- Map validation:
  - Must be rectangular.
  - Must be surrounded by walls.
  - Must contain at least 1 exit, 1 starting position, and 1 collectible.
- Movement counter printed in the terminal.
- Smooth window handling (ESC closes, clicking the window’s close button quits).

### Bonus
Want to make the game more fun? You can add:
- **Enemies/patrols** that the player must avoid.
- **Sprite animations** for characters, collectibles, or enemies.
- **On-screen movement counter** (instead of printing it to terminal).

---

## Installation

This project requires the **MiniLibX** graphics library.

Clone the repository and also fetch **MiniLibX** inside the project folder:

```bash
git clone https://github.com/your-username/so_long.git
cd so_long

# Clone MiniLibX (Linux version, or macOS depending on your setup)
git clone https://github.com/42Paris/minilibx-linux.git minilibx

# Build MiniLibX manually
cd minilibx
./configure
cd ..

---

### Usage

```bash
make
./so_long maps/example.ber
