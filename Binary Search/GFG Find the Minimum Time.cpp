//https://practice.geeksforgeeks.org/problems/find-the-minimum-time0253/1/#

int minTime(int S1, int S2, int N){
        // code here
        int x = S1, y = S2;
        if(x>y) swap(x, y);
        
        int l = 0, r = N, ans = INT_MAX;
        while(l<=r){
            int mid = l+(r-l)/2;
            int p = x*mid, q = y*(N-mid);
            ans = min(ans, max(p, q));
            if(p<q) l = mid+1;
            else r = mid-1;
        }
        return ans;
}
