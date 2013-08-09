#ifndef FUNCTIONTEMPATE_H
#define FUNCTIONTEMPATE_H

template<typename T>
inline T max(T a, T b)
{
	return a < b ? b : a;
}

void testFuncitonTemplate()
{
	cout << ::max(7, 8) <<endl;
	cout << ::max<double>(8.9, 3.2) << endl;
}
#endif // FunctionTempate_h