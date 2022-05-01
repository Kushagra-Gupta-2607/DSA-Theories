// https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1/

// Stcok Span = index - Nearest Greater to left index

vector <int> calculateSpan(int price[], int n){
       // Your code here
       stack<pair<int, int>> st;
       vector<int> ans;
       for(int i = 0; i<n; i++){
           if(st.empty()) ans.push_back(i+1);
           else{
               if(st.top().first<=price[i]){
                   st.pop();
                   i--;
                   continue;
               }
               else ans.push_back(i-st.top().second);
           }
           st.push({price[i], i});
       }
       return ans;
}
