#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
    deque<int> dq;
    dq.push_back(0);
	for(int i=1; i<k; i++){
        while(!dq.empty() && arr[i] >= arr[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout << arr[dq.front()] << " ";
    for(int i=k; i<n; i++){
        while(!dq.empty() && arr[i] >= arr[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(!dq.empty() && dq.front() <= i - k){
            dq.pop_front();
        }
        cout << arr[dq.front()] << " ";
    }
    cout << endl;
}

int main(){
  
	int t;
	cin >> t;
	while(t--) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
  	}
  	return 0;
}
