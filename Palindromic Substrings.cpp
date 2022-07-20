class Solution {
public:
    int helper(int i, int j, string s){
        if(i<0 or j==s.size() or s[i]!=s[j]){ //Base case
            return 0;
        }
        return (1+helper(i-1,j+1,s));
    }
    int f(int i,int n,string s){
        if(i == n){ // Base case
            return 0;
        }
        int ans1 = helper(i,i,s);
        int ans2 = helper(i,i+1,s);
        return (ans1+ans2+f(i+1,n,s));
    }
    int countSubstrings(string s) {
        return f(0,s.size(),s);
    }
};
