#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n, q;
    cin >> n >> q;
    vector<vector<int> > a(n);
    for(int i=0; i<n; i++){
        int k;
        cin >> k;
        vector<int> b(k);
        for(int j=0; j<k; j++){
            cin >> b[j];
        }
        a[i] = b;
    } 
    while(q--){
        int i, j;
        cin >> i >> j;
        cout << a[i][j] << endl;
    }
    return 0;
}
