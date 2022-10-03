# Recursive Solution
class Solution {
public:
    void f(string &col, vector<int> &time,int &last, int i, int &n,int &ans){
        if(i == n)
            return;
        if(col[i] == col[last]){
            if(time[i]<time[last]){
                ans+=time[i];
            }
            else{
                ans+=time[last];
                last = i;
            }
        }
        else{
            last = i;
        }
        f(col,time,last,i+1,n,ans);
    }
    int minCost(string colors, vector<int>& time) {
        int last = 0;
        int i = 1;
        int ans = 0;
        int n = colors.size();
        f(colors,time,last,i,n,ans);
        return ans;
    }
};

# Iterative Solution
class Solution {
public:
    int minCost(string colors, vector<int>& time) {
        int last = 0;
        int n = time.size();
        int ans = 0;
        for(int i = 1;i<n;i++){
            if(colors[i] == colors[last]){
                if(time[i]<time[last]){
                    ans+=time[i];
                }
                else{
                    ans+=time[last];
                    last=i;
                }
            }
            else{
                last = i;
            }
        }
        return ans;
    }
};
