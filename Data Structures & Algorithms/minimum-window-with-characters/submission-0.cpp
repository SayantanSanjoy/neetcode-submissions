class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>count;
        unordered_map<char,int>window;

        for(char c: t){
            count[c]++;
        }
        int have=0;
        int need=count.size();

        int left=0;
        int minLen=INT_MAX;
        int start=0;

        for(int right=0;right<s.size();right++){
            char c=s[right];
            window[c]++;

            if(count.count(c)&& window[c]==count[c]){
                have++;
            }
            while(have==need){
                if(right-left+1<minLen){
                    minLen=right-left+1;
                    start=left;
                }

                window[s[left]]--;

                if(count.count(s[left])&&window[s[left]]<count[s[left]]){
                    have--;
                }
                left++;
            }
        }
        return minLen==INT_MAX ? "":s.substr(start,minLen);
    }
};
