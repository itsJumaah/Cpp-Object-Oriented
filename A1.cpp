/* ----------------- Assignment 1 -- 159.234 ----------------- */
/* -----------   Name: Bilal Jumaa -- ID: 12232659  ---------- */
/*  This program manipulates a data file data.txt to find the  */
/* sum, average, standard deviation, maximum and minimum value */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cfloat>
#include <cmath>
#include <iomanip>

using namespace std;

void displayInfo();

//bool ContainsHash (string x);
void CheckMin (double minarray[], double value);
void CheckMax (double maxarray[], double value);
double CalcSum (double myarray[], int arraysize);

int main (int argc, char** argv) {
	displayInfo ();
	
	ifstream File;
	File.open ("data.txt");
	// check if file opened correctly.
	if (File.is_open() == false) {
		cout << "Could not read file." << endl; 
		exit (0);
	}

	string firstline, nextline;
	int numlines = 0, count = 0;


	
	getline (File,firstline); //gets first line which signals number of lines in 
	numlines = atoi (firstline.c_str()); //converts string to integer	

	double *values = new double[numlines]; 
	double max[3] = {DBL_MIN, DBL_MIN, DBL_MIN};
	double min[3] = {DBL_MAX, DBL_MAX, DBL_MAX};

	while(!File.eof ()) {
		getline (File, nextline); //get lines following the first
		if (nextline[0] != '#') { 
		//if (ContainsHash (nextline) == false) { 
			values[count] = atof (nextline.c_str());
			count++;
		}
	}	
	
	double sum = 0;
	sum = CalcSum(values,count);
	
	for (int i = 0; i < count; i++) {
		CheckMax (max,values[i]);
	}
	
	for (int i = 0; i < count; i++) {
		CheckMin (min,values[i]);
	}
	cout << endl;
	cout << "values: "<< endl;
	for (int i = 0; i < count; i++) {
		cout << values[i] << endl;
	}



	double sum1 = 0, variance = 0, std_deviation = 0, average = 0;
	average = sum/count;
	for (int i = 0; i < count; i++) {
        sum1 = sum1 + pow((values[i] - average), 2);
    }
    variance = sum1 / (count-1);
    std_deviation = sqrt(variance);
	
	cout << endl;
	cout << "Total records: = " << count << endl;
	cout << "Sum: " << sum << endl;
	cout << "Average of the records: " << setprecision(5) << average << endl;
	cout << "max: " << max[0] << " " << max[1] << " " << max[2] << endl;
	cout << "min: " << min[0] << " " << min[1] << " " << min[2] << endl;
	cout << "ST deviation: " << std_deviation << endl;
	//delete 
}

void CheckMax (double maxarray[], double value) {
	//this function stores the 3 largest variables
	double temp = 0;
	if (value > maxarray[0]) {
		temp = maxarray[0];
		maxarray[0] = value;
		CheckMax (maxarray,temp);
	} else if (value > maxarray[1]) {
		temp = maxarray[1];
		maxarray[1] = value;
		CheckMax (maxarray,temp);
	} else if (value > maxarray[2]) {
		temp = maxarray[2];
		maxarray[2] = value;
		CheckMax (maxarray,temp);
	} else {
		return; //no new max variables so exit
	}
}

void CheckMin (double minarray[], double value) {
	//this function stores the 3 largest variables
	double temp = 0;
	if (value < minarray[0]) {
		temp = minarray[0];
		minarray[0] = value;
		CheckMin (minarray,temp);
	} else if (value < minarray[1]) {
		temp = minarray[1];
		minarray[1] = value;
		CheckMin (minarray,temp);
	} else if (value < minarray[2]) {
		temp = minarray[2];
		minarray[2] = value;
		CheckMin (minarray,temp);
	} else {
		return; //no new max variables so exit
	}
}

double CalcSum (double myarray[], int arraysize) {
	double total = 0;	
	for (int i = 0; i < arraysize; i++) {
		total += myarray[i]; 
	}
	return total;
}



void displayInfo () {
	cout << "----------------------------------------" << endl;
	cout << "     Assignment 1 -- Semester 2 2015    " << endl;
	cout << " Submitted by: Bilal Jumaah, 12232659   " << endl;
	cout << "----------------------------------------" << endl;
	cout << endl;
}
