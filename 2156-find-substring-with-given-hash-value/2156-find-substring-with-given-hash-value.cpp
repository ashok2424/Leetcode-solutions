class Solution {
public:
    #define ll long long
    string subStrHash(string s, int p, int mod, int k, int target) {
        string ans="";
        
        ll hash = 0, pr = 1; int n = s.size(),i=n-1,j=n-1;
        
        while(j>=0){
            //multiply each char by p to power 0
            //aslo each time multiply whole hash with p(i,e power given )
            hash = ((hash*p)%mod + (s[j]-'a'+1)*1 )%mod;
            
            if(i-j+1<=k){
                pr = (pr*p)%mod;
            }
            
            else{
                hash = ( (hash - (s[i]-'a'+1)*pr)%mod + mod) %mod; i--;
            }
            
            if(hash==target) ans = s.substr(j,k);
    
            j--;
        }
        return ans;
    }
};

