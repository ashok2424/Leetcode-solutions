class Solution {
public:
    bool is_vowel(char &ch){
        return ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u';
    }
    long long countVowels(string s) {
        long long ans = 0; int n = s.size();
        
        for(int i=0;i<s.size();i++){
            
            if(is_vowel(s[i])){
                long long prev_count  = i+1; //including itself
                long long after_count = n-i; //inclusing itself;
                
                long long contribution= prev_count*after_count;
                ans+=contribution;
            }
        }
        return ans;
    }
};/*

 9           25          9
'a'  d f c  'a'  b f v  'a'
 0   1 2 3   4   5 6 7   8 
 
 */