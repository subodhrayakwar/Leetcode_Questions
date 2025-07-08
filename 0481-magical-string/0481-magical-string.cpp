class Solution {
public:
    int magicalString(int n) {
        if(n<=3)
        return 1;
        string s="122";
        int ind=2;
        int cnt=1;
        int y=s.size();
        while(y<n){
            if(s.back()=='2'){
                s+='1';
                cnt++;
                if(s[ind]=='2'){
                s+='1';
                cnt++;
                }
            }
            else{
                s+='2';
                if(s[ind]=='2')
                s+='2';
            }
            ind++;
            y=s.size();
        }
        if(s.size()==n)
        return cnt;
        if(s.back()=='1')
        return cnt-1;
        return cnt;
    }
};