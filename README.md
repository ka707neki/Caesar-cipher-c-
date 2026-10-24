# 🔐 Caesar Cipher (C++)

A colorful command-line Caesar cipher tool written in C++. Type a message, choose a shift, and instantly see it encrypted and decrypted, with a typewriter effect and ANSI colors in the terminal.

## ✨ Features

- Encrypts and decrypts text using the Caesar cipher
- Preserves upper/lower case; digits, spaces and symbols stay unchanged
- Handles any shift value, including negative and very large numbers
- Input validation (re-asks if you type a non-number)
- Colored terminal UI with a boxed title and typing animation
- Run as many times as you like without restarting

## 📖 How it works

Each letter is moved forward `shift` places in the alphabet and wraps around after `z`.

```
Plain text : Hello, World!
Shift      : 3
Encrypted  : Khoor, Zruog!
```

Decryption simply applies the opposite shift (`26 - shift`).

## 🚀 Build & Run

Requirements: a C++11 (or newer) compiler such as `g++`, and a terminal that supports ANSI colors (most Linux/macOS terminals and Windows Terminal).

```bash
g++ -std=c++11 caesar_cipher.cpp -o caesar_cipher
./caesar_cipher
```

## 🖥️ Example

```
  ==================================================
  |                                                |
  |               CAESAR CIPHER TOOL               |
  |                                                |
  ==================================================

  Enter text  : Hello, World!
  Enter shift : 3

  --------------------------------------------------
  Encrypted : Khoor, Zruog!
  Decrypted : Hello, World!
  --------------------------------------------------

  Try again? (y/n):
```

## 📁 Project structure

```
.
├── caesar_cipher.cpp
└── README.md
```

## 📚 What I practiced

- Functions and string manipulation
- Modulo arithmetic for wrapping around the alphabet
- Input validation with `cin`
- ANSI escape codes and `<chrono>` / `<thread>` for terminal effects

## 📄 License

Free to use and modify. Add a `LICENSE` file (e.g. MIT) if you want to define the terms formally.
