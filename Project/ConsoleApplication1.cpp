// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" 
#include <iostream>  
#include <string> 
#include <fstream>
#include <sstream> 
#include <vector>  
#include "Flight.hpp"

using namespace std; 

vector<string> divide(string str, string delimiter) {
	/*vector<string> internal;
	stringstream ss(str); // Turn the string into a stream.
	string tok;

	while (getline(ss, tok, delimiter)) {
		internal.push_back(tok);
	} 
	cout << internal.size(); 
	return internal;*/ 

	string info = str.substr(0, str.find(delimiter)); 
	string flightNum = str.substr(str.find(delimiter) + 1, str.length());
	vector<string> result; 
	result.push_back(info);
	result.push_back(flightNum);
	return result;

}

void searchFlights() {
	string origin; 
	string destination; 
	string departDate; 

	cin.ignore();
	cout << "Origin?" << endl;  
	getline(cin, origin); 
		
	cout << "Destination?" << endl; 
	getline(cin, destination);   
	 
	cout << "Date of Departure? (mm/dd/yyyy)" << endl;
	getline(cin, departDate);

	ifstream inFile("Flights.txt");   
	string search = origin + "," + destination + "," + departDate;
		
	bool found = false;
	vector<string> flightInfo;
	if (inFile.is_open()) {
		while (true) {
			string flight; 
			getline(inFile, flight);  
			flightInfo = divide(flight, "|");
			if (flightInfo[0] == search) { 
				found = true;
				break;
			}
			if (inFile.fail()) {
				break; 
			}
		}
	}  

	if (!found) {
		cout << "No Flights Found" << endl;
	}
	else { 
		cout << endl;
		cout << "RESULTS:" << endl; 
		string a = flightInfo[0]; 
		string b = flightInfo[1];
		Flight f(a, b); 
		f.displayFlight(); 
		cout << endl; 
		cout << "Do you wish to reserve? (yes/no)" << endl; 
		bool reserve;  
		string ans;
		getline(cin, ans);  
		reserve = ans == "yes"; 
		if (reserve) {
			f.reserve();
		}
	} 
	cout << "Thank for using HorizonAir" << endl;

}

void viewReservation() { 
 
}

int main()
{ 
	cout << "Search Flights (SF) or View Rervation (VR)?" << endl;    
	string answer; 
	cin >> answer; 

	if (answer == "SF") {
		searchFlights(); 
	}
	else {
		viewReservation(); 
	}

    return 0; 
} 
