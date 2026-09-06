class Solution {
public:
    int tribonacci(int n) {
        int first=0;
        int second=1;
        int third=1;
        int ans=0;
        if(n<=1){
            return n;
        }
        if(n==2){
            return 1;
        }
        for(int i=3;i<=n;i++){
            ans=first+second+third;
            first=second;
            second=third;
            third=ans;
        }
        return ans;
    }
};