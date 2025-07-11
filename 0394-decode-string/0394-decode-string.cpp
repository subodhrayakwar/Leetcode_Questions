class Solution {
public:
    void func(stack<pair<string, int>>&st){
        auto p = st.top();
        string str = "";
        while(p.second != 0){
            str = p.first + str;
            st.pop();
            p = st.top();
        }
        string ans = "";
        int num = stoi(p.first);
        st.pop();
        for (int i = 0; i < num; i++){
            ans += str;
        }
        st.push({ans, 1});
    }

    string decodeString(string s) {
        stack<pair<string, int>> st;
        int val = 0;
        int n = s.size();
        string curr = "";

        for (int i = 0; i < n; i++){
            if (s[i] == '['){
                if (curr.size() > 0) st.push({curr, val});
                curr = "";
            }
            else if (s[i] - '0' >= 0 && s[i] - '0' <= 9){
                if (curr.size() > 0 && val == 1) {
                    st.push({curr, val});
                    curr = "";
                }
                curr += s[i];
                val = 0;
            }else if (s[i] == ']'){
                if (curr.size() > 0) st.push({curr, val});
                func(st);
                curr = "";
            }
            else{
                curr += s[i];
                val = 1;
            }
        }
        if (curr.size() > 0){
            st.push({curr, val});
        }
        
        string ans = "";
        while(!st.empty()){
            auto & p = st.top();
            ans = p.first + ans;
            st.pop();
        }

        return ans;
    }
};