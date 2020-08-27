class Solution {
public:
    int reverse(int x) {
        
        string s = to_string(x);          
        std::reverse(s.begin(), s.end());
            
        int value = 0;
        try 
        {
            value = stoi(s);
        } 
        
        catch (...) 
        {
            return 0;
        }
       

        if (x < 0)
            return -value;

        return value; 
      
    }
};
