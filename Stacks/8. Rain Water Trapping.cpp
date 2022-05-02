// https://leetcode.com/problems/trapping-rain-water/

// min( max from left, max from right) - height of the block

int trap(vector<int>& height) {
        int ans = 0, n = height.size();
        vector<int> a(n), b(n);
        for(int i = 0; i<n; i++){
            a[i] = i == 0 ? height[i] : max(height[i], a[i-1]);
            b[n-1-i] = i == 0 ? height[n-1-i] : max(height[n-1-i], b[n-i]);
        }
        for(int i = 0; i<n; i++){
            int z = min(a[i], b[i]);
            ans+= (height[i]<z ? z-height[i] : 0);
        }
        return ans;
}
