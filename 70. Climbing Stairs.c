// Recursive function with memoization
int climbStairsHelper(int n, int memo[]) {
    if (n <= 1) {
        return 1;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    memo[n] = climbStairsHelper(n - 1, memo) + climbStairsHelper(n - 2, memo);
    return memo[n];
}

int climbStairs(int n) {
    int memo[n + 1];
    for (int i = 0; i <= n; i++) {
        memo[i] = -1; // Initialize memoization array
    }
    return climbStairsHelper(n, memo);
}