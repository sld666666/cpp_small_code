#pragma once
template<typename T, bool isPoly>
class NiftyContainer
{
public:
	void doSomething()
	{
		T* obj = new T();
		if(isPoly){
			T* newObj = obj->clone();
		}else{
			T* newObj = new T(*obj);
		}
	}
};

class Test
{
public:
	Test(){};
};


// void test04()
// {
// 	NiftyContainer<Test, false> test;
// 	test.doSomething();
// }

template <int v>
struct Int2Type
{
	enum { value = v };
};


template <typename T, bool isPolymorphic>
class NiftyContainer2
{
private:
	void DoSomething(T* pObj, Int2Type<true>)
	{
		T* pNewObj = pObj->Clone();

	}
	void DoSomething(T* pObj, Int2Type<false>)
	{
		T* pNewObj = new T(*pObj);

	}
public:
	void DoSomething(T* pObj)
	{
		DoSomething(pObj, Int2Type<isPolymorphic>());
	}
};
class Test2
{
public:
	Test2(){};
};

void test04()
{
	NiftyContainer2<Test, false> test;
	Test* t = new Test();
	test.DoSomething(t);
}
