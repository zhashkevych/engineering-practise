# Markov Chain Weather Simulator (C++)

This small project demonstrates a **two-state Markov chain** by simulating weather over many days.

---

## What is a Markov Chain?

A **Markov chain** is a stochastic (random) process that moves between a set of states over time, where:

> The probability of the next state depends **only on the current state**, not on the full history.

This is called the **Markov property** (memorylessness).

A Markov chain is defined by:

1. **States** — possible conditions the system can be in
2. **Transition probabilities** — chances of moving from one state to another in one step
3. **Transition matrix** — a convenient table of those probabilities

---

## Problem Statement

We model weather with two states:

* `S` — Sunny
* `R` — Rainy

Transition probabilities:

* If today is **Sunny (S)**:

  * Tomorrow is Sunny with probability **0.8**
  * Tomorrow is Rainy with probability **0.2**

* If today is **Rainy (R)**:

  * Tomorrow is Sunny with probability **0.4**
  * Tomorrow is Rainy with probability **0.6**

Transition matrix:

[
P=
\begin{pmatrix}
0.8 & 0.2 \
0.4 & 0.6
\end{pmatrix}
]

Rows correspond to the **current** state, columns to the **next** state.

---

## What the Program Does

Given an initial state (`S` or `R`) and number of days `N` (default `1000`), the program:

1. Simulates the Markov chain for `N` days
2. Prints the first 20 simulated days
3. Counts how many days were Sunny vs Rainy
4. Outputs the final percentages

This also approximates the **stationary distribution** empirically when `N` is large.

---

## Build & Run (macOS)

### 1) Prerequisites

Make sure you have Xcode Command Line Tools installed:

```bash
xcode-select --install
```

### 2) Create the source file

Save the code into a file, e.g.:

```bash
nano markov.cpp
```

Paste the C++ code, then save and exit.

### 3) Compile

```bash
clang++ -std=c++17 -O2 markov.cpp -o markov
```

* `-std=c++17` — use C++17 standard
* `-O2` — enable optimization
* `-o markov` — output executable name

### 4) Run

```bash
./markov
```

When prompted, enter the start state:

```
S
```

or

```
R
```

---

## Example Output (shortened)

```
Start state (S or R): S
day #0. state -> S
day #1. state -> S
day #2. state -> R
...
total days: 1000
rainy days 33.1%
sunny days 66.9%
```

---

## Notes / Extensions

Possible next steps:

* Compute the stationary distribution analytically (`π = πP`)
* Add more states (e.g., cloudy, snowy)
* Generalize to arbitrary transition matrices
* Use matrix exponentiation to compute probabilities without simulation

---

Если хочешь — следующим файлом докину маленький `Makefile` и/или версию `README` с формулами стационарного распределения.
