#include <type_traits>
#include <cstdio>
#include <iostream>
#include <vector>
#include <list>

/**
Generic implementation for non-list and non-vector 
*/
template <typename T>
struct is_list_or_vector {
	static const bool value = false;
};
/**
Specialization for vector
*/
template <typename T, typename Alloc>
struct is_list_or_vector<std::vector<T, Alloc> > {
	static const bool value = true;
};
/**
Specialization for list
*/
template <typename T, typename Alloc>
struct is_list_or_vector<std::list<T, Alloc> > {
	static const bool value = true;
};

/// Integral type implementation
template<typename T> typename std::enable_if<std::is_integral<T>::value>::type Print(T t)
{
	for (auto i = 0; i < sizeof (T); ++i)
	{
		std::cout << ((t >> 8 * (sizeof (T) - 1 - i)) & 0xff);
		if (sizeof(T) - 1 == i) return;
		std::cout << '.';
	}
}

/// Container type implementation
template<typename T> typename std::enable_if<is_list_or_vector<T>::value>::type Print(const T& t)
{
	for (const auto& iter : t)
	{
		//Print(iter);
		std::cout << +iter;
		if (t.back() == iter) return;
		std::cout << '.';
	}
}

/// C-string implementation
void Print(const std::string& str)
{
	std::cout << str.c_str();
}

/// Program entry point
int main(int, char *[])
{
	Print(char(-1));
	std::cout << std::endl;
	Print(int(0));
	std::cout << std::endl;
	Print(int(2130706433));
	std::cout << std::endl;
	Print(int64_t(8875824491850138409));
	std::cout << std::endl;

	Print("192.168.0.1");
	std::cout << std::endl;

	Print(std::vector<int>{ 1, 2, 3, 4, 5});
	std::cout << std::endl;

	Print(std::list<char>{ 6, 7, 8, 9, 10});
	std::cout << std::endl;

	return 0;
}