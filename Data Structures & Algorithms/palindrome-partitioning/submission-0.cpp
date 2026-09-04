class Solution {
public:
    void solve(int index, string s,vector<vector<string>>&ans,vector<string>&path){
        if(index==s.length()){
            ans.push_back(path);
            return;
        }
        for(int i=index;i<s.length();i++){
            if(isPalindrome(index,s,i)){
                path.push_back(s.substr(index,i-index+1));
                solve(i+1,s,ans,path);
                path.pop_back();
            }
        } 
    }
    bool isPalindrome(int start, string s,int last){
        while(start<=last){
            if(s[start++]!=s[last--]){
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>path;
        solve(0,s,ans,path);
        return ans;
    }
};
