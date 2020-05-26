#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    set<int> s;
    int q, x, y;
    cin >> q;
    while(q--){
        cin >> x >> y;
        if(x == 1){
            s.insert(y);
        }else if(x == 2){
            s.erase(y);
        }else if(x == 3){
            if(s.find(y) != s.end()){
                cout << "Yes\n";
            }else{
                cout << "No\n";
            }
        }
    }
    return 0;
}