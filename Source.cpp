#include <stdio.h>
#include <iostream>
#include <ios>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

bool checkMin(int minute, string var = "undefined") {
	if (minute >= 0 || minute <= 60) return true;
	else {
		throw("checkMin exception: " + var);
		return false;
	}
}

bool checkHour(int hour, string var = "undefined") {
	if (hour >= 0 || hour <= 24) return true;
	else {
		throw("checkHour exception: " + var);
		return false;
	}
}

// This is a simple program to calculate the duration between 2 times inputted by the user

int main() {
	string startTime;
	cout << "Clock In Time ? (HHMM) ";
	getline(cin, startTime);
	cout << endl;

	if (startTime.length() != 4) { cout<<"Start time needs to be 4 digits!"<<endl; return -1; }

	int SH, SM;

	//Start time.
	SH = (startTime[0] - '0')*10 + (startTime[1] - '0');
	SM = (startTime[2] - '0') * 10 + (startTime[3] - '0');

	//End time.
	string endTime;
	int EH, EM;

	cout << "Clock Out Time ? (HHMM) ";
	getline(cin, endTime);
	cout << endl;

	if (endTime.length() != 4) { cout<<"End time needs to be 4 digits!"<<endl; return -1; }

	EH = (endTime[0] - '0')*10 + (endTime[1] - '0');
	EM = (endTime[2] - '0') * 10 + (endTime[3] - '0');

	//checking
	checkHour(SH);
	checkHour(EH);
	checkMin(SM);
	checkMin(EM);

	//time_t & tm
	time_t start_time;
	struct tm start_time_info;
	time_t end_time;
	struct tm end_time_info;

	time(&start_time);
	localtime_s(&start_time_info, &start_time);
	start_time_info.tm_hour = SH;
	start_time_info.tm_min = SM;

	time(&end_time);
	localtime_s(&end_time_info, &end_time);
	end_time_info.tm_hour = SH;
	end_time_info.tm_min = SM;




	//break time
	string _break;
	cout << "Break Duration? (hrs) ";
	getline(cin, _break);
	cout << endl;


	return 0;
}

