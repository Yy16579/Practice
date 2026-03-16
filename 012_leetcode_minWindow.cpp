#include<iostream>
#include<unordered_map>


using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()){
            return "";
        }
        
        unordered_map<char , int> need;
        for(char& c : t){
            need[c]++;
        }

        int start = -1;
        int min_len = s.size() + 1;
        unordered_map<char , int> wind;
        int valid = 0;
        int l=0 , r=0;
        while(r < s.size()){
            char c = s[r];
            if(need.find(c) != need.end()){
                wind[c]++;
                if(wind[c] == need[c]){
                    valid++;
                }
            }
            r++;

            while(valid == need.size()){
                if(r-l < min_len){
                    start = l;
                    min_len = r-l;
                }
            
                char cl = s[l];
                if(need.find(cl) != need.end()){
                    wind[cl]--;
                    if(wind[cl] < need[cl]){
                        valid--;
                    }
                }
                l++;
            }
        }
        return start == -1 ? "" : s.substr(start , min_len);
    }
};

int main(){
    

    return 0;
}