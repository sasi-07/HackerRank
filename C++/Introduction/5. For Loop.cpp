#include <iostream>
#include <cstdio>
using namespace std;

void printNumber(int n){
    if(n == 1)
        cout << "one";
    else if(n == 2)
        cout << "two";
    else if(n == 3)
        cout << "three";
    else if(n == 4)
        cout << "four";
    else if(n == 5)
        cout << "five";
    else if(n == 6)
        cout << "six";
    else if(n == 7)
        cout << "seven";
    else if(n == 8)
        cout << "eight";
    else if(n == 9)
        cout << "nine";
    cout << endl;
}

int main() {
    int a, b;
    cin >> a >> b;
    for(int i = a; i <= b; i++){
        if(i >= 1 && i <= 9){
            printNumber(i);
        }else if(i % 2 == 0){
            cout << "even\n";
        }else{
            cout << "odd\n";
        }
    }
    return 0;
}