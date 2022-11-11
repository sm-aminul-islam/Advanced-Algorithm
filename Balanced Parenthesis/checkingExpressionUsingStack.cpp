#include<bits/stdc++.h>
using namespace std;
struct Node
{
    char ch;
    Node *next;
    Node(char c)
    {
        this->ch=c;
        this->next=NULL;
    }
};
struct Stack
{
    Node *top;

    Stack()
    {
        this->top=NULL;
    }
    bool isEmpty()
    {
        return top==NULL;
    }
    void push(char ch)
    {
        Node *temp = new Node(ch);
        temp->ch=ch;
        temp->next=top;
        top=temp;
    }
    char Top()
    {
        return top->ch;
    }
    void pop()
    {
        Node *temp=top;
        top=temp->next;
        free(temp);
    }
};

bool is_balance(string &s)
{
    Stack st;
    for(auto ch : s)
    {
        if(ch == '(' or ch == '{' or ch == '[')
        {
            st.push(ch);
        }
        else if(ch == ')')
        {
            if(!st.isEmpty() and st.Top() == '(')
            {
                st.pop();
            }
            else return false;
        }
        else if(ch == '}')
        {
            if(!st.isEmpty() and st.Top() == '{')
            {
                st.pop();
            }
            else return false;
        }
        else if(ch == ']')
        {
            if(!st.isEmpty() and st.Top() == '[')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return st.isEmpty();
}


int main()
{

    string s;
    getline(cin,s);
    if(is_balance(s))
    {
        cout<<"Valid!"<<endl;

    }
    else
    {
        cout<<"Invalid!"<<endl;
    }



}
