# 8-Bit Computer 💻

This project is a simulation of an 8-bit computer built using [Logisim Evolution](https://github.com/reds-heig/logisim-evolution), inspired by [Ben Eater's YouTube series](https://www.youtube.com/playlist?list=PLowKtXNTBypGqImE405J2565dvjafglHU).  
It demonstrates the basic architecture and functioning of a simple CPU, including a version with full control logic and basic instruction set support.

---

## Project Overview

This project includes **two versions** of the 8-bit CPU:

1. **Basic Version (without control logic):**  
   - Manually controlled CPU execution by execution micro instructions at a time.
   - Useful for learning how individual components interact.
     
     <img width="1474" height="868" alt="image" src="https://github.com/user-attachments/assets/46f73ffe-2589-4c90-aae8-ac6d79a02075" />


2. **Full Version (with control logic):**  
   - Automated instruction execution using a control logic ROM.
   - Supports a simple assembly-like instruction set.
  
     

---

## Features

- Simulates an 8-bit CPU architecture.
- Includes ALU, Registers, RAM, Memory Address Register, Program Counter, Instruction Register, Flag Register, Control Logic, and Output Register.
- Simple instruction set to write and execute custom programs.
- C program to generate microcode that has to be loaded in control logic rom.

---

## Components

**Clock**

<img width="904" height="404" alt="image" src="https://github.com/user-attachments/assets/e5a72c3c-6a1b-4e36-9cb1-69ba40438fce" />



**Program Counter**

<img width="948" height="293" alt="image" src="https://github.com/user-attachments/assets/f7e21162-842b-48ac-b471-e79934c08868" />



**A Register**

<img width="878" height="292" alt="image" src="https://github.com/user-attachments/assets/006e6363-b658-42a6-9353-5d56b505313e" />



**B Register**

<img width="1186" height="911" alt="image" src="https://github.com/user-attachments/assets/a5dcb3b7-ba05-4d02-9acb-df1d8733960e" />



**ALU**

<img width="945" height="355" alt="image" src="https://github.com/user-attachments/assets/b4ad817b-a2e7-4682-8e0d-ab7170469131" />




---

## Instruction Set

| Opcode | Mnemonic | Description                     |
|--------|----------|---------------------------------|
| `0000` | NOP      | No operation                    |
| `0001` | LDA      | Load from RAM to A              |
| `0010` | ADD      | Add value to A                  |
| `0011` | SUB      | Subtract value from A           |
| `0100` | STA      | Store A to RAM                  |
| `0101` | LDI      | Load A with given value         |
| `0110` | JMP      | Jump to address                 |
| `0111` | JC       | Jump if carry flag is set       |
| `1000` | JZ       | Jump if zero flag is set        |
| `1110` | OUT      | Load from A to output register  |
| `1111` | HLT      | Halt execution                  |

---

## Example


---

## ToDo

Add swap, compare, add immediate and sub immediate instruction
Add images and videos
Add examples
