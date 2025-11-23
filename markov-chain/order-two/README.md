# Weather Forecast — 2nd-Order Markov Chain (C++)

This folder contains a solution for simulating weather using a **second-order Markov chain**.

Compared to the first task (order one), the system now **remembers the last two days**, and the probability of tomorrow’s weather depends on that pair.

---

## What is a 2nd-Order Markov Chain?

A **Markov chain** is a stochastic process where the next state depends only on the current state.

A **second-order Markov chain** extends this idea:

\[
P(X_{t+1} \mid X_t, X_{t-1})
\]

Meaning:

> The probability of tomorrow’s state depends on the **two most recent states**, not just one.

This is closer to many real systems:
- language models (n-grams)
- systems with inertia
- simple predictive models in finance / behavior

---

## Problem Statement

We model weather with two states:

- `S` — Sunny  
- `R` — Rainy  

Tomorrow’s weather depends on the **last two days**:

| Last two days | P(next = S) | P(next = R) |
|--------------|-------------|-------------|
| SS           | 0.9         | 0.1         |
| SR           | 0.5         | 0.5         |
| RS           | 0.6         | 0.4         |
| RR           | 0.3         | 0.7         |

We encode the pair of previous states into 4 combined states:

```

0: SS
1: SR
2: RS
3: RR

````

And use a transition table:

```cpp
double P[4][2] = {
    {0.9, 0.1}, // SS
    {0.5, 0.5}, // SR
    {0.6, 0.4}, // RS
    {0.3, 0.7}, // RR
};
````

---

## What the Program Does

1. Reads **two initial states** (`S` or `R`) from the user
2. Simulates `N` days (default: `1000`)
3. On each step:

   * determines the current pair (`stateA`, `stateB`)
   * samples next weather using probabilities from the table
   * shifts window `(stateA, stateB) → (stateB, next)`
4. Counts sunny vs rainy days
5. Prints final percentages
6. (Optional to add) prints first 20 days to inspect behavior

With large `N`, the empirical frequencies approximate the stationary behavior.

---

## Build & Run (macOS)

### 1) Compile

From this folder:

```bash
clang++ -std=c++17 -O2 markov-order-two.cpp -o markov
```

### 2) Run

```bash
./markov
```

You will be asked for two initial states:

```
First initial state (S or R): S
Second initial state (S or R): R
```

---

## Example Output (shortened)

```
First initial state (S or R): S
Second initial state (S or R): R
total days: 1000
rainy days 38.2%
sunny days 61.8%
```

Percentages will differ between runs due to randomness, but should stabilize near consistent values as `N` grows.

---

## Notes / Extensions

Ideas to explore next:

* Print the first K days and show transitions by pair
* Add burn-in (ignore first 50–100 steps)
* Compute stationary distribution analytically for 4 pair-states
* Generalize to k-order chains
* Add more states (cloudy, snowy, etc.)
* Convert to a 4×4 pair-state Markov chain and analyze eigenvectors