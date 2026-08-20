# Experiment 06 – Arithmetic Calculator Using LEX and YACC

## Aim
To implement an arithmetic calculator using LEX and YACC for evaluating expressions containing numeric operands and arithmetic operators.

## Algorithm
1. Define a lexical pattern for integer and decimal numbers.
2. Convert each recognized number into a numeric value and return it as a `NUM` token.
3. Define grammar rules for addition, subtraction, multiplication and division.
4. Apply operator precedence for the arithmetic operators.
5. Parse the input expression using YACC.
6. Perform the corresponding arithmetic operation through parser actions.
7. Display the calculated answer.

## Procedure
1. Create `cal.l` for lexical analysis.
2. Create `cal.y` for the calculator grammar and semantic actions.
3. Generate the scanner and parser using LEX/FLEX and YACC/Bison.
4. Compile the generated files using GCC.
5. Run the executable and enter an arithmetic expression.
6. Observe the calculated answer.

## Logic
The LEX scanner recognizes integer and decimal numbers and stores their values in `yylval`. The YACC parser combines the numbers according to the arithmetic grammar. Semantic actions perform `+`, `-`, `*` and `/` operations and print the resulting value.

## Program Files
- `cal.l` – LEX specification.
- `cal.y` – YACC calculator grammar.
- Generated scanner/parser files and executable – supporting build files.
- `output6.png` – Execution output.

## Result
The arithmetic calculator successfully parses and evaluates the entered expression and displays its result.

## Output
Refer to `output6.png` for the execution result.
