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
        vi d(n);
        for (int i = 0; i < n; i++){
            cin >> d[i];
        }
        vi a(n);
        bool can_be_reconstructed = true;
        int last_a = 0;
        for (int i = 0; i < n; i++){
            if ((d[i] != 0) && (last_a - d[i] >= 0)){
                can_be_reconstructed = false;
                break;
            }
            else{
                a[i] = last_a + d[i];
                last_a += d[i];
            }
        }
        if (!can_be_reconstructed) cout << -1 << endl;
        else{
            for (int i = 0; i < n; i++){
                cout << a[i] << " ";
            }
            cout << endl;
        }

    }
    return 0;
}
