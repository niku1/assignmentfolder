#include<bits/stdc++.h>
using namespace std;
 double distance(int x1,int y1,int x2,int y2)
    {
        return (double)sqrt((double)pow(x2 - x1, 2) +  (double)pow(y2 - y1, 2) );
    }
vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int max_distance=0;
        vector<int> ans(2,0);
        int n=towers.size();

        for(int i=0;i<n;i++)
            {
            int curr_distance=0;
            for(int j=0;j<n;j++)
                {
                double d=distance(towers[i][0],towers[i][1],towers[j][0],towers[j][1]);
                if(d<=radius)
                    curr_distance+=(towers[j][2]/(1+d));
            }
            if(curr_distance>max_distance)
            {
                max_distance=curr_distance;
                ans[0]=towers[i][0];
                ans[1]=towers[i][1];
            }
            else if(curr_distance==max_distance)
            {
                if(ans[0]>towers[i][0] || (ans[0]==towers[i][0] && ans[1]>towers[i][1]) )
                {
                    ans[0]=towers[i][0],ans[1]=towers[i][1];
                }
            }
        }
        return ans;
    }
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> x1;
    for(int i=0;i<n;i++)
    {
        vector<int> x2;
        for(int j=0;j<3;j++)
        {
         int x3;
         cin>>x3;
         x2.push_back(x3);
        }
        x1.push_back(x2);
    }
    int r;
    cin>>r;
   // vector<int> ans;
     vector<int> ans=bestCoordinate(x1,r);
     for(int i=0;i<2;i++)
     {
         cout<<ans[i]<<" ";
     }
}
