#include <iostream>
#include <string>
#include "linked_list.hpp"
#include "student.hpp"

int main() {
    Student rags("Raghav", "Vivek");
    rags.addCourse("math");
    rags.addCourse("cs");
    rags.addCourse("eng");
    std::cout << rags.toString(true) << std::endl;

    Student syke1("Dylan", "Sykes");
    syke1.addCourse("math");
    syke1.addCourse("eng");
    std::cout << syke1.toString(true) << std::endl;

    Student syke2("Mason", "Sykes");
    syke2.addCourse("math");
    syke2.addCourse("cs");
    std::cout << syke2.toString(true) << std::endl;

    Student surnameLacking("Ashley", "Koch");
    surnameLacking.addCourse("math");
    surnameLacking.addCourse("eng");
    std::cout << surnameLacking.toString(true) << std::endl;

    Student knob("Jake", "Knabner");
    knob.addCourse("cs");
    knob.addCourse("eng");
    std::cout << knob.toString(true) << std::endl;

    LinkedList<Student> list = LinkedList<Student>(rags);
    list.add(syke1);
    list.add(syke2);
    list.add(surnameLacking);
    list.add(knob);
    std::cout << list.toString() << std::endl;
    list.remove();
    std::cout << list.toString() << std::endl;
    list.remove(syke2);
    std::cout << list.toString() << std::endl;
    list.remove(rags);
    std::cout << list.toString() << std::endl;

    std::cout << "Is Mason Sykes alive? ";
    bool alive = list.exists(syke2);
    if(alive)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;

    std::cout << "Is the character that didn't have a last name until today (Ashley) alive? ";
    alive = list.exists(surnameLacking);
    if(alive)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;

    // list.~LinkedList();
    // if(list.toString() == "")
    //     std::cout << "All values and deleted and memory deallocated successfully!" << std::endl;
    // else
    //     std::cout << "Oh no! Something bad happened! This could be a memory leak....." << std::endl;
}
