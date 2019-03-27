// Time: O(n*m)
// Space: O(m) 

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int LCS(string &X, string &Y) {
	int n = X.length();
	int m = Y.length();

	int dp[2][m+1];
	bool curr;

	for(int i = 0; i <= n; i++) {
		
		curr = i & 1;  // Swap curr and prev rows of dp on every iteration
	
		for(int j = 0; j <= m; j++) {
			if(i == 0 || j == 0) {
				dp[curr][j] = 0;	
			}
			else if(X[i-1] == Y[j-1]) {
				dp[curr][j] = dp[1-curr][j-1] + 1;
			}
			else {
				dp[curr][j] = max(dp[1-curr][j], dp[curr][j-1]);
			}
		}
	}
	return dp[curr][m];
}

int main() {

	string s = "XABAYUDDFG";
	string t = "AGHADDFTG";

	cout << LCS(s, t);
}

