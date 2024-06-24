#pragma once
#include <map>

namespace tst {

	class Date_tst {
	private:
		int year = 1970;
		int month = 1;
		int day = 1;
		int absolut_days = 0;

		void Normalize() {
			for (int i = 1970; i < year; ++i) {
				absolut_days += NumDays(i);
			}
			for (int i = 1; i < month; ++i) {
				absolut_days += NumDays(year, i);
			}
			absolut_days += day;

			int& _year = year;
			int& _month = month;
			int tmp_absolut_days = absolut_days;

			while (tmp_absolut_days < NumDays(_year)) {
				tmp_absolut_days -= NumDays(_year);
				++year;
			}
			while (absolut_days < NumDays(_year, _month)) {
				tmp_absolut_days -= NumDays(_year, _month);
				++month;
			}
			day = tmp_absolut_days;
		};

		bool TypeYear(int year) {
			if (year % 400 == 0) return 1;
			else if (year % 100 == 0) return 0;
			else if (year % 4 == 0) return 1;
			else return 0;
		}

		int NumDays(int year) {
			if (TypeYear(year)) {
				return 366;
			}
			else return 365;
		}

		int NumDays(int year, int mnth) {
			std::map<int, int> yearTypeMap = {
				{1,31}, {2,28}, {3,31}, {4,30}, {5,31}, {6,30},
				{7,31}, {8,31}, {9,30}, {10,31}, {11,30}, {12,31}, {13,29},
			};

			if (TypeYear(year) && 2 == mnth) {
				return yearTypeMap[13];
			}
			else return yearTypeMap[mnth];
		}

	public:
		Date_tst() = default;
		Date_tst(int y, int m, int d);
		Date_tst(int a) : Date_tst(0, 0, a) {};

		int GetYear()const;
		int GetMonth()const;
		int GetDay()const;
		int GetTotalDay() const;

		Date_tst& operator += (int _day) {
			day += _day;
			Normalize();
			return *this;
		}

		Date_tst& operator -= (int _day) {
			day -= _day;
			Normalize();
			return *this;
		}

	};

	int operator - (const Date_tst& dt1, const Date_tst& dt2) {
		return dt1.GetTotalDay() - dt2.GetTotalDay();
	}

	Date_tst::Date_tst() {
		year = 1970;
		month = 1;
		day = 1;
	};

	Date_tst::Date_tst(int y, int m, int d) {
		if (y < 1970 || y > 2099 || m < 1 || m>12 || d < 1 || d>31) {
			year = 1970;
			month = 1;
			day = 1;
		}
		else {
			year = y;
			month = m;
			day = d;
		}
		Normalize();
	};

	int Date_tst::GetYear() const {
		return year;
	};

	int Date_tst::GetMonth() const {
		return month;
	};

	int Date_tst::GetDay() const {
		return day;
	};

	int Date_tst::GetTotalDay() const {
		return absolut_days;
	};
}