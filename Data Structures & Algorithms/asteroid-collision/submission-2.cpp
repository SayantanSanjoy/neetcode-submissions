class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        int n=asteroids.size();
        stack<int>st;

        for(int i=0;i<n;i++){
            if(asteroids[i]>0){
                st.push(asteroids[i]);
            }else{
                bool alive=true;
                while(!st.empty() && st.top()>0){
                    int num=st.top();
                    if(num<-(asteroids[i])){
                        st.pop();
                    }else if(num==-asteroids[i]){
                        st.pop();
                        alive=false;
                        break;
                    }else{
                        alive=false;
                        break;
                    }
                }
                if(alive){
                    st.push(asteroids[i]);
                }
            }
        }
        while(!st.empty()){
            int num2=st.top();
            st.pop();
            ans.push_back(num2);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};