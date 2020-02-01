// Bucket - Multiple stack

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