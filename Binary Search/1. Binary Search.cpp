int binarySearch(vector<int>& arr, int target){
    
    int l = 0, r = arr.size()-1;
    while(l<=r){
        int mid = l + (r-l)/2; // integer overflow correction
        if(arr[mid] == target) return mid;
        else if(arr[mid]<target) l = mid+1;
        else r = mid-1;
    }
    return -1;

}

int binarySearch_ReverseSortedArray(vector<int>& arr, int target){
    
    int l = 0, r = arr.size()-1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(arr[mid] == target) return mid;
        else if(arr[mid]<target) r = mid-1;
        else l = mid+1;
    }
    return -1;

}
