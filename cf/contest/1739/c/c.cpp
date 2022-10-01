#include<bits/stdc++.h>
using namespace std;
#define triche ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define vi vector<int>
#define vl vector<long long>
#define N 998244353

vl modulo_inverse (61);

pair<long long, long long> bezout(long long a, long long b){
    if (a < b) return bezout(b, a);
    if (a % b == 1) return make_pair(1, -a / b);
    else{
        pair<long long, long long> aibi = bezout(b, a % b);
        aibi = make_pair(aibi.second, aibi.first - a / b * aibi.second);
        return aibi;
    }
}

long long inv(long long a, long long b){
    return bezout(a, b).second;
}

void find_inverse(){
    modulo_inverse[1] = 1;
    for (long long i = 2; i < 61; i++){
        modulo_inverse[i] = inv(N, i);
    }
}

long long comb(long long n, long long m){
    long long fact = 1;
    for(long long i = 1; i <= n; i++){
        fact *= i;
        fact %= N;
    }
    for (int i = 1; i <= m; i++){
        fact *= modulo_inverse[i];
        fact %= N;
    }
    for (int i = 1; i <= n - m; i++){
        fact *= modulo_inverse[i];
        fact %= N;
    }
    return fact;
}


int main(){
    triche;
    int t;
    cin >> t;
    find_inverse();

    vl a(61);
    vl b(61);

    a[2] = 1;
    b[2] = 0;

    for (long long i = 4; i < 61; i+= 2){
        a[i] = (comb(i-1, i/2) + b[i-2]) % N;
        b[i] = (comb(i-2, i/2) + a[i-2]) % N;
        if(a[i] < 0) a[i] += N;
        if (b[i] < 0) b[i] += N;
    }

    while (t--){
        int n;
        cin >> n;
        cout << a[n] << " " << b[n] << " " << 1 << endl;
    }
    return 0;
}
