#include<iostream>
#include<vector>
#include<unordered_map>


using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char,int> need , window;           //两个哈希表，用于存储 需要的和当前窗口的 字符信息
        int valid = 0;                                  //窗口中满足条件的 不同字符的个数 
        int l=0 , r=0;

        for(char& c : p){
            need[c]++;
        }

        while(r < s.size()){
            char c = s[r];
            if(need.count(c)){
                window[c]++;
                if(window[c] == need[c]){      
                    valid++;              //当字符c 存在于窗口中 且 字符数量满足条件 valid++
                }
            }
            r++;
            while(r-l >= p.size()){
                if(valid == need.size()){
                    ans.push_back(l);
                }
                char cl = s[l];
                if(need.count(cl)){
                    if(window[cl] == need[cl]){
                        valid--;
                    }
                    window[cl]--;        
                }
                l++;
            }
        }
        return ans;
    }
};

int main(){
    //测试数据
    string s("aaabc");
    string p("abc");
    Solution sol;
    vector<int> ans;
    ans = sol.findAnagrams(s,p);
    for(int& n : ans){
        cout << n << "  ";
    }

    return 0;
}