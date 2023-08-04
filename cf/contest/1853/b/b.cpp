#include<bits/stdc++.h>
using namespace std;
#define triche ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define vi vector<int>
#define vl vector<long long>

bool possible(int k, int a, int b) {
  if (k == 1) {
    return true;
  }
  else {
    return a >= 0 && b >= a && possible(k-1, b-a, a);
  }
}

int main(){
  triche;
  int t;
  cin >> t;
  while (t--){
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for (int i=0; i<n+1; i++) {
      if (possible(k, i, n)) {
        ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
