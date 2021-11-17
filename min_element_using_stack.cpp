#include<iostream>
#include<stack>
using namespace std;

class minElement {
    stack<int> st;
    int min;

    public: 
        minElement();
        void push(int);
        void pop();
        int min_element();
};

minElement :: minElement() {
    
}

void minElement :: push (int x) {
    while (this -> st.top() > x && !this -> st.empty()) {
        this -> st.pop();
    }

    this -> st.push(x);
    this -> min = x;
}