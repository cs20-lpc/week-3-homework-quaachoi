#include <iostream>
#include <string>
#include "Student.hpp"
#include "Course.hpp"
#include "LinkedList.hpp"
// TO DO:
// If you want to use the LinkedList code you wrote in Week 4 Mon Lab for creating list
// include LinkedList.hpp here and also add it both LinkedList.hpp and LinkedList.tpp to this repository.

using namespace std;

void printListContents(LinkedList<Student>*);

int main()
{
    LinkedList<Student>* studentList;
    studentList = new LinkedList<Student>();

    while(true)
    {
        int input = 0;
        cout << "1: Insert Student\n2: Delete Student\n3: Search Student\n4: Display All\n5: Count Students\n6: Add a Course\n7: Quit" << endl;
        cin >> input;

        if(input == 7)
        {
            break;
        }

        cin.ignore();

        switch(input)
        {
            case 1:
            {
                int tempID = 0;
                string tempName = "";
                float tempGPA = 0;

                cout << "Enter ID: ";
                cin >> tempID;
                cin.ignore();

                cout << "Enter Name: ";
                getline(cin, tempName);

                cout << "Enter GPA: ";
                cin >> tempGPA;
                cin.ignore();

                studentList->append(Student(tempID, tempName, tempGPA));
                break;
            }

            case 2:
            {
                if(studentList->isEmpty())
                {
                    cout << "No students to delete" << endl;
                }
                else
                {
                    bool removed = false;
                    int tempID = 0;
                    cout << "Enter ID: ";
                    cin >> tempID;
                    cin.ignore();

                    for(int i = 0; i < studentList->getLength(); i++)
                    {
                        if(studentList->getElement(i).getID() == tempID)
                        {
                            studentList->remove(i);
                            removed = true;
                        }
                    }

                    if(removed)
                    {
                        cout << "Student with ID " << tempID << " successfully removed." << endl;
                    }
                    else
                    {
                        cout << "No Student with ID " << tempID << endl;
                    }
                }
                break;
            }

            case 3:
            {
                int tempID = 0;
                cout << "Enter ID: ";
                cin >> tempID;
                cin.ignore();

                for(int i = 0; i < studentList->getLength(); i++)
                {
                    if(studentList->getElement(i).getID() == tempID)
                    {
                        studentList->getElement(i).printData();
                        cout << endl;
                        studentList->getElement(i).printCourseData();
                    }
                }
                break;
            }

            case 4:
            {
                printListContents(studentList);
                break;
            }

            case 5:
            {
                cout << "There are " << studentList->getLength() << " students." << endl;
                break;
            }

            case 6:
            {
                int tempID = 0;
                string tempCourseName = "";
                string tempCourseID = "";

                cout << "Enter ID: ";
                cin >> tempID;
                cin.ignore();

                cout << "Enter Course Name: ";
                getline(cin, tempCourseName);

                cout << "Enter Course Location: ";
                cin >> tempCourseID;
                cin.ignore();

                for(int i = 0; i < studentList->getLength(); i++)
                {
                    if(studentList->getElement(i).getID() == tempID)
                    {
                        studentList->getElement(i).addCourse(Course(tempCourseName, tempCourseID));
                    }
                }
            }
        }

        cout << "\n";
    }

    return 0;
}


void printListContents(LinkedList<Student>* listPtr)
{
    if(listPtr->isEmpty())
    {
        cout << "List is empty" << endl;
        return;
    }

    cout << "List contents:" << endl;
    for(int i = 0; i < listPtr->getLength(); i++)
    {
        listPtr->getElement(i).printData();
        cout << endl;
        listPtr->getElement(i).printCourseData();
    }
}