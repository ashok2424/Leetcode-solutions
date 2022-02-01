class Solution {
public:
    bool isValid(string a) {
        stack<char>st; 
        for(auto &ch:a){
            if(ch=='c'){
                if(st.size()<2){
                    return false;
                }else{
                    char s=st.top(); st.pop();
                    char f=st.top(); st.pop();
                    
                    if(f!='a' or s!='b') return false;
                }
            }
            else{
                st.push(ch); //dont push 'c'
            }
        }
        return st.size()==0;
    }
};
// string str = "abc"; int size = str.size();

// while(s.find(str)!=string ::npos){

//     int ind = s.find(str); 
//     s.erase(ind,size);
// }
// return s=="";