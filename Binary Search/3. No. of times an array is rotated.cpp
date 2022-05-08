// https://practice.geeksforgeeks.org/problems/rotation4723/1/

int findKRotation(int arr[], int n) {
	    // code here
	    int l = 0, r = n-1, ans = 0;
	    while(l<=r){
	        int mid = l+(r-l)/2;
	        if(arr[0]<=arr[mid]) l = mid+1;
	        else ans = mid, r = mid-1;
	    }
	    return ans;
}
