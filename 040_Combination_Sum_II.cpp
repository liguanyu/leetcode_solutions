class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> can = candidates;
        sort(can.begin(), can.end());
        
        vector<int> truecan;
        map<int, int> count_map;
        
        for(int a : can){
            if(count_map.find(a) == count_map.end()){
                truecan.push_back(a);
                count_map[a] = 1;
            }else{
                count_map[a]++;
            }
        }
        vector<vector<int> > result;
        vector<int> base;
        cal(truecan, count_map, 0, target, base, result);
        return result;
    }
    
    void cal(vector<int>& candidates, map<int, int> count_map, int index, int target, vector<int> base,vector<vector<int> >& result) 
    {
        for(int i=index; i<candidates.size(); i++){
            int a = candidates[i];
            if(count_map[a] == 0)
                continue;

            if(a > target)
                return; 
            else if(a == target){
                base.push_back(a);
                result.push_back(base);
                return;
            }
            else{
                base.push_back(a);
                count_map[a]--;
                cal(candidates, count_map, i, target - a, base, result);
                count_map[a]++;
                base.pop_back();
            }
        }
    }
};