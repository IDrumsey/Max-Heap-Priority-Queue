runme: main.o maxHeap.o
	g++ main.o maxHeap.o -o runme

main.o: main.cpp
	g++ -c main.cpp
maxHeap.o: maxHeap.cpp
	g++ -c maxHeap.cpp

clean:
	rm *.o runme
