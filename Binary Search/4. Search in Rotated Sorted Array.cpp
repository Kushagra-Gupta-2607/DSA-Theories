// https://leetcode.com/problems/search-in-rotated-sorted-array/

int check(vector<int>& arr, int l, int r, int target){
        while(l<=r){
            int mid = l+(r-l)/2;
            if(arr[mid] == target) return mid;
            if(arr[mid]>target) r = mid-1;
            else l = mid+1;
        }
        return -1;
}
    
int search(vector<int>& arr, int t) {
        int l = 0, r = arr.size()-1, idx = 0;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(arr[0]<=arr[mid]) l = mid+1;
            else idx = mid, r = mid-1;
        }
        int x = check(arr, 0, idx-1, t), y = check(arr, idx, arr.size()-1, t);
        if(x != -1) return x;
        if(y != -1) return y;
        return -1;
}
