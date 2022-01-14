class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
      
        vector <int> indegree (numCourses, 0);
        vector <int> * l = new vector <int> [numCourses];
        queue <int> pendingNodes;
        vector <int> ans;
        
        for( auto edge : prerequisites){
            indegree[edge[0]]++;
            l[edge[1]].push_back(edge[0]);
        }
        
        for(int i = 0 ; i < numCourses ; i ++){
            if(indegree[i] == 0)
                pendingNodes.push(i);
        }
        
        while(!pendingNodes.empty()){
            
            int current = pendingNodes.front();
            pendingNodes.pop();
            ans.push_back(current);
            
            for(auto nbr : l[current]){
                 indegree[nbr]--;
                 if(indegree[nbr] == 0)
                     pendingNodes.push(nbr);
                     
            }
        }
        
       return ( ans.size() != numCourses ?  vector <int> () : ans);
    }
};
    