// std::source_location in C++2a, replacement of __FILE__
//
// $ g++ -std=c++2a src/200217-01-cxx2a-source-location.cpp && ./a.out
//
// ref: <https://en.cppreference.com/w/cpp/utility/source_location>
//      <https://en.cppreference.com/w/cpp/experimental/source_location>
//
#include <iostream>

#if 1
#include <experimental/source_location>
namespace std
{
	using source_location = experimental::fundamentals_v2::source_location;
}
#else
#include <source_location>
#endif

using namespace std;

void print(source_location&& loc, string_view msg)
{
	cout << loc.file_name() << ':' << loc.line() << ' ' << msg << endl;
}

void foo()
{
	print(source_location::current(), "in foo");
}

int main()
{
	print(source_location::current(), "in main");
	foo();
	return 0;
}
