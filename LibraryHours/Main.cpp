// Rob Wood
// 1/31/19
// In-class work

/*
Write a C++ program that uses a scoped enum
whose values are the days of the week.
Write a function that takes a day
of the week as a parameter and prints
the hours a certain libray is open:
Monday:    10AM-6PM
Tuesday:   10AM-6PM
Wednesday: 10AM-6PM
Thursday:  10AM-8PM
Friday:    10AM-8PM
Saturday:  10AM-9PM
Sunday:    10AM-9PM
*/

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

enum class Day { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday, InvalidDay };
Day getDay(string day);
string libraryHours(Day today);

// function prototypes go here
int main() {
	cout << "This program gives you library hours." << endl;
	cout << "Which day do you want? ";
	string day;
	cin >> day;
	cout << "Your input: " << day << endl;
	Day today = getDay(day);
	cout << static_cast<int>(today) << endl;
	cout << libraryHours(today) << endl;
	system("pause");
	return 0;
}

// function definitions go here

Day getDay(string day) {
	switch (tolower(day[0])){
	case 'm':
		return Day::Monday;
	case 't':
		return tolower(day[1]) == 'u' ? Day::Tuesday : Day::Thursday;
	case 'w':
		return Day::Wednesday;
	case 'f':
		return 	Day::Friday;
	case 's':
		return tolower(day[1]) == 'a' ? Day::Saturday : Day::Sunday;
	default: 
		return Day::InvalidDay;
	}
}

//Day getDay(string day) {
//	if (tolower(day[0]) == 'm') {
//		return Day::Monday;
//	}
//	else if (tolower(day[0]) == 't') {
//		if (tolower(day[1]) == 'u') {
//			return Day::Tuesday;
//		}
//		else {
//			return Day::Thursday;
//		}
//	}
//	else if (tolower(day[0]) == 'w') {
//		return Day::Wednesday;
//	}
//	else if (tolower(day[0]) == 'f') {
//		return Day::Friday;
//	}
//	else if (tolower(day[0]) == 's') {
//		if (tolower(day[1] == 'a')) {
//			return Day::Saturday;
//		}
//		else {
//			return Day::Sunday;
//		}
//	}
//	else {
//		return Day::InvalidDay;
//	}
//}

string libraryHours(Day today) {
	switch (today) {
		case Day::Monday:
		case Day::Tuesday:
		case Day::Wednesday:
			return  "10AM - 6PM";
		case Day::Thursday:
			return "10AM - 8PM";
		case Day::Friday:
			return "10AM - 8PM";
		case Day::Saturday:
		case Day::Sunday:
			return "10AM - 9PM";
		case Day::InvalidDay:
			return "not a day";

	}

	return "jgg";
}