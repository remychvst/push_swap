*This activity has been created as part of the 42 curriculum by rchavast and yaaguerd.*

# Push_swap

## Description

Push_swap is an algorithmic sorting project from the 42 curriculum.

The goal of the project is to sort a stack of integers using only the authorized Push_swap operations and two stacks (`a` and `b`).

This implementation provides four different sorting strategies:

* Simple (`O(n²)`)
* Medium (`O(n√n)`)
* Complex (`O(n log n)`)
* Adaptive (strategy selected according to measured disorder)

The project focuses on algorithmic complexity, optimization, data structures, stack manipulation, and performance analysis.

---

## Instructions

### Compilation

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

### Usage

Default adaptive mode:

```bash
./push_swap 4 67 3 87 23
```

Force a strategy:

```bash
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1
```

Benchmark mode:

```bash
./push_swap --bench --adaptive 4 67 3 87 23
```

The operation stream is printed to stdout.

Benchmark information is printed to stderr.

---

## Allowed Operations

### Swap

| Operation | Description                            |
| --------- | -------------------------------------- |
| sa        | Swap the first two elements of stack a |
| sb        | Swap the first two elements of stack b |
| ss        | Execute sa and sb simultaneously       |

### Push

| Operation | Description                                |
| --------- | ------------------------------------------ |
| pa        | Push the top element of stack b to stack a |
| pb        | Push the top element of stack a to stack b |

### Rotate

| Operation | Description                      |
| --------- | -------------------------------- |
| ra        | Rotate stack a upward            |
| rb        | Rotate stack b upward            |
| rr        | Execute ra and rb simultaneously |

### Reverse Rotate

| Operation | Description                        |
| --------- | ---------------------------------- |
| rra       | Reverse rotate stack a             |
| rrb       | Reverse rotate stack b             |
| rrr       | Execute rra and rrb simultaneously |

---

## Implemented Strategies

### Simple Strategy — O(n²)

The simple strategy is based on repeated minimum extraction.

The smallest indexed element is repeatedly moved to stack `b`, then all elements are pushed back to stack `a`.

**Justification:** This strategy provides a simple and reliable baseline. It is straightforward to implement and verify, making it a good reference point. Its O(n²) complexity in Push_swap operations comes from the fact that locating and moving each minimum requires up to O(n) rotations, repeated n times.

---

### Medium Strategy — O(n√n)

The medium strategy uses a chunk-based sorting approach.

The stack is divided into approximately √n ranges. Elements belonging to the current range are pushed to stack `b`, then pushed back to stack `a` in descending index order.

**Justification:** Dividing the input into √n chunks means each pass over stack `a` costs O(n) rotations, and there are √n passes, yielding O(n√n) total operations. This is a significant improvement over O(n²) for moderately disordered inputs and remains simple enough to implement correctly.

---

### Complex Strategy — O(n log n)

The complex strategy uses Binary Radix Sort on normalized indexes.

Steps:

1. Assign an index to each value according to its sorted position.
2. Process indexes bit by bit.
3. Move elements between stacks according to the current bit.
4. Rebuild stack `a`.

**Justification:** Radix sort on normalized indexes processes each of the log₂(n) bits with a single pass of O(n) Push_swap operations, giving O(n log n) total. This is optimal for comparison-based models and provides the best worst-case behavior for large, highly disordered inputs.

---

### Adaptive Strategy

The adaptive strategy first computes the disorder of the stack.

Disorder is defined as the ratio of inverted pairs to the maximum possible number of inversions.

Values range from:

* `0.00` → already sorted
* `1.00` → completely reversed

The adaptive strategy selects the internal method according to the measured disorder:

| Disorder               | Strategy                      |
| ---------------------- | ----------------------------- |
| disorder < 0.20        | Low strategy — O(n)           |
| 0.20 ≤ disorder < 0.50 | Medium strategy — O(n√n)      |
| disorder ≥ 0.50        | Complex strategy — O(n log n) |

**Rationale for thresholds:**

The thresholds were chosen to distinguish three structurally different input types:

* **disorder < 0.20** — Nearly sorted inputs: only a few elements are out of place. A linear scan with targeted swaps and rotations is sufficient and optimal. Applying a heavier algorithm here would waste operations.
* **0.20 ≤ disorder < 0.50** — Moderately disordered inputs: the stack has meaningful disorder but still retains partial structure. Chunk-based sorting exploits this structure efficiently at O(n√n).
* **disorder ≥ 0.50** — Highly disordered inputs: the stack is close to random or reversed. No structural shortcut is available; the full O(n log n) Radix strategy is required to meet performance targets.

This allows the program to adapt its behavior to the actual structure of the input rather than only its size.

---

## Benchmark Mode

The optional benchmark mode displays:

* Computed disorder (%)
* Selected strategy
* Complexity class
* Total operation count
* Count of each Push_swap instruction

Example:

```bash
./push_swap --bench --adaptive 4 67 3 87 23
```

Example output:

```text
[bench] disorder: 40.00%
[bench] strategy: Adaptive / O(n sqrt n)
[bench] total_ops: 13
[bench] sa: 0 sb: 0 ss: 0 pa: 5 pb: 5
[bench] ra: 2 rb: 1 rr: 0 rra: 0 rrb: 0 rrr: 0
```

---

## Error Handling

The program prints:

```text
Error
```

to stderr when:

* Invalid arguments are provided
* Values are outside the integer range
* Duplicate numbers are detected
* Parsing fails
* Unknown options are used

If no argument is provided, the program exits silently.

---

## Project Structure

```text
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
├── low_sort.c
├── simple_sort.c
├── medium_sort.c
├── radix_sort.c
├── sort.c
├── split.c
├── free.c
└── utils.c
```

---

## Performance

Typical results:

| Input Size | Operations |
| ---------- | ---------- |
| 3          | ≤ 3        |
| 5          | ≤ 16       |
| 100        | ~700–1200  |
| 500        | ~7000–8500 |

Actual results depend on disorder and selected strategy.

---

## Contributions

### rchavast

* Stack operations integration
* Sorting strategy architecture
* Adaptive selection logic
* Benchmark integration
* Project documentation

### yaaguerd

* Parsing
* Stack initialization
* Memory management
* Radix sort implementation
* Utilities
* Project structure and testing

Both contributors understand and can explain the complete implementation during evaluation.

---

## Resources

### References

* Knuth, D. E. — *The Art of Computer Programming, Vol. 3: Sorting and Searching* — foundational reference on sorting algorithms and complexity
* [Big-O Cheat Sheet](https://www.bigocheatsheet.com/) — quick reference for algorithm complexity classes
* [Radix Sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort) — theoretical basis for the LSD Radix sort strategy used in the complex algorithm
* [Inversion (discrete mathematics) — Wikipedia](https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics)) — theoretical basis for the disorder metric
* [42 Push_swap resources — harm-smits/push_swap_tester](https://github.com/harm-smits/42docs/blob/master/projects/push_swap.md) — community documentation and testing tools

### AI Usage

Artificial Intelligence tools were used as development assistants for:

* Reviewing project structure
* Verifying compliance with the subject
* Discussing algorithmic approaches
* Generating documentation drafts

All code was reviewed, tested, modified, and validated by the project authors.

---

## Compilation Flags

```bash
-Wall
-Wextra
-Werror
```

The project follows the 42 School Norm.
