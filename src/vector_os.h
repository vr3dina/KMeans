#pragma once
#include <vector>
#include <iostream>

template<typename T>
std::ostream& operator << (std::ostream& out, const std::vector<T>& v)
{
	for (const auto& val : v)
	{
		out << val << "\t";
	}
	return out;
}
