class Solution {
public:
    string removeKdigits(string nums, int k) {
        stack<char>st;
        for(int i=0;i<nums.length();i++)
        {
            while(!st.empty()&&st.top()-'0'>nums[i]-'0'&&k>0)
            {
                st.pop();
                k--;
            }
            
                st.push(nums[i]);
            
        }
        while(k>0&&!st.empty())
        {
            st.pop();
            k--;
        }
        if(st.empty())
        {
            return "0";
        }
        string ans="";
        while(!st.empty())
        {
           ans.push_back(st.top());
            st.pop();
        }
        while(ans.size()!=0&&ans.back()=='0')
        {
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        if(ans.empty())
        {
            return "0";
        }
        return ans;
    }
};