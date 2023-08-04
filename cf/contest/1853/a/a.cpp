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
    int n, a, temp;
    cin >> n;
    cin >> temp;
    int ans = INT_MAX;
    for (int i=1; i<n; i++) {
      cin >> a;
      if (a < temp) {
        ans = 0;
      }
      else {
        ans = min(ans, (a - temp + 2) / 2);
      }
      temp = a;
    }
    cout << ans << endl;
  }
  return 0;
}
