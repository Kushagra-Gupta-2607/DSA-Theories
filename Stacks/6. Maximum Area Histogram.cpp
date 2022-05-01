// https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1

// max = arr[i] * (nearest smallest index from right - nearest smallest index from left - 1)

long long getMaxArea(long long arr[], int n){
        // Your code here
        stack<pair<long long, long long>> st1, st2;
        vector<long long> a, b;
        for(int i = 0; i<n; i++){
            if(st1.empty()) a.push_back(-1);
            else{
                if(st1.top().first>=arr[i]){
                    st1.pop();
                    i--;
                    continue;
                }
                else a.push_back(st1.top().second);
            }
            st1.push({arr[i], i});
        }
        for(int i = n-1; i>-1; i--){
            if(st2.empty()) b.push_back(n);
            else{
                if(st2.top().first>=arr[i]){
                    st2.pop();
                    i++;
                    continue;
                }
                else b.push_back(st2.top().second);
            }
            st2.push({arr[i], i});
        }
        reverse(b.begin(), b.end());
        //for(int i = 0; i<n; i++) cout << a[i] << " " << b[i] << endl;
        
        long long ans = 0;
        for(int i = 0; i<n; i++){
            long long z = arr[i]*(b[i]-a[i]-1);
            //cout << z << endl;
            ans = max(ans, z);
        }
        return ans;
        
}
