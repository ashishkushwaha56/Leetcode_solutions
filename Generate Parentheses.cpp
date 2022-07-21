class Solution {
public:
    vector<string> ans;
    void f(int &i, int &j, int &n, string &s){
        if(j == n){
            ans.push_back(s);
            return;
        }
        if(j<i){
            s+=')';
            j++;
            f(i,j,n,s);
            s.pop_back();
            j--;
        }
        
        if(i<n){
            s+='(';
            i++;
            f(i,j,n,s);
            s.pop_back();
            i--;
        }
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        int i = 0;
        int j = 0;
        f(i,j,n,s);
        return ans;        
    }
};
