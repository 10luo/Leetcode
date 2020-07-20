class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,priority_queue<vector<int>>> save(nums.size());
        for (int num: nums){
            if (save[num-1].size() == 0){
                save[num].push({num});//end point as the key
            }
            else{
                vector<int> temp = save[num-1].top();
                save[num-1].pop();
                temp.push_back(num);
                save[num].push(temp);// vector with largest staring integer, i.e. shortest length will be on the top
            }  
        }
        for (pair<int,priority_queue<vector<int>>> s : save){
            if (s.second.size()>0){
            vector<int> q = s.second.top();// just check the shortest interval for every end point
            if (q.size()<3) return false;
            }
        }
        return true;
        
        
    }
};
