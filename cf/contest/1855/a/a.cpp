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
    int n;
    cin >> n;
    int temp;
    int count = 0;
    for (int i=0; i<n; i++) {
      cin >> temp;
      temp--;
      if (i == temp) {
        count++;
      };
    }
    cout << (count + 1) / 2 << endl;
  }
  return 0;
}
