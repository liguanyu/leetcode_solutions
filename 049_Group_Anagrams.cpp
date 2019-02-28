class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<char>, vector<string> > mp;
        vector<vector<string> > result;
        
        if(strs.size() == 0)
            return result;
        
        for(string &s : strs){
            vector<char> v_c;
            for(char &c : s){
                v_c.push_back(c);
            }
            sort(v_c.begin(), v_c.end());
            if(mp.find(v_c) == mp.end()){
                vector<string> tmp;
                mp[v_c] = tmp;
            }
            mp[v_c].push_back(s);
        }
        
        map<vector<char>, vector<string> >::iterator it;
        it = mp.begin();
        while(it != mp.end()){
            result.push_back(it->second);
            it++;
        }
        
        return result;
    }
};