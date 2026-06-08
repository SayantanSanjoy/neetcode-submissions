class Solution {
public:
    bool isValid(string s) {
        if(s.length()==1) return false;

        stack<char> st;
        for(char c:s){
            if(c=='['||c=='{'||c=='('){
                st.push(c);
            }
        else{
            if(st.empty())return false;

            char d=st.top();
            st.pop();
            if((d=='('&&c!=')')||(d=='['&&c!=']')||(d=='{'&&c!='}')){
                return false;
            }

        }
    }
        return st.empty();
    }
};
