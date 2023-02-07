#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>

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

int main()
{
    std::cout << balanced("{({[(])})}") << std::endl;
}