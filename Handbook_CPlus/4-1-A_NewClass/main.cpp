#include <iostream>
#include <D:\VS\progs\Handbook\Handbook_CPlus\4-1-A_NewClass\Date.h>


int main() {
	tst::Date one(1970,1,5);
	std::cout << one.GetYear() << " " << one.GetMonth() << " " << one.GetDay() << std::endl;

	tst::Date _one(1960, 2, 2);
	std::cout << _one.GetYear() << " " << _one.GetMonth() << " " << _one.GetDay() << std::endl;

	_one += 2;
	std::cout << _one.GetYear() << " " << _one.GetMonth() << " " << _one.GetDay() << std::endl;

	int val = one - _one;
	std::cout << val << "\n";

	return 0;
}