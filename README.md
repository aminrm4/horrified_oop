# 🎲 Horrified Board Game 👻

> A thrilling cooperative C++ board game adventure where heroes battle classic monsters to save a small town from darkness!

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-20-blue.svg" alt="C++20"/>
  <img src="https://img.shields.io/badge/SFML-2.5+-green.svg" alt="SFML"/>
  <img src="https://img.shields.io/badge/CMake-3.11+-orange.svg" alt="CMake"/>
  <img src="https://img.shields.io/badge/License-Educational-brightgreen.svg" alt="License"/>
</p>

---

## 🎮 About the Game

**Horrified** is an immersive cooperative board game experience built in C++ that brings classic horror monsters to life on your screen. Players take on the roles of heroic characters racing against time to save a small town from legendary creatures like Dracula, The Invisible Man, and other iconic monsters.

This project demonstrates advanced C++ programming concepts including:

- **Object-Oriented Design** with inheritance and polymorphism
- **Game State Management** with save/load functionality
- **Graphics Programming** using SFML
- **Algorithm Implementation** (BFS pathfinding, game logic)
- **Memory Management** and resource handling

### 🖼️ Game Screenshots

#### 🎯 Main Menu

![Main Menu](Horrified_Assets/extra_assets/monster_cards.png)
_The atmospheric main menu featuring the game title with blood-like drips and shadowy monster figures_

#### 🗺️ Game Board

![Game Board](Horrified_Assets/extra_assets/main_menu.png)
_The interactive game board showing locations, characters, and the terror track_

#### 🃏 Monster Cards

![Monster Cards](Horrified_Assets/extra_assets/game_board.png)
_Collection of monster action cards that dictate game events and monster behavior_

---

## 🎯 Game Features

### 🎮 Core Gameplay

- **🏃‍♂️ Cooperative Experience:** Work together with up to 5 players to defeat monsters before they unleash chaos
- **👹 Dynamic Monster AI:** Each monster has unique abilities and behavior patterns that adapt throughout the game
- **🗺️ Modular Map System:** Explore a town with multiple locations, each offering different strategic opportunities
- **⚔️ Hero Abilities & Items:** Choose from various heroes with special powers and collect items to enhance your capabilities

### 🛠️ Technical Features

- **🎲 Perk System:** Unlock and use special perks that provide strategic advantages
- **💾 Save/Load System:** Save your progress and continue your adventure later
- **🎵 Audio Experience:** Immersive sound effects and background music
- **🎨 Rich Visual Assets:** Beautiful graphics and animations using SFML
- **🔍 Pathfinding:** Intelligent monster movement using BFS algorithm
- **📊 Game State Management:** Comprehensive save/load system for multiple save slots

---

## 🎪 Game Mechanics

### 🎲 Turn-Based Strategy

- **Action Points:** Each hero has limited actions per turn - plan carefully!
- **Movement System:** Navigate between locations on the map strategically
- **Combat Resolution:** Engage monsters with items, perks, and special abilities

### 🏘️ Location-Based Gameplay

- **Strategic Positioning:** Different locations offer unique opportunities and challenges
- **Resource Collection:** Gather items and perks from various town locations
- **Villager Protection:** Rescue innocent townspeople from monster attacks

### 👻 Monster Behavior

- **Frenzy System:** Monsters become more dangerous as the game progresses
- **AI Movement:** Intelligent pathfinding and behavior patterns
- **Special Abilities:** Each monster has unique powers and weaknesses

---

## 🛠️ Prerequisites

Before building the game, ensure you have the following installed:

- **C++20 compatible compiler** (GCC 10+ or Clang 12+)
- **CMake 3.11 or higher**
- **SFML 2.5+** (Graphics, Window, System, and Audio modules)
- **Linux OS** (recommended for best compatibility)

### 📦 Installing Dependencies

#### Ubuntu/Debian:

```bash
sudo apt update
sudo apt install build-essential cmake libsfml-dev
```

#### Arch Linux:

```bash
sudo pacman -S base-devel cmake sfml
```

#### Fedora:

```bash
sudo dnf install gcc-c++ cmake SFML-devel
```

---

## 🚀 Installation & Build

### 1. Clone the Repository

```bash
git clone https://github.com/SSCBasu/horrified_board_game
cd horrified_board_game
```

### 2. Build the Project

```bash
mkdir build
cd build
cmake ..
make -j$(nproc)
```

### 3. Run the Game

```bash
./app
```

---

## 🎮 How to Play

### 🎯 Basic Controls

- **Arrow Keys:** Navigate menus and move around the game
- **Enter:** Select options and confirm actions
- **Double Enter:** Execute selected actions

### 🎪 Game Setup

1. **Choose Your Hero:** Select from available characters with unique abilities
2. **Select Monsters:** Choose which monsters to face in your adventure
3. **Plan Your Strategy:** Coordinate with other players to defeat the monsters

### 🎲 Gameplay

- **Movement:** Navigate between locations on the map
- **Actions:** Perform special abilities, collect items, and fight monsters
- **Cooperation:** Work with other players to achieve victory
- **Time Management:** Complete objectives before monsters overwhelm the town

### 🏆 Victory Conditions

- Defeat all selected monsters
- Protect villagers from harm
- Complete monster-specific objectives

### 💀 Defeat Conditions

- All heroes are defeated
- Monsters achieve their sinister goals
- Town is overrun by darkness

---

## 🏗️ Project Architecture

### 📁 Directory Structure

```
horrified_board_game/
├── src/                    # Source files
│   ├── main.cpp           # Entry point and game loop
│   ├── programm.cpp       # Main game logic and state management
│   ├── hero.cpp           # Hero class implementations
│   ├── monster.cpp        # Monster class implementations
│   ├── location.cpp       # Location and map management
│   ├── item.cpp           # Item system implementation
│   ├── perk.cpp           # Perk and ability system
│   ├── villager.cpp       # NPC and villager management
│   ├── free_func.cpp      # Utility functions and helpers
│   ├── load_game.cpp      # Save/load system
│   ├── hint.cpp           # Game help and tutorial system
│   ├── starting_menu.cpp  # Main menu interface
│   └── ...                # Additional game components
├── include/               # Header files
│   ├── hero.hpp           # Hero class definitions
│   ├── monster.hpp        # Monster class definitions
│   ├── location.hpp       # Location class definitions
│   ├── programm.hpp       # Main game class definitions
│   └── ...                # Other headers
├── Horrified_Assets/      # Game assets
│   ├── Heros/            # Hero character sprites
│   ├── Monsters/         # Monster sprites
│   ├── Items/            # Item graphics
│   └── extra_assets/     # UI and menu assets
├── sounds/               # Audio files
├── save1/ - save5/       # Save game directories
├── build/                # Build output directory
├── CMakeLists.txt        # Build configuration
└── horrified_uml.puml   # UML class diagram
```

### 🏛️ Class Architecture

#### Core Game Classes

- **`programm`**: Main game controller managing game state, monsters, and heroes
- **`hero`**: Abstract base class for all playable characters
- **`monster`**: Abstract base class for all enemy entities
- **`location`**: Represents game board locations with items, NPCs, and monsters
- **`item`**: Collectible objects that provide benefits
- **`perk`**: Special abilities and bonuses

#### Hero Implementations

- **`Archaeologist`**: Expert in ancient artifacts and monster lore
- **`Courier`**: Fast movement and delivery abilities
- **`Mayor`**: Leadership skills and town influence
- **`Scientist`**: Advanced research and item creation
- **`Thief`**: Stealth and lockpicking abilities
- **`The_Innocent`**: Special survivor mechanics

#### Monster Implementations

- **`Drakula`**: Classic vampire with hypnotic powers
- **`Invisible_man`**: Stealth and surprise attacks
- **`form_of_the_bat`**: Shapeshifting abilities
- **`The_chthyologist`**: Aquatic monster with water-based powers

---

## 🎭 Game Characters

### 🦸‍♂️ Heroes

Each hero has unique abilities and starting perks:

- **Archaeologist:** Expert in ancient artifacts and monster lore
- **Courier:** Fast movement and delivery abilities
- **Mayor:** Leadership skills and town influence
- **Scientist:** Advanced research and item creation
- **Thief:** Stealth and lockpicking abilities
- **The Innocent:** Special survivor mechanics

### 👹 Monsters

Each monster presents unique challenges:

- **Dracula:** Classic vampire with hypnotic powers
- **Invisible Man:** Stealth and surprise attacks
- **Form of the Bat:** Shapeshifting abilities
- **The Ichthyologist:** Aquatic monster with water-based powers

### 🏘️ Villagers

Protect these innocent townspeople:

- **Dr. Cranly:** Town doctor with medical knowledge
- **Dr. Reed:** Scientific expertise
- **Fritz:** Local handyman
- **Maleva:** Mysterious fortune teller
- **Maria:** Innocent town resident
- **Prof. Pearson:** Academic knowledge
- **Wilbur and Chick:** Local farmers

---

## 🛠️ Development

### 🔧 Building for Development

For development with VS Code, the project includes a `.vscode/` directory with configuration files for IntelliSense and debugging.

### 🐛 Debugging Tips

- Use `Ctrl+Shift+P` and reset IntelliSense database if needed
- Check console output for error messages
- Verify SFML installation with `pkg-config --modversion sfml-all`
- Use the included UML diagram for understanding class relationships

### 📊 UML Diagram

The project includes a comprehensive UML class diagram:

- **File:** `horrified_uml.puml`
- **Visual:** `uml.drawio.png`
- **Tool:** PlantUML compatible

---

## 🤝 Contributing

We welcome contributions! Please feel free to submit issues, feature requests, or pull requests.

### 🐛 Reporting Bugs

- Use the issue tracker to report bugs
- Include detailed steps to reproduce the issue
- Provide system information and error messages

### 💡 Feature Requests

- Describe the feature you'd like to see
- Explain how it would improve the game
- Consider implementation complexity

### 🔧 Development Guidelines

- Follow the existing code style and architecture
- Add appropriate header documentation
- Test your changes thoroughly
- Update the UML diagram if adding new classes

---

## 📝 License

This project is licensed under the **Basu University Computer Engineering Department** as an advanced programming project.

For more information, visit: [https://github.com/SSCBasu](https://github.com/SSCBasu)

---

## 👥 Collaborators

- 👤 **[Ali Kermani](https://codeberg.org/Ali_kermani)** - 40312358032
- 👤 **[Amin Rahimi Mehrnia](https://codeberg.org/aminrm4)** - 40312358013

---

## 🙏 Acknowledgements

- **SFML Team** for the excellent multimedia library
- **Basu University** for educational support and guidance
- **Open Source Community** for inspiration and tools
- **Game Design Community** for board game mechanics inspiration

---

## 📞 Support

If you encounter any issues or have questions:

1. Check the [Issues](https://github.com/SSCBasu/horrified_board_game/issues) page
2. Review the installation requirements
3. Ensure all dependencies are properly installed
4. Contact the development team

---

## 🎯 Future Enhancements

### 🚀 Planned Features

- **Multiplayer Support:** Network-based cooperative gameplay
- **Additional Monsters:** More classic horror creatures
- **Enhanced Graphics:** Improved visual effects and animations
- **Sound Design:** More immersive audio experience
- **Mobile Support:** Cross-platform compatibility

### 🔧 Technical Improvements

- **Performance Optimization:** Better memory management and rendering
- **Mod Support:** User-created content and modifications
- **AI Enhancement:** More sophisticated monster behavior
- **Accessibility:** Better UI for different user needs

---

**🎮 Ready to face the horrors? Start your adventure now!**

<p align="center">
  <em>Built with ❤️ by Computer Engineering students at Basu University</em>
</p>
