#include<bits/stdc++.h>
using namespace std;

vector<int> nearest_smaller_int(vector<int>& v){
    
    int n = v.size();
    vector<int> res;
    stack<int> st;
    
    for(int i = 0; i<n; i++){
        if(st.empty()) res.push_back(-1);
        else{
            if(st.top()>=v[i]){
                st.pop();
                i--;
                continue;
            }else{
                res.push_back(st.top());
            }
        }
        st.push(v[i]);
    }
    
    return res;
}

int main(){
    
    int n;
    cin >> n;
    vector<int> v(n), ans;
    for(int i = 0; i<n; i++) cin >> v[i];

    ans = nearest_smaller_int(v);
    for(int i = 0; i<n; i++) cout << ans[i] << " ";
    
    return 0;
}
