# README: Dynamic Book List Program

---

## Overview

This program allows a user to manage a **dynamic list of books** they have read, create a **favorites list** from the main list, and optionally save both lists to a file. The program demonstrates fundamental programming concepts such as **dynamic memory allocation**, **pointers**, and **file I/O**. 

---

## Features

1. **Dynamic List Management**:
   - Accepts user input to create a dynamic list of book titles.
   - Displays the list with numbered indices.

2. **Favorites List**:
   - Allows users to select a subset of books as favorites.
   - Dynamically allocates memory for the favorites list.

3. **File Saving**:
   - Saves the book list and favorites list to a user-specified file in a structured format.

4. **Pointer-Based Array Management**:
   - Implements all array operations using pointers and pointer arithmetic.

5. **Memory Management**:
   - Ensures all dynamically allocated memory is freed before program termination.

---

## Usage

### Compilation

Use the provided `Makefile` for easy compilation and packaging:

- **Compile the program**:
  ```bash
  make lab3
