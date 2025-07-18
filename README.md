# 🐝 Buzz Bombers – C++ SFML Game Project

A first-semester game development project built using **C++** and **SFML**. This version captures the core mechanics and brings them to life with smooth controls, multiple levels, and an engaging arcade-style gameplay loop.

---

## Game Objective

Control a **spray can** to defend your garden from waves of bees. Spray them before they pollinate flowers and trap you. Sprayed bees turn into honeycombs, which your friendly hummingbird collects for bonus points.

Survive waves, collect honeycombs, avoid killer bees, and keep your spray levels in check!

---

## 🕹️ Features

- Spray bees (worker and killer bees) before they reach the ground and pollinate flowers.
- Worker bees (yellow) turn into **yellow honeycombs**; Killer bees (white) turn into **red honeycombs**.
- Sprayed bees drop honeycombs that earn you more points when collected by the hummingbird.
- **3 Levels of Increasing Difficulty**:
  - **Level 1**: 20 Worker Bees, 3 Honeycombs
  - **Level 2**: 15 Worker Bees + 5 Killer Bees, 9 Honeycombs
  - **Level 3**: 20 Worker Bees + 10 Killer Bees, 15 Honeycombs
- Unique background and music for each level.
- Player starts with 3 spray cans; each can contains 56 sprays.
- Spray can visually indicates remaining spray level.
- Spray is automatically refilled at the start of a new level.
- Bees move in tiers, changing direction when hitting screen edges or bouncing off honeycombs.
- Killer bees are faster and more challenging.
- Pollination by bees causes flowers to grow and can trap your spray can.
- If your can is completely trapped, you lose a life and restart the level.
- **Hummingbird** collects honeycombs for bonus points:
  - Becomes sick and leaves temporarily if sprayed too much.
- **Beehives** are formed when a worker bee is trapped:
  - Beehives give extra points if preserved until level ends.
- **Flowers** grow randomly from sides or center, altering player movement area.
- Menu system at the start of the game.

---

## ✅ Prerequisites

To compile and run this project:

- C++ Compiler (G++ or MSVC)
- [SFML 2.5+](https://www.sfml-dev.org/download.php)
- Git (for cloning)
- CMake or Make (optional for easier build)

### 📦 Install SFML

#### On Windows:
1. Download from [SFML Downloads](https://www.sfml-dev.org/download.php)
2. Set up SFML in your IDE (Visual Studio or Code::Blocks)
3. Link the required SFML libraries:
   - `sfml-graphics`
   - `sfml-window`
   - `sfml-system`
   - `sfml-audio`

#### On Linux (Ubuntu/Debian):
```bash
sudo apt update
sudo apt install libsfml-dev
```
## 👨‍💻 Author

**Muhammad Tayyab**  
FAST NUCES – School of Computing  
First Semester C++ Project
