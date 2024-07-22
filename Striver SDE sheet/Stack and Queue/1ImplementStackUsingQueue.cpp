#include<bits/stdc++.h>
using namespace std;

//While pushing first push into q2 then add remaining q1 elements into q2.
//Then swap q1 and q2.
class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }    

        swap(q1,q2);
    }
    
    int pop() {
        int ans=q1.front();
        q1.pop();
        return ans;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        if(q1.size()==0) return true;
        else return false;
    }
};

//Using only one queue
class MyStack {
public:
    queue<int> q;

    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int n=q.size();
        for(int i=0;i<n-1;i++){
            q.push(q.front());
            q.pop();
        }    
    }
    
    int pop() {
        int ans=q.front();
        q.pop();
        return ans;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        if(q.size()==0) return true;
        else return false;
    }
};

