#pragma once
#include <map>

class Date {
private:
	int year = 1970;
	int month = 1;
	int day = 1;

	int CalcAbsDays() {
		int absolut_days{ 0 };
		for (int i = 1970; i < year; ++i) {
			absolut_days += NumDays(i);
		}
		for (int i = 1; i < month; ++i) {
			absolut_days += NumDays(year, i);
		}
		absolut_days += day;
		return absolut_days;
	};
	void Normalize_absolute(int absDays) {
		int tmp_absolut_days(absDays);

		int& _year = this->year;
		int& _month = this->month;

		this->year = 1970;
		this->month = 0;
		this->day = 0;

		while (tmp_absolut_days > NumDays(_year)) {
			tmp_absolut_days = tmp_absolut_days - NumDays(_year);
			++this->year;
		}
		while (tmp_absolut_days > NumDays(_year, _month)) {
			tmp_absolut_days = tmp_absolut_days - NumDays(_year, _month);
			++this->month;
		}
		this->day = tmp_absolut_days;
	};
	bool TypeYear(int year) const {
		if (year % 400 == 0) return 1;
		else if (year % 100 == 0) return 0;
		else if (year % 4 == 0) return 1;
		else return 0;
	}
	int NumDays(int year) {
		if (TypeYear(year)) return 366;
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
	Date(int y, int m, int d) {
		bool trigger = false;
		if (y >= 1970 && y <= 2099 && NumDays(y, m) >= d) trigger = true;
		else trigger = false;
		if (trigger) { year = y; month = m; day = d; }
		else { year = 1970; month = 1; day = 1; }
	};
	int GetYear()const {
		return year;
	};
	int GetMonth()const {
		return month;
	};
	int GetDay()const {
		return day;
	};
	int GetCalcAbsDays() {
		int absolut_days{ 0 };
		for (int i = 1970; i < year; ++i) {
			absolut_days += NumDays(i);
		}
		for (int i = 1; i < month; ++i) {
			absolut_days += NumDays(year, i);
		}
		absolut_days += day;
		return absolut_days;
	};
	Date operator + (int _day) {
		Normalize_absolute(CalcAbsDays() + _day);
		return *this;
	}
	Date operator - (int _day) {
		Normalize_absolute(CalcAbsDays() - _day);
		return *this;
	}	
};

int operator - (Date& dt1, Date& dt2) {
	return dt1.GetCalcAbsDays() - dt2.GetCalcAbsDays();
}