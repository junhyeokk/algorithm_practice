#include <iostream>
#include <cstring>
using namespace std;

int cnt[1000001];
int arr[1000001];
int output[1000001];
int stack[1000001];

int main() {
    int N;
    int top = 0;

    memset(cnt, 0, sizeof(int) * 1000001);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        cnt[arr[i]]++;
    }

    for (int i = N - 1; i >= 0; i--) {
        if (top != 0 && cnt[stack[top - 1]] > cnt[arr[i]]) {
            output[i] = stack[top - 1];
            stack[top++] = arr[i];
            continue;
        }

        while (top != 0) {
            if (cnt[stack[top - 1]] > cnt[arr[i]]) {
                break;
            } else {
                top--;
            }
        }

        if (top != 0) {
            output[i] = stack[top - 1];
            stack[top++] = arr[i];
        } else {
            output[i] = -1;
            stack[top++] = arr[i];
        }

        // cnt[arr[i]]++;
    }

    for (int i = 0; i < N; i++) {
        cout << output[i];
        if (i != N - 1) cout << " ";
    }
    cout << '\n';

    return 0;
}