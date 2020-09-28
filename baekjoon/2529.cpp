#include <iostream>
#include <cstring>
using namespace std;

int k;
char arr[10];
int cand[11];
bool visited[10];
bool done;

void solve1(int depth) {
    if (done) return;

    if (depth == k + 1) {
        for (int i = 0; i < k + 1; i++) {
            cout << cand[i];
        }
        cout << '\n';
        done = true;

        return;
    }

    for (int i = 0; i < 10; i++) {
        if (!visited[i]) {
            if (depth >= 1) {
                if (arr[depth - 1] == '>') {
                    if (cand[depth - 1] > i) {
                        cand[depth] = i;

                        visited[i] = true;
                        solve1(depth + 1);
                        visited[i] = false;
                    }
                } else if (arr[depth - 1] == '<') {
                    if (cand[depth - 1] < i) {
                        cand[depth] = i;

                        visited[i] = true;
                        solve1(depth + 1);
                        visited[i] = false;
                    }
                }
            } else if (depth == 0) {
                cand[depth] = i;

                visited[i] = true;
                solve1(depth + 1);
                visited[i] = false;
            }
        }
    }
}

void solve2(int depth) {
    if (done) return;

    if (depth == k + 1) {
        for (int i = 0; i < k + 1; i++) {
            cout << cand[i];
        }
        cout << '\n';
        done = true;
        
        return;
    }

    for (int i = 9; i >= 0; i--) {
        if (!visited[i]) {
            if (depth >= 1) {
                if (arr[depth - 1] == '>') {
                    if (cand[depth - 1] > i) {
                        cand[depth] = i;

                        visited[i] = true;
                        solve2(depth + 1);
                        visited[i] = false;
                    }
                } else if (arr[depth - 1] == '<') {
                    if (cand[depth - 1] < i) {
                        cand[depth] = i;

                        visited[i] = true;
                        solve2(depth + 1);
                        visited[i] = false;
                    }
                }
            } else if (depth == 0) {
                cand[depth] = i;

                visited[i] = true;
                solve2(depth + 1);
                visited[i] = false;
            }
        }
    }
}

int main() {
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
    }

    memset(visited, 0, sizeof(bool) * 10);
    done = false;
    solve2(0);

    memset(visited, 0, sizeof(bool) * 10);
    done = false;
    solve1(0);

    return 0;
}