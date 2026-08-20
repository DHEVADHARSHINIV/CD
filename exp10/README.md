# Experiment 10 – 8086 Code Generation

## Aim
To implement a simple compiler back-end that converts a three-address arithmetic statement into corresponding 8086 assembly instructions.

## Algorithm
1. Read a three-address statement in the form `result = operand1 operator operand2`.
2. Extract the result, first operand, operator and second operand from the input.
3. Generate `MOV AX, operand1` to load the first operand into the AX register.
4. Check the arithmetic operator using a switch statement.
5. Generate `ADD`, `SUB`, `MUL` or `DIV` according to the operator.
6. Generate `MOV result, AX` to store the result.
7. Display the generated 8086 assembly code.

## Procedure
1. Create the C program `backend.c`.
2. Compile it using GCC.
3. Run the executable.
4. Enter a three-address arithmetic statement such as `t1=a+b`.
5. Observe the corresponding 8086-style assembly instructions.

## Logic
The program separates the input into the result, operands and operator using `scanf`. The first operand is moved into the AX register. A `switch` statement selects the corresponding assembly instruction for addition, subtraction, multiplication or division. Finally, the value in AX is moved to the result variable.

## Program Files
- `backend.c` – 8086 code generation program.
- `backend` – Compiled executable.
- `output10.png` – Execution output.

## Result
The program successfully converts a supported three-address arithmetic statement into corresponding 8086-style assembly instructions.

## Output
Refer to `output10.png` for the execution result.
