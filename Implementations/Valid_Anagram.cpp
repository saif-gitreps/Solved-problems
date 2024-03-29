class Solution {
  // O(nlogn) soln.
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
    }
};

class Solution {
public:
  //best solution.
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        vector<int> v(26,0);
        for(int i=0;i<s.size();i++){
            v[s[i]-'a']++;
            v[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(v[i]!=0)
            return false;
        }
        return true;

    }
};
