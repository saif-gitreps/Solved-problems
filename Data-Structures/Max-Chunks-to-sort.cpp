class Solution {
  // attempt 1: 17 test cases.
public:
    int splityboy(vector<int> &a,int left,int right){
        if(right-left>=2){
            if(is_sorted(a.begin(),a.end())!=true){
                return 1;
            }
        }
        if(left>=right){
            return 1;
        }
        int mid = (left+right)/2;
        int left_split = splityboy(a,left,mid)+1;
        int right_split = splityboy(a,mid+1,right)+1;
        return left_split+right_split;
    }
    int maxChunksToSorted(vector<int>& arr) {
        return splityboy(arr,0,arr.size()-1);
    }
};

class Solution {
  // just like that yt video.
public:
    int maxChunksToSorted(vector<int>& arr) {
        int count = 0;
        int mx = -1;
        for(int i=0;i<arr.size();i++){
            mx = max(arr[i],mx);
            if(mx==i){
                count++;
            }
        }
        return count;
    }
};
