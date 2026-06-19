class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double result;

        for(int x:nums2){
            nums1.push_back(x);
        }
        sort(nums1.begin(),nums1.end());

        
        int x=nums1.size()/2;
        if((nums1.size()%2)==0){
            result=(nums1[x-1]+nums1[x])/2.0;
        }else{
            result=nums1[x];
        }
        return result;
    }
};
