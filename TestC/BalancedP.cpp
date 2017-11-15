#include <iostream>
#include <string>
#include <vector>

// Little Monk and Balanced Parentheses 
// https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/little-monk-and-balanced-parentheses/ 
using namespace std;
int balancedP()
{
    int n;
    cin>>n;

    vector<int> arr;
    int curElement;
    int maxLength = 0;
    int curMaxLength = 0;
    int previousMaxLength = 0;
    for(int index=0;index<n;++index)
    {
        cin>>curElement;
        if (curElement > 0)
        {
            arr.push_back(curElement);
        }
        else if (curElement < 0)
        {
            if (!arr.empty() && arr.back() == curElement*(-1))
            {
                curMaxLength += 2;
                arr.pop_back();
            }
            else
            {
                arr.clear();
            }

            if (arr.empty())
            {
                previousMaxLength += curMaxLength;
                curMaxLength = 0;
                if (previousMaxLength > maxLength)
                {
                    maxLength = previousMaxLength;
                }
            }
        }
    }

    if (curMaxLength > maxLength)
    {
        maxLength = curMaxLength;
    }

    cout<<maxLength <<"\n";
    return 0;
}