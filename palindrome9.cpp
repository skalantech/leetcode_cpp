#include <string>
#include <algorithm>

using std::string;
using std::to_string;
using std::reverse;

class Solution1 {
public:
    bool isPalindrome(int x) {
        std::string entry = to_string(x);
        char rev[80];
        bool res;
        int k = 0;
        int n = entry.size();
        for(int i=n-1; i>=0; i--)
        {
            rev[k]=entry[i];
            k++;
        }
        rev[k]='\0';
        if(entry.compare(rev)==0)
            res=true;
        else
            res=false;
        return res;
    }
};

class Solution2 {
public:
    bool isPalindrome(int x) {
        std::string entry = to_string(x);
        std::string rev = entry;
        bool res;
        reverse(rev.begin(), rev.end());
        if(entry.compare(rev)==0)
            res=true;
        else
            res=false;
        return res;
    }
};

