#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int height = 0, count = 0;
    bool inValley = false;
    for(char c : s){
        // Compute current height
        height += (c == 'U') ? 1 : -1;
        // If we are going into a valley for the first time,
        // increment count and set inValley to true.
        // Once we are out of a valley, set inValley to false
        if(height < 0 && inValley == false){
            count++;
            inValley = true; 
        }else if(height == 0){
            inValley = false;
        }
    }
    return count;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
