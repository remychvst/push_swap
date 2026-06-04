*This activity has been created as part of the 42 curriculum by rchavast and yaaguerd.*

# Push_swap

## Description

Push_swap is an algorithmic sorting project from the 42 curriculum.

The objective is to sort a list of integers using two stacks (`a` and `b`) and a restricted set of stack operations while generating a valid sequence of instructions.

The project focuses on:

* Algorithms
* Complexity analysis
* Stack manipulation
* Data structures
* Sorting optimization
* Performance evaluation

The program receives integers as arguments and outputs the operations required to sort stack `a` in ascending order.

---

## Compilation

```bash
make
```

Available rules:

```bash
make
make clean
make fclean
make re
```

---

## Usage

### Default adaptive mode

```bash
./push_swap 4 67 3 87 23
```

### Force a strategy

```bash
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1
```

### Benchmark mode

```bash
./push_swap --bench --adaptive 4 67 3 87 23
```

Benchmark information is printed on stderr.

---

## Allowed Operations

### Swap

| Instruction | Description                            |
| ----------- | -------------------------------------- |
| sa          | Swap the first two elements of stack a |
| sb          | Swap the first two elements of stack b |
| ss          | Execute sa and sb simultaneously       |

### Push

| Instruction | Description                                  |
| ----------- | -------------------------------------------- |
| pa          | Push the top element from stack b to stack a |
| pb          | Push the top element from stack a to stack b |

### Rotate

| Instruction | Description                      |
| ----------- | -------------------------------- |
| ra          | Rotate stack a upward            |
| rb          | Rotate stack b upward            |
| rr          | Execute ra and rb simultaneously |

### Reverse Rotate

| Instruction | Description                        |
| ----------- | ---------------------------------- |
| rra         | Reverse rotate stack a             |
| rrb         | Reverse rotate stack b             |
| rrr         | Execute rra and rrb simultaneously |

---

## Implemented Strategies

### Small Sort

Dedicated sorting routines are used for:

* 2 numbers
* 3 numbers
* 5 numbers

---

### Simple Strategy — O(n²)

The simple strategy repeatedly moves the smallest indexed element to stack `b` and rebuilds stack `a`.

---

### Medium Strategy — O(n√n)

The medium strategy provides an intermediate sorting mode.

---

### Complex Strategy — O(n log n)

The complex strategy uses Binary Radix Sort.

Steps:

1. Normalize values by assigning indexes
2. Process indexes bit by bit
3. Move elements between stacks according to the current bit
4. Rebuild stack `a`

---

### Adaptive Strategy

Adaptive mode automatically selects the sorting strategy according to the initial disorder of the stack.

Disorder values:

| Disorder        | Interpretation       |
| --------------- | -------------------- |
| 0.00            | Already sorted       |
| 1.00            | Completely reversed  |
| Between 0 and 1 | Partially disordered |

Adaptive mode is used when no strategy flag is provided.

---

## Benchmark Mode

The option:

```bash
--bench
```

displays:

* Initial disorder
* Selected strategy
* Theoretical complexity
* Total number of operations

Example:

```bash
./push_swap --bench --adaptive 4 67 3 87 23
```

---

## Error Handling

The program prints:

```txt
Error
```

when:

* Invalid arguments are provided
* Integers exceed the valid range
* Duplicate values are detected
* Parsing fails
* Unknown options are used

If no argument is provided, the program exits silently.

---

## Performance

Typical operation counts:

| Numbers | Operations |
| ------- | ---------- |
| 3       | ≤ 3        |
| 5       | ≤ 12       |
| 100     | ~700–1100  |
| 500     | ~5500–7000 |

---

## Project Structure

```txt
.
├── Makefile
├── push_swap.h
├── main.c
├── option.c
├── parsing.c
├── init_stack.c
├── stack_utils.c
├── stack_utils2.c
├── disorder.c
├── bench.c
├── sa_sb_ss.c
├── pa_pb.c
├── ra_rb_rr.c
├── rra_rrb_rrr.c
├── small_sort.c
├── simple_sort.c
├── medium_sort.c
├── radix_sort.c
├── sort.c
├── split.c
├── free.c
└── utils.c
```

---

## Learning Outcomes

Through this project we developed skills in:

* Stack manipulation
* Sorting algorithms
* Algorithmic optimization
* Complexity analysis
* Memory management
* Modular programming
* Performance-oriented development
* Debugging and testing

---

## Resources

* 42 Push_swap subject
* Linux man pages
* Big-O complexity documentation
* Radix Sort documentation

---

## Compilation Flags

```bash
-Wall -Wextra -Werror
```

The project follows the 42 School Norm.
