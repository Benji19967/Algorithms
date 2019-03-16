// Bottom-Up DP solution. Efficient if we have to compute all values of C(n, k) from n = 0 up to a certain n.
// Building Pascal's triangle.

#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main() {

    int n;
    cin >> n;

    vector<vi> t; 

    t.push_back(vi(1, 1));
    t.push_back(vi(2, 1));
    cout << 1 << endl;
    cout << 1 << " " << 1 << endl;

    for(int i = 2; i < n; i++) {
        t.push_back(vi(i+1));
        t[i][0] = 1;
        t[i][i] = 1;
        cout << 1 << " ";
        for(int j = 1; j < i; j++) {
            t[i][j] = t[i-1][j-1] + t[i-1][j];
            cout << t[i][j] << " ";
        }
        cout << 1;
        cout << endl;
        t[i-1].clear();
        t[i-1].shrink_to_fit();
    }
}