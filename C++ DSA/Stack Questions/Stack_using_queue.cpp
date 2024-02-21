#include <bits/stdc++.h>
using namespace std;

class Stack
{
    // Define the data members.
    int front;
    int rear;
    vector<int> arr;

public:
    Stack()
    {
        // Implement the Constructor.
        front = -1;
        rear = -1;
        arr.resize(1000001);
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize()
    {
        // Implement the getSize() function.
        return rear + 1;
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function.
        return front == -1;
    }

    void push(int element)
    {
        // Implement the push() function.
        if (front == -1)
        {
            front++;
            rear++;
            arr[front] = element;
        }
        else
        {
            rear++;
            arr[rear] = element;
        }
    }

    int pop()
    {
        // Implement the pop() function.
        if (front != rear)
        {
            int ans = arr[rear];
            rear--;
            return ans;
        }
        else if (front != -1)
        {
            int ans = arr[rear];
            rear = -1;
            front = -1;
            return ans;
        }
        else
        {
            return -1;
        }
    }

    int top()
    {
        // Implement the top() function.
        if (front != -1)
        {
            return arr[rear];
        }
        else
        {
            return -1;
        }
    }
};

int main(){
    Stack s;
    s.push(5),
    s.push(5);
    s.push(7);
    s.push(9);
    s.push(1);
    cout<<s.pop();
    cout<<s.pop();
    cout<<s.pop();
    cout<<s.pop();
    cout<<s.pop();
    cout<<s.pop();
}