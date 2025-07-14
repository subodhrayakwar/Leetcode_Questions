class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int n=nums.size();
       int sum=n*(n+1)/2;
       int actSum=0;
       for(int num:nums){
        actSum+=num;
       }
        
       return sum-actSum;
    }
};