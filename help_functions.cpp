#include<bits/stdc++.h>
using namespace std;

// Menu :
// smallest_prime_divisor
// gcd
// lcm
// bezout
// min_cumsum
// largest_digits
// uf_find
// uf_union

template <typename T>
T smallest_prime_divisor(T n){
    T prime = 3;
    if (n % 2 == 0) return 2;
    else{
        while ((n%prime != 0) && prime < sqrt(n)) prime += 2;
    }
    if (prime > sqrt(n)) return n;
    return prime;
}

template <typename T>
T gcd(T a, T b){
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

template <typename T>
T lcm(T a, T b){
    return a * b / gcd(a, b);
}

template <typename T>
pair<T, T> bezout(T a, T b){
    if (a < b) return bezout(b, a);
    if (a % b == 1) return make_pair(1, -a / b);
    else{
        pair<T, T> aibi = bezout(b, a % b);
        aibi = make_pair(aibi.second, aibi.first - a / b * aibi.second);
        return aibi;
    }
}

template <typename T>
T min_cumsum(vector<T> loc){
    T min_ending_here = 0;
    T min_so_far = 0;
    for (int i = 0; i < loc.size(); i++){
        min_ending_here += loc[i];
        if (min_ending_here > 0) min_ending_here = 0;
        if (min_so_far > min_ending_here) min_so_far = min_ending_here;
    }
    return min_so_far;
}

template <typename T>
int largest_digits(T a){
    int largest = 0;
    while (a){
        int r = a % 10;
        a /= 10;
        largest = max(r, largest);
    }
    return largest;
}

int uf_find (vector<int>& parents, int i){
    if (parents[i] == i) return i;
    else{
        parents[i] = uf_find(parents, parents[i]);
        return parents[i];
    }
}

void uf_union (vector<int>& parents, vector<int>& ranks, int i, int j){
    int I = uf_find(parents, i);
    int J = uf_find(parents, j);
    if (I == J) return;
    if (ranks[I] < ranks[J]){
        parents[I] = J;
    }
    else if (ranks[I] > ranks[J]){
        parents[J] = I;
    }
    else{
        parents[J] = I;
        ranks[I]++;
    }
    return;
}
