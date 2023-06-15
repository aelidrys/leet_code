#include <iostream>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;
        while (j < s.length() && i < t.length()){
            if (t[i] == s[j]){
                j++;
                i++;
            }
            else
                i++;
        }
        if (j == s.length())
            return true;
        return false;
    }
};

int main()
{
	cout<<"s = abc , t = africa bc => res = "<<Solution().isSubsequence("abc","africa bc")<<endl;
	cout<<"s = abc , t = africa b => res = "<<Solution().isSubsequence("abc","africa b")<<endl;
}