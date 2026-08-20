# Experiment 05 – Validation of C Control Structures

## Aim
To implement a parser using LEX and YACC to recognize and validate selected C control structure syntax such as `if`, `while`, `for` and `switch` statements.

## Algorithm
1. Define lexical rules for control-structure keywords, identifiers, numbers, relational operators, assignment operators and punctuation symbols.
2. Generate tokens from the input using LEX.
3. Define grammar rules for statements, blocks, assignments, conditions, loops and switch-case structures using YACC.
4. Pass the tokens to the parser.
5. Check whether the input conforms to the grammar.
6. Display `Valid control structure syntax` for a valid input; otherwise display `Invalid control structure syntax`.

## Procedure
1. Create `control.l` with the required lexical patterns.
2. Create `control.y` with grammar rules for the supported control structures.
3. Generate the scanner and parser using LEX/FLEX and YACC/Bison.
4. Compile the generated files using GCC.
5. Run the executable and enter a C control structure syntax.
6. Observe the validation result.

## Logic
The LEX scanner converts keywords and symbols into parser tokens. The YACC grammar combines these tokens according to rules for `if`, `while`, `for`, `switch`, blocks, assignments and conditions. Successful parsing indicates that the entered syntax matches one of the supported control structures.

## Program Files
- `control.l` – LEX specification.
- `control.y` – YACC grammar.
- `lex.yy.c`, `y.tab.c` – Generated files.
- `control` – Compiled executable.
- `output5.png` – Execution output.

## Result
The parser successfully validates the syntax of the supported C control structures.

## Output
Refer to `output5.png` for the execution result.
