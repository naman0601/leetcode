class Solution {
public:
    bool check(char a,char b){
        if(a=='{' && b=='}')
            return true;
        if(a=='(' && b==')')
            return true;
        if(a=='[' && b==']')
            return true;
        return false;
    }
    bool isValid(string s) {
        stack<char> st;
        for(auto c:s){
            if(c=='(' || c=='{' || c=='[')
                st.push(c);
            else{
                if(st.empty())
                    return false;
                if(check(st.top(),c))
                    st.pop();
                else
                    return false;
            }
        }
            return st.empty();
    }
};