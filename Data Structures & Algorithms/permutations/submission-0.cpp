class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>&curr,vector<int>&nums,vector<bool>&used){
        if(curr.size()==nums.size()){
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<nums.size();i++){

            if(used[i]){
                continue;
            }
            used[i]=true;
            
            curr.push_back(nums[i]);
            solve(ans,curr,nums,used);
            curr.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        vector<bool>used(nums.size(),false);

        solve(ans,curr,nums,used);

        return ans;
    }
};
