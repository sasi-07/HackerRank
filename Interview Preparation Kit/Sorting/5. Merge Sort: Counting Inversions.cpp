#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long merge(vector<int> *arr, int start, int mid, int end){
    long count = 0;
    int n1 = mid - start + 1, n2 = end - mid;
    vector<int> leftArray(n1);
    vector<int> rightArray(n2);
    for(int i=0; i<n1; i++){
        leftArray[i] = (*arr)[start + i];
    }
    for(int i=0; i<n2; i++){
        rightArray[i] = (*arr)[i + mid + 1];
    }
    int i = 0, j = 0, k = start;
    while(i < n1 && j < n2){
        if(leftArray[i] <= rightArray[j]){
            (*arr)[k++] = leftArray[i++];
        }else{
            (*arr)[k++] = rightArray[j++];
            count += (n1 - i);
        }
    }
    while(i < n1){
        (*arr)[k++] = leftArray[i++];
    }
    while(j < n2){
        (*arr)[k++] = rightArray[j++];
    }
    return count;
}

long mergeSort(vector<int> *arr, int start, int end){
    if(start >= end){
        return 0;
    }
    long inversions = 0;
    int mid = (start + end)/2;
    inversions += mergeSort(arr, start, mid);
    inversions += mergeSort(arr, mid+1, end);
    inversions += merge(arr, start, mid, end);
    return inversions;
}

// Complete the countInversions function below.
long countInversions(vector<int> arr) {
    int n = arr.size();
    return mergeSort(&arr, 0, n-1);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        long result = countInversions(arr);

        fout << result << "\n";
    }

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
