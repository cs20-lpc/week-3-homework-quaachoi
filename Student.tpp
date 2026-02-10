// TODO:  Student class methods implementation here.
Student::Student(int _id, string _name, float _gpa)
{
    this->id = _id;
    this->name = _name;
    this->gpa = _gpa;
    this->courseList = new LinkedList<Course>();
}

void Student::printData()
{
    cout << "\nID: " << this->id;
    cout << "\nName: " << this->name;
    cout << "\nGPA: " << this->gpa;
    
}

void Student::addCourse(const Course& course)
{
    this->courseList->append(course);
}

void Student::printCourseData()
{
    if(this->courseList->isEmpty())
    {
        cout << "No courses on record" << endl;
        return;
    }

    cout << "List contents:" << endl;
    for(int i = 0; i < this->courseList->getLength(); i++)
    {
        cout << this->courseList->getElement(i).getCourseInfo() << endl;
    }
    cout << "Number of elements: " << this->courseList->getLength() << endl;
}

int Student::getID()
{
    return this->id;
}