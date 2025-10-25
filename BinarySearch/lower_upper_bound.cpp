#include <iostream>
#include <vector>

using namespace std;


int lower_bound(vector<int> arr, int key){
    int start = 0;
    int end = arr.size()-1;
    int mid;
    
    int ans = -1;
    
    while(start <= end){
        mid = (start + end)/2;
        
        if(arr[mid] == key){
            ans = mid;
            end = mid - 1;
        }
        else if(arr[mid] > key){
            end = mid - 1 ;
        }
        else{
            start = mid + 1;
        }
    }
    
    return ans;
}


int upper_bound(vector<int> arr, int key){
    int start = 0;
    int end = arr.size()-1;
    int mid;
    
    int ans = -1;
    
    while(start <= end){
        mid = (start + end)/2;
        
        if(arr[mid] == key){
            ans = mid;
            start = mid + 1;
        }
        else if(arr[mid] > key){
            end = mid - 1 ;
        }
        else{
            start = mid + 1;
        }
    }
    
    return ans;
}

int main() {
    vector<int> arr = {0,1,1,2,3,3,3,3,4,5,5,5,10};
    int n = arr.size();
    
    int res1, res2;
    res1 = lower_bound(arr, 10);
    res2 = upper_bound(arr, 10);
    
    cout<<res1<<" "<<res2<<endl;

    return 0;
}
