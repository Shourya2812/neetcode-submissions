class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        for(int num:nums){
            freq[num]++;
        }

        vector<vector<int>> bucket(nums.size()+1);
        for(auto &p:freq){
            int num=p.first;
            int count=p.second;
            bucket[count].push_back(num);
        }

        vector<int> ans;
        for(int i=bucket.size()-1 ; i>=0 ; i--){
            for(int num:bucket[i]){
                ans.push_back(num);
                if(ans.size()==k){
                    return ans;
                }
            }
        }
        return ans;
    }
};
