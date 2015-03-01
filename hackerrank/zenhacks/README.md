
Solution for Zenhacks (Feb 2015)

## Find Maximum Index Product

  Go over from left to right, to get LEFT(i) for every i. Maintain a stack during the processing, whose elements are decreasing from bottom to top. For each new element a_i, keep poping the stack until a_i is less than the top, so the index of current top element is LEFT(i). Then push a_i into the stack. 
  
  Same procedure again from right to left. Total complexity is O(n).

## Introduction to Algebra

  Just following the definition, do a brute-forece check.

## Eugene and Big Number

  Divide and conquer. Let's say the final result is F(A, N). If N is even, we can get F(A,N) from F(A, N/2): Assuming F(A,N/2) is x, then F(A,N) = (x * 10^(dig(A) * N/2) + x) % M, where dig(A) is the count of digits of A. When N is odd, we need an extra x * 10^(dig(A) * (N-1).

## Wet Shark and Two Subsequences

  Dynamic programming. Firstly transform the equaltion a little bit, we can get sum(ai) = (r+s) / 2, and sum(bi) = (r-s) / 2. By using dynamic programming, we can get `**dp[i][K] = the number of possible ways to choose exactly i numbers whose sum is K**`. Then the result will be `**sum(dp[len][(r+s)/2] * sum(dp[len][(r-s)/2] for all 1 <= len <= n**`.


