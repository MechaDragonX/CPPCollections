CC=g++
# CFLAGS=
# DEPS =
OBJS = double_linked_list.o linked_list.o queue.o student.o main.o

coll: $(OBJS)
	$(CC) -o $@ $^

double_linked_list.o: double_linked_list.cpp i_link.hpp double_linked_list.hpp list_node.hpp student.hpp
	$(CC) -c double_linked_list.cpp

linked_list.o: linked_list.cpp i_link.hpp linked_list.hpp list_node.hpp student.hpp
	$(CC) -c linked_list.cpp

queue.o: queue.cpp i_link.hpp queue.hpp list_node.hpp student.hpp
	$(CC) -c queue.cpp

student.o: student.cpp student.hpp
	$(CC) -c student.cpp

main.o: main.cpp double_linked_list.hpp linked_list.hpp list_node.hpp queue.hpp student.hpp
	$(CC) -c main.cpp

clean:
	rm $(OBJS) coll
