#include <iostream>
#include <queue>
using namespace std;
int main() {
	int n, i;
	int sum = 0;
	priority_queue<int, vector<int>, greater<int> >q;
	cin >> n;
	for (i = 1; i <= n; i++) {
		int temp;
		cin >> temp;
		q.push(temp);
	}
	while (q.size() != 1) {
		int x = q.top();
		q.pop();
		int y = q.top();
		q.pop();
		sum += x + y;
		q.push(x + y);
	}
	cout << sum;
	return 0;
}