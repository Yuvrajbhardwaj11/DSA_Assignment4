#include <iostream>
#include <queue>
#include <stack>
using namespace std;

string checkSorted(queue<int> q) {
    stack<int> s;
    int expected = 1;
    while (!q.empty()) {
        if (q.front() == expected) {
            q.pop();
            expected++;
        } else if (!s.empty() && s.top() == expected) {
            s.pop();
            expected++;
        } else {
            s.push(q.front());
            q.pop();
        }
    }
    while (!s.empty()) {
        if (s.top() == expected) {
            s.pop();
            expected++;
        } else {
            return "No";
        }
    }
    return "Yes";
}

int main() {
    queue<int> q;
    q.push(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout << checkSorted(q);
    return 0;
}
