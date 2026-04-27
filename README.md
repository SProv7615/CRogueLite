# CRogueLite

CRogueLite is a small, extendable console-based roguelite demo written in C++. The project is intended to be an introduction to C++ to enable the ability to iterate on gameplay, UI, and architecture.

## Elevator Pitch
Navigate a simple dungeon through a text-based UI. Explore, manage a party (of up to 4 members), and make choices through clearly structured menus. The demo will focus on clean code, easy extensibility, and a focus on clear presentation.

## Core Gameplay Loop
- Start at the main menu.
- Choosing 'Play' opens the 'Play' menu where a new run can be started.
- Choosing 'Load' opens a Loading Screen where an old run can be continued.
- In a full game, 'Play' will lead to a dungeon loop: generate a level → present options (move, inspect, inventory, fight, flee) → resolve player action → update world and render → repeat until death/victory/exit.
- Menus will return Booleans to indicate navigation/combat.

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

## Controls
- Keyboard input via the console.
- Numeric menu choices

## Navigation model
- To Be Developed

## Project Structure
- To Be Developed

## Technical Notes
- To Be Decided

## How to Run
- To Be Developed

## Unit Tests
- To Be Developed

## Roadmap
- To Be Pulled from ROADMAP.md

## Contribution
- Open a PR for any feature or bugfix.
- Keep changes small and focused; prefer single-responsibility commits.
- Write unit tests for non-UI logic where feasible.

## Notes for development
- To Be Developed

<-- Back to [Top](#croguelite)



