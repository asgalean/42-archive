# Push Swap

*This project has been created as part of the 42 curriculum by asgalean.*

---

## Description

push_swap takes a list of integers and sorts them using two stacks (`a` and `b`) and a fixed set of operations, aiming to do it in as few moves as possible. The program prints the sequence of operations needed to leave stack `a` sorted in ascending order with stack `b` empty.

Key features:
- Custom doubly linked list to represent each stack (`t_node`, with `prev`/`next` pointers)
- Input accepted either as a single quoted string of numbers (`./push_swap "1 2 3"`) or as separate arguments (`./push_swap 1 2 3`)
- Full input validation: duplicate detection, integer overflow checks, and a no-op exit if the input is already sorted
- Specialized hand-written sorts for small stacks (3, 4, and 5 elements) that compute the minimum-move sequence directly
- A radix sort for larger stacks: each value is given a rank (`radix_index`), then sorted bit by bit by rotating or pushing into stack `b` and back, in `O(n × log₂n)` operations
- Bundled `ft_printf` for output

---------------

## Instructions

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
./push_swap 4 67 3 87 23
```

or, with a single string argument:

```bash
./push_swap "4 67 3 87 23"
```

Output is the list of operations to perform on the stacks, one per line:

```
pb
sa
ra
...
```

To check the result against a checker program (`pa`, `pb`, `sa`, `sb`, `ra`, `rb`, `rra`, `rrb`):

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker_linux $ARG
```
