#pragma once

class Interface{
public:
	virtual void fun() = 0;
};

template <typename T, typename P>
Interface* makeAdapter(const T& obj, const P& arg)
{
	class Local : public Interface
	{
	public:
		Local(const T& obj, const P& arg)
		{

		}

		virtual void fun()
		{
			obj_.call(arg);
		}

	private:
		T obj_;
		P arg_;
	};

	return new Local(obj, arg);
}