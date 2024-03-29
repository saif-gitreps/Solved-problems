class Solution {
// the recursions works, i need to find a way to do the dp.
public:
    int kev(int n, string str, string s, string t, vector<int> &dp){
        if(n == s.size() - 1){
            if(str == t){
                return 1;
            }
            str += s[n];
            if(str == t){
                return 1;
            }
            else{
                return 0;
            }   
        }
        if(str == t){
            return 1;
        }
        int pick = 0;
        int not_pick = 0;
        str += s[n];
        pick = kev(n + 1, str, s, t, dp);
        str.pop_back();

        not_pick = kev(n + 1, str, s, t, dp);
        return  pick + not_pick;
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        vector<int> dp(n + 1, -1);
        return kev(0 ,"", s, t, dp);
    }
};

class Solution {
// i had to think differently.
public:
    int kev(int i, int j, string s, string t, vector<vector<int>> &dp){
        if(j == t.size()){
            // so when j gets full that means we found a subsequence.
            return 1;  
        }
        if(i == s.size()){
            // when i becomes full that means we ran out of S .
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int pick = 0;
        int not_pick = 0;
        if(s[i] == t[j]){
            // so here if we match a char, we can make two number of moves, 
            // we move both index together, or we move the s index and keep t index constant to see for more subsequence.
            pick = kev(i+1, j+1, s, t, dp) + kev(i+1, j, s , t, dp);
        }
        else{
            not_pick = kev(i+1, j, s, t, dp);
        }
        return dp[i][j] = pick + not_pick;
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return kev(0 , 0, s, t, dp);
    }

};


class Solution {
// so the tabulation was showing some test case errors ,we had to adapt. typecast.
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<double>> dp(n + 1, vector<double> (m + 1, 0));

        //this means for every index of i, if j is 0 then put 1.
        for(int i = 0; i <= n; i++){
            dp[i][0] = 1;
        }
        // we dont need this because , during dp declaration we already gave inner array as 0.
        // for(int j = 0; j <= m; j++){
        //     dp[1][j] = 0;
        // }
        for(int i = 1 ; i <= n; i ++){
            for(int j = 1; j <= m; j ++){
                double pick = 0, not_pick = 0;
                if(s[i - 1] == t[j -1]){
                    pick = dp[i-1][j-1] + dp[i-1][j];
                }
                else{
                    not_pick = dp[i-1][j];
                }
                dp[i][j] = pick + not_pick; 
            }
        }
        return (int)dp[n][m];
    }

};


class Solution {
// sort of understood something , but i understood the prev curr mehtod tho.
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<double> prev(m + 1, 0);       
        prev[0] = 1;
        // remember i - 1 basically means previous. and i means curr.
        for(int i = 1 ; i <= n; i ++){
            for(int j = m; j >=1 ; j --){
                if(s[i - 1] == t[j -1]){
                    prev[j] = prev[j - 1] + prev[j];
                }
            }
        }
        return (int)prev[m];
    }
};
