class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        int k=s1.size();

        for(int left=0;left<=s2.size()-k;left++){
            int right=left+k-1;

            unordered_map<char,int>mp;
            for(char c:s1){
                mp[c]++;
            }

            for(int i=left;i<=right;i++){
                mp[s2[i]]--;
            }
            bool ok=true;

            for(auto &p:mp){
                if(p.second!=0){
                    ok=false;
                    break;
                }
            }
            if(ok) return true;
        }
        return false;
    }
};
