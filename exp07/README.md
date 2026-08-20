# Experiment 07 – Three Address Code Generation

## Aim
To implement a three-address code generator using LEX and YACC for arithmetic expressions.

## Algorithm
1. Define lexical rules to recognize identifiers, numbers and operators.
2. Return identifiers and numbers as parser tokens with their string values.
3. Define grammar rules for arithmetic expressions and assignment statements.
4. When an arithmetic operation is recognized, create a new temporary variable such as `t1`, `t2`, etc.
5. Generate a three-address statement for each intermediate operation.
6. Continue until the complete expression is reduced.
7. Generate the final assignment to the left-hand-side identifier.

## Procedure
1. Create `tac.l` for lexical analysis.
2. Create `tac.y` containing the grammar and semantic actions.
3. Generate the scanner and parser using LEX/FLEX and YACC/Bison.
4. Compile the generated files using GCC.
5. Run the executable and enter an assignment expression.
6. Observe the generated three-address code.

## Logic
The parser recursively evaluates the expression structure. For every binary operation, the program creates a temporary variable using `tempCount`, emits an instruction of the form `tN = operand1 operator operand2`, and returns the temporary variable for use in the next operation. Finally, the resulting temporary or operand is assigned to the left-hand-side identifier.

## Program Files
- `tac.l` – LEX specification.
- `tac.y` – YACC grammar and code-generation actions.
- Generated scanner/parser files and executable – supporting build files.
- Output screenshot – execution result.

## Result
The program successfully generates three-address code for the entered arithmetic assignment expression using temporary variables.

## Output
Refer to the output screenshot in this folder for the execution result.
