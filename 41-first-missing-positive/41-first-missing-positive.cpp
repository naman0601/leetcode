class Solution {
public:
    int firstMissingPositive(vector<int>& v) {
      set<int> s;
      for(int i=0;i<v.size();i++)
         if(v[i]>0)
            s.insert(v[i]);
      int max_value=0;
      int size=v.size();
      bool res=false;
      for(int i=1;i<=size;i++)
         if(s.find(i)==s.end()){
           return i;
         }
      return s.size()+1;
    }
};