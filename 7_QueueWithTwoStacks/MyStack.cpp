#include <iostream>
#include <queue>

using namespace std;


//use two queues to implement the stack 

template<typename T>
class MyStack
{
public:
	void Push(const T& x)
	{
		q1.push(x);
	}

	void Pop()
	{
		while (q1.size() != 1)
		{
			q2.push(q1.front());
			q1.pop();
		}
		q1.pop();
		while (!q2.empty())
		{
			q1.push(q2.front());
			q2.pop();
		}
	}

	T& Top()
	{
		while (q1.size() != 1)
		{
			q2.push(q1.front());
			q1.pop();
		}
		T &ret = q1.front();
		q2.push(q1.front());
		q1.pop();
		while (!q2.empty())
		{
			q1.push(q2.front());
			q2.pop();
		}
		return ret;
	}

	const T& Top() const
	{
		while (q1.size() != 1)
		{
			q2.push(q1.front());
			q1.pop();
		}
		T &ret = q1.front();
		q2.push(q1.front());
		q1.pop();
		while (!q2.empty())
		{
			q1.push(q2.front());
			q2.pop();
		}
		return ret;
	}
	
	size_t Size() const
	{
		return q1.size() + q2.size();
	}

	bool Empty() const
	{
		return q1.empty() && q2.empty();
	}


private:
	queue<T> q1;
	queue<T> q2;
};


void Test()
{
	MyStack<int> s;
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);
	cout << s.Top() << endl;
	s.Pop();
	while (!s.Empty())
	{
		cout << s.Top() << endl;
		s.Pop();	
	}
	cout << endl;
}


int main()
{
	Test();
	return 0;
}
