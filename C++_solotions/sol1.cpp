#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int len_n = nums.size();
        int max_n = nums[len_n-1];
        int arry1[len_n];
        int j = len_n;
        while (--j >= 0)
        {
            if (max_n < nums[j])
                max_n = nums[j];
            arry1[j] = max_n;
        }

        int i = 0;
        int min_n = nums[0];
        while (i < len_n){
            if (min_n > nums[i])
                min_n = nums[i];
            if (min_n < nums[i] && nums[i] < arry1[i])
                return true;
            i++;
        }
        return false;
    }
};

int main(){
	int arry[] = {20,1,10,5,30};
	vector<int> nums(arry, arry+sizeof(arry)/4);
	bool res = Solution().increasingTriplet(nums);
    cout<< res <<endl;
}
