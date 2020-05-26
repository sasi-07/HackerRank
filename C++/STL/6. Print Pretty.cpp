#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
        // Line 1:
        cout << hex << left << showbase << nouppercase;
        cout << (long long) A << endl;

        // Line 2:
        cout << setw(15) << setfill('_') << right << dec << showpos << fixed << setprecision(2);
        cout << B << endl;

        // Line 3:
        cout << setprecision(9) << scientific << noshowpos << uppercase;
        cout << C << endl;
        
	}
    return 0;
}   