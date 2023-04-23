class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        vector<int> v(n+1,1000*1000);
        v[0]=0;
        for(int i=0;i<n;i++){
            int maxh=0,noww=0;
            for(int j=i;j>=0;j--){
                noww+=books[j][0];
                if(noww>shelfWidth)break;
                maxh=max(maxh,books[j][1]);
                v[i+1]=min(v[i+1],maxh+v[j]);
            }

        }
        return v[n];
    }
};
