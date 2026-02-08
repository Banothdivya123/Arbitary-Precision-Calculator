# apc-in-c
# Arbitrary Precision Calculator in C
# 📌 Overview

APC (Arbitrary Precision Calculator) is a console-based application developed in the C programming language to perform arithmetic operations on very large integers that exceed the limits of standard C data types such as int, long, and long long.

This project uses linked lists to represent numbers digit by digit, allowing calculations with numbers of unlimited length (subject to system memory). The main goal of this project is to gain hands-on experience with data structures, pointers, dynamic memory allocation, and modular programming in C by building a real-world calculator engine.

#  Features

-> Perform arithmetic operations on arbitrarily large integers

-> Supports core arithmetic operations:

➕ Addition

➖ Subtraction

✖ Multiplication

➗ Division

-> Linked list–based number representation

-> Proper handling of carry and borrow operations

-> Supports positive and negative integers

-> Modular and structured C implementation

-> Lightweight and completely written in C

-> Designed as an educational, system-level project

# 🧠 Project Concept

In normal C programs, arithmetic operations are limited by fixed-size data types. This project overcomes that limitation by:

-> Storing each digit of a number in a node of a linked list

-> Performing arithmetic digit by digit

-> Avoiding all built-in arithmetic for large values

-> This approach closely resembles how calculations are done manually and helps understand low-level computation.

# ⚙️ How to Run

#  Compile the Program
gcc *.c -o apc

#  Run the Program
./apc

# 🚀 Usage Examples
# Addition
./apc 123456789123456789 + 987654321987654321

# Subtraction
./apc 987654321987654321 - 123456789123456789

# Multiplication
./apc 123456789 * 987654321

# Division
./apc 987654321987654321 / 123456789

# Notes
Numbers are internally stored using linked lists, one digit per node.
This allows handling numbers of unlimited length (memory dependent).
The program avoids built-in data types like int, long, long long for calculations.
Designed as a learning-oriented system-level project for understanding:

-> memory management

-> pointer manipulation

-> algorithm design

-> modular programming in C

# Skills Learned

-> C programming

-> Linked list implementation

-> Dynamic memory allocation (malloc, free)

-> Pointer manipulation

-> Algorithmic logic for arithmetic operations

-> Modular project structuring

-> Debugging large-scale C programs
