#include<bits/stdc++.h>
using namespace std;
#define triche ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define vi vector<int>
#define vl vector<long long>

int main(){
  triche;
  int t;
  cin >> t;
  while (t--){
    int m, n, k, temp_x, temp_y;
    int init_x, init_y;
    cin >> m >> n >> k;
    cin >> init_x >> init_y;
    init_x += init_y;
    bool ans=false;
    for(int i=0; i<k; ++i){
      cin >> temp_x >> temp_y;
      temp_x += temp_y;
      if ((temp_x - init_x) % 2 == 0){
        ans = true;
      }
    }
    if (ans){
      cout << "NO" << endl;
    }
    else{
      cout << "YES" << endl;
    }
  }
  return 0;
}
