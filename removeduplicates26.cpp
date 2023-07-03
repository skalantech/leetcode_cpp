#include <vector> 
using std::vector;
using std::size_t;
class Solution1 {
public:
    void swap(int* a, int* b)
    {
        int tmp=*a;
        *a=*b;
        *b=tmp;
    }

    void sort(vector<int>& nums, int size)
    {
        for(int i=0; i<size; ++i)
            for(int j=0; j<size-i;++j)
            {
                if(nums[j]>nums[j+1])
                    swap(&nums[j], &nums[j+1]);
            }
    }

    int removeDuplicates(vector<int>& nums) {
        size_t n = nums.size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n-1;j++)
            {
                if(i!=j+1 && nums[i]==nums[j+1])
                {
                    nums[j+1]=-1;
                    swap(&nums[j+1], &nums[n-1]);
                    n--;
                    j--;
                }
            }          
        }
        sort(nums, n-1);       
        return n;
    }
};

class Solution2 {
public:
    void swap(int* a, int* b)
    {
        int tmp=*a;
        *a=*b;
        *b=tmp;
    }

    int removeDuplicates(vector<int>& nums) {
        size_t n = nums.size();
        int i=0;
        while(i<n-1)
        {
            if(nums[i]==nums[i+1])
            {
                for(int j=i; j<n-1;j++)
                {               
                    swap(&nums[j], &nums[j+1]);
                }
                n--;
            }
            else    
                i++;                     
        }      
        return n;
    }
};