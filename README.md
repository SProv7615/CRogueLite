# CRogueLite

CRogueLite is a small, extendable console-based roguelite demo written in C++. The project is intended to be an introduction to C++ to enable the ability to iterate on gameplay, UI, and architecture.

---
## Contents
- [Elevator Pitch](#elevator-pitch)
- [Core Gameplay Loop](#core-gameplay-loop)
- [Features (Planned)](#features-planned)
- [Controls](#controls)
- [Navigation model](#navigation-model)
- [Project Structure](#project-structure)
- [Technical Notes](#technical-notes)
- [How to Run](#how-to-run)
- [Unit Tests](#unit-tests)
- [Project Roadmap](#project-roadmap)
- [Contributions](#contributions)
- [Notes for development](#notes-for-development)

---
## Elevator Pitch
Navigate a simple dungeon through a text-based UI. Explore, manage a party (of up to 4 members), and make choices through clearly structured menus. The demo will focus on clean code, easy extensibility, and a focus on clear presentation.

[Table of Contents](#contents)

---
## Core Gameplay Loop
- Start at the main menu.
- Choosing 'Play' opens the 'Play' menu where a new run can be started.
- Choosing 'Load' opens a Loading Screen where an old run can be continued.
- In a full game, 'Play' will lead to a dungeon loop: generate a level → present options (move, inspect, inventory, fight, flee) → resolve player action → update world and render → repeat until death/victory/exit.
- Menus will return Booleans to indicate navigation/combat.

[Table of Contents](#contents)

---
## Features (Planned)
- Clean console UI
- Text wrapping and formatting
- Input capture
- Menu system
- Player stats, simple combat, inventory
- Persistent saves
- Difficulty choices
- Additional menus (skills, character, options)
- Roguelite element (Unlock buildings, additional character-types, for future playthroughs)

[Table of Contents](#contents)

---
## Controls
- Keyboard input via the console.
- Numeric menu choices

[Table of Contents](#contents)

---
## Navigation model
- To Be Developed

[Table of Contents](#contents)

---
## Project Structure
- To Be Developed

[Table of Contents](#contents)

---
## Technical Notes
- To Be Decided

[Table of Contents](#contents)

---
## How to Run
- To Be Developed

[Table of Contents](#contents)

---
## Unit Tests
- To Be Developed

[Table of Contents](#contents)

---
## Project Roadmap
- Go to project [ROADMAP.md](ROADMAP.md)

[Table of Contents](#contents)

---
## Contributions
- Open a PR for any feature or bugfix.
- Keep changes small and focused; prefer single-responsibility commits.
- Write unit tests for non-UI logic where feasible.

[Table of Contents](#contents) 

---
## Notes for development
- To Be Developed

Go to [Top](#croguelite)



