class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& sp) {
        vector<pair<int,int>> v; stack<double> s;
        for(int i = 0;i<pos.size();i++) v.push_back({pos[i],sp[i]});
        
        sort(begin(v),end(v));
        
        for(int i = v.size()-1;i>=0;i--){
            double time = (double)(target-v[i].first)/(double)v[i].second;
            
            //if it cant reach the car in front of it in time...push it
            //(it make a fleet on own as it cant join the others
            if(s.empty() or time>s.top()){
                s.push(time);
            }
        }
        return s.size();
    }
};
// [0,3,5,8,10]
// [1,3,1,4,2]

