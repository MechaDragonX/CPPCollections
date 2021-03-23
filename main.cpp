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
    knob.addCourse("end");
    std::cout << knob.toString(true) << std::endl;

    LinkedList list = LinkedList(rags);
    list.add(syke1);
    list.add(syke2);
    list.add(surnameLacking);
    list.add(knob);
    std::cout << list.toString() << std::endl;
    list.remove();
    std::cout << list.toString() << std::endl;
    list.remove(syke2);
    std::cout << list.toString() << std::endl;
}
