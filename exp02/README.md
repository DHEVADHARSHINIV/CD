# Experiment 02 – Lexical Analysis of a C Program

## Aim
To implement a lexical analyzer in C to read a C source file and identify keywords, identifiers, numbers, delimiters, operators, comments, preprocessor directives and header files.

## Algorithm
1. Open the C source file specified by the user.
2. Read the file character by character until the end of file is reached.
3. Identify and skip single-line and multi-line comments.
4. Recognize strings, identifiers, keywords, numbers, delimiters and operators.
5. Compare identifiers with the predefined keyword, header-file and preprocessor-directive lists.
6. Display the category and value of each recognized token.
7. Close the file and display the end-of-file message.

## Procedure
1. Create the C source file containing the lexical analyzer.
2. Compile the program using GCC.
3. Run the executable.
4. Enter the name of the C source file to be analyzed.
5. Observe the tokens and their corresponding categories in the output.

## Logic
The program scans the source file sequentially. It uses predefined arrays for delimiters, operators, keywords, preprocessor directives and header files. Characters are grouped into tokens and checked against these lists. Comments are skipped, while recognized tokens are printed with their appropriate category.

## Program Files
- `nano.c` – Lexical analyzer implementation.
- `iplex.c` – Sample C input program.
- `nano` – Compiled executable.
- `output2.png` – Execution output.

## Result
The lexical analyzer successfully reads the C source file and identifies the different lexical tokens and their categories.

## Output
Refer to `output2.png` for the execution result.
