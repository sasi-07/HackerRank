#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    map<string, int> m;
    int q;
    cin >> q;
    while(q--){
        int x;
        string name;
        cin >> x >> name;
        switch(x){
            case 1: int y;
                    cin >> y;
                    m[name] += y;
                    break;
            case 2: m.erase(name);
                    break;
            case 3: if(m.find(name) != m.end()){
                        cout << m[name] << endl;
                    }else{
                        cout << "0\n";
                    }
                    break;
        }
    }  
    return 0;
}