// TODO:  Course class definitins go here.
#ifndef COURSE_HPP
#define COURSE_HPP

using namespace std;

struct Course
{
    string name;
    string location;
    
    Course(string _name, string _location);

    virtual string getCourseInfo();
};

#include "Course.cpp"
#endif