#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k0) {
        int i = 1;
        double x = 0;
        double res = 0;
        double k = k0;
        while (i < nums.size()){
           nums[i] += nums[i-1];i++;
        }
        i = k - 1;
        res = (double)nums[i++] / k;
        while (i < nums.size()){
            x = (double)(nums[i] - nums[i - k]) / k;
            if (res < x)
                res = x;
            i++;
        }
        return res;
    }
};

int main()
{
	int arry[] = {0,10,2,5,4,6,-9};
	vector<int> nums(arry, arry + sizeof(arry)/sizeof(int));
	cout<<"res = "<<Solution().findMaxAverage(nums,3)<<endl;
}