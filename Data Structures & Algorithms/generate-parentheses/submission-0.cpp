class Solution {
public:
    void solve(int left,int right,vector<string>&ans,string curr,int n){
        if(curr.length()==2*n){
            ans.push_back(curr);
            return;
        }
        if(left<n){
            curr.push_back('(');
            solve(left+1,right,ans,curr,n);
            curr.pop_back();
        }
        if(right<left){
            curr.push_back(')');
            solve(left,right+1,ans,curr,n);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr="";
        vector<string>ans;

        solve(0,0,ans,curr,n);
        return ans;
    }
};
