# Smart Microwave Oven Controller (PIC16F877A)

## 📌 Overview
This project implements a **Smart Microwave Oven Controller** using the **PIC16F877A microcontroller**.  
The system allows users to set cooking time via keypad input and displays real-time information on a character LCD.

The project was designed, implemented, and simulated using **Embedded C**, **MPLAB X**, and **PICSimLab**.

---

## 🧰 Hardware Used
- PIC16F877A Microcontroller
- HD44780 Character LCD (16x2 / 16x4)
- Matrix Keypad
- Heater (Relay controlled)
- Buzzer
- PICGenios Trainer Board

---

## 🛠️ Software Tools
- MPLAB X IDE
- XC8 Compiler
- PICSimLab (PICGenios)
- Embedded C

---

## 🧠 Project Architecture
- `main.c` – Application flow control
- `clcd.c / clcd.h` – Character LCD driver
- `micro_oven.c / micro_oven.h` – Microwave logic and states
- `matrix_keypad.c / .h` – Keypad interface
- `timers.c / .h` – Timer configuration
- `isr.c` – Interrupt Service Routines

---

## ⚙️ Features
- Power ON welcome screen
- Time setting in MM:SS format
- Start / Pause / Stop functionality
- LCD-based user interface
- Timer-based cooking control
- Modular embedded software design

---

## 🧪 Simulation
The project was successfully simulated using **PICSimLab (PICGenios)**.  
LCD output, keypad input, and timer behavior were verified.

---

## 🚀 How to Run
1. Open project in **MPLAB X IDE**
2. Select **PIC16F877A** and **Simulator**
3. Build using **XC8 compiler**
4. Load HEX file into PICSimLab (optional)
5. Run simulation

---

## 📄 Documentation
- Project Report (PDF)
- Project Presentation (PPT)

---

## 👤 Author
**DUDEKULA SAJID ALI**  
B.Tech ECE  
IIITDM KURNOOL
BS IIT MADRAS

---

## 📌 Note
This project was completed independently for learning and academic purposes.
