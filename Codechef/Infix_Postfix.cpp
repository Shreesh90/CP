#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool IsOperator(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^') // +, -, *, /, ^
    {
        return true;
    }
    return false;
}


bool IsOperand(char c){
    if(c >= 'A' && c<= 'Z')   return true;
    return false;
} 

int getWeight(char c){
    if(c=='+' || c=='-')
        return 1;
    else if(c=='*' || c=='/')
        return 2;
    else if(c=='^')
        return 3;
}


bool IsHigherPrecedence(char top, char present){
    int w_top = getWeight(top);
    int w_present = getWeight(present);
    if(w_top >= w_present) return true;
    else if(w_top < w_present) return false;
}

string InfixToPostfix(string infix){
    string postfix = "";
    stack<char> op;

    for(int i=0;i<infix.length();i++){
        
        if(infix[i] == ' ')
            continue;

        else if(IsOperator(infix[i])){
            while(!op.empty() && op.top()!='(' && IsHigherPrecedence(op.top(), infix[i])){
                postfix += op.top();
                op.pop();
            }
            op.push(infix[i]);
        }

        else if(IsOperand(infix[i])){
            postfix += infix[i];
        }

        else if(infix[i] == '('){
            op.push(infix[i]);
        }

        else if(infix[i] == ')'){
            while(!op.empty() && op.top() != '('){
                postfix += op.top();
                op.pop();
            }
            op.pop();
        }
    }

    while(!op.empty()){
        postfix += op.top();
        op.pop();
    }

    return postfix;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        string infix; cin>>infix;
        string postfix = InfixToPostfix(infix);
        cout<<postfix<<endl;
    }    
}


