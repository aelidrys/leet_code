#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size() - 1;
        int x = 0;
        while (i < j){
           if (nums[i] + nums[j] == k){j--;i++;x++;}
           if (nums[i] + nums[j] > k)j--;
           if (nums[i] + nums[j] < k)i++;
        }
        return x;
    }
};

int main()
{
	int arr[] = {1,2,5,8,4,3,6};
	vector<int> nums(arr,arr+sizeof(arr)/sizeof(int));
	int res = Solution().maxOperations(nums,8);
	cout<<"res = "<<res<<endl;
}
