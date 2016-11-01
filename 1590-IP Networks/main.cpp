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

typedef struct IP{
    int data[4];
}IP;

IP ip[1001];

int cmp(IP a,IP b){
    for (int i = 0; i < 4; ++i) {
        if(a.data[i] != b.data[i])return a.data[i] < b.data[i];
    }
    return 0;
}

string Ten_To_Binary(int num){
    stack<int> S;
    while(num){
        S.push(num % 2);
        num /= 2;
    }
    string temp = "";
    while(S.size() < 8)S.push(0);
    while(!S.empty()){
        temp += (char)(S.top() + '0');
        S.pop();
    }
    return temp;
}

string IP_To_Binary(IP &a){
    string temp = "";
    for (int i = 0; i < 4; ++i) {
        temp += Ten_To_Binary(a.data[i]);
    }
    return temp;
}

string Get_Mask(string &a,string &b){
    string temp = "";
    for (int i = 0; i < 32; ++i) {
        if(a[i] != b[i])break;
        temp += '1';
    }
    while(temp.length() < 32)temp += '0';
    return temp;
}

string Get_Ans(string &a,string &b){
    string temp = "";
    for (int i = 0; i < 32; ++i) {
        if(a[i] == '1' && b[i] == '1')temp += '1';
        else temp += '0';
    }
    return temp;
}

IP Binary_To_IP(string &a){
    int cal = 0;
    int count = 0;
    IP ip;
    for (int i = 0; i < 32; ++i) {
        cal = cal * 2 + (a[i] - '0');
        if((i + 1) % 8 == 0){
            ip.data[count++] = cal;
            cal = 0;
        }
    }
    return ip;
}

void Print_IP(IP &a){
    for (int i = 0; i < 4; ++i) {
        if(i != 0)printf(".");
        printf("%d",a.data[i]);
    }
    printf("\n");
}

void solve(int n){
    string Min = IP_To_Binary(ip[0]);
    string Max = IP_To_Binary(ip[n-1]);
    string Mask = Get_Mask(Min,Max);
    string ans = Get_Ans(Mask,Min);
    IP mask = Binary_To_IP(Mask);
    IP min = Binary_To_IP(ans);
    Print_IP(min);
    Print_IP(mask);
}


int main() {
#ifdef LOCAL
    freopen("IN.txt", "r", stdin);
#endif
    int m;
    while(scanf("%d",&m) != EOF){
        for (int i = 0; i < m; ++i) {
            scanf("%d.%d.%d.%d",&ip[i].data[0],&ip[i].data[1],&ip[i].data[2],&ip[i].data[3]);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = i + 1; j < m; ++j) {
                if(cmp(ip[i],ip[j]))swap(ip[i],ip[j]);
            }
        }
        solve(m);
    }

    return 0;
}

/*
 * 这个题刚开始一直Runtime Error，还以为是自己写的那一堆函数有问题，结果一直错
 * 于是乎就想看看哪里出错，就删代码，删到核心代码都删没了，只剩下输入排序的时候，还是Runtime Error
 * 于是乎就感觉 ，啊 ！排序有问题啊，删掉排序，果然不RE了，然后自己手写了一个排序，A掉了
 * 这个题也是很有意思，牵扯到IP地址和二进制的事情
 */