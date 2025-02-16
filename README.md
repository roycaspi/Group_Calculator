Group Calculator

Overview

The Group Calculator is a C++ console application that allows users to perform basic set operations such as union, intersection, and power sets. It also provides functionalities to add, remove, and print sets. The application runs through a simple menu-driven interface.

Features

Add and remove sets dynamically.

Perform set operations, including union, intersection, and power sets.

Print existing sets stored in the calculator.

Error handling for invalid input.

Interactive menu for easy navigation.

Installation

To use this project, clone the repository and navigate to its directory:

git clone https://github.com/roycaspi/Group_Calculator.git
cd Group_Calculator

Ensure you have a C++ compiler installed (GCC recommended).

Compilation

Compile the program using:

g++ -o group_calculator main.cpp GroupCalculator.cpp

Usage

Run the executable by executing:

./group_calculator

Menu Options

Once the program is running, you will see the following menu:

[1] add set
[2] remove set
[3] union
[4] intersection
[5] power set
[6] print
[0] exit

Select an option by entering the corresponding number.

Example Usage

Example 1: Adding a Group

Enter group name: A
Enter group elements: {1, 2, 3}
Group A={1,2,3} added successfully.

Example 2: Removing a Group

Enter group name to remove: A
Group A removed successfully.

Example 3: Union of Two Groups

Enter first group name: A
Enter second group name: B
Enter result group name: C
Result: C={1,2,3,4,5,6} (union of A and B)

Example 4: Intersection of Two Groups

Enter first group name: A
Enter second group name: B
Enter result group name: D
Result: D={2,3} (common elements of A and B)

Example 5: Generating a Power Set

Enter group name: A
Power set of A: P(A)={{},{1},{2},{3},{1,2},{1,3},{2,3},{1,2,3}}

Algorithms & Concepts

The implementation follows fundamental group theory principles:

Closure: Ensures operations remain within the group.

Associativity: Supports mathematical properties of operations.

Identity Elements: Finds and verifies identity elements.

Sorting and Searching: Efficiently organizes and retrieves group elements.

Complexity Analysis

The time complexity depends on the operations performed:

Sorting Groups: O(N log N)

Finding Power Set: O(2^N)

Checking Group Existence: O(N)

Contributions

Contributions are welcome! Feel free to open issues or submit pull requests to improve the functionality.
