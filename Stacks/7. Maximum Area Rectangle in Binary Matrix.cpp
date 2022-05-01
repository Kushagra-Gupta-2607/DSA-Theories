// https://leetcode.com/problems/maximal-rectangle/

void maxAreaHistogram(vector<int>& v, int &ans){
        int n = v.size();
        stack<pair<int, int>> st;
        vector<int> a;
        for(int i = n-1; i>-1; i--){
            if(st.empty()) a.push_back(n);
            else{
                if(st.top().first>=v[i]){
                    st.pop();
                    i++;
                    continue;
                }
                else a.push_back(st.top().second);
            }
            st.push({v[i], i});
        }
        reverse(a.begin(), a.end());
        while(!st.empty()) st.pop();
        for(int i = 0; i<n; i++){
            if(st.empty()) ans = max(ans, v[i]*a[i]);
            else{
                if(st.top().first>=v[i]){
                    st.pop();
                    i--;
                    continue;
                }
                else ans = max(ans, v[i]*(a[i]-st.top().second-1));
            }
            st.push({v[i], i});
        }
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), ans = 0;
        vector<int> v(m, 0);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == '0') v[j] = 0;
                else v[j]+=1;
            }
            maxAreaHistogram(v, ans);
        }
        return ans;
    }
