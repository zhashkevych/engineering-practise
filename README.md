# Engineering Practise

A collection of small engineering exercises focused on strengthening
core skills in **algorithms**, **mathematics**, **probability theory**,  
**systems design**, and **low-level programming**.

This repository is not about building production software.  
It is about building *the engineer* — through deliberate practice,
problem-solving, and exploration of different concepts across CS, math,
and physics.

---

## 🎯 Purpose

Modern software development is heavily abstracted.  
To stay sharp, it’s useful to periodically return to fundamentals:

- writing clean C/C++ & Python code  
- understanding probabilistic models  
- revisiting algorithms & data structures  
- modelling real-world systems mathematically  
- solving problems from first principles  
- learning how to think clearly and structurally  

This repo serves as a personal training ground.

Each subfolder contains one problem, its implementation, and a README
explaining the concept behind it.

---

## 📂 Repository Structure

```

engineering-practise/
├── weather-forecast/
│     ├── markov.cpp
│     ├── README.md
│     └── visualisation.png
├── next-task/
│     └── ...
└── ...

```

- **Each folder = one self-contained exercise**
- Written primarily in **C++**, sometimes **Python**
- All tasks include:
  - description of the underlying theory  
  - implementation  
  - minimal instructions on how to build & run  

---

## 🧠 Current Tasks

### **Weather Forecast Simulation (Markov Chain)**
A two-state Markov chain simulating Sunny/Rainy weather transitions.
Demonstrates:
- stochastic processes  
- transition matrices  
- random number generation in C++  
- empirical stationary distributions  

---

## 🔧 Build & Run

Each task is isolated, so build instructions live in individual READMEs.
Typical C++ workflow (macOS):

```bash
clang++ -std=c++17 -O2 file.cpp -o app
./app
````

Python tasks run directly:

```bash
python3 script.py
```

---

## 🚀 Future Tasks (planned)

* Monte-Carlo simulations
* Text generation via Markov chains (N-gram models)
* Small data-structures implementations (linked lists, tries, heaps)
* Probability distributions & random sampling
* Simple physics simulations
* Mathematical puzzles and algorithmic challenges
* System design micro-exercises

---

## 📜 Philosophy

This repository follows three principles:

### 1. **Depth over breadth**

Even small tasks can teach deep engineering insights if explored seriously.

### 2. **Hands-on practice**

Understanding comes from *implementing*, not passively reading.

### 3. **Consistency over intensity**

One well-solved problem per week compounds enormously over months.

---

## 🤝 Contributions

This is a personal practise repo, but suggestions and ideas for new
problems are welcome.

---

## 📬 Contact

If you want to share ideas or suggest a new exercise, feel free to reach out.

---

Happy building.
