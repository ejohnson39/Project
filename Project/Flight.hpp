#pragma once 
#include <string>  
#include <vector>
using namespace std; 

class Flight
{
public:
	Flight(string info, string flightNo);  
	void displayFlight(); 
	void reserve();

private: 
	string flightNum;
	string origin; 
	string destination; 
	string date; 
	void split(string& text, char delimiter, vector<string>& result); 
};

