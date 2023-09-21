#include <iostream>
#include <vector>
using namespace std;
int n,k;
vector<bool> vis(n+1);
vector<vector<int>> ans;
void hs(vector<int>& cur, int high, int next){
    if(high>k){
        ans.push_back(cur);
        return;
    }
    for(int i=next;i<=n;i++){
        if(!vis[i]){
            cur.push_back(i);
            vis[i]=true;
            hs(cur, high+1, i+1);
            vis[i]=false;
            cur.pop_back();
        }
    }
}

int main(){

    cin >> n >> k;

    vector<int> cur;
    hs(cur, 1, 1);

    for(int i=0;i<ans.size();i++){
        cout << ans[i][0];
        for(int j=1;j<k;j++){
            cout<< " " << ans[i][j] ;
        }
        cout << endl;
    }

    


    return 0;
}