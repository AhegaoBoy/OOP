#include "solution.h"
#include <iostream>
#include <stack>

bool solution(std::string const& str)
{
    std::stack<char> open_brackets;
    for(auto iter : str)
    {
        if(iter == '(')
            open_brackets.push(iter);
        else
            open_brackets.pop();
    }
    return open_brackets.empty();
}