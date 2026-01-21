# Computer-graphics

## 📌 Project Overview

This project is a **menu-driven computer graphics application** developed in **C using Turbo C Graphics Library (BGI)**.
It demonstrates the implementation of **basic computer graphics algorithms** such as line drawing and circle drawing, along with built-in shape functions.

The program allows the user to select different graphics operations from a menu and displays the corresponding output on the screen.

---

## 🎯 Features

The program includes the following graphics operations:

1. **Line Drawing using DDA Algorithm**
2. **Line Drawing using Bresenham’s Algorithm**
3. **Circle using Built-in `circle()` Function**
4. **Circle using Midpoint Circle Algorithm**
5. **Rectangle using Built-in `rectangle()` Function**
6. **Triangle using Built-in `line()` Function**
7. **Ellipse using Built-in `ellipse()` Function**
8. **Exit Option**

---

## 🛠️ Technologies Used

* **Programming Language:** C
* **Compiler:** Turbo C / Turbo C++
* **Graphics Library:** BGI (Borland Graphics Interface)
* **Header Files Used:**

  * `graphics.h`
  * `conio.h`
  * `stdio.h`
  * `math.h`
  * `stdlib.h`

---

## 🖥️ How to Run the Project

### Step 1: Install Turbo C

* Install **Turbo C / Turbo C++** on your system.
* Make sure the **BGI folder** is present (usually `C:\TURBOC3\BGI`).

### Step 2: Create the Source File

* Open Turbo C.
* Create a new file (e.g., `graphics_menu.c`).
* Paste the project source code into the file.

### Step 3: Compile and Run

* Press **Alt + F9** to compile.
* Press **Ctrl + F9** to run the program.

⚠️ **Important:**
Ensure the BGI path in `initgraph()` is correct:

```c
initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
```

---

## 📋 Program Workflow

1. The program initializes the graphics mode.
2. A menu is displayed on the console.
3. The user selects an option (1–8).
4. The selected shape or algorithm is drawn on the graphics screen.
5. The program waits for a key press and returns to the menu.
6. Selecting **Exit** closes the graphics window.

---

## 📚 Algorithms Implemented

* **DDA Line Drawing Algorithm**
* **Bresenham’s Line Drawing Algorithm**
* **Midpoint Circle Algorithm**

These algorithms are widely used in **Computer Graphics** courses to understand pixel-level drawing techniques.

---

## ✍️ Author

**Project by:** *Kamakshi Tak*
**Course:** Computer Graphics
**Language:** C (Turbo C)

---
