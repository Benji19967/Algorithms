// Overflow after fibonacci of 100. 
// ull can store up to 2^64.

#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

ull fibonacci(int n, vector<ull> (&memo)) {
	
    if(n == 0 || memo[n] != 0) return memo[n];

    memo[n] = fibonacci(n-1, memo) + fibonacci(n-2, memo);
    return memo[n];
}

int main() {

    int n;
    cin >> n;

    vector<ull> memo(n+1);
    memo[0] = 0;
    memo[1] = 1;

    cout << fibonacci(n-1, memo);  // 10th fibonacci number is 34. 

}