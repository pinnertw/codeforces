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
  vi a(t);
  for (int i=0; i<t; i++) {
    cin >> a[i];
  }
  // Use priority queue
  priority_queue<int> pq;
  int max_unlocked_index = 0;
  int score = 0;
  pq.push(a[0]);
  while (!pq.empty()) {
    int temp = pq.top();
    pq.pop();
    score += temp;
    for (int i=max_unlocked_index + 1; i < min(max_unlocked_index + temp - 1, t); i++) {
      pq.push(a[i]);
    }
    max_unlocked_index += temp;
  }
  cout << score << endl;
  return 0;
}
