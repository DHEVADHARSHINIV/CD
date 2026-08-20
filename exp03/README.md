# Experiment 03 – Arithmetic Expression Recognition

## Aim
To implement an arithmetic expression recognizer using LEX and YACC and determine whether a given expression is valid.

## Algorithm
1. Define lexical rules to recognize identifiers, digits and arithmetic symbols.
2. Generate tokens from the input expression using LEX.
3. Define grammar rules for arithmetic expressions using YACC.
4. Apply operator precedence and associativity for `+`, `-`, `*`, `/` and unary minus.
5. Parse the input expression using the generated parser.
6. Display `valid Expression` if the expression satisfies the grammar; otherwise display `Invalid Expression`.

## Procedure
1. Create the LEX file `art_expr.l` and YACC file `art_expr.y`.
2. Generate the lexical analyzer using LEX/FLEX.
3. Generate the parser using YACC/Bison.
4. Compile the generated C files using GCC.
5. Run the executable and enter an arithmetic expression.
6. Observe whether the expression is accepted or rejected.

## Logic
The LEX specification converts identifiers and numbers into `ID` and `DIG` tokens. The YACC grammar recursively defines expressions using arithmetic operators, parentheses, operands and unary minus. Precedence declarations resolve the order of arithmetic operations during parsing.

## Program Files
- `art_expr.l` – LEX specification.
- `art_expr.y` – YACC grammar and parser actions.
- `lex.yy.c`, `y.tab.c`, `y.tab.h` – Generated parser/scanner files.
- `art_expr` – Compiled executable.
- `output3.png` – Execution output.

## Result
The arithmetic expression recognizer successfully validates whether the entered expression follows the defined grammar.

## Output
Refer to `output3.png` for the execution result.
