#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;
using Paper = vector<vi>;

Paper paper;

vi solve(int N, int x, int y) {
    if (1 == N) {
        vi ans(3, 0);
        if (-1 == paper[y][x]) {
            ans[0] = 1;
        }
        else if (0 == paper[y][x]) {
            ans[1] = 1;
        }
        else if (1 == paper[y][x]) {
            ans[2] = 1;
        }

        return ans;
    }

    vi ans(3, 0);
    auto v = paper[y][x];
    bool isFull{ true };
    for (int i = 0; i < N && isFull; ++i)
    {
        for (int j = 0; j < N && isFull; ++j)
        {
            if (v != paper[y + i][x + j]) {
                isFull = false;
            }
        }
    }

    if (isFull) {
        if (-1 == v) {
            ans[0] = 1;
        }
        else if (0 == v) {
            ans[1] = 1;
        }
        else if (1 == v) {
            ans[2] = 1;
        }

        return ans;
    }

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            auto n3 = N / 3;
            auto sub = solve(n3, x + j * n3, y + i * n3);

            ans[0] += sub[0];
            ans[1] += sub[1];
            ans[2] += sub[2];
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    cin >> N;

    paper = Paper(N, vi(N));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int x;
            cin >> x;

            paper[i][j] = x;
        }
    }

    auto answer = solve(N, 0, 0);

    for (const auto& v : answer)
    {
        cout << v << '\n';
    }

    return 0;
}