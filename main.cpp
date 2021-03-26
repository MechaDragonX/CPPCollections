#include <iostream>
#include <string>
#include "double_linked_list.hpp"
#include "linked_list.hpp"
#include "list_node.hpp"
#include "queue.hpp"
#include "student.hpp"

DoubleLinkedList<Student> doubleLinkedListStuff(Student rags, Student syke1, Student syke2, Student surnameLacking, Student knob) {
    DoubleLinkedList<Student> list = DoubleLinkedList<Student>(rags);
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
    return list;
}
LinkedList<Student> linkedListStuff(Student rags, Student syke1, Student syke2, Student surnameLacking, Student knob) {
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
    return list;
}
Queue<Student> queueStuff(Student rags, Student syke1, Student syke2, Student surnameLacking, Student knob) {
    Queue<Student> queue = Queue<Student>(rags);
    queue.add(syke1);
    queue.add(syke2);
    queue.add(surnameLacking);
    queue.add(knob);
    std::cout << queue.toString() << std::endl;
    queue.remove();
    std::cout << queue.toString() << std::endl;
    return queue;
}

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

    // DoubleLinkedList<Student> list = doubleLinkedListStuff(rags, syke1, syke2, surnameLacking, knob);
    // LinkedList<Student> list = linkedListStuff(rags, syke1, syke2, surnameLacking, knob);
    Queue<Student> list = queueStuff(rags, syke1, syke2, surnameLacking, knob);

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

    // list.~DoubleLinkedList();
    // if(list.toString() == "")
    //     std::cout << "All values and deleted and memory deallocated successfully!" << std::endl;
    // else
    //     std::cout << "Oh no! Something bad happened! This could be a memory leak....." << std::endl;
}
