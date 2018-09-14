class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 0)
            return true;
        
        std::stack<char> stk;
        
        for(char &c : s){
            switch(c){
                case '(':
                case '[':
                case '{':
                    {
                        stk.push(c);
                        break;
                    }
                case ')':
                    {
                        if(stk.empty())
                            return false;
                        
                        if(stk.top() != '(')
                            return false;
                        else{
                            stk.pop();
                            break;
                        }
                    }                    
                case ']':
                    {
                        if(stk.empty())
                            return false;
                        
                        if(stk.top() != '[')
                            return false;
                        else{
                            stk.pop();
                            break;
                        }
                    }                    
                case '}':
                    {
                        if(stk.empty())
                            return false;
                        
                        if(stk.top() != '{')
                            return false;
                        else{
                            stk.pop();
                            break;
                        }
                    }
            }
        }
        
        if(stk.empty())
            return true;
        else
            return false;
    }
};