# Experiment 01 – Lexical Analyzer Using LEX

## Aim
To design and implement a lexical analyzer using LEX to identify tokens in a C program and maintain a symbol table for identifiers.

## Objective
The program recognizes comments, keywords, identifiers, constants, operators and special symbols from the input C source program. Identifiers are also entered into a symbol table without duplicates.

## Algorithm
1. Define regular expressions for identifiers and constants.
2. Define rules for comments, keywords, operators, whitespace and special symbols.
3. Read the input C program using the LEX-generated scanner.
4. Classify each lexeme according to the matching rule.
5. Insert each identifier into the symbol table if it is not already present.
6. Display the token classification and symbol table.

## Procedure
1. Create the LEX specification file `lexical.l`.
2. Generate the scanner using LEX/FLEX.
3. Compile the generated C program using GCC.
4. Provide the C source program as input.
5. Observe the lexical analyzer output and symbol table.

## Program Files
- `lexical.l` – LEX specification.
- `input.c` – Sample C input program.
- `lex.yy.c` – Generated scanner source.
- `lexical` – Compiled executable.

## Result
The lexical analyzer successfully identifies the tokens in the input C program and generates a symbol table containing the identifiers.

## Output
Refer to the output screenshots in this folder for the execution results.
