// Bucket - Multiple stack

// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
// push(x) – Push element x onto stack.
// pop() – Removes the element on top of the stack.
// top() – Get the top element.
// getMin() – Retrieve the minimum element in the stack.
// Note that all the operations have to be constant time operations.
// Questions to ask the interviewer :
// Q: What should getMin() do on empty stack? 
// A: In this case, return -1.
// Q: What should pop do on empty stack? 
// A: In this case, nothing. 
// Q: What should top() do on empty stack?
// A: In this case, return -1

// Approach 1 : Store min value also with data in stack
// This uses 2N memory

vector<pair<int,int>> data;

MinStack::MinStack() {
    data.clear();
}

void MinStack::push(int x) {
    int y = x;
    if(data.size()){
        y = min(data.back().second,y);
    }
    data.push_back(make_pair(x,y));
}

void MinStack::pop() {
    if(data.size()){
        data.pop_back();
    }
}

int MinStack::top() {
    if(!data.size()){
        return -1;
    }
    return data.back().first;
}

int MinStack::getMin() {
    if(!data.size()){
        return -1;
    }
    return data.back().second;
}

/***************************************************************************************************************************/

// Approach 2 : Space Optimized Version
// We can limit the number of elements in auxiliary stack. 
// We can push only when the incoming element of main stack is smaller than or equal to top of auxiliary stack. 
// Similarly during pop, if the pop off element equal to top of auxiliary stack, remove the top element of auxiliary stack. 
// Space complexity : O(N + X) where X = number of places where minimum changes or the element is same as the minimum

vector<int> data;
vector<int> mins;

MinStack::MinStack() {
    data.clear();
    mins.clear();
}

void MinStack::push(int x) {
    data.push_back(x);
    if(mins.size()==0||x<=mins.back()){
        mins.push_back(x);
    }
}

void MinStack::pop() {
    if(data.size()==0) return;
    if(mins.back()==data.back()) mins.pop_back();
    data.pop_back();
}

int MinStack::top() {
    if(data.size()==0) return -1;
    return data.back();
}

int MinStack::getMin() {
    if(data.size()==0) return -1;
    return mins.back();
}