#include<iostream>
#include<vector>

using namespace std;

class Date
{
	public:
		void setDate(int y, int m, int d);
		void showDate();
	private:
		int d_year;
		int d_month;
		int d_day;
};

vector<Date> dates;

int main()
{
	cout << "enter 0 to kill the program" << endl;
	int num = -1;
	while (true)
	{
		cin >> num;
		if (num == 0) {
			break;
		}
		int y = 0;
		int m = 0;
		int d = 0;
		cin >> y >> m >> d;
		Date date;
		date.setDate(y, m, d);
		dates.push_back(date);
	}
	for (auto& date : dates) {
		date.showDate();
	}
}

void Date::setDate(int y, int m, int d)
{
	d_year = y;
	d_month = m;
	d_day = d;
}

void Date::showDate()
{
	cout << d_year << "-" << d_month << "-" << d_day << endl;
}