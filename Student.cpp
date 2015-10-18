/*
 * Student.cpp
 *
 *  Created on: Mar 27, 2015
 *      Author: bryce14
 */

#include "Student.h"
#include <iomanip>
#include <iostream>
#include <sstream>

Student::Student(unsigned long long int ID, string name, string address, string phone) {
	// TODO Auto-generated constructor stub
	this->ID = ID;
	this->name = name;
	this->address = address;
	this->phone = phone;
	this->runningGPA = 0;
	this->classes = 0;
}

Student::~Student() {
	// TODO Auto-generated destructor stub
}


unsigned long long int Student::getID() {
	return ID;
}

string Student::getName() {
	return name;
}

string Student::getGPA() {
	if (classes == 0) {
		return "0.00";
	}
	else {
		double GPA = runningGPA / classes;
		stringstream ss;
		ss << fixed << setprecision(2) << GPA;
		return ss.str();
	}
}

/*
 * addGPA()
 *
 * Incorporates the given course grade into the Student's overall GPA.
 */

void Student::addGPA(double classGrade) {
	runningGPA += classGrade;
	classes++;
}

/*
 * toString()
 *
 * The student object will be put into string representation. Student info will be
 * ordered ID, name, address, phone number, and GPA. Each piece of information will
 * be on its own line. GPA will not have a newline following it and the precision
 * of the GPA will be rounded to two decimal places. For example,
 *
 * 123456789
 * Ben Thompson
 * 17 Russell St, Provo, UT 84606
 * 555-555-5555
 * 3.12
 *
 * Returns a string representation of the student object There is no trailing new line.
 */
string Student::toString() {
	stringstream tt;
	tt << ID << endl << name << endl << address << endl << phone << endl << getGPA();
	return tt.str();
}
