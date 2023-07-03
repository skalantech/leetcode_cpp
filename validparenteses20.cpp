#include <iostream>
#include <string>

using namespace std;

typedef char Item;

class Stack
{
private:
    enum
    {
        MAX = 10000
    };
    Item items[MAX];
    int top;

public:
    Stack() : top(0) {}
    bool isEmpty() const
    {
        return top == 0;
    }
    bool isFull() const
    {
        return top == MAX;
    }
    bool push(const Item &item)
    {
        if (top < MAX)
        {
            items[top++] = item;
            return true;
        }
        else
            return false;
    }
    Item peek()
    {
        if(top>0)
            return items[top - 1];
        else
            return items[0]='0'; //Possible bug here!
    }
    bool pop()
    {
        if (top > 0)
        {
            items[--top];
            return true;
        }
        else
            return false;
    }
};

class Solution
{
public:
    bool isValid(string s)
    {
        Stack stack;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                stack.push(s[i]);
                //cout << stack.peek() << '\n';
            }
            if (s[i] == ')' || s[i] == ']' || s[i] == '}')
            {
                switch (s[i])
                {
                case ')':
                    if (stack.peek() == '(')
                    {
                        //cout << stack.peek() << '\n';
                        stack.pop();
                    }
                    else
                        stack.push(s[i]);
                    break;
                    

                case ']':
                    if (stack.peek() == '[')
                    {
                        //cout << stack.peek() << '\n';
                        stack.pop();
                    }
                    else
                        stack.push(s[i]);
                    break;
                    

                case '}':
                    if (stack.peek() == '{')
                    {
                        //cout << stack.peek() << '\n';
                        stack.pop();
                    }
                    else
                        stack.push(s[i]);
                    break;
                }
            }
            cout << s[i];
        }
        if (stack.isEmpty())
            return true;
        else
            return false;
    }
};

int main()
{
    string s = "]}}}";
    Solution sol;
    string ans = sol.isValid(s) == true ? "true" : "false"; 
    cout << ans << '\n';
    return 0;
}