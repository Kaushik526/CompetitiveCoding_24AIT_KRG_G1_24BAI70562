class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = -1;
        int prefix_sum = 0;
        for(int i = 0; i < nums.size(); i++){     
            prefix_sum += nums[i];
            int rem = prefix_sum % k;
            if(mp.count(rem)){
                if(i - mp[rem] >= 2)
                    return true;
            }
            else{
                mp[rem] = i;
            }
        }
        return false;
    }
};