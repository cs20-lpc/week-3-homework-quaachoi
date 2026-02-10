// TO DO:  Student class definition  here.
#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "LinkedList.hpp"
#include "Course.hpp"
using namespace std;

class Student
{
    private:
        int id;
        string name;
        float gpa;
        LinkedList<Course>* courseList;
    
    public:
        Student(int, string, float);

        virtual void printData();

        virtual void addCourse(const Course&);

        virtual void printCourseData();

        virtual int getID();
};

#include "Student.cpp"
#endif