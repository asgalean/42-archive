# So Long

*This project has been created as part of the 42 curriculum by asgalean.*

---

## Description

so_long is a 2D top-down game built with the classic **MiniLibX** graphics library. A map is loaded from a file, the player walks around it collecting items, and the game is won by picking up every collectible and reaching the exit. It's the first graphical project of the 42 core curriculum, focused on map parsing/validation, sprite rendering, and basic game-loop logic rather than performance.

Key features:
- `.ber` map file parser: checks rectangular shape, enclosing walls, valid tile characters, exactly one player, exactly one exit, and at least one collectible
- Flood-fill reachability check, so the map is rejected if the exit or any collectible can't actually be reached from the player's start
- Animated player sprite (idle + two-frame walk cycles for up/down/left/right)
- Animated exit tile that updates its sprite as the player collects more items (0%, 25%, 50%, 75%, 100%)
- Move counter printed to the terminal on every step
- Custom `get_next_line` and `ft_printf` bundled in for file reading and output
- Clean teardown of every image and the window on exit (`ESC`, window close button, or reaching the exit with all items collected)

---------------

## Instructions

### Requirements

- Linux with X11 (Xorg, `libxext-dev`, `libbsd-dev`)
- The [minilibx-linux](https://github.com/42Paris/minilibx-linux) graphics library, present in the `mlx/` folder at the project root

```bash
sudo apt update && sudo apt install xorg libxext-dev zlib1g-dev libbsd-dev
git clone https://github.com/42Paris/minilibx-linux mlx
```

### Compilation

```bash
make
```

```bash
make clean   # remove object files
make fclean  # remove object files + binary
make re      # full rebuild
```

### Execution

```bash
./so_long maps/easy.ber
```

A few sample maps are included in `maps/`.

### Map format (.ber)

A `.ber` map is a rectangular grid of characters, fully enclosed by walls:
- `1` — wall
- `0` — empty floor
- `P` — player start position (exactly one required)
- `C` — collectible (at least one required)
- `E` — exit (exactly one required)

### Controls

| Key | Action |
|-----|--------|
| `W` / `↑` | Move up |
| `A` / `←` | Move left |
| `S` / `↓` | Move down |
| `D` / `→` | Move right |
| `ESC` / window close button | Quit |

---------------

## Notes

The `legacy/` folder and a few loose files (`prueba2.c`, `posibles_makefiles`) are earlier experiments and aren't part of the actual build — the Makefile only compiles the files under `functions/`, `gnl_printf/`, and `so_long.c`.
