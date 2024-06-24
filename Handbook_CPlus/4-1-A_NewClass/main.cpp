#include <iostream>
#include <D:\VS\progs\Handbook\Handbook_CPlus\4-1-A_NewClass\Date.h>


int main() {
	tst::Date_tst one(1971,2,2);
	int val = one.GetTotalDay();
	std::cout << val<< std::endl;
	std::cout << one.GetYear() << " " << one.GetMonth() << " " << one.GetDay() << std::endl;

	return 0;
}