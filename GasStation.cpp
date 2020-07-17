class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> diff(n);
        
        for (int i=0;i<n;i++){
            diff[i] = gas[i] - cost[i];
        }
        int index = 0;
        int min = 0,val = 0;
        for (int i=0;i<n;i++){
            val += diff[i];
            if (val<=min){
                index = i;
                min = val;
            }
        }
        
        int start = (index+1)%n;
        val = 0;
        for (int i=0;i<n;i++){
            val += diff[(start+i)%n];
            if (val < 0) return -1;      
        }
        return start;        
    }
};
