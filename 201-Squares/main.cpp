//NCC_31060 Majestic
#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

#define input(a) scanf("%d",&a);
#define print_one_blank printf(" ");

void Judge(int (*H)[10], int (*V)[10], int *ans, int n, bool &find_or_not) {
    for (int size = 1; size <= n; ++size) {//size代表要组成的正方形的大小，从1开始
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < n; ++j) {

                if (i + size > n || j + size > n)
                    continue;

                bool match_one = true;
                bool match_two = true;
                int end_i = i + size, end_j = j + size;
                for (int k = 0; k < size; ++k) {
                    if (!(H[i][j + k] && V[j][i + k])) {
                        match_one = false;
                        break;
                    }
                    if (!(H[end_i][end_j - k - 1] && V[end_j][end_i - k - 1])) {
                        match_two = false;
                        break;
                    }
                }
                if (match_one && match_two) {
                    ans[size]++;
                    find_or_not = true;
                }
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("IN.txt", "r", stdin);
#endif
    int n, m;
    int H[10][10], V[10][10];
    int ans[10];
    int cases = 1;
    while (scanf("%d", &n) != EOF) {
        scanf("%d", &m);
        memset(H, 0, sizeof H);
        memset(V, 0, sizeof V);
        memset(ans, 0, sizeof ans);
        for (int i = 0; i < m; ++i) {
            char c;
            int a, b;
            cin >> c >> a >> b;
            if (c == 'H') {
                H[a][b] = 1;
            } else {
                V[a][b] = 1;
            }
        }

//        for (int i = 1; i <= n; ++i) {
//            for (int j = 1; j <= n; ++j) {
//                if (H[i][j])
//                    cout << 'H' << ' ' << i << ' ' << j << endl;
//            }
//        }
//
//        for (int i = 1; i <= n; ++i) {
//            for (int j = 1; j <= n; ++j) {
//                if (V[i][j])
//                    cout << 'V' << ' ' << i << ' ' << j << endl;
//            }
//        }


        bool find_or_not = false;
        Judge(H, V, ans, n, find_or_not);

        if (cases != 1) {
            printf("\n**********************************\n\n");
        }

        printf("Problem #%d\n\n", cases++);

        if (find_or_not) {
            for (int i = 1; i <= n; ++i) {
                if (ans[i] > 0)
                    printf("%d square (s) of size %d\n", ans[i], i);
            }
        } else {
            printf("No completed squares can be found.\n");
        }

    }

    return 0;
}