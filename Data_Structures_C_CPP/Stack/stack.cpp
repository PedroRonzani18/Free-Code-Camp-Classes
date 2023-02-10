#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <ranges>
#include <cctype>

bool balanced_parentheses(std::string str)
{
    std::vector<char> vec;

    std::string aux = "(){}[]";

    for(char i:str)
    {
        if(aux.find(i) != std::string::npos)
        {
            vec.push_back(i);
        }
    }

    if(std::count(vec.begin(), vec.end(),'(') == std::count(vec.begin(), vec.end(),')') && std::count(vec.begin(), vec.end(),')') != 0)
    {
        while(std::count(vec.begin(), vec.end(),'(') == std::count(vec.begin(), vec.end(),')'))
        {
            for(size_t  i=0; i<vec.size(); i++)
            {
                if(vec[i] == '(')
                {
                    if(vec[i+1] == ')')
                    {
                        vec.erase(vec.begin() + i);
                        vec.erase(vec.begin() + i + 1);
                        
                        for(char i: vec)
                        {
                            std::cout << i;
                        }
                        std::cout << std::endl;
                    }
                }
            }
        }
    }
    else return false;


    if(std::count(vec.begin(), vec.end(),'[') == std::count(vec.begin(), vec.end(),']') && std::count(vec.begin(), vec.end(),']') != 0)
    {
        while(std::count(vec.begin(), vec.end(),'[') == std::count(vec.begin(), vec.end(),']'))
        {
            for(size_t  i=0; i<vec.size(); i++)
            {
                if(vec[i] == '[')
                {
                    if(vec[i+1] == ']')
                    {
                        vec.erase(vec.begin() + i);
                        vec.erase(vec.begin() + i + 1);
                        
                        for(char i: vec)
                        {
                            std::cout << i;
                        }
                        std::cout << std::endl;
                    }
                }
            }
        }
    }
    else return false;

    if(std::count(vec.begin(), vec.end(),'{') == std::count(vec.begin(), vec.end(),'}') && std::count(vec.begin(), vec.end(),'}') != 0)
    {
        while(std::count(vec.begin(), vec.end(),'{') == std::count(vec.begin(), vec.end(),'}'))
        {
            for(size_t  i=0; i<vec.size(); i++)
            {
                if(vec[i] == '{')
                {
                    if(vec[i+1] == '}')
                    {
                        vec.erase(vec.begin() + i);
                        vec.erase(vec.begin() + i + 1);
                        
                        for(char i: vec)
                        {
                            std::cout << i;
                        }
                        std::cout << std::endl;
                    }
                }
            }
        }
    }
    else return false;

    return true;

}


bool pair_top(char i, char top)
{
    return((top == '(') && (i == ')') || (top == '[') && (i == ']') || (top == '{') && (i == '}'));
}

bool balanced(std::string str)
{
    using namespace std;

    stack<char> st;

    for(int i=0; i<str.size(); i++)
    {
        if((str[i] == '(') || (str[i] == '[') || (str[i] == '{')) 
            st.push(str[i]);

        else if((str[i] == ')') || (str[i] == ']') || (str[i] == '}'))
        {
            if((st.empty()) || !((st.top() == '(') && (str[i] == ')') || (st.top() == '[') && (str[i] == ']') || (st.top() == '{') && (str[i] == '}')))
            {
                return false;
            }
            else st.pop();
        }
    }

    return st.empty();
}

int evaluate_postfix(std::string str)
{
    std::stack<int> stk;

    for(char ch : str)
    {
        if(ch != '*' && ch != '/' && ch != '+' && ch != '-')
        {
            stk.push((int)ch - '0');
        }
        else
        {
            int n1 = stk.top(); stk.pop();
            int n2 = stk.top(); stk.pop();

            switch (ch)
            {
            case '*': stk.push(n2 * n1);
                break;

            case '+': stk.push(n2 + n1);
                break;

            case '-': stk.push(n2 - n1);
                break;

            case '/': stk.push(n2 / n1);
                break;
            }
        }

    }
    return stk.top();
}

int evaluate_prefix(std::string str)
{
    std::stack<int> stk;

    for (char ch : std::views::reverse(str)) 
    {
        std::cout << ch << std::endl;
        if(ch != '*' && ch != '/' && ch != '+' && ch != '-')
        {
            stk.push((int)ch - '0');
        }
        else
        {
            int n1 = stk.top(); stk.pop();
            int n2 = stk.top(); stk.pop();

            switch (ch)
            {
            case '*': stk.push(n2 * n1);
                break;

            case '+': stk.push(n2 + n1);
                break;

            case '-': stk.push(n1 - n2);
                break;

            case '/': stk.push(n2 / n1);
                break;
            }

            std::cout << stk.top() << std::endl;
        }

    }
    return stk.top();
}

bool has_higher_precedence(char top, char ch)
{
    return((top == '*' || top == '/') && (ch == '+' || ch == '-'));
}

int priority (char alpha){
    if(alpha == '+' || alpha =='-') return 1;
    if(alpha == '*' || alpha =='/') return 2;
    if(alpha == '^') return 3;
    return 0;
}

std::string infix_to_postfix(std::string str)
{
    std::stack<char> stk;
    std::string result = "";

    for(char ch : str)
    {
        if(std::isdigit(ch))
            result += ch;

        else
        {
            while(!stk.empty() && priority(stk.top()) <= priority(ch))
            {
                result += stk.top();
                stk.pop();
            }
            stk.push(ch);
        }
    }

    while(!stk.empty())
    {
        result += stk.top();
        stk.pop();
    }

    return result;
}

using namespace std;

string convert(string infix)
{
    string postfix = "";
    stack <char> s;

    for(char ch : infix)
    {
        if((ch>='a' && ch<='z'|| ch>='A'&& ch<='Z') || isdigit(ch))     
            postfix += ch;

        
        else if(ch=='(')
            s.push(ch);
        

        else if(ch==')')
        {
            while(s.top()!='('){
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
        
        else            
        {
            while (!s.empty() && priority(ch) <= priority(s.top())){
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }
    while(!s.empty()){
        postfix += s.top();
        s.pop();
    }

    return postfix;
}






int main()
{
    // std::cout << evaluate_postfix("23*54*+9-") << std::endl;
    // std::cout << evaluate_prefix("-+*23*549") << std::endl;
    std::cout << convert("1+2*3-4*5") << std::endl;
}