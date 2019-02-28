class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> can = candidates;
        sort(can.begin(), can.end());
        vector<vector<int> > result;
        vector<int> base;
        cal(can, target, base, result);
        return result;
    }
    
    void cal(vector<int>& candidates, int target, vector<int> base,vector<vector<int> >& result) 
    {
        for(int a : candidates){
            if(!base.empty() && a < base.back()){
                continue;
            }
            if(a > target)
                return; 
            else if(a == target){
                base.push_back(a);
                result.push_back(base);
                return;
            }
            else{
                base.push_back(a);
                cal(candidates, target - a, base, result);
                base.pop_back();
            }
        }
    }
};