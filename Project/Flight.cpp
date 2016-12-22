#include "stdafx.h"
#include "Flight.hpp"  
#include <vector> 
#include <algorithm> 
#include <iostream> 
#include <deque> 
#include <string>  
#include <string.h> 

void Flight::split(string& text, char delimiter, vector<string>& result) {
	string token;
	for (size_t i = 0; i < text.size(); i++) {
		if (text[i] == delimiter) { 
			result.push_back(token); 
			token = ""; 
		}
		else {
			token += text[i];
		}
	} 
	result.push_back(token);
}



Flight::Flight(string info, string num) {
	vector<string> flightInfo;  
	split(info, ',', flightInfo);
	if (flightInfo.size() == 3) {
		origin = flightInfo[0];
		destination = flightInfo[1];
		date = flightInfo[2];
	}
	flightNum = num; 
} 

void Flight::displayFlight() {  
	cout << "****************************************" << endl;
	cout << "Flight number: " << flightNum << endl;
	cout << "Origin: " << origin << endl;  
	cout << "Destination: " << destination << endl;
	cout << "Date: " << date << endl; 
	cout << "****************************************" << endl;
}  

void Flight::reserve() {
	cout << "Please Enter your full name" << endl; 
	string name;
	getline(cin, name); 
	cout << "Reservation completed" << endl;
}