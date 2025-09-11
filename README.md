# 8-Bit Computer 

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

     <img width="1186" height="911" alt="image" src="https://github.com/user-attachments/assets/a5dcb3b7-ba05-4d02-9acb-df1d8733960e" />


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
   <img width="822" height="292" alt="image" src="https://github.com/user-attachments/assets/8905d1f4-d6c7-45d9-ba39-6f348f2c39cf" />



   **ALU**             
   <img width="945" height="355" alt="image" src="https://github.com/user-attachments/assets/b4ad817b-a2e7-4682-8e0d-ab7170469131" />



   **Output Register**                       
   <img width="677" height="192" alt="image" src="https://github.com/user-attachments/assets/9f0efa36-28c1-48c0-ba09-3e8f71964485" />



   **Memory Address Register**               
   <img width="683" height="262" alt="image" src="https://github.com/user-attachments/assets/9941cfd9-3a1f-4137-bc5c-da43ab6e5cca" />



   **RAM**                      
   <img width="715" height="950" alt="image" src="https://github.com/user-attachments/assets/205ba17c-6cf8-4dcd-aa1c-3146dd1e161d" />



   **Instruction Register**         
   <img width="774" height="396" alt="image" src="https://github.com/user-attachments/assets/bc43efe5-b32e-4488-bab2-709f2b08f315" />



   **Step Counter**                    
   <img width="704" height="212" alt="image" src="https://github.com/user-attachments/assets/c25214a3-bbaa-464c-950d-9be65a59ca5c" />



   **Zero Flag**                    
   <img width="497" height="188" alt="image" src="https://github.com/user-attachments/assets/8e526133-6a47-4719-84b9-9fcdaaea4d79" />



   **Flags**                         
   <img width="715" height="318" alt="image" src="https://github.com/user-attachments/assets/3ad35ffe-0282-4bcc-9fba-3c3dc1914b05" />

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

## Examples

1) Using basic version to add two numbers

   Program:
   | Assembly | Memory Address | Machine Code |
   |----------|----------------|--------------|
   | LDA 14   | `0000`         | `0001 1110`  |
   | ADD 15   | `0001`         | `0010 1111`  |
   | OUT      | `0010`         | `1110 0000`  |
   |          |  ...           |              |
   |          | `1110`         | `0001 1100`  |
   |          | `1111`         | `0000 1110`  |

   Micro Instructions:

   |    | LDA 14 |                                                   | 
   |----|--------|---------------------------------------------------|
   | T0 | CO MI  | Going to Memory Address '0000' (Fetch opertation) |
   | T1 | RO II  | Transfer Data from RAM To IR                      |
   |    | CE     | Increment PC                                      |
   | T2 | IO MI  | Pointing Memory at address '1110'                 |
   | T3 | RO AI  | Store data in A                                   |

   |    | ADD 15 |                                                   | 
   |----|--------|---------------------------------------------------|
   | T0 | CO MI  | Going to Memory Address '0001' (Fetch opertation) |
   | T1 | RO II  | Transfer Data from RAM To IR                      |
   |    | CE     | Increment PC                                      |
   | T2 | IO MI  | Pointing Memory at address '1111'                 |
   | T3 | RO BI  | Store data in B                                   |
   | T4 | EO AI  | Calculate sum of A and B and store it in A        |

   |    | LDA 14 |                                                                  |
   |----|--------|------------------------------------------------------------------|
   | T0 | CO MI  | Going to Memory Address '0010' (Fetch opertation)                |
   | T1 | RO II  | Transfer Data from RAM To IR                                     |
   |    | CE     | Increment PC                                                     |
   | T2 | AO OI  | data stored in A is transfered to Output Register for displaying |



2) Getting Multiples of 3
   
   Program:
   | Assembly  | Memory Address | Machine Code |
   |-----------|----------------|--------------|
   | 0: LDI 03 | `0000`         | `0101 0011`  |
   | 1: STA 15 | `0001`         | `0100 1111`  |
   | 2: LDI 00 | `0010`         | `0101 0000`  |
   | 3: ADD 15 | `0011`         | `0010 1111`  |
   | 4: OUT    | `0100`         | `1110 0000`  |
   | 5: JMP 03 | `0101`         | `0110 0011`  |



3) Counting Up and Down

   Program:
   | Assembly   | Memory Address | Machine Code |
   |------------|----------------|--------------|
   | 00: OUT    | `0000`         | `1110 0000`  |
   | 01: ADD 15 | `0001`         | `0010 1111`  |
   | 02: JC 04  | `0010`         | `0111 0100`  |
   | 03: JMP 00 | `0011`         | `0110 0000`  |
   | 04: SUB 15 | `0100`         | `0011 1111`  |
   | 05: OUT    | `0101`         | `111O OOOO`  |
   | 06: JZ 00  | `0110`         | `1000 0000`  |
   | 07: JMP 04 | `0111`         | `0110 0100`  |
   | 15: 25     | `1111`         | `0011 0010`  |



4) Multipling x & y using conditional jump

   Pseudocode:\
   product = 0\
   loop until x is 0\
   &emsp;load x\
   &emsp;subtract 1\
   &emsp;store x\
   &emsp;load product\
   &emsp;add y\
   &emsp;store product\
   output product

   Assembly:\
   TOP:\
   &emsp;LDA x\
   &emsp;SUB 1\
   &emsp;JC CONTINUE\
   &emsp;LDA product\
   &emsp;OUT\
   &emsp;HLT\
   CONTINUE:\
   &emsp;STA x\
   &emsp;LDA product\
   &emsp;ADD y\
   &emsp;STA product\
   &emsp;JMP TOP

   Program:
   | Assembly    | Memory Address | Machine Code |
   |-------------|----------------|--------------|
   | 00: LDA 14  | `0000`         | `0001 1110`  |
   | 01: SUB 12  | `0001`         | `0011 1100`  |
   | 02: JC 06   | `0010`         | `0111 0110`  |
   | 03: LDA 13  | `0011`         | `0001 1101`  |
   | 04: OUT     | `0100`         | `1110 0000`  |
   | 05: HLT     | `0101`         | `1111 0000`  |
   | 06: STA 14  | `0110`         | `0100 1110`  |
   | 07: LDA 13  | `0111`         | `0001 1101`  |
   | 08: ADD 15  | `1000`         | `0010 1111`  |
   | 09: STA 13  | `1001`         | `0100 1101`  |
   | 10: JMP 00  | `1010`         | `0110 0000`  |
   | 11:         | `1011`         |              |
   | 12: 1       | `1100`         | `0000 0001`  |
   | 13: product | `1101`         | `0000 0000`  |
   | 14: x       | `1110`         |              |
   | 15: y       | `1111`         |              |
   

---
