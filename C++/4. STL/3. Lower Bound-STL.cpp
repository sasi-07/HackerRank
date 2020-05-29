#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, q;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    vector<int>::iterator low;
    cin >> q;
    while(q--){
        int y;
        cin >> y;
        low = lower_bound(v.begin(), v.end(), y);
        int pos = low - v.begin();
        if(v[pos] == y){
            cout << "Yes " << pos + 1 << endl;
        }else{
            cout << "No " << pos + 1 << endl;
        }
    }
    return 0;
}
