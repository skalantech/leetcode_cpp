#include <vector>
using std::vector;
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        
        if(nums.size()>1)
        {
            int l=0;
            int m=nums.size()/2;
            int r=nums.size();
            
            vector<int> L;
            vector<int> M;
            
            for(int i=0; i<m; ++i)
                L.push_back(nums[i]);
            for(int i=m; i<r; ++i)
                M.push_back(nums[i]);
            
            sortArray(L);
            sortArray(M);

            int i,j,k;
            i=0;
            j=0;
            k=0;

            while(i<L.size() && j<M.size())
            {
                if(L[i]<M[j])
                {
                    nums[k]=L[i];
                    i++;
                }
                else
                {
                    nums[k]=M[j];
                    j++;
                }
                k++;
            }

            while(i<L.size())
            {
                nums[k]=L[i];
                i++;
                k++;
            }

            while(j<M.size())
            {
                nums[k]=M[j];
                j++;
                k++;
            } 
        }
        return nums;
    }    
};