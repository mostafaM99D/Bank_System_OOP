#pragma once
#include<iostream>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>
using namespace std;
class clsSession; 
class clsHeader {
private:
	static string _getCurrentDate() {
		auto now = chrono::system_clock::now();
		time_t now_c = chrono::system_clock::to_time_t(now);

		tm tm_struct;
		localtime_s(&tm_struct, &now_c); 
		ostringstream oss;
		oss << std::put_time(&tm_struct, "%Y-%m-%d");
		return oss.str();
	}
public:
	static void DrawHeader(const std::string& Title);

};