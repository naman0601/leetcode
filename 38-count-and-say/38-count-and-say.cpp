class Solution {
public:
    string say(string s){
        string temp;
        int count=1;
        char a=s[0];
        for(int i=1;i<s.length();i++){
            if(a==s[i]){
                count++;
            }
            else{
                temp+=(count+'0');
                temp+=a;
                a=s[i];
                count=1;
            }
        }
       temp+=(count+'0');
        temp+=a;
        return temp;
    }
    string countAndSay(int n) {
        if(n==1)
            return "1";
        return say(countAndSay(n-1));
    }
};