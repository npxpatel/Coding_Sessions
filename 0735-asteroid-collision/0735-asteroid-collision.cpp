class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        int n = asteroids.size();
        for(int i = n - 1; i >= 0; i --){
            if(st.empty()){
                st.push(asteroids[i]);
            }
            else{
                
                bool conflict =  (st.top() < 0 && asteroids[i] > 0);
               

                while( conflict && abs(asteroids[i]) >= abs(st.top()) ){

                    if(conflict && abs(asteroids[i]) == abs(st.top())){
                        st.pop();
                        conflict = true;
                        break;
                    }

                     st.pop();
                     if( st.empty()){
                        conflict = false;
                        break;
                     }
                     conflict = (st.top() < 0 && asteroids[i] > 0);
                }

                if(! conflict){
                    st.push(asteroids[i]);
                }

            }
        }

        vector<int>ans;
        while(! st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};