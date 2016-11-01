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

void Change_Top(char *A, int i) {
    if (i == 1) return;
    else if (i == 2) {
        swap(A[1], A[2]);
        swap(A[2], A[5]);
        swap(A[2], A[6]);
    } else if (i == 3) {
        swap(A[1], A[3]);
        swap(A[3], A[4]);
        swap(A[3], A[6]);
    } else if (i == 4) {
        swap(A[1], A[4]);
        swap(A[4], A[3]);
        swap(A[4], A[6]);
    } else if (i == 5) {
        swap(A[1], A[5]);
        swap(A[5], A[2]);
        swap(A[5], A[6]);
    } else if (i == 6) {
        swap(A[6], A[1]);
        swap(A[2], A[5]);
    }
}

void Change_Y(char *B) {
    swap(B[2], B[4]);
    swap(B[3], B[4]);
    swap(B[4], B[5]);
}

bool Compare(char *A, char *B) {
    for (int i = 1; i <= 6; ++i) {
        if (A[i] != B[i])
            return false;
    }
    return true;
}

bool solve(char *A, char *B) {//这里直接传的指针，所以每次选取一个Top面的时候，都改变了A的样子
    bool Same = false;
    char A_bak[7];
    for (int i = 1; i <= 6; ++i) {//决定哪个面做Top面
        for (int j = 0; j < 7; ++j) {
            A_bak[j] = A[j];
        }
        Change_Top(A_bak, i);
        for (int j = 0; j < 4; ++j) {//旋转三次
            if (Compare(A_bak, B)) {
                Same = true;
                break;
            } else {
                Change_Y(B);
            }
        }
        if (Same)break;
    }
    return Same;
}

int main() {
#ifdef LOCAL
    freopen("IN.txt", "r", stdin);
#endif
    string ipt;
//    cin >> ipt;
//    char A[7],B[7];
//    for (int i = 1; i <= 6; ++i) {
//        A[i] = ipt[i-1];
//        B[i] = ipt[i + 6 - 1];
//    }
//    Change_Top(A,5);
//    Change_Y(B);
//    Change_Y(B);
//    Change_Y(B);
//    for (int i = 1; i <= 6; ++i) {
//        cout << A[i];
//    }
//    cout << endl;
//    for (int i = 1; i <= 6; ++i) {
//        cout << B[i];
//    }


    while (cin >> ipt) {
        char A[7], B[7];
        for (int i = 1; i <= 6; ++i) {
            A[i] = ipt[i - 1];
            B[i] = ipt[i + 6 - 1];
        }
        if (solve(A, B))printf("TRUE\n");
        else printf("FALSE\n");
        ipt.clear();
    }
    return 0;
}