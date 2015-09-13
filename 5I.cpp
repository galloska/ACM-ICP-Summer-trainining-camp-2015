#include <bits/stdc++.h>
using namespace std;
 
bool is_upper(char c) {
    return 'A' <= c && c <= 'Z';
}
 
bool is_lower(char c) {
    return 'a' <= c && c <= 'z';
}
 
char to_lower(char c) {
    return 'a' + (c - 'A');
}
 
char to_upper(char c) {
    return 'A' + (c - 'a');
}
 
int main() {
    string s;
    int lang = 0;
    freopen("java_c.in", "r", stdin);
    freopen("java_c.out", "w", stdout);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> s;
    if (s.size() == 0) {
        puts("");
        exit(0);
    }
    if (is_upper(s[0]) || s[0] == '_' || s[s.size() - 1] == '_') {
        puts("Error!");
        exit(0);
    }
    int readund = -1;
    for (int i = 1; i < s.size(); i++) {
        if (is_upper(s[i])) {
            if (lang == 2) {
                puts("Error!");
                exit(0);
            }
            lang = 1;
        } else if (s[i] == '_') {
            if (i - 1 == readund) {
                puts("Error!");
                exit(0);
            }
            readund = i;
            if (lang == 1) {
                puts("Error!");
                exit(0);
            }
            lang = 2;
        }
    }
    if (lang == 1) {
        for (int i = 0; i < s.size(); i++) {
            if (is_upper(s[i])) {
                printf("_%c", to_lower(s[i]));
            } else {
                printf("%c", s[i]);
            }
        }
    } else {
        bool makeupper = false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '_') {
                makeupper = true;
            } else if (makeupper) {
                printf("%c", to_upper(s[i]));
                makeupper = false;
            } else {
                printf("%c", s[i]);
            }
        }
    }
    puts("");
    return 0;
}
