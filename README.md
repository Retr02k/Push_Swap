*This project has been created as part of the 42 curriculum by psilva-p.*

# Push_Swap

## Description
Push_Swap is a 42 sorting project where the objective is to sort a list of integers using two stacks (`a` and `b`) and a limited set of operations.

The goal is to:
- validate inputs (invalid tokens, overflows, duplicates, edge cases)
- assign each value an index (rank)
- sort efficiently with stack operations while minimizing instruction count

This implementation uses:
- dedicated logic for very small inputs (size <= 5)
- index-based radix sort for larger inputs

## Instructions
### Prerequisites
- `cc` compiler
- `make`
- Unix-like shell (macOS/Linux)

### Compilation
From the project root:

```bash
make
```

Useful targets:

```bash
make re
make clean
make fclean
```

### Execution
Run with integer arguments:

```bash
./push_swap 3 2 1
```

If the input is invalid, the program writes `Error` to stderr.

### Optional local testing
If you have a checker binary/script available:

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker_OS $ARG
```

## Technical Choices
- Data structure: circular doubly linked lists for stacks
- Input parsing: custom `ps_atoi` with overflow and token validation
- Duplicate detection: check on extracted values
- Indexing: values mapped to sorted rank before sorting
- Sorting strategy:
  - small sort for up to 5 numbers
  - radix pass by bit on indices for larger sets

## Resources
### References
- Peer discussions and guidance were my main resource for this project.
- 42 subject and intra project documentation
- C standard library reference (man pages)

### AI Usage
AI was used in a limited way, mainly for:
- occasional sanity checks on edge cases
- light README/commit message wording support

Core implementation, debugging, and final decisions were driven by my own work and peer feedback.
