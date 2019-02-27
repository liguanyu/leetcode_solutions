class Solution {
public:
    string simplifyPath(string path) {
        int len = path.size();
        if(len == 0)
            return path;
        if(path[0] != '/')
            return path;
        
        queue<int> pos_stk;
        stack<string> s_stk;
        
        for(int pos=1; pos<len; pos++){
            if(path[pos] == '/')
                pos_stk.push(pos);
        }
        pos_stk.push(len);
        
        int head = 0;
        int tail = 0;
        
        while(!pos_stk.empty()){
            head = tail;
            tail = pos_stk.front();
            pos_stk.pop();
            
            if(tail > head+1){
                string s = path.substr(head+1, tail-head-1);
                if(s == ".")
                    continue;
                else if(s == ".."){
                    if(!s_stk.empty())
                        s_stk.pop();
                }else{
                    s_stk.push(s);
                }
            }
        }
        
        string result;
        
        while(!s_stk.empty()){
            result = "/" + s_stk.top() + result;
            s_stk.pop();
        }
        
        if(result.size() == 0)
            result += "/";
        
        return result;
        
        
    }
};