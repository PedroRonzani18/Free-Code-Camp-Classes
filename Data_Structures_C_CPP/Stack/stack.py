"""
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
"""

def balanced(string) -> bool:
    stack = []
    
    for i in string: 
        if i in '([{': stack.append(i)
            
        elif i in ')]}':
            if (not stack) or ((stack[-1],i) not in [('(',')'), ('[',']'), ('{','}')]):
                return False
            else:
                stack.pop()
        
    return not stack

print(balanced("[{([[(])])}]"))
