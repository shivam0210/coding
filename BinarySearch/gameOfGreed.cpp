#include<iostream>
using namespace std;

bool divideAmongK(int arr[], int n, int k, int min_coins){
    int partitions = 0;
    int current_friend = 0;
    for(int i=0; i<n; i++){
        if(current_friend + arr[i] >= min_coins){
            partitions++;
            current_friend = 0;
        }
        else{
            current_friend += arr[i];
        }
    }
    
    return partitions >= k;
}

int k_partition(int *arr, int n, int k){
    int start = 0;
    int end = 0, ans = -1;
    for(int i=0;i<n;i++) end+=arr[i];
    
    while(start <= end){
        int mid = (start+end)/2;
        bool isPossible = divideAmongK(arr, n, k, mid);
        
        if(isPossible){
            start = mid + 1;
            ans = mid;
        }
        else{
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int a[] = {1,2,3,4};
    int n = sizeof(a)/sizeof(int);
    int k = 3; // number of partition
    cout<<k_partition(a, n, k)<<endl;
    
    return 0;
}
