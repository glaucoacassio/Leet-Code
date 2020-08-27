class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> ans(numRows);
        if(numRows == 1) return s;
        
        int row = 0;
        int incremento = -1;
        for(int i=0; i<s.length(); i++)
        {
        //se eu cheguei num ponto de virada, nos mudamos a direcao de incremento
            if(i%(numRows-1) == 0) incremento*= -1;
            ans[row].push_back(s[i]);
            row += incremento;
        }
        
        string ret;
        for(const auto& res:ans)
            ret += res;
        
        return ret;
    }
};
