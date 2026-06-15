class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left1=0;
        int right1=matrix.size()-1;

        while(left1<=right1){
            int mid1=(left1+right1)/2;

            if(target<matrix[mid1][0]){
                right1=mid1-1;
            }else if(target>matrix[mid1].back()){
                left1=mid1+1;
            }else{
                int left2=0;
                int right2=matrix[mid1].size()-1;

                while(left2<=right2){
                    int mid2=(left2+right2)/2;
                    if(matrix[mid1][mid2]==target){
                        return true;
                        
                    }else if(matrix[mid1][mid2]<target){
                        left2=mid2+1;
                    
                    }else{
                        right2=mid2-1;
                    }
                }
                return false;
            }
        }
        return false;
    }
};
