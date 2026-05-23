# Quiz Generator System (C++ Console Application)

A menu-driven **console-based Quiz Generator System** developed in **C++** as a **2nd Semester Programming Fundamentals Project**.

This application allows users to attempt quizzes across multiple subjects with selectable difficulty levels, randomized questions, real-time score calculation, result storage, and an interactive colorful console interface.

---

# Project Overview

The Quiz Generator System is designed to demonstrate practical implementation of core **Programming Fundamentals concepts** using file handling and modular programming.

The system supports:

- Multiple quiz subjects
- Difficulty-based question selection
- Real-time scoring system
- Negative marking for advanced level
- File-based result storage
- Interactive user experience using console colors and sound effects

---

# Features

## Multi-Subject Quiz System

Supports:

- Programming Fundamentals (PF)
- English
- Mathematics

Each subject contains its own external question files.

---

## Difficulty Levels

Users can choose:

- Beginner
- Intermediate
- Advanced

**Advanced Mode includes negative marking**

- Correct Answer → **+10 points**
- Wrong Answer → **−10 points**

---

## File-Based Question Management

Questions are stored in external `.txt` files.

Benefits:

- Easy to edit questions
- Easy to add more quizzes
- No code modification required

---

## Structured Question Handling

Uses `struct Question` to store:

- Question statement
- Four MCQ options
- Correct answer

Questions are displayed clearly with:

- A
- B
- C
- D options

Questions are randomized for every quiz attempt.

---

## Real-Time Score Calculation

The program:

- Calculates score instantly
- Displays current score after each question
- Shows final result summary

---

## Result Storage System

Quiz results are saved in:

`results.txt`

Stored data includes:

- Player Name
- Subject
- Difficulty
- Final Score

Users can also view previous quiz attempts.

---

## Input Validation

Validates:

- Player name (letters & spaces only)
- Menu selections
- Subject selection
- Difficulty selection
- Answer input (A–D only)

---

## Enhanced Console Experience

Uses:

- `SetConsoleTextAttribute()` → Colored interface
- `Beep()` → Sound feedback
- `Sleep()` → Smooth readable transitions
- `system("cls")` → Clean screen refresh

---

# Programming Concepts Used

## Core C++ Concepts

- Structures (`struct`)
- Arrays
- Loops
- Conditional Statements
- Functions
- Modular Programming

---

## File Handling

- `ifstream`
- `ofstream`

Provides persistent data storage.

---

## Standard Libraries Used

- `<iostream>`
- `<fstream>`
- `<string>`
- `<cctype>`
- `<cstdlib>`
- `<ctime>`
- `<windows.h>`

---

# System Workflow

### Main Menu

- Start Quiz
- Instructions
- View Results
- Exit

### Player Registration

User enters validated name.

### Subject Selection

Choose:

- PF
- English
- Mathematics

### Difficulty Selection

Choose:

- Beginner
- Intermediate
- Advanced

### Question Loading

Program dynamically loads question files.

### Quiz Execution

- Randomized question display
- Validated answer input
- Score updates
- Sound + color feedback

### Final Result

Displays:

- Final Score
- Quiz Summary

Saves record to file.

---

# Project Structure

```plaintext
Quiz-Generator-System/
│
├── QuizGenerator.cpp
├── results.txt
│
├── Questions/
│   ├── PF
│   ├── ENG
│   ├── MATH
│
├── Documentation/
│   └── Project_Documentation.pdf
│
└── Screenshots/
```

---

# Screenshots

(Add project screenshots here)

Example:

- Main Menu
- Quiz Interface
- Result Summary
- Results File Output

---

# Learning Outcomes

This project strengthened practical understanding of:

- File Handling
- Modular Programming
- Problem Solving
- Data Structuring
- Input Validation
- User Interaction Design
- Console-Based Application Development

---

# Author

**Sultan Shahzad Awan**

Artificial Intelligence Student | Future Game Developer

---

# Academic Use Notice

This project is published for educational and portfolio purposes only.

Unauthorized copying, redistribution, modification, or commercial usage is prohibited without explicit permission from the author.

---

# License

All Rights Reserved © Sultan Shahzad Awan
