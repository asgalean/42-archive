# 42 Archive

A consolidated archive of projects from the 42 core curriculum (42 Urduliz Bizkaia), brought together into a single repository with `git subtree` so each project keeps its full original commit history.

| Project | Description |
|---|---|
| [`minishell`](./minishell) | A custom Unix shell in C — parser, command tree, pipes, redirections, built-ins, signal handling. Partner project with cvon-hee. |
| [`philosophers`](./philosophers) | The Dining Philosophers problem, solved with POSIX threads and mutexes. |
| [`push-swap`](./push-swap) | Sorts a stack of integers using two stacks and a minimal set of operations, with a radix sort for larger inputs. |
| [`so-long`](./so-long) | A 2D top-down game built with MiniLibX — map parsing, sprite animation, collectibles. |
| [`cub3d`](./cub3d) | A first-person raycasting engine inspired by Wolfenstein 3D, using MLX42. Partner project with mcuello. |
| [`cpp`](./cpp) | The C++ module series (work in progress). |

Each project has its own `README.md` with a full description, build instructions, and usage. `cpp` is still in progress and isn't documented yet.

---

## Working in this repo

Since each project was added with `git subtree add --prefix=<name> <original-repo> <branch>`, you can keep editing files directly inside each folder as part of this monorepo. If you ever want to sync changes back to (or pull updates from) one of the original individual repos:

```bash
# push local changes in a subfolder back to its original repo
git subtree push --prefix=<name> <original-repo-url> <branch>

# pull updates from the original repo into this monorepo
git subtree pull --prefix=<name> <original-repo-url> <branch>
```
