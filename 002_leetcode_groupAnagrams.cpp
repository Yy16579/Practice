#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>  ans;
        unordered_map<string,int> map;
        string str;
        unordered_map<string,int>::iterator it;
        int index = 0;
        for(int i=0 ; i<strs.size() ; i++){
            str = strs[i];
            sort(str.begin(),str.end());
            it = map.find(str);
            if(it == map.end()){
                map.insert(pair<string,int>(str,index));
                vector<string> temp;            //创建临时数组，避免越界访问
                temp.push_back(strs[i]);
                ans.push_back(temp);
                index++;
            }else{
                ans[it->second].push_back(strs[i]);
            }
        }
        return ans;
    }

    // vector<vector<string>> groupAnagrams(vector<string>& strs) {
    //     vector<vector<string>>  ans;
    //     unordered_map<string,vector<string>> map;
    //     string key;
    //     for(string& str : strs){
    //         key = str;
    //         sort(key.begin(),key.end());
    //         map[key].push_back(str);    
    //     }
    //     for(auto it=map.begin() ; it != map.end() ; it++){
    //         ans.push_back(it->second);
    //     }
    //     return ans;
    // }
};


int main(){
    //测试数据
    Solution s;
    vector<string> v;
    v.push_back("eat");
    v.push_back("tea");
    v.push_back("tan");
    v.push_back("ate");
    v.push_back("nat");
    v.push_back("bat");

    vector<vector<string>> ans;
    ans = s.groupAnagrams(v);

    for(int i=0 ; i<ans.size() ; i++){
        for(int j=0 ; j<ans[i].size() ; j++){
            cout<<ans[i][j]<<"  ";
        }
        cout<<endl;
    }

    return 0;
}