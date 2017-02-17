#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

template<typename T>
class MyQueue //use 2 stacks to implement the queue 
{
public:
	void Push(const T& x)
	{
		s1.push(x);
	}

	void Pop()
	{
		if (!s2.empty())
			s2.pop();
		else
		{
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
			s2.pop();
		}
	}

	T& Front()
	{
		if (!s2.empty())
			return s2.top();
		else
		{
			while (!s1.empty()) //!s1.empty()
			{
				s2.push(s1.top());
				s1.pop();
			}
			return s2.top();
		}
	}

	const T& Front() const
	{
		if (!s2.empty())
			return s2.top();
		else
		{
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
			return s2.top();
		}
	}

	bool Empty() const
	{
		return s1.empty() && s2.empty();
	}

	size_t Size() const
	{
		return s1.size() + s2.size();
	}
private:
	stack<T> s1;
	stack<T> s2;
};


void TestQueue()
{
	MyQueue<int> q;
	q.Push(1);
	q.Push(2);
	cout << q.Front() << endl;
	q.Pop();
	q.Push(3);
	q.Push(4);
	while (!q.Empty())
	{
		cout << q.Front() << " ";
		q.Pop();
	}
}

int main()
{
	TestQueue();
	char dest[10] = {};
	return 0;
}
