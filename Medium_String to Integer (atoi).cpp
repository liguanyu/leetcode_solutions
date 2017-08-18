class Solution {
public:
    int myAtoi(string str) {
        int jd = 1;
        
        int m=0;
        while(m<str.size()&&str[m]==' '){
            if(str[m]==' '){
                str.erase(m,1);
                m--;
            }
            m++;
        }
        
        if(str[0]<'0'||str[0]>'9'){
            if(str[0]=='+'){
                str.erase(0,1);
            }
            else if(str[0]=='-'){
                jd=0;
                str.erase(0,1);
            }
            else{
                return 0;
            }
        }
        
        m=0;
        while(m<str.size()){
            if(str[m]<'0'||str[m]>'9'){
                if(m==0){
                    return 0;
                }
                else{
                    str=str.substr(0,m);
                    break;
                }
            }
            m++;
        }
        int len = str.size();
        
        if(len==0){
            return 0;
        }
        
        int result=0;
        for (int i = 0;i < len ; i++){
            if(result > 214748364 ||(result >= 214748364 && (int)(str[i]-'0') >= 8)){
                if(jd){return 2147483647;}
                else{return -2147483648;}
            }
            else{
                result=result*10+(int)(str[i]-'0');
            }
        }
        if(!jd){
            return 0-result;
        }
        
        return result;
    }
};
