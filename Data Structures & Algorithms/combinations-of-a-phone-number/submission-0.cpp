class Solution {
public:
    unordered_map<int,string>mp={
        {2,"abc"},
        {3,"def"},
        {4,"ghi"},
        {5,"jkl"},
        {6,"mno"},
        {7,"pqrs"},
        {8,"tuv"},
        {9,"wxyz"}
    };

    void solve(int index,vector<string>&ans, string& digits, string& curr){
        if(digits.length()==curr.length()){
            ans.push_back(curr);
            return;
        }
        int digit=digits[index]-'0';
        
        for(char ch:mp[digit]){
            curr.push_back(ch);
            solve(index+1,ans,digits,curr);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string curr;
        if(digits.empty()){
            return ans;
        }
        solve(0,ans,digits,curr);
        return ans;
    }
};
