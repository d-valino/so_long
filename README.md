
# so_long

**so_long** is a small 2D game written in C as part of the 42 curriculum.

The objective is simple: collect all the collectibles and reach the exit without getting stuck.

The project focuses on basic game loops, window drawing, event handling, and memory management.

## 🚀 Features

+ 2D tile-based movement

+ Collectibles and exit logic

+ Map validation (walls, player, exit, collectibles)

+ Smooth player movement using MiniLibX

+ Clean error handling and memory management

## 📦 Installation
### Requirements

+ MiniLibX

+ Make

+ gcc / clang

### Build & Run
`git clone https://github.com/d-valino/so_long.git`

`cd so_long`

Then you can `cd mandatory` or `cd bonus`

You'll be able to play once you install the MiniLibx features.

`make` or `make bonus`

`./so_long [map file path]`

## 🗺️ Map Format

You can create your own maps using .ber files.
Allowed characters:

| Character | Meaning |
|---|---|
| 1 | Wall |
| 0	| Empty space |
| C | Collectible |
| P | Player |
| E | Exit |

A valid map must be fully surrounded by walls, contain 1 player, 1 exit, and at least one collectible.

## ⌨️ Controls

- W/A/S/D – Move

- Esc – Quit the game

## 📚 What I Learned

- Basics of 2D game rendering with MiniLibX

- Event-driven programming

- Map parsing and input validation

- Memory management and debugging leaks

- Better code organization in C
