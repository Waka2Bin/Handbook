#pragma once
#include <map>



namespace trdt {
	
	class Date {
	private:
		int year = 1970;
		int month = 1;
		int day = 1;
		int absolut_days = 1;

		void Normalize() {};

	public:
		Date() = default;
		Date(int y, int m, int d);
		Date(int a) : Date(0, 0, a) {};

		int GetYear()const;
		int GetMonth()const;
		int GetDay()const;
	};

	Date::Date(int y, int m, int d) {
		if (y < 1970 || y > 2099 || m<1 ||m>12 || d<1 || d>31) {
			year = 1970;
			month = 1;
			day = 1;
		}
		Normalize();
	};

	void Normalize() {
		std::map<int, int> yearType = {
			{1,31}, {2,28}, {3,31}, {4,30}, {5,31}, {6,30}, 
			{7,31}, {8,31}, {9,30}, {10,31}, {11,30}, {12,31}, {13,29},
		};

		int usual_year = 365;
		int vis_year = 366;



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


}
