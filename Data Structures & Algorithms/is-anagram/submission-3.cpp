class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size()!=t.size()){
            return false;
        }
        vector<char>d(s.begin(),s.end());
        for(char z:t){
            bool found=false;

            for(int i=0;i<d.size();i++){
                if(z==d[i]){
                    d.erase(d.begin()+i);
                    found=true;
                    break;
                }
            }
            if(!found)return false;
        }
        return d.empty();
    }
};
