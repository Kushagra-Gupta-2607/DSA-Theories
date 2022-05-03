// https://practice.geeksforgeeks.org/problems/special-stack/1/#

int minEle;

void push(stack<int>& s, int a){
	// Your code goes here
	if(s.size() == 0) s.push(a), minEle = a;
	else{
	    if(a<minEle) s.push(2*a - minEle), minEle = a;
	    else s.push(a);
	}
}

bool isFull(stack<int>& s,int n){
	// Your code goes here
	return s.size() == n ? 1 : 0;
}

bool isEmpty(stack<int>& s){
	// Your code goes here
	return s.size() == 0 ? 1 : 0;
}

int pop(stack<int>& s){
	// Your code goes here
	if(s.size() == 0) return -1;
	int z;
	if(s.top()>=minEle){
	    z = s.top();
	    s.pop();
	}
	else{
	    z = minEle;
	    minEle = 2*minEle - s.top();
	}
	return z;
}

int getMin(stack<int>& s){
	// Your code goes here
	if(s.size() == 0) return -1;
	return minEle;
}
