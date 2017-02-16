#include <iostream> 
#include <stack>
using namespace std;

//create a stack with min 
//the time complexity of push pop min is O(1)

template<class T>
class MinStack
{
public:
	void Push(const T& x)
	{
		if (_data_stack.empty())
		{
			_data_stack.push(x);
			_min_stack.push(x);
		}
		else
		{
			_data_stack.push(x);
			if (x < _min_stack.top())
			{
				_min_stack.push(x);
			}
			else
			{
				_min_stack.push(_min_stack.top());
			}
		}
	}

	void Pop()
	{
		_min_stack.pop();
		_data_stack.pop();
	}

	const T& Min() const
	{
		return _min_stack.top();
	}

	T& Top()
	{
		return _data_stack.top();
	}

	const T& Top() const
	{
		return _data_stack.top();
	}

	size_t Size() const
	{
		return _data_stack.size();
	}

	bool Empty() const
	{
		return _data_stack.empty();
	}

private:
	stack<T> _data_stack;
	stack<T> _min_stack;
};


void Test()
{
	MinStack<int> min;
	min.Push(1);
	min.Push(2);
	min.Push(-1);
	min.Push(5);
	min.Pop();
	cout << min.Min() << endl;
	while (!min.Empty())
	{
		cout << min.Min() << endl;
		min.Pop();
	}
}

int main()
{
	Test();
	return 0;
}
