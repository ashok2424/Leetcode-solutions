class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0 ; for(auto &e:batteries) sum+=e;
        long long l = 0,h =sum,ans = -1;
        
        while(l<=h){
            long long mid = l + (h-l)/2;
            
            long long tot_run_time = n*mid, c = 0; 
            for(auto &e:batteries){
                c+=min((long long)e,mid);
            } 
            
            if(c>=tot_run_time){
                l = mid+1; ans = mid; 
            }
            else{ 
                h = mid-1;
            }
        }
        return ans;
    }
};
//we want to run every computer mid minutes simultaneosly at samee time
//so total time  = mid*no. of computers . so  if we can run we move l=mid+1
