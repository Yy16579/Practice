#include<iostream>
#include<unordered_set>


using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0){
            return 0;
        }
        int ans = 0;
        unordered_set<char> set;
        int l=0 , r=0;
        while(r < s.size()){
            while(set.find(s[r]) != set.end()){
                set.erase(s[l]);
                l++;
            }
            set.insert(s[r]);
            r++;
            ans = max(ans , r-l);
        }
        return ans;
    }
};

int main(){
    


    return 0;
}