#include<cctype>
class Solution {
public:
    bool isPalindrome(string s) {
        string result;

        for(char c:s){
            if(isalnum(c)){
                result+=tolower(c);
            }
        }
        int size=result.length();
        
        for(int i=0;i<size;i++){
            if(result[i]!=result[size-i-1]){
                return false;
                break;
            }
        }
        return true;
    }
};
