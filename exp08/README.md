# Experiment 08 – Type Checking

## Aim
To implement a type checking mechanism using LEX and YACC to identify whether the operands used in an arithmetic expression have compatible data types.

## Algorithm
1. Define lexical rules for `int`, `float`, identifiers, assignment, addition and semicolon.
2. Return the appropriate tokens to the parser.
3. Parse two declarations followed by an assignment expression.
4. Store the types of the declared identifiers.
5. Compare the operand types used in the expression.
6. Display `No Type Mismatch` when the stored types are the same; otherwise display `Type Mismatch`.

## Procedure
1. Create `typecheck.l` for lexical analysis.
2. Create `typecheck.y` for grammar and type-checking actions.
3. Generate the scanner and parser using LEX/FLEX and YACC/Bison.
4. Compile the generated files using GCC.
5. Run the executable and enter the declarations and expression in the required format.
6. Observe the type-checking result.

## Logic
The lexical analyzer recognizes the data-type keywords and identifiers. The parser stores the type associated with the declared identifiers in `type1` and `type2`. During the assignment expression, these stored types are compared using `strcmp`. The program reports whether the two types match.

## Program Files
- `typecheck.l` – LEX specification.
- `typecheck.y` – YACC grammar and type-checking logic.
- Generated scanner/parser files and executable – supporting build files.
- Output screenshot – execution result.

## Result
The type checker successfully compares the operand types and reports whether a type mismatch is present for the supported input format.

## Output
Refer to the output screenshot in this folder for the execution result.
