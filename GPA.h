/*
 * GPA.h
 *
 *  Created on: Mar 27, 2015
 *      Author: bryce14
 */

#ifndef GPA_H_
#define GPA_H_

#include "GPAInterface.h"
#include "StudentInterface.h"
#include "Student.h"

class GPA: public GPAInterface {
public:
	GPA();
	virtual ~GPA();
	map<unsigned long long int,StudentInterface*> getMap();
	set<StudentInterface*,Comparator> getSet();
	bool importStudents(string mapFileName, string setFileName);
	bool importGrades(string fileName);
	bool check_map(string mapFileName);
	bool check_set(string setFileName);
	string querySet(string fileName);
	string queryMap(string fileName);
	void clear();

private:
	string query_map;
	string query_set;
	map<unsigned long long int, StudentInterface*> themap;
	set<StudentInterface*, Comparator> theset;
};

#endif /* GPA_H_ */

