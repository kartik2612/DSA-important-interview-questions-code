class Solution {
public:
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        vector<vector<pair<int,int>>> g(n);
        for(auto x:flights)
        {
            g[x[0]].push_back({x[1],x[2]});
        }
        
 priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>  pq;
        
        pq.push({0,src,0});
        
        while(!pq.empty())
        {
            auto [cost,city,stop]=pq.top();
            pq.pop();
             
                if(city==dst)
                {
                    return cost;
                }
                if(stop>k)
                {
                    continue;
                }
            
            for(auto x:g[city])
            {
                auto [v,w]=x;
               
                pq.push({w+cost,v,stop+1});
                
            }
            
        }
        return -1;
    }
};
