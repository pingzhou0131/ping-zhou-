class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v;
        int n=nums.size(),j,z;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            if(i>0&&nums[i]==nums[i-1])continue;
            j=i+1;z=n-1;
            while(j<z){
                if(j>i+1&&nums[j]==nums[j-1]){
                    j++;continue;
                }
                if(z<n-1&&nums[z]==nums[z+1]){
                    z--;continue;
                }
                if(nums[i]+nums[j]+nums[z]==0){
                    v.push_back({nums[i],nums[j],nums[z]});
                    z--;
                }else if(nums[i]+nums[j]+nums[z]>0)z--;
                else j++;
            }
        }
        
        return v;
    }
};
