#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int getTwiceMedian(int d, vector<int> &count){
    int twiceMedian;
    if(d % 2 == 0){
        int total = 0, m1 = -1, m2 = -1;
        for(int i=0; i<201; i++){
            total += count[i];
            if(m1 == -1 && total >= (d/2)){
                m1 = i;
            }
            if(m2 == -1 && total >= (d/2)+1){
                m2 = i;
                break;
            }
        }
        twiceMedian = m1 + m2;
    }else{
        int total = 0;
        for(int i=0; i<201; i++){
            total += count[i];
            if(total > (d/2)){
                twiceMedian = 2 * i;
                break;
            }
        }
    }
    return twiceMedian;
}

// Complete the activityNotifications function below.
int activityNotifications(vector<int> expenditure, int d) {
    vector<int> count(201, 0);
    // Add first d transactions
    for(int i=0; i<d; i++){
        count[expenditure[i]]++;
    }
    int notification_count = 0;
    for(int i=d; i<expenditure.size(); i++){
        // Calculate median
        int twiceMedian = getTwiceMedian(d, count);
        // Check condition
        if(expenditure[i] >= twiceMedian){
            notification_count++;
        }
        // Update prior transactions
        count[expenditure[i]]++;
        count[expenditure[i-d]]--;
    }
    return notification_count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
