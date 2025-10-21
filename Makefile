bin/testListArray: TestListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -o bin/testListArray -g -O2 -Wall TestListArray.cpp ListArray.h
bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/testNode -g -O2 -Wall testNode.cpp Node.h

clean:
	rm -r *.o *.gch bin
