class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;

        if(n == 0)
            return result;

        string str = "";
        step(n, str, 0, 0, 0, result);
        return result;
    }

    void step(int n, string str, int left, int right, int time, vector<string> &result){
        if(time >= 2*n){
            result.push_back(str);
        }else{
            if(left == n){
                step(n, str+")", left, right+1, time+1, result);
            }else if(left > right){
                step(n, str+"(", left+1, right, time+1, result);
                step(n, str+")", left, right+1, time+1, result);                
            }else{
                step(n, str+"(", left+1, right, time+1, result);
            }
        }
    }
};