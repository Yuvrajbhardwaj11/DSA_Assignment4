#include <iostream>
#include <queue>
using namespace std;

void sortQueue(queue<int>& q) {
    int n = q.size();
    for (int i = 0; i < n; i++) {
        int minVal = INT_MAX, minIndex = -1;
        for (int j = 0; j < q.size(); j++) {
            int curr = q.front();
            q.pop();
            if (j < n - i && curr < minVal) {
                minVal = curr;
                minIndex = j;
            }
            q.push(curr);
        }
        for (int j = 0; j < q.size(); j++) {
            int curr = q.front();
            q.pop();
            if (j == minIndex)
                continue;
            q.push(curr);
        }
        q.push(minVal);
    }
}

int main() {
    queue<int> q;
    q.push(11);
    q.push(5);
    q.push(4);
    q.push(21);
    sortQueue(q);
    while (!q.empty()) {
        cout << q.front() << (q.size() > 1 ? ", " : "\n");
        q.pop();
    }
    return 0;
}
