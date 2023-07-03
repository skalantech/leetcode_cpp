#include <map>
#include <string>
#include <iostream>

class Solution {
public:
    int romanToInt(std::string s) {
        std::map<char, int> roman;
        roman['I']=1;
        roman['V']=5;
        roman['X']=10;
        roman['L']=50;
        roman['C']=100;
        roman['D']=500;
        roman['M']=1000;
        int n, i, integer=0;
        n = s.length();
        for(i=0; i<n; ++i)
        {
            if(i<n-1)
            {
                if(s[i]=='I' && (s[i+1]=='V' || s[i+1]=='X'))
                    roman['I']=-1;
                if(s[i]=='X' && (s[i+1]=='L' || s[i+1]=='C'))
                    roman['X']=-10;
                if(s[i]=='C' && (s[i+1]=='D' || s[i+1]=='M'))
                    roman['C']=-100;
            }
            integer=integer+roman[s[i]];
            roman['I']=1;
            roman['X']=10;
            roman['C']=100;
        }
        return integer;
    }
};

int main()
{
    Solution sol;
    std::string str {"MCMXCIV"};
    int res = sol.romanToInt(str);
    std::cout << res;
    return 0;
}