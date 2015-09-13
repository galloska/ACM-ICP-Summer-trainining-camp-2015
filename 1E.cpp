#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    stack< long long int > s;
    long long int a;
    freopen("zero.in", "r", stdin);
    freopen("zero.out", "w", stdout);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    scanf("%d", &n);
    while (n--) {
        scanf("%lld", &a);
        s.push(a);
    }
    while (!s.empty()) {
        cout << s.top();
        s.pop();
        if (!s.empty()) {
            cout << ' ';
        }
    }
    cout << endl;
    cout.flush();
    return 0;
}
