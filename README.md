# 🎲 Horrified 👻

> A thrilling C++ terminal board game adventure! 

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-17-blue.svg" alt="C++17"/>
  <img src="https://img.shields.io/badge/License-GPLv3-blue.svg" alt="GPLv3"/>

</p>

---

## Contents

1. [✨ Features](#-features)
2. [⚡ Installation](#-installation)
3. [🕹️ Usage](#-usage)
4. [📦 Dependencies](#-dependencies)
5. [📝 License](#-license)
6. [🤝 Collaborators](#-collaborators)
7. [🚀 Contributing](#-contributing)
8. [🙏 Acknowledgements](#-acknowledgements)

---

## 🕹️ About the Game

**Horrified** is a thrilling, cooperative terminal-based board game adventure where you and your friends take on the roles of classic heroes racing against time to save a small town from legendary monsters. Drawing inspiration from classic horror films, each scenario pits you against iconic creatures — Dracula, The Wolf Man, The Mummy, The Invisible Man, and more — each with its own unique abilities and terrorizing effects.

- **Cooperative Gameplay:** Work together with up to 5 players. Share resources, coordinate actions, and strategize each turn to thwart the monsters’ sinister plans before they unleash chaos upon the town.
- **Dynamic Monster AI:** Each monster follows its own AI-driven behavior. One might stalk the town’s edges, while another unleashes frenzy at every opportunity. You’ll need to adapt your tactics as the creatures pursue different objectives.
- **Modular Map & Events:** The map is composed of reusable tiles representing different locations (e.g., town square, graveyard, forest edge). Randomized event cards keep each playthrough fresh, presenting new challenges and surprises every time you start.
- **Hero Abilities & Upgrades:** Choose from a roster of heroic characters, each with distinct strengths and special powers. As the game progresses, you can collect items and power‑ups that enhance your skills — from holy water to silver bullets.
- **Tension & Theme:** With a creeping sense of dread built into every turn, Horrified captures the spirit of classic monster movies. Will you manage to seal away the evil forces in time, or will the horrors overwhelm the town?

Whether you’re a fan of cooperative challenges, classic horror, or strategic board games, **Horrified** delivers an immersive, high-stakes experience you can enjoy right in your terminal. Rally your friends, sharpen your wits, and prepare for a night of monstrous mayhem!  

---

# Prerequisites

-  C++ compiler (C++20  at least needed)
-  CMake as a recomended build system
-  [ftxui library](https://github.com/ArthurSonzogni/FTXUI) (installation guide on the link)
-  recommended os (linux)

# Installation guide:



1. **Clone the repository:**
   ```sh
   git clone https://codeberg.org/Ali_kermani/horrified_board_game
   cd horrified_board_game
   mkdir build
   cd build
   cmake ..
   make
   .app


## 🕹️ Usage

```sh
use the Arrow keys to navigate the menu and double enter on selected part
```

---

## 📦 Note:

Recommended to intall the **ftxui** library as the owner described  
after the installation of the library 


## 📝 License

This project is licensed under the [GNU General Public License v3.0 (GPLv3)](LICENSE).

---

## 🤝 Collaborators

- 👤 [**Taha Sadeghi**](https://codeberg.org/Taha_Sadeghi) -> 40312358025
- 👤 [**Shahriar Kolivand**](https://codeberg.org/imShahriar-klvd) ->40312358035

---

## 🚀 Contributing

Contributions are welcome! Please open issues or pull requests for bug fixes, improvements, or new features.

---

## 🙏 Acknowledgements

- 🎲 Inspired by the "Horrified" board game.
- 🧑‍💻 Uses [fmt](https://github.com/fmtlib/fmt) for formatting.
- 📊 Table rendering and some utility code based on [tabulate](https://github.com/p-ranav/tabulate) (MIT License).

---

> **Enjoy the game! But be careful monsters are around us 👾**
