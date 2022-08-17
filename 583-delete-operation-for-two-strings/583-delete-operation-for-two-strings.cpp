class Solution {
public:
    int minDistance(string s1, string s2) {
        int n1=s1.length();
        int n2=s2.length();
        
        vector<int> prev(n2,0),cur(n2,0);
        for(int ind1=0;ind1<n1;ind1++){
            for(int ind2=0;ind2<n2;ind2++){
               if(s1[ind1]==s2[ind2] ){
                  cur[ind2]=1;
                  if(ind1>0 && ind2>0)
                      cur[ind2]+=prev[ind2-1];
               }
               else{
                   int choice1=0,choice2=0;
                   if(ind2>0)
                       choice1=cur[ind2-1];
                   if(ind1>0)
                       choice2=prev[ind2];
                   cur[ind2]=max(choice1,choice2);
               }
            }
            prev=cur;
        }
        return n1+n2-(2*prev[n2-1]);
    }
};