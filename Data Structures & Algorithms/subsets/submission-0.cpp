class Solution {
public:
    void solve(vector<vector<int>>&ans, vector<int>&curr, vector<int>&nums,int index){
        ans.push_back(curr);

        for(int i=index;i<nums.size();i++){
            curr.push_back(nums[i]);
            solve(ans,curr,nums,i+1);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>curr;
        vector<vector<int>>ans;

        solve(ans,curr,nums,0);
        return ans;
    }
};
