#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include "student.hpp"

Student::Student() {
    // Initialize RNG with current time as seed
    srand(time(nullptr));

    id_ = rand() % 10000 + 1;
    givenName_ = "";
    surname_ = "";
    coursesTaken_ = {};
}
Student::Student(std::string givenName, std::string surname) : givenName_(givenName), surname_(surname) {
    // Initialize RNG with current time as seed
    srand(time(nullptr));
    id_ = rand() % 10000 + 1;
}

int Student::getId() {
    return id_;
}
std::string Student::getGivenName() {
    return givenName_;
}
std::string Student::getSurname() {
    return surname_;
}
std::vector<std::string> Student::getCoursesTaken() {
    return coursesTaken_;
}

int Student::amountOfCoursesTaken() {
    return coursesTaken_.size();
}

std::string Student::getCourse(int index) {
    if(index >= 0 && index < coursesTaken_.size())
        return coursesTaken_[index];

    return "";
}
bool Student::hasTaken(std::string courseId) {
    return std::find(coursesTaken_.begin(), coursesTaken_.end(), courseId) != coursesTaken_.end();
}
void Student::addCourse(std::string courseId) {
    coursesTaken_.push_back(courseId);
}
void Student::removeCourse() {
    coursesTaken_.pop_back();
}
bool Student::removeCourse(std::string courseId) {
    if(std::find(coursesTaken_.begin(), coursesTaken_.end(), courseId) != coursesTaken_.end()) {
        coursesTaken_.erase(std::find(coursesTaken_.begin(), coursesTaken_.end(), courseId));
        return true;
    }

    return false;
}
void Student::removeCourse(int index) {
    coursesTaken_.erase(std::find(coursesTaken_.begin(), coursesTaken_.end(), coursesTaken_[index]));
}
std::string Student::toString(bool full) {
    if(full) {
        std::string output = surname_ + ", " + givenName_ + "\n";
        output += "{ ";
        for(int i = 0; i < coursesTaken_.size(); i++) {
            if(i != coursesTaken_.size() - 1)
                output += coursesTaken_[i] + ", ";
            else
                output += coursesTaken_[i];
        }
        return output + " }";
    }
    return "[" + surname_ + ", " + givenName_ + "]";
}

bool Student::operator<(const Student& other) const {
    if(surname_ == other.surname_)
        return givenName_.compare(other.givenName_) < 0;

    return surname_.compare(other.surname_) < 0;
}
bool Student::operator>(const Student& other) const {
    if(surname_ == other.surname_)
        return givenName_.compare(other.givenName_) > 0;

    return surname_.compare(other.surname_) > 0;
}
bool Student::operator==(const Student& other) const {
    if(surname_ == other.surname_)
        return givenName_ == other.givenName_;

    return surname_ == other.surname_;
}
bool Student::operator<=(const Student& other) const{ 
    if(surname_ == other.surname_)
        return givenName_.compare(other.givenName_) <= 0;

    return surname_.compare(other.surname_) <= 0;
}
bool Student::operator>=(const Student& other) const {
    if(surname_ == other.surname_)
        return givenName_.compare(other.givenName_) >= 0;

    return surname_.compare(other.surname_) >= 0;
}
