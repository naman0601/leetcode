class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> ps;
        stack<int> s1;
        s1.push(-1);
        for(int i=0;i<heights.size();i++){
            int x=heights[i];
            while(s1.top()!=-1 && heights[s1.top()]>=x)
                s1.pop();
            ps.push_back(s1.top());
            s1.push(i);
        }
        // for(auto x:ps)
        //     cout<<x<<" ";
        cout<<endl;
        stack<int> s;
        s.push(-1);
        vector <int>ns(heights.size()); 
        for(int i=heights.size()-1;i>=0;i--){
        int curr = heights[i];
        while(s.top() != -1 && heights[s.top()] >= curr){
            s.pop();
        }
        ns[i] = s.top();
        s.push(i);
        }
        int maxx=0;
        // for(auto x:ns)
        //     cout<<x<<" ";
        for(int i=0;i<heights.size();i++){
            if(ns[i] == -1){
              ns[i] = heights.size();
            }
            int b = ns[i] - ps[i] - 1;
            int curr = heights[i]*b;
            maxx=max(curr,maxx);
         }
         return maxx;
    }
};