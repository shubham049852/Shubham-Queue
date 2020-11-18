#include<bits/stdc++.h>  //Universal Header file of C++
using namespace std;

struct Queue {
	stack<int> s1, s2;
	void enQueue(int x)
	{
		s1.push(x);
	}
	int deQueue()
	{
		if (s1.empty() && s2.empty()) {
			cout << "Q is empty";
			exit(0);
		}
		if (s2.empty()) {
			while (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
		}
		int x = s2.top();
		s2.pop();
		return x;
	}
};

int main()
{
	Queue q;
	q.enQueue(2);
	q.enQueue(5);
	q.enQueue(7);

	cout<<q.deQueue()<<'\n';
	cout<<q.deQueue()<<'\n';
	cout<<q.deQueue()<<'\n';

	return 0;
}
