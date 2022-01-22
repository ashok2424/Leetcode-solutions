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
 
contribution  9           25          9
             'a'  d f c  'e'  b z v  'i'
indices       0   1 2 3   4   5 6 7   8 

just take an example tets case and ull catch the formula
 
=>as there are no prev to a, only subtrings starting with itself can make all the contributions
  "a","ad","adf"...n substrings so contribution is just 9 

=>there are 4 chars prev to e ..so all the substrings that start with these 4 chars and include 
  'e' in them will make the contribution of e,there are 6 options for each char appearing before 
  'e' and for 'e' itself (those 6 are to stop at e/b/f/z/v/i ) so total of (4+1)*(5+1)
  (+1 becuz to include subtrings starting with 'e' itself).
  
  for 'a' the no. of substtrings where it include 'e' are :
  "adfce","adfceb","adfcebz","adfcebzv","adfcebzvi" 
  similarly substring starting with d,f,c and e(itself) ..has 6 subtrings including 'e'
  
=> for last 'i' all the chars (including itself)  will contribuite 1 time each 
   (by including i in them in each of their substring(i will be last char in them))  
  
=> inshort the formula = 
(no. of prev chars including itself) * (no. of chars later to that vowel ,including itself)
    
  
  
  */