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
    int n, k, temp;
    cin >> n >> k;
    int c;
    vi last_step(k);
    vi max_step(k);
    vi max_step2(k);
    for (int i=1; i<n+1; i++){
      cin >> c;
      c -= 1;
      temp = i - last_step[c] - 1;
      last_step[c] = i;
      if (temp > max_step[c]){
        max_step2[c] = max_step[c];
        max_step[c] = temp;
      }
      else if (temp > max_step2[c]){
        max_step2[c] = temp;
      }
    }
    int temp2 = INT_MAX;
    for (int i=0; i<k; i++){ // Last step here.
      temp = n - last_step[i];
      if (temp > max_step[i]){
        max_step2[i] = max_step[i];
        max_step[i] = temp;
      }
      else if (temp > max_step2[i]){
        max_step2[i] = temp;
      }
      temp2 = min(temp2, max(max_step[i] / 2, max_step2[i]));
    }
/* #ifdef DEBUG
    for(int i=0; i<k; i++){
      cout << last_step[i] << " " << max_step[i] << " " << max_step2[i] << endl;
    }
    cout << endl;
#endif */
    cout << temp2<< endl;
  }
  return 0;
}
