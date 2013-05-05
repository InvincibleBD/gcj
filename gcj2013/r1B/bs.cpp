#include <iostream>
#include <cmath>
#include <cfloat>
#include <iomanip>

using namespace std;

#define rep(i,b,e) for(int i=b;i<e;++i)

typedef long long ll;

// N=20までの、辺の位置のダイヤの存在確率のテーブル
// Excelシートで手計算
// 右端 = Px[i+1][X] = Px[i][X] + (1-Px[i][X])*0.5
// 途中 = Px[i+1][x] = Px[i][x] + (Px[i][x+1]-Px[i][x])*0.5
// Px[i][1]が0でなくなったら、Px[i+1][X]は1になる
// 以降は順次、Px[i+1][X-a]が1になっていく
double
P1[4][5] = {{0.5 , 0   ,  0, 0   ,   0.5 },
            {0.75, 0.25,  0, 0.25,   0.75},
            {1   , 0.5 ,  0,  0.5,   1   },
            {1   , 1   ,  0,    1,   1   }};

double
P2[8][9] = {{0.5   , 0     , 0      , 0      ,   0,   0      , 0      , 0     , 0.5},
            {0.75  , 0.25  , 0      , 0      ,   0,   0      , 0      , 0.25  , 0.75},
            {0.875 , 0.5   , 0.125  , 0      ,   0,   0      , 0.125  , 0.5   , 0.875},
            {0.9375, 0.6875, 0.3125 , 0.0625 ,   0,   0.0625 , 0.3125 , 0.6875, 0.9375},
            {1     , 0.8125, 0.5    , 0.1875 ,   0,   0.1875 , 0.5    , 0.8125, 1},
            {1     ,      1, 0.65625, 0.34375,   0,   0.34375, 0.65625, 1     , 1},
            {1     ,      1, 1      , 0.5    ,   0,   0.5    , 1      , 1     , 1},
            {1     ,      1, 1      , 1      ,   0,   1      , 1      , 1     , 1}};

double
P3[5][13] = {{0.5    , 0     , 0     , 0     , 0      , 0, 0, 0, 0      , 0     , 0     , 0     , 0.5},
             {0.75   , 0.25  , 0     , 0     , 0      , 0, 0, 0, 0      , 0     , 0     , 0.25  , 0.75},
             {0.875  , 0.5   , 0.125 , 0     , 0      , 0, 0, 0, 0      , 0     , 0.125 , 0.5   , 0.875},
             {0.9375 , 0.6875, 0.3125, 0.0625, 0      , 0, 0, 0, 0      , 0.0625, 0.3125, 0.6875, 0.9375},
             {0.96875, 0.8125, 0.5   , 0.1875, 0.03125, 0, 0, 0, 0.03125, 0.1875, 0.5   , 0.8125, 0.96875}};


int T;
ll N;
int X,Y;

int main(int argc, char *argv[]) {
    cin>>T;
    for(int t=1;t<=T;++t) {
        cin>>N>>X>>Y;

        double ans=0.0;

        ll d=abs(X)+abs(Y);

        // 足りないので必ず0
        if (N <= (d*(d-1))/2) ans=0.0;

        // 充分にダイヤがあるので必ず1
        else if(N >= ((d+1)*(d+2))/2) ans=1.0;

        // 最外周の辺の場合は確率を計算
        else {
            // 残りの落ちてくるダイヤの数
            ll nl = N-(d*(d-1))/2;
            ll h = d/2+1;

            if (h==2) {
                ans = P1[nl-1][X+2];
            } else
            if (h==3) {
                ans = P2[nl-1][X+4];
            } else {
                ans = P3[nl-1][X+6];
            }
        }
        cout<<"Case #"<<t<<": "<<fixed << setprecision(6)<<ans<<endl;
    }
    return 0;
}
