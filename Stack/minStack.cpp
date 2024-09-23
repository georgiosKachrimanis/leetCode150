/*
Just a small explanation of how the solution works

There are two stacks.
One that holds all the values (dataStack), and one that holds only the minimum values (minStack);

Each time a new item is pushed to the stack then we check if is also less than the current top value of the minStack. 
If this is true then the new value becomes the new min. Finally we push the value per normal to the dataStack.

Now each time we pop a value we check if it is the top(minimum value) of the minStack. If this is true we pop the value from both stacks. 
If this is not true means that the minimum value is still inside the dataStack so we leave it in the minStack. 

When there is a request for minimum value the return value is taken from the minStack!
*/

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
    stack<int> dataStack;
    stack<int> minStack;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        dataStack.push(val);

        if (minStack.empty() || val <= minStack.top())
        {
            minStack.push(val);
        }
    }
    
    void pop() {
        if (dataStack.top() == minStack.top())
        {
            minStack.pop();
        }

        dataStack.pop();
    }
    
    int top() {
        return dataStack.top();
        }
    
    int getMin() {
        return minStack.top();
    }
};

