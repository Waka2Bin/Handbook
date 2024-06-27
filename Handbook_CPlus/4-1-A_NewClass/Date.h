#pragma once
#include <map>

namespace tst {

	class Date {
	private:
		int year = 1970;
		int month = 1;
		int day = 1;
		int absolut_days = 0;

		bool ChekDate(int y, int m, int d) {
			if (y>=1970 && y<=2099 && NumDays(y, m) >= d) {
				return true;
			}
			else return false;
		}
		
		void CalcAbsDays() {
			this->absolut_days = 0;
			for (int i = 1970; i < year; ++i) {
				this->absolut_days += NumDays(i);
			}
			for (int i = 1; i < month; ++i) {
				this->absolut_days += NumDays(year, i);
			}
			this->absolut_days += day;
		};
		
		void Normalize_absolute() {
			int tmp_absolut_days(absolut_days);
			
			int& _year = this->year;
			int& _month = this->month;

			this->year = 1970;
			this->month = 0;
			this->day = 0;

			while (tmp_absolut_days > NumDays(_year)) {
				tmp_absolut_days = tmp_absolut_days - NumDays(_year);
				++this->year;
			}
			while (absolut_days > NumDays(_year, _month)) {
				tmp_absolut_days = tmp_absolut_days - NumDays(_year, _month);
				++this->month;
			}
			this->day = tmp_absolut_days;
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
		Date(int y, int m, int d);

		int GetYear()const;
		int GetMonth()const;
		int GetDay()const;
		int GetTotalDay() const;

		Date& operator += (int _day) {
			this->absolut_days += _day;
			Normalize_absolute();
			CalcAbsDays();
			return *this;
		}

		Date& operator -= (int _day) {
			this->absolut_days -= - _day;
			Normalize_absolute();
			CalcAbsDays();
			return *this;
		}

	};

	int operator - (const Date& dt1, const Date& dt2) {
		return dt1.GetTotalDay() - dt2.GetTotalDay();
	}
	
	Date::Date(int y, int m, int d) {
		if (ChekDate(y, m, d)) { year = y; month = m; day = d; }
		else { year = 1970; month = 1; day = 1; }
		CalcAbsDays();
	};

	int Date::GetYear() const {
		return year;
	};

	int Date::GetMonth() const {
		return month;
	};

	int Date::GetDay() const {
		return day;
	};

	int Date::GetTotalDay() const {
		return absolut_days;
	};

}