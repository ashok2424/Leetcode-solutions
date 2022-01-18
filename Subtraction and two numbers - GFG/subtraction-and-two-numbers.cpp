// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
    public:
    int repeatedSubtraction(int a,int b){
        int ans=0;
        while(a!=0 and b!=0){
            if(a>b){
                a-=b;
            }else{
                b-=a;
            }
            ans++;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int A,B;
        cin>>A>>B;
        Solution ob;
        cout<<ob.repeatedSubtraction(A,B)<<"\n";
    }
}  // } Driver Code Ends