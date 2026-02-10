// TODO:  Course class methods implementation here.
Course::Course(string _name, string _location)
{
    this->name = _name;
    this->location = _location;
}

string Course::getCourseInfo()
{   
    return this->name + ", " + this->location;
}