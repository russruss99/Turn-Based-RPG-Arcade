# FinalProject: Text-Based Battle Game Version 1.0

A turn-based, console RPG written in C++. You lead a small party through three waves of enemies and a final boss fight, choosing your attacks each turn while your allies fight alongside you.

## Features

- Two difficulty modes (Normal and Hard)
- Three waves of enemies followed by a final boss battle
- A hero plus two AI-assisted allies
- Light attacks, heavy attacks, and item use each turn
- Shield reinforcement option in the first wave
- Rewards and a shop between waves, and ally health upgrades after each wave
- Boss with special moves (light, heavy, barrage, and self-heal)

## Project Structure

| File | Purpose |
|------|---------|
| `FinalProject.sln` | Visual Studio solution file |
| `main.cpp` | Game flow, combat loops, and the final boss fight |
| `Warrior.h` | Player and ally class (hero, allies) |
| `Evil.h` | Standard enemy class |
| `Warlord.h` | Boss class (derived from `Evil`) |

### How `main.cpp` is organized

- `run_wave()` runs one wave of combat. It is reused for Waves I-III.
- `run_boss_fight()` handles the final battle, which has extra boss moves and a second enemy.
- Small helpers (`prompt_choice`, `show_party`, `list_enemies`, `remove_dead`) handle input validation, display, and cleanup of defeated enemies.

## Building and Running

**Requirements:** Visual Studio (with the "Desktop development with C++" workload) and a C++11 or later compiler.

1. Open `FinalProject.sln` in Visual Studio.
2. Make sure `main.cpp`, `Warrior.h`, `Evil.h`, and `Warlord.h` are all part of the project.
3. Build the solution (**Ctrl+Shift+B**).
4. Run it (**Ctrl+F5**) to launch the game in a console window.

## How to Play

### Starting the game

You are first asked to choose a difficulty:

- `0`: Normal (start with a Shortsword)
- `1`: Hard (start with a Broadsword, but enemies have extra health)

### Your party

| Character | Health | Weapon |
|-----------|--------|--------|
| Russ (you) | 100 | Shortsword / Broadsword |
| Reed (ally) | 400 | Battle Axe |
| Royce (ally) | 400 | Glaive |

### Each turn

1. **Pick an opponent** from the numbered list of enemies.
2. **Pick an action:**
   - `1`: Light Attack
   - `2`: Heavy Attack
   - `3`: Use Item
   - `4`: Reinforce (shield, available in Wave I only)
3. **Your allies attack.** You choose each ally's target.
4. **The enemies attack** you or your allies.

Defeated enemies are removed from the fight. A wave ends when every enemy in it has been defeated.

### Waves

| Stage | Enemies | Base Health (each) | Extra Health on Hard |
|-------|---------|--------------------|----------------------|
| Wave I: Entrance | 5 | 100 | +100 |
| Wave II: Main Corridor | 4 | 200 | +250 |
| Wave III: Dining Hall | 3 | 500 | +500 |
| Final Boss | Unruly Emperor (2000 HP) and Conniving Schemer (900 HP, +500 on Hard) | n/a | n/a |

After each of the first three waves you receive rewards, get a chance to make purchases, and your allies' health is upgraded.

### Winning

Defeat the final boss to win the game.

## Notes

- Invalid or non-numeric input is rejected and you are asked to try again.
- Enemy and ally attack styles are decided by a random roll at the start of the game.
- Enemies are stored in `std::vector` containers and freed with `delete` as they are defeated, and the allies and boss are freed when the game ends.
