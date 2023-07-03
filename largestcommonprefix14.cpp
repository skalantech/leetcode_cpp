#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int g, i, j, k, l, m, shortest, nWords = strs.size();
        string word;
        string other;
        string pattern;
        vector<int> min;
        int newMin;
        if (nWords == 0)
            return pattern;
        else if (nWords == 1)
            return strs[0];
        else
        {
            word = strs[0];
            shortest = word.length();
            for (g = 1; g < nWords; g++)
            {
                if (strs[g].length() < shortest)
                {
                    shortest = strs[i].length();
                }
            }
            for (i = 1; i < nWords; i++)
            {
                other = strs[i];
                k = 0;
                for (j = 0; j < shortest; j++)
                    if (word[j] == other[j])
                        k++;
                    else
                        min.push_back(k);
                min.push_back(k);
            }
            int n = min.size();
            if (n > 0)
            {
                newMin = min[0];
                for (l = 1; l < n; l++)
                {
                    if (min[l] < newMin)
                        newMin = min[l];
                }
                for (m = 0; m < newMin; m++)
                {
                    pattern.push_back(word[m]);
                }
            }
            else
                return pattern;
            return pattern;
        }
    }
};

int main()
{
    vector<string> strs{"flower", "flower", "flower", "flower"};
    Solution p;
    string res = p.longestCommonPrefix(strs);
    std::cout << res;
}