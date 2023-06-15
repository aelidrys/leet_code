#include <iostream>
using namespace std;

class Solution {
public:
    int maxVowel(string s, int k) {
        int max = 0,i = 0,j = 0,k1 = 0;
        char c1;
        while (j < k){
            c1 = s[j];
            if (c1 == 'a' || c1 == 'e' || c1 == 'i' || c1 == 'o' || c1 == 'u')k1++;
                j++;
        }
        max = k1;
        while (j < s.length()){
            c1 = s[i];
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')k1--;
            if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')k1++;
            if (k1 > max)
                max = k1;
            if (max == k)
                return (max);
            j++;
            i++;
        }
        return max;
    }
};

int main()
{
	int res = Solution().maxVowel("abciiidef",3);
	cout<<"res = "<<res<<endl;
}