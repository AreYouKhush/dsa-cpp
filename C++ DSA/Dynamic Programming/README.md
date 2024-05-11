Dynamic programming is a method used in computer science to solve problems by breaking them down into simpler subproblems. Here's a simple explanation of what dynamic programming is:

1. Dynamic programming is used to solve optimization problems where we need to find the best solution among a set of possible solutions.
2. It involves breaking down a complex problem into smaller, more manageable subproblems.
3. The solutions to these subproblems are stored and reused, which helps avoid redundant computations.
4. Dynamic programming is typically used when the problem has overlapping subproblems, meaning the same subproblem is solved multiple times in the course of solving the larger problem.
5. By storing the solutions to subproblems, dynamic programming reduces the time complexity of the overall problem, making it more efficient.
6. There are two main approaches to dynamic programming: bottom-up and top-down. Bottom-up starts solving the smallest subproblems first and builds up to the larger problem, while top-down starts with the larger problem and breaks it down into smaller subproblems.
7. Dynamic programming is commonly used in algorithms such as the Fibonacci sequence, shortest path problems, and knapsack problems.

In essence, dynamic programming is a technique that helps solve complex problems efficiently by breaking them down into smaller, manageable parts and reusing solutions to subproblems.

1. Recursion: each function calls give rise to 2 more: therefore O(2^n)
2. Memoization: stores in an array: O(n)
   Subproblem results are stored in an array, ensuring that each subproblem is solved only once.
3. Tabulation: iterative approach and takes O(n) subproblems from the smallest to the largest.

RECURSION: Top down: We start from answer, go to the base case and then go back
MEMOIZATION: TOP DOWN:  avoids redundant calls done in recursion reducing time complexity
TABULATION IS: Bottom up: We start from the base case and we try to go to the required answer

## Understanding a DP problem

- Count the total number of ways
- Try possible ways -> Count or Best way -> Recursion (All possible ways)
- Minial or maximal output (Recursion mostly)

## Shortcut

1. Try to represent the problem in terms of index
2. Do all possible stuffs on that index according to the problem statement
3. Sum of all stuffs -> Count all ways
4. Min. or Max. of all stuffs as the question says