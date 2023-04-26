class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int maxa=0;
        int i=0,j=n-1;
        while(i<j){
            maxa=max(maxa,min(height[i],height[j])*(j-i));
            if(height[i]<=height[j])i++;
            else j--;
        }
        return maxa;
    }
};
