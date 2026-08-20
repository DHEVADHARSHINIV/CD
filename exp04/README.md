# Experiment 04 – Validation of Variables

## Aim
To implement a variable validator using LEX and YACC and determine whether an input string follows the defined variable naming grammar.

## Algorithm
1. Define lexical rules to recognize letters and digits.
2. Return `LET` for alphabetic characters and `DIG` for digits.
3. Define a grammar in YACC in which a variable begins with a letter and may be followed by letters or digits.
4. Pass the generated tokens from LEX to the YACC parser.
5. If the input satisfies the grammar, display `Valid variable`.
6. Otherwise, display `Invalid variable`.

## Procedure
1. Create `valvar.l` containing the lexical rules.
2. Create `valvar.y` containing the grammar rules.
3. Generate the scanner and parser using LEX/FLEX and YACC/Bison.
4. Compile the generated C files using GCC.
5. Run the executable and enter a variable name.
6. Observe the validation result.

## Logic
The lexical analyzer classifies each character as a letter or digit. The parser applies the grammar `var: var DIG | var LET | LET`, which ensures that the first character is a letter and subsequent characters may be letters or digits.

## Program Files
- `valvar.l` – LEX specification.
- `valvar.y` – YACC grammar.
- `lex.yy.c`, `y.tab.c`, `y.tab.h` – Generated files.
- `valvar` – Compiled executable.
- `output4.png` – Execution output.

## Result
The variable validator successfully determines whether the entered variable follows the defined grammar.

## Output
Refer to `output4.png` for the execution result.
