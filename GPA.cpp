/*
 * GPA.cpp
 *
 *  Created on: Mar 27, 2015
 *      Author: bryce14
 */

#include "GPA.h"
#include <fstream>
#include <iostream>
#include <sstream>

GPA::GPA() {
	// TODO Auto-generated constructor stub

}

GPA::~GPA() {
	// TODO Auto-generated destructor stub
	clear();
}

map<unsigned long long int,StudentInterface*> GPA::getMap() {
	return themap;
}

set<StudentInterface*,Comparator> GPA::getSet() {
	return theset;
}

bool GPA::importStudents(string mapFileName, string setFileName) {
	unsigned long long int ID;
	string name;
	string address;
	string phone;
	string blank;
	if (check_map(mapFileName) == true) {
		if (check_set(setFileName) == true) {
		ifstream map_in(mapFileName);
		while (!map_in.eof()) { //maybe use getline
			map_in >> ID;
			getline(map_in, blank);
			getline(map_in, name);
			getline(map_in, address);
			getline(map_in, phone);
			map_in.peek();
			StudentInterface* temp1 = new Student(ID, name, address, phone);
			themap[ID] = temp1;
		}
		map_in.close();
		ifstream set_in(setFileName);
			while (!set_in.eof()) {
				set_in >> ID;
				getline(set_in, blank);
				getline(set_in, name);
				getline(set_in, address);
				getline(set_in, phone);
				set_in.peek();
				StudentInterface* temp2 = new Student(ID, name, address, phone);
				theset.insert(temp2);
			}
			set_in.close();
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
	return true;
}

bool GPA::check_map(string mapFileName) {
	unsigned long long int ID;
	string name;
	string address;
	string phone;
	string blank;
	ifstream map_in(mapFileName);
	if (map_in.fail()) { //still going to work with test driver cuz of c++11
		return false;
	}
	else {
		while (!map_in.eof()) {
			ID = 0;
			name = "";
			address = "";
			phone = "";
			map_in >> ID;
			getline(map_in, blank);
			getline(map_in, name);
			getline(map_in, address);
			getline(map_in, phone);
			map_in.peek();
		//	cout << "ID: " << ID << " name: " << name << " address: " << address << " phone: " << phone << endl;
			if (ID == 0) {
				return false;
			}
			if (name == "") {
			return false;
			}
			if (address == "") {
				return false;
			}
			if (phone == "") {
				return false;
			}
		}
		if (!map_in.eof()) {
			return false;
		}
		map_in.close();
		return true;
	}
}

bool GPA::check_set(string setFileName) {
	unsigned long long int ID;
	string name;
	string address;
	string phone;
	string blank;
	ifstream set_in(setFileName);
	if (set_in.fail()) { //still going to work with test driver cuz of c++11
		return false;
	}
	else {
		while (!set_in.eof()) {
			ID = 0;
			name = "";
			address = "";
			phone = "";
			set_in >> ID;
			getline(set_in, blank);
			getline(set_in, name);
			getline(set_in, address);
			getline(set_in, phone);
			set_in.peek();
			//cout << "ID: " << ID << " name: " << name << " address: " << address << " phone: " << phone << endl;
			if (ID == 0) {
				return false;
			}
			if (name == "") {
			return false;
			}
			if (address == "") {
				return false;
			}
			if (phone == "") {
				return false;
			}
		}
		if (!set_in.eof()) {
			return false;
		}
		set_in.close();
		return true;
	}
}

bool GPA::importGrades(string fileName) {
	unsigned long long int ID;
	double num_grade;
	string subject;
	string grade;
	string blank;
	ifstream grades_in(fileName);
	if (grades_in.fail()) { //still going to work with test driver cuz of c++11
		return false;
	}
	else {
		while (!grades_in.eof()) {
			grades_in >> ID;
			getline(grades_in, blank);
			getline(grades_in, subject);
			getline(grades_in, grade);
			grades_in.peek();
			if (grade == "A") {
				num_grade = 4.0;
			}
			if (grade == "A-") {
				num_grade = 3.7;
			}
			if (grade == "B+") {
				num_grade = 3.4;
			}
			if (grade == "B") {
				num_grade = 3.0;
			}
			if (grade == "B-") {
				num_grade = 2.7;
			}
			if (grade == "C+") {
				num_grade = 2.4;
			}
			if (grade == "C") {
				num_grade = 2.0;
			}
			if (grade == "C-") {
				num_grade = 1.7;
			}
			if (grade == "D+") {
				num_grade = 1.4;
			}
			if (grade == "D") {
				num_grade = 1.0;
			}
			if (grade == "D-") {
				num_grade = 0.7;
			}
			if (grade == "E") {
				num_grade = 0.0;
			}
			for(auto it : themap) {
				if (it.first == ID) {
					it.second->addGPA(num_grade);
				}
			}
			for(StudentInterface* it : theset) {
				if (it->getID() == ID) {
					it->addGPA(num_grade);
				}
			}
		}
	}
	grades_in.close();
	return true;
}

string GPA::querySet(string fileName) {
	unsigned long long int ID;
	string blank;
	stringstream result;
	ifstream squery_in(fileName);
	if (squery_in.fail()) { //still going to work with test driver cuz of c++11
		return "";
	}
	else {
		while (!squery_in.eof()) {
			squery_in >> ID;
			getline(squery_in, blank);
			squery_in.peek();
			for(StudentInterface* it : theset) {
				if (it->getID() == ID) {
					result << ID << " " << it->getGPA() << " " << it->getName() << "\n";
				}
			}
		}
	}
	squery_in.close();
	return result.str();
}

string GPA::queryMap(string fileName) {
	unsigned long long int ID;
	string blank;
	stringstream result;
	ifstream mquery_in(fileName);
	if (mquery_in.fail()) { //still going to work with test driver cuz of c++11
		return "";
	}
	else {
		while (!mquery_in.eof()) {
			mquery_in >> ID;
			getline(mquery_in, blank);
			mquery_in.peek();
			for(auto it : themap) {
				if (it.first == ID) {
					result << ID << " " << it.second->getGPA() << " " << it.second->getName() << "\n";
				}
			}
		}
	}
	mquery_in.close();
	return result.str();
}

void GPA::clear() {
	for(auto it : themap) {
		delete it.second;
	}
	themap.clear();
	for(StudentInterface* it : theset) {
		delete it;
	}
	theset.clear();
}










