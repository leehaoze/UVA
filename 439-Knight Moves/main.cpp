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

int move_x[] = {-2,-2,-1,-1, 1, 1, 2, 2};
int move_y[] = {-1, 1,-2, 2,-2, 2,-1, 1};
int Hash[10][10];

struct Node{
    int x,y,step;
    Node(int a,int b,int c):x(a),y(b),step(c){}
};

bool Is_Legal(int x,int y){
    if(x < 1 || x > 8 || y < 1 || y > 8)return false;
    if(Hash[x][y] == 1)return false;
    return true;
}

int Bfs(Node &start,Node &end){
    queue<Node> horse;
    horse.push(start);
    while(!horse.empty()){
        Node temp = horse.front();
        Hash[temp.x][temp.y] = 1;
        horse.pop();

        for (int i = 0; i < 8; ++i) {
            int dx = temp.x,dy = temp.y;
            dx = dx + move_x[i];
            dy = dy + move_y[i];
            if(dx == end.x && dy == end.y){
                return temp.step + 1;
            }
            if(Is_Legal(dx,dy)){
                horse.push(Node(dx,dy,temp.step + 1));
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("IN.txt", "r", stdin);
#endif
    string A,B;
    while(cin >> A >> B){
        Node start(A[0]-'a'+1,A[1] - '0',0),end(B[0]-'a'+1,B[1]-'0',0);
       // cout << start.x << ' ' << start.y << ";" << end.x << ' ' << end.y << endl;
        memset(Hash,0,sizeof Hash);
        if(start.x == end.x && start.y == end.y)
            printf("To get from %s to %s takes 0 knight moves.\n",A.c_str(),B.c_str());
        else
            printf("To get from %s to %s takes %d knight moves.\n",A.c_str(),B.c_str(),Bfs(start,end));
    }
    return 0;
}