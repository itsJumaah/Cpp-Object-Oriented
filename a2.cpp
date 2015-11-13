/* --------------------------- Assignment 1 -- 159.234 --------------------------- */
/*                              Bilal Jumaah  12232659                             */
/* ------------------------------------------------------------------------------- */
/*    Write a program which reads a file of employee records and prints lists of   */
/*   whose salaries fall within given ranges. An Employee class should be created  */
/*         ranges. An Employee class should be created to store the records        */
/* ------------------------------------------------------------------------------- */

#include <iostream> 	
#include <string> 	
#include <iomanip>
#include <sstream> 	
#include <fstream>	
#include <cstdlib>
#include <vector>

using namespace std;

//display this info on the screen first
void displayInfo () {
	cout << "----------------------------------------" << endl;
	cout << "     Assignment 1 -- Semester 2 2015    " << endl;
	cout << " Submitted by: Bilal Jumaah, 12232659   " << endl;
	cout << "----------------------------------------" << endl;
}

/* -------------------------- Start of class functions --------------------------- */

//defining the employee class
class Employee {
private:
	string firstName;
	string lastName;
	int idNumber;
	float salary;
public:
	//default constructor
	Employee() { firstName = ""; lastName = ""; idNumber = 0; salary = 0.0;	}
	
	//default destructor
	~Employee () { }	
	
	//overload constructor
	Employee(string _firstName, string _lastName, int _idNumber, float _salary) {
		firstName = _firstName;
		lastName = _lastName;
		idNumber = _idNumber;
		salary = _salary;
	}
	
	//checks if the salary is in the range
	bool SalaryInRange(float low, float high, Employee X);
	
	//displays all information at top of the screen
	void DisplayRecords(vector<Employee> X);
	
	//if salary is in the range, display information about employee
	void DisplaySalary(Employee X);
	
	//custom operators
	friend istream &operator >> (istream &input, Employee &EmpObj);
	friend ostream &operator << (ostream &output, Employee &EmpObj);
};

//checks if the salary is in the range
bool Employee::SalaryInRange(float low, float high, Employee X)  {
	float eSalary = X.salary;
	if (low < eSalary && eSalary < high) {
		//if salary is in range return true
		return true;
	} else {
		//if not in range, return false
		return false;
	}
}

//displays all information at top of the screen
void Employee::DisplayRecords(vector<Employee> X){
	//gets number of employees
	int len = X.size();
	//prints information for each employee
	for (int i = 0; i < len; i++) {
		cout << X[i];
	}
	cout << endl;
}

//if salary is in the range, display information about employee
void Employee::DisplaySalary(Employee X) {
	cout << X;
}

//custom input operator
istream &operator >> (istream &input, Employee &EmpObj) {
	input >> EmpObj.firstName >> EmpObj.lastName >> EmpObj.idNumber >> EmpObj.salary;
	return input;
}

//custom output operator
ostream &operator << (ostream &output, Employee &EmpObj) {
	output << EmpObj.firstName << " ";
	output << EmpObj.lastName << " ";
	output << EmpObj.idNumber << " ";
	output << EmpObj.salary << endl;
	return output;
}

/* ------------------------------- Misc Functions -------------------------------- */

//print out the results on the screen
void printResults(vector<Employee> _listEmployees){
	//new instance of Employee
	Employee X;
	X.DisplayRecords(_listEmployees);
	
	char confirmation = 'y';
	while (confirmation == 'y') {
		//declarations
		int counter = 0, numEmployees = _listEmployees.size();
		float low = 0.0, high = 0.0;
		
		//get low and high salaries from user
		cout << "Enter low salary: ";	cin >> low;
		cout << "Enter high salary: "; cin >> high; cout << endl;
		
		//work out if employees salary is in range and print if true
		for (int i = 0; i < numEmployees; i++) {
			if ((X.SalaryInRange(low, high, _listEmployees[i]))== true) {
				X.DisplaySalary(_listEmployees[i]);
				counter++;
			}
		}
		
		//display how many employees' salaries were in range
		cout << counter << " matching employees found" << endl << endl;
		
		//repeat function
		//we have assumed lowercase is used.
		cout << "Repeat? (y/n) "; cin >> confirmation;
		cout << endl;
		if (confirmation == 'n') {
			exit(0);
		} else {
			//wrong option has been selected
			cout << "That option is invalid. Please try again." << endl;
			cout << "Repeat? (y/n) "; cin >> confirmation; cout << endl;
		}
	}
}

/* ------------------------------------ Main ------------------------------------- */
int main () {
	//call this so it will always appear first
	displayInfo ();
	
	//vector list of all employees
	vector<Employee> listEmployees;
	
	//open file
	ifstream File;
	File.open ("a2.txt");
	
	// check if file opened correctly, proceed if true.
	if (File.is_open() == false) {
		cout << "Could not read file." << endl; 
		exit (0);
	}
	
	//while not the end of the file
	while (!File.eof ()) {
		//declare needed variabes
		string line, first, last;
		int id; float sal;
		
		//get next line of file and put into 'line'
		getline (File, line);
		istringstream iss(line);
		
		//sorts the line into correct variables
		iss >> first >> last >> id >> sal;
		
		//store those variables in employee e
		Employee e(first, last, id, sal);
		
		//add e to the list
		listEmployees.push_back(e);
	}
	
	//print end results
	printResults(listEmployees);
}

/* ------------------------------------- End ------------------------------------- */
