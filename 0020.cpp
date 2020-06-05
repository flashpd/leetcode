#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s) 
    {
        stack<char> st;
        for (int i = 0; i < s.length(); ++i)
        {
            /*
             每次扫描到左括号的时候将对应的右括号放入栈中
             每次扫描到右括号的时候直接与栈顶元素进行对比
             如果最后刚好栈为空，则代表括号完全能对应，返回true
             */
            switch(s[i])
            {
                case '(':
                    st.push(')');
                    break;
                case '{':
                    st.push('}');
                    break;
                case '[':
                    st.push(']');
                    break;
                case ')':
                case '}':
                case ']':
                    if (st.empty() || st.top() != s[i])
                        return false;
                    else
                        st.pop();
                    break;
            }
        }
        if (!st.empty())
            return false;
        else 
            return true;
    }
};

int main()
{
    Solution s;
    string str = "";
    cin >> str;
    bool flag = s.isValid(str);
    if (flag)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}


