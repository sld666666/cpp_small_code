#pragma once
#include "stdafx.h"

template <typename T, 
		template <typename ELEM> class CONT = deque>

class Stack
{
private:
	CONT<T> elems_;

public:
	void push(T elem);
};

template <typename T, 
			template <typename> class CONT = deque>
void Stack<T, class> ::push(T elem)
{

}

template <typename T, 
			template<typename ELEM,
			typename ALLOC = std::allocator<ELEM>>
			class CONT = std::deque>