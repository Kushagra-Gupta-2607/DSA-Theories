#include<bits/stdc++.h>
using namespace std;

int firstAndLastOccurrence(vector<int>& v, int i, int target){
    int l = 0, r = v.size()-1, ans = -1;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(v[mid] == target){
            ans = mid;
            if(i == 1) r = mid-1;
            else l = mid+1;
        }
        else if(v[mid]<target) l = mid+1;
        else r = mid-1;
    }
    return ans;
}

int main(){
    
    int n;
    cin >> n;
    vector<int> v(n), res;
    for(int i = 0; i<n; i++) cin >> v[i];
    
    cout << "1. First Occurrence : \n2.Second Occurrence : \n";
    int i, target;
    cin >> i >> target;
    cout << firstAndLastOccurrence(v, i, target);
    
}
