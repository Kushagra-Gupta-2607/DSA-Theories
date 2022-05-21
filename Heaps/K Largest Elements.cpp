// https://practice.geeksforgeeks.org/problems/k-largest-elements3736/1#

vector<int> kLargest(int arr[], int n, int k)
    {
        // code here
        vector<int> v(k);
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i<k; i++) pq.push(arr[i]);
        for(int i = k; i<n; i++){
            if(pq.top()<arr[i]){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        for(int i = k-1; i>-1; i--){
            v[i] = pq.top();
            pq.pop();
        }
        return v;
    }
