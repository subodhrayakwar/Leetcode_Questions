class Solution {
public:
    bool isHappy(int n) {
        int sum=n,rem,count=0;
        while(true)
        {
            n=sum;
            sum=0;
            while(n!=0)
            {
                rem=n%10;
                sum+=(rem*rem);
                n/=10;
            }
            count++;
            if(sum==1) return 1;
            if(count>50) return 0;
        }
    }
};