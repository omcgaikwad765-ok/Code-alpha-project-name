# Terminal-Based CGPA Calculator 

This is a clean, lightweight command-line tool built in C++ to help university students map out their semester grades and quickly figure out their GPA or cumulative CGPA. 

**Developed by:** Om Gaikwad

---

## What It Does

* **Adapts to Your Semester:** You aren't stuck with a rigid template—type in exactly how many courses you took this semester, and it builds the session around that.
* **No Manual Math Needed:** Just type in standard letter grades like `A+`, `B-`, or `F`. The system automatically handles the conversion to standard 4.0 scale grade points.
* **Crash-Proof Input:** Built defensively so accidental typos, text inputs where numbers should be, or negative credits won't break the application mid-run.
* **Clean Table Layout:** Outputs a neat summary box at the end so you can review your entire semester layout at a glance.

---

## How the Calculations Work Under the Hood

The app tracks data iteratively as you type. Once your courses are complete, it calculates the numbers using the standard weighted credit equation:

$$\text{GPA} = \frac{\sum (\text{Grade Points} \times \text{Credit Hours})}{\sum \text{Credit Hours}}$$

---

## Getting Started / How to Run

### Quick Prerequisite
You just need a working C++ compiler (like `g++`) installed on your machine.

### Terminal Commands
1. Clone or save the source code as `main.cpp` in a folder.
2. Open your command line tool, navigate to that folder, and compile it:
   ```bash
   g++ main.cpp -o cgpa_calculator
