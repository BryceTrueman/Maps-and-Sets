/*
 * Student.h
 *
 *  Created on: Mar 27, 2015
 *      Author: bryce14
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include "StudentInterface.h"
#include <map>
#include <set>

class Student: public StudentInterface {
public:
	Student(unsigned long long int ID, string name, string address, string phone);
	virtual ~Student();
	unsigned long long int getID();
	string getName();
	string getGPA();
	void addGPA(double classGrade);
	string toString();


private:
	unsigned long long int ID;
	string name;
	double runningGPA;
	double classes;
	string address;
	string phone;
};

#endif /* STUDENT_H_ */



//map<key type, map to key> ie map<string, int> people;


