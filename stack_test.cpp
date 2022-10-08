#include "stack.h"
using namespace std;

int main () {
    Stack<int> testStack;
    testStack.push(5);
    cout<<testStack.size()<<endl;//1
    cout<<testStack.top()<<endl;//5
    testStack.pop();
    testStack.push(4);
    testStack.push(3);
    testStack.push(2);
    cout<<testStack.size()<<endl;//3
    cout<<testStack.top()<<endl;//2
    testStack.pop();
    cout<<testStack.top()<<endl;//3
    testStack.pop();
    cout<<testStack.top()<<endl;//4
    testStack.pop();
    return 0;
}