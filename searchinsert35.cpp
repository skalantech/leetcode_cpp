#include <vector>
#include <cstdio>

using std::vector;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i, numsSize;
        numsSize=nums.size();
        if(target==nums[numsSize-1])
            return numsSize-1;        
        else if(target>nums[numsSize-1])
            return numsSize;
        for(i=0; i<numsSize; ++i)
        {
            if(nums[i]==target)
                return i;
            else if(target>nums[i] && target<nums[i+1])
                return i+1;
        }
        return 0;
    }
};

int main()
{
    vector<int> nums {1,3,5,6};
    Solution s;
    int res = s.searchInsert(nums, 4);
    printf("%d\n",res);
}