#include <iostream>
#include <vector>

template<typename T, typename R> void PrintTemplate(const T& val, const R& separator);

int main() {
	std::vector<int>data { 1,2,3,4,5 };
	PrintTemplate(data, '-');
}

template<typename T, typename R> void PrintTemplate(const T& val, const R& separator) {
	auto i = val.begin();
	for (auto iter = val.begin(); iter != val.end(); ++iter) {
		if (iter != val.end() && iter != val.begin()) {
			std::cout << separator;
		}
		std::cout << *iter;
	}
	std::cout << "\n";
}
