#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> stack1;
    stack<int> stack2(stack1);

    stack1.push(2);
    stack1.push(4);
    stack1.push(6);
    cout<<"顶部元素为："<<stack1.top()<<endl;
    stack1.pop();//出栈操作是不反回栈顶元素的
    cout<<"顶部元素为："<<stack1.top()<<endl;

    cout<<"stack 是否为空："<<stack1.empty()<<endl;
    cout<<"stack.size: "<<stack1.size()<<endl;

    return 0;
}
