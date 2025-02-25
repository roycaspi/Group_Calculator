# Group Calculator

## Overview
The **Group Calculator** is a C++ console-based application for performing mathematical set operations such as union, intersection, and power sets. It allows users to dynamically add and remove sets while managing calculations efficiently.

## Features
- **Dynamically add and remove sets**.
- Perform **union, intersection, and power set** calculations.
- Provides **sorting** functionality for set elements.
- Interactive **menu-based UI**.
- Error handling for invalid inputs.

## Installation
```bash
git clone https://github.com/roycaspi/Group_Calculator.git
cd Group_Calculator
```

## Compilation
```bash
g++ -o group_calculator main.cpp GroupCalculator.cpp
```

## Usage
```bash
./group_calculator
```

## Menu Options and Examples
```
[1] Add set
Enter set name: A
Enter elements: {1, 2, 3}
Set A={1,2,3} added successfully.

[2] Remove set
Enter set name: A
Set A removed successfully.

[3] Union
Enter first set: A
Enter second set: B
Enter result set: C
Result: C={1,2,3,4,5}

[4] Intersection
Enter first set: A
Enter second set: B
Enter result set: D
Result: D={2,3}

[5] Power Set
Enter set: A
P(A)={{},{1},{2},{3},{1,2},{1,3},{2,3},{1,2,3}}
```
