class Solution {
public:
    int max_elt(vector<int> &piles){
        int maxx=INT_MIN;
        for(auto x:piles) maxx=max(maxx,x);
        return maxx;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=max_elt(piles);
        int ans=INT_MAX;
        while(l<=r){
            int k=(l+r)/2;
            long long time_taken=0;
            for(auto value:piles){
                time_taken+=ceil((double)value/k);
            }
            if(time_taken<=h){
                ans=min(ans,k);
                r=k-1;
            }
            else l=k+1;
        }
        return ans;
    }
};