//#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <algorithm>
#include <vector>
#include <assert.h>
using namespace std;

#define MAXN (1<<19)
#define MAXQ 65536


int main() {
    int N, Q;
    long long A[65536];
    long long cmd, x, y, v;
    while (scanf("%d", &N) == 1) {
        for (int i = 1; i <= N; i++)
            scanf("%lld", &A[i]);
        vector<long long> TA(A+1, A+1+N);
        scanf("%d", &Q);
        int verIdx = 0;
        long long encrypt = 0, ret = 0;
        for (int i = 1; i <= Q; i++) {
            scanf("%lld", &cmd);
            cmd ^= encrypt;
            if (cmd == 1) { 		// insert
                scanf("%lld %lld", &x, &v);
                x ^= encrypt, v ^= encrypt;
                assert(0 <= x && x <= TA.size());
                TA.insert(TA.begin()+x, v);
            } else if (cmd == 2) { 	// erase
                scanf("%lld", &x);
                x ^= encrypt;
                assert(1 <= x && x <= TA.size());
                TA.erase(TA.begin()+x-1);
            } else if (cmd == 3) { 	// reverse
                scanf("%lld %lld", &x, &y);
                x ^= encrypt, y ^= encrypt;
                assert(1 <= x && y <= TA.size() && x <= y);
                reverse(TA.begin()+x-1, TA.begin()+y);
            } else if (cmd == 4) { 	// [x, y] += v
                scanf("%lld %lld %lld", &x, &y, &v);
                x ^= encrypt, y ^= encrypt, v ^= encrypt;
                assert(1 <= x && y <= TA.size() && x <= y);
                for (int i = (int) x-1; i < y; i++)
                    TA[i] += v;
            } else if (cmd == 5) {  // max(A[x:y])
                scanf("%lld %lld", &x, &y);
                x ^= encrypt, y ^= encrypt;
                assert(1 <= x && y <= TA.size() && x <= y);
                long long ret = LONG_LONG_MIN;
                for (int i = (int) x-1; i < y; i++)
                    ret = max(ret, TA[i]);
                printf("%lld\n", ret);
                encrypt = ret;
            } else if (cmd == 6) {  // min(A[x:y])
                scanf("%lld %lld", &x, &y);
                x ^= encrypt, y ^= encrypt;
                assert(1 <= x && y <= TA.size() && x <= y);
                long long ret = LONG_LONG_MAX;
                for (int i = (int) x-1; i < y; i++)
                    ret = min(ret, TA[i]);
                printf("%lld\n", ret);
                encrypt = ret;
            } else if (cmd == 7) {  // sum(A[x:y])
                scanf("%lld %lld", &x, &y);
                x ^= encrypt, y ^= encrypt;
                assert(1 <= x && y <= TA.size() && x <= y);
                long long ret = 0;
                for (int i = (int) x-1; i < y; i++)
                    ret += TA[i];
                printf("%lld\n", ret);
                encrypt = ret;
            } else if (cmd == 0) {  // back Day x-th
                scanf("%lld", &x);
                x ^= encrypt;
            } else {
                puts("WTF");
                return 0;
            }
//            for (auto &x: TA)
//                printf("[%3lld]", x);
//            puts("");
        }
    }
    return 0;
}
