# Experiment 09 – Code Optimization

## Aim
To demonstrate common code optimization techniques such as constant folding, algebraic transformation and strength reduction.

## Algorithm
1. Read the values of `a` and `b` from the user.
2. Apply constant folding by evaluating the constant expression `10 + 20` before runtime.
3. Demonstrate algebraic transformations such as `a + 0` and `b * 1`.
4. Demonstrate strength reduction by replacing multiplication by 2 with a left-shift operation.
5. Display the optimized forms and their corresponding results.

## Procedure
1. Create the C program `codeopt.c`.
2. Compile the program using GCC.
3. Run the executable.
4. Enter values for `a` and `b`.
5. Observe the output for each optimization technique.

## Logic
The program demonstrates three optimization techniques directly. Constant folding evaluates a constant expression in advance. Algebraic transformation uses identities such as adding zero or multiplying by one. Strength reduction demonstrates multiplication by 2 using the left-shift operation `a << 1`.

## Program Files
- `codeopt.c` – Code optimization demonstration program.
- `codeopt` – Compiled executable.
- `output9.png` – Execution output.

## Result
The program successfully demonstrates constant folding, algebraic transformation and strength reduction and displays their optimized forms.

## Output
Refer to `output9.png` for the execution result.
