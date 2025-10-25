#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool canPlaceBirds(int B, int N, vector<int> nests, int sep ){
    
    int birds = 1;
    int location = nests[0];
    for(int i=1; i<N-1; i++){
        int dis = nests[i] - location;
        if(dis >= sep){
            birds++;
            location = nests[i];
        }
        if(birds == 3){
            return true;
        }
    }
    return false;
}

int main()
{
    int B = 3;
    vector<int> nests = {1,2,4,8,9};
    //sorting
    sort(nests.begin(), nests.end());
    int N = nests.size();
    
    //Binary Search
    int start = 0, mid, ans = -1;
    int end = nests[N-1] - nests[0];
    while(start <= end){
        mid = (start + end)/2;
        bool canPlace = canPlaceBirds(B,N,nests, mid);
        if(canPlace){
            start = mid + 1;
            ans = mid;
        }
        else{
            end = mid - 1;
        }
    }
    
    cout<<ans<<endl;
    
    
    return 0;
}
