# so_long

[![C](https://img.shields.io/badge/C-00599C?style=flat-square&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Makefile](https://img.shields.io/badge/Makefile-000000?style=flat-square&logo=gnu&logoColor=white)](https://www.gnu.org/software/make/)
[![MiniLibX](https://img.shields.io/badge/MiniLibX-1E1E1E?style=flat-square)](https://harm-smits.github.io/42docs/libs/minilibx)
[![Libft](https://img.shields.io/badge/Libft-4B8BBE?style=flat-square)](libft/)
[![Linux](https://img.shields.io/badge/Linux-FCC624?style=flat-square&logo=linux&logoColor=black)](https://www.linux.org/)

## Description
`so_long` is a small 2D game written in C for the 42 curriculum. The goal is to move the player through a tile-based map, collect every collectible, and then reach the exit. The project focuses on MiniLibX usage, image rendering, event handling, map parsing, and path validation.

This repository contains the mandatory part of the project:
- loading and displaying a `.ber` map
- validating the map structure and its reachable path
- moving the player with the keyboard
- printing the movement count in the shell
- closing the window cleanly with `ESC` or the window close button

## Project Structure

```text
.
├── img/
│   ├── 0.xpm
│   ├── 1.xpm
│   ├── c.xpm
│   ├── e.xpm
│   └── p.xpm
├── include/
│   └── so_long.h
├── libft/
│   ├── include/
│   │   ├── ft_printf.h
│   │   ├── get_next_line.h
│   │   └── libft.h
│   ├── Makefile
│   └── src/
│       ├── ft_printf/
│       │   ├── ft_printf.c
│       │   ├── output.c
│       │   ├── print_hex.c
│       │   ├── print_ptr.c
│       │   └── unsigned_itoa.c
│       ├── gnl/
│       │   ├── get_next_line.c
│       │   └── get_next_line_utils.c
│       └── std_libft/
│           ├── ctype/
│           ├── error/
│           ├── fd/
│           ├── lst/
│           ├── mem/
│           ├── stdlib/
│           └── str/
├── Makefile
├── map/
│   ├── map.ber
│   ├── maze.ber
│   └── test.ber
├── minilibx/
├── README.md
└── src/
	├── game.c
	├── img.c
	├── main.c
	├── map.c
	├── move.c
	└── window.c
```

## Instructions

### Requirements
- Linux environment
- `cc`, `make`, and the dependencies needed by MiniLibX on your system
- the included `libft` and MiniLibX sources in this repository

### Build
From the repository root:

```bash
make
```

This compiles `libft`, builds the MiniLibX static library, and links the `so_long` executable.

Useful targets:

```bash
make clean
make fclean
make re
make norm
make leak
```

### Run
Launch the game with a valid `.ber` map file:

```bash
./so_long maps/map.ber
```

Other sample maps are available in `maps/`.

### Controls
- Arrow keys: move the player
- `ESC`: close the game cleanly
- Window close button: close the game cleanly

### Map rules
A valid map must:
- be rectangular
- be surrounded by walls
- contain exactly 1 player start `P`
- contain exactly 1 exit `E`
- contain at least 1 collectible `C`
- use only these characters: `0`, `1`, `C`, `E`, `P`
- have a valid path so that all collectibles can be reached and the exit remains reachable after collecting them

## Resources
- 42 subject: So Long
- MiniLibX documentation and examples from the school environment
- X11 / Linux graphics documentation
- `libft` and `get_next_line` references from the 42 curriculum
- Breadth-first search / flood fill references for map validation

### AI usage
AI was used to rewrite and structure this README, align the instructions with the current codebase, and improve clarity. The implementation, build flow, and project-specific details were verified against the repository files.
