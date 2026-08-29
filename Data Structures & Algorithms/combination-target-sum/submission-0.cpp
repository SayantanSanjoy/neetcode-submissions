class Solution {
public:
    void sum1(int ind,int n,int sum,vector<vector<int>>&ans,vector<int>&curr, vector<int>&nums, int target){
        if(sum==target){
            ans.push_back(curr);
            return;
        }
        if(ind==n||sum>target){
            return;
        }
        for(int i=ind;i<n;i++){
            sum+=nums[i];
            curr.push_back(nums[i]);
            sum1(i,n,sum,ans,curr,nums,target);
            curr.pop_back();
            sum-=nums[i];
            
        }
        //sum1(ind+1,n,sum,ans,curr,nums,target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        int n=nums.size();

        sum1(0,n,0,ans,curr,nums,target);
        return ans;
    }
};
