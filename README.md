# 8-Bit Computer 💻

This project is a simulation of an 8-bit computer built using [Logisim Evolution](https://github.com/reds-heig/logisim-evolution), inspired by [Ben Eater's YouTube series](https://www.youtube.com/playlist?list=PLowKtXNTBypGqImE405J2565dvjafglHU).  
It demonstrates the basic architecture and functioning of a simple CPU, including a version with full control logic and basic instruction set support.

---

## 🔧 Project Overview

This project includes **two versions** of the 8-bit CPU:

1. **Basic Version (without control logic):**  
   - Manually controlled CPU execution.
   - Useful for learning how individual components interact.

2. **Full Version (with control logic):**  
   - Automated instruction execution using a control logic ROM.
   - Supports a simple assembly-like instruction set.

---

## 💡 Features

- Simulates an 8-bit CPU architecture.
- Includes ALU, RAM, Program Counter, Instruction Register, Control Logic, and Output Register.
- Simple instruction set to write and execute custom programs.

---

## 🧾 Instruction Set

Here’s a sample of the basic instructions (example, update as needed):

| Opcode | Mnemonic | Description               |
|--------|----------|---------------------------|
| `0000` | NOP      | No operation              |
| `0001` | LDA      | Load from RAM to A        |
| `0010` | ADD      | Add value to A            |
| `0011` | SUB      | Subtract value from A     |
| `0100` | STA      | Store A to RAM            |
| `0101` | LDI      | Load immediate to A       |
| `0110` | JMP      | Jump to address           |
| `0111` | JC       | Jump if carry             |
| `1000` | JZ       | Jump if zero              |
| `1110` | OUT      |                           |
| `1111` | HLT      | Halt execution            |

