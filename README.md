# MarquisNevadaAssignment5_P8_2
## Overview
The program checks the spelling of all words in a text file by comparing them against a dictionary word list.

## What the Program Does
1. Opens a dictionary file and loads each word into a `vector<string>` named `words`.
2. Opens a file to be checked and reads it word-by-word (token-by-token).
3. Normalizes each token by:
   - converting to lowercase
   - trimming leading and trailing punctuation
4. Prints tokens that **are not found** in the dictionary vector.

This follows the textbook pseudocode:
- Open dictionary file  
- Store dictionary words in a vector  
- Open file to check  
- Print each word not contained in the vector

## Included Files
- `Source.cpp` — C++ implementation
- `words.txt` — dictionary word list (one word per line)
- `check.txt` — sample text file for testing
- `pseudocode_*.docx` — pseudocode document (assignment deliverable)

## How to Run (Visual Studio)
This program expects **two command-line arguments**:
