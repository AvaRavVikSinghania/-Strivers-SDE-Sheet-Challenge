#include<bits/stdc++.h>
 class Queue {
    // Define the data members(if any) here.
    
    public:
    stack<int>top1;
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
       top1.push(val);
    }

    int deQueue() {
        // Implement the dequeue() function.
        if(top1.empty()) return -1;
        vector<int>temp;
        while(top1.size()!=1){
            temp.push_back(top1.top());
            top1.pop();
        }
        int element=top1.top();
        top1.pop();
        for(int i=temp.size()-1;i>=0;i--){
           top1.push(temp[i]);
        }
        return element;
    }

    int peek() {
        // Implement the peek() function here.
        if(top1.empty()) return -1;
        vector<int>temp;
        while(top1.size()!=1){
            temp.push_back(top1.top());
            top1.pop();
        }
        int element=top1.top();

        for(int i=temp.size()-1;i>=0;i--){
           top1.push(temp[i]);
        }
        return element;
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return top1.empty();
    }
};