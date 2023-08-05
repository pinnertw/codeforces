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
        long long diff_positive = 0;
        long long diff_negative = 0;
        int temp;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            if (temp == 1) {
                diff_positive++;
            }
            else {
                diff_negative += (long long)temp - 1;
            }
        }
        if (n == 1) {
            cout << "NO" << endl;
        }
        else if (diff_negative >= diff_positive) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
