class Solution {
public:
    string lastSubstring(string s) {
        int i=0,j=1,n=s.size(),k;
        while(j<n){
            if(s[i]<s[j]){
                i=j;
                j++;
            }
            else if(s[i]==s[j]){
                k=0;
                while(s[i+k]==s[j+k]&&j+k+1<n)k++;
                if(s[i+k]<s[j+k]){
                    int t=i;
                    i=j;
                    j=max(j+1,t+k+1);
                }else j=j+k+1;
            }else j++;
        }
        return s.substr(i,n-i);
    }
};
