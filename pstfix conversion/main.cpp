
// program to convert infix notation to postfix notation.......

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stack>
using namespace std;
bool isoperand(char s)
{
    if(s=='+'|| s=='-'|| s=='*'|| s=='/'||s=='^'||s=='('||s==')')
        return false;
    return true;
}
// check the precidence of operator.....
int precidence(char s)
{
    if(s==')')
        return 1;
    if(s=='+'|| s=='-')
        return 2;
    else if(s=='*'|| s=='/')
        return 3;
    else if (s=='^')
        return 4;
    else
        return 0;
}

// use the function convert infix to postfix notation....
char *convertpost(char *infix)
{
    char *postfix;
    stack <char>st;
    st.push('#');
    int len=strlen(infix);
    postfix=new char[len+1];
    int i=0,j=0;
    char x;
    while(infix[i] !='\0')
    {
        if(isoperand(infix[i]))
        {
            postfix[j++]=infix[i++];
        }
        else if(infix[i]=='(')
        {
            st.push(infix[i]);
            i++;


        }
        else if(infix[i]==')')
        {
            while((x=st.top()) !='(')
            {
                st.pop();
                postfix[j++]=x;

            }
            i++;


        }
        else
        {
            while(precidence(st.top()) >=precidence(infix[i]))
            {
                postfix[j++]=st.top();
                st.pop();

            }
            st.push(infix[i]);
            i++;
        }

    }
    while(st.top()!='#')
    {
        postfix[j++]=st.top();
        st.pop();
    }
    postfix[j]='\0';
    return postfix;
}
int main()
{
    char *s="a+b*c";


    char *postfix=convertpost(s);
    puts(postfix);


    return 0;
}
