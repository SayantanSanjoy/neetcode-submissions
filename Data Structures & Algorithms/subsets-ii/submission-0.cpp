class Solution {
public:
    void solve(int ind,vector<vector<int>>&ans,vector<int>&curr,vector<int>&nums){
        int n=nums.size();
        ans.push_back(curr);

        for(int i=ind;i<n;i++){
            if(i>ind && nums[i]==nums[i-1]){
                continue;
            }
            curr.push_back(nums[i]);
            solve(i+1,ans,curr,nums);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        sort(nums.begin(),nums.end());
        solve(0,ans,curr,nums);

        return ans;
    }
};
