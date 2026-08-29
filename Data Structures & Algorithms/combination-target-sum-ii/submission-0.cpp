class Solution {
public:
    void sum1(int ind,vector<vector<int>>&ans, vector<int>&curr,vector<int>&candidates,int target){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        for(int i=ind;i<candidates.size();i++){
            if(candidates[i]>target){
                return;
            }
            if(i>ind && candidates[i]==candidates[i-1]){
                continue;
            }
            curr.push_back(candidates[i]);
            sum1(i+1,ans,curr,candidates,target-candidates[i]);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>curr;
        sort(candidates.begin(),candidates.end());
        sum1(0,ans,curr,candidates,target);

        return ans;
    }
};
