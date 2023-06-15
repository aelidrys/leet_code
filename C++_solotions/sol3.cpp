#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& hgt) {
        int i = 0;
        int max = -1;
        int s = 1;
        int j = hgt.size() - 1;
        while (i < j){
            if (hgt[i] < hgt[j])
            {
                s = hgt[i] * (j - i);
                i++;
            }
            else
            {
                s = hgt[j] * (j - i);
                j--;
            }
            if (max < s)
                max = s;
        }
        return max;
    }
};

int main()
{
	int arry[] = {0,10,2,5,4,6,-9};
	vector<int> nums(arry, arry + sizeof(arry)/sizeof(int));
	cout<<"res = "<<Solution().maxArea(nums)<<endl;
}
