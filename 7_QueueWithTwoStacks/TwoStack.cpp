#include <iostream>
using namespace std;

using size_t = unsigned int;

//use the array to implement two stacks
template<class T>
class TwoStack
{
public:
	TwoStack()
		: _a(nullptr)
		, _capacity(0)
		, _top1(0)
		, _top2(0)
	{}

	void Push1(const T& x)
	{
		_checkCapacity();
		_a[_top1++] = x;
	}

	void Push2(const T& x)
	{
		_checkCapacity();
		_a[_top2--] = x;
	}

	void Pop1()
	{
		if (!Empty1())
			--_top1;
	}

	void Pop2()
	{
		if (!Empty2())
			++_top2;
	}

	T& Top1()
	{
		if (!Empty1())
		return _a[_top1 - 1];
	}

	const T& Top1() const
	{
		if (!Empty1())
			return _a[_top1 - 1];
	}

	T& Top2()
	{
		if (!Empty2())
			return _a[_top2 + 1];
	}

	const T& Top2() const
	{
		if (!Empty2())
			return _a[_top2 + 1];
	}

	bool Empty1() const
	{
		return _top1 == 0;
	}

	bool Empty2() const
	{
		return _top2 == _capacity - 1;
	}

	size_t Size1() const
	{
		return _top1 - 0;
	}

	size_t Size2() const
	{
		return _capacity - 1 - _top2;
	}

	~TwoStack()
	{
		if (_a != nullptr)
		{
			delete[] _a;
			_a = nullptr;
		}
	}
private:
	void _checkCapacity()
	{
		if (_a == nullptr)
		{
			_capacity += INCREMENT;
			_a = new T[_capacity];
			_top2 += _capacity - 1;
		}
		else
		{
			if (_top1 == _top2)
			{
				size_t newCap = _capacity + INCREMENT * 2;
				T *temp = new T[newCap];
				for (size_t i = 0; i < _top1; ++i)
					temp[i] = _a[i];
				size_t j = newCap - 1;
				for (size_t i = _capacity - 1; i > _top2; --i, --j)
					temp[j] = _a[i];
				delete[] _a;
				_a = temp;
				_top2 = newCap - _capacity + _top2;
				_capacity = newCap;
				//_top1 doesn't change
				//newCap - newTop2 = _cap - _top2
			}
		}
	}
private:
	enum {INCREMENT = 5};

private:
	T *_a;
	size_t _capacity;
	size_t _top1;
	size_t _top2;
};

void TestTwoStack()
{
	TwoStack<int> s;
	s.Push1(1);
	s.Push1(2);
	s.Push1(3);
	s.Push1(4);
	s.Push1(5);
	s.Push2(1);
	s.Push2(2);
	s.Push2(3);
	s.Push2(4);
	s.Push2(5);
	cout << "s1:" << s.Size1() << endl;;
	cout << "s2:" << s.Size2() << endl;
	while (!s.Empty1())
	{
		cout << s.Top1() << endl;
		s.Pop1();
	}
	while (!s.Empty2())
	{
		cout << s.Top2() << endl;
		s.Pop2();
	}
}

int main()
{
	TestTwoStack();
	return 0;
}
