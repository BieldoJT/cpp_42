#include "iter.hpp"

#include <string>


template <typename T>
void print(const T& x) {
	std::cout << x << "\n";
}

int dobrar(int x) {
	int value = x * 2;
	std::cout << value << std::endl;
	return value; }

void printarChar(char c)
{
	std::cout << c << "\n";
}

int main() {
	int arr[] = {1, 2, 3, 4};
	//função recbendo arry de inteiros
	::iter(arr, 4, print<int>); // passando função template especializada
	std::cout << "\n";
	char charArr[] = "algo aqui";
	::iter(charArr, 10, printarChar);
}
