#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <vector>

class Student {
    private:
        // int id_;
        std::string givenName_;
        std::string surname_;
        std::vector<std::string> coursesTaken_;
    public:
        Student();
        Student(std::string givenName, std::string surname);

        // int getId();
        std::string getGivenName();
        std::string getSurname();
        std::vector<std::string> getCoursesTaken();

        // Return size of courses vector
        int amountOfCoursesTaken();

        // Get course at given index. Returns blank string if failed.
        std::string getCourse(int index);
        // Returns true if the student has taken the given course
        bool hasTaken(std::string courseId);
        // Add given course to the end of the vector
        void addCourse(std::string courseId);
        // Remove the last course in the vector
        void removeCourse();
        // Remove given course from vector. Returns false if failed.
        bool removeCourse(std::string courseId);
        // Remove course at given index from vector.
        void removeCourse(int index);
        std::string toString(bool full);

        bool operator<(const Student& other) const;
        bool operator>(const Student& other) const;
        bool operator==(const Student& other) const;
        bool operator<=(const Student& other) const;
        bool operator>=(const Student& other) const;
};

#endif
