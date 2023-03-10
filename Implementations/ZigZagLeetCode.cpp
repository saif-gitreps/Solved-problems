class Solution {
public:
   string convert(string s, int num_row) {
        if(num_row==1){
            return s;
        }
        int n = int(s.size());
        int sections= ceil(n/(2*num_row - 2.0));
        int num_col = sections*(num_row-1);
        vector<vector<char>> matrix(num_row,vector<char>(num_col,' '));
        int cur_row = 0;
        int cur_col = 0;
        int curr_index = 0;
        while(curr_index<n){
            while(cur_row < num_row && curr_index < n){
                matrix[cur_row][cur_col] = s[curr_index];
                curr_index++;
                cur_row++; 
            }
            cur_col++;
            cur_row -= 2;
            while(cur_row>0 && cur_col < num_col && curr_index < n){
                matrix[cur_row][cur_col] = s[curr_index];
                curr_index++;
                cur_row--;
                cur_col++;
            }
        }
        string ans;
        for(auto &x: matrix){
            for(auto &c: x){
                if(c!=' '){
                    ans += c;
                }
            }
        } 
        return ans;
    }
};

class Solution2 {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) {
            return s;
        }
        std::vector<std::string> list(numRows, "");
        int currentLine = 0;
        bool reachedEdge = true;

        for (int i = 0; i < s.length(); ++i) {
            if (currentLine == 0 || currentLine == numRows - 1) {
                reachedEdge = !reachedEdge;
            }
            list.at(currentLine) += s.at(i);
            if (!reachedEdge) {
                currentLine++;
            } else {
                currentLine--;
            }
        }

        std::string result;
        for (int i = 0; i < numRows; ++i) {
            result += list.at(i);
        }
        return result;
    }
};
class Solution3 {
public:
   string convert(string s, int num_row) {
        vector<string> pat(num_row,"");
        int n = s.size();
        for(int k=0;k<n;){
            for(int i=0;i<num_row && k<n;k++){
                pat[i++] += s[k];
            }
            for(int i=num_row-2;i>0 && k<n;k++){
                pat[i--] += s[k];
            }
        }
        string newstr = "";
        for(int i=0;i<pat.size();i++){
            newstr += pat[i];
        }
    return newstr;
    }
};
