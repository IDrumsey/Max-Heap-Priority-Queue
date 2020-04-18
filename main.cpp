#include "maxHeap.h"

#include <fstream>
#include <string>


using namespace std;

int main() {
	//Create heap
	maxHeap myHeap = maxHeap();

	//Find file
	ifstream commands("..\\maxHeap\\heap.dat");
	
	if (commands.fail()) {
		cout << "Failed to open file stream!\n";
	}
	else {
		string curr;
		int toInsert;
		while (!commands.eof()) {
			commands >> curr;
			
			if (curr == "I") {
				commands >> toInsert;
				myHeap.insert(toInsert);
			}
			else if (curr == "D") {
				cout << "Deleted " << myHeap.Pull() << " from the heap!\n";
			}
			else if (curr == "P") {
				//PreOrder Traversal
				myHeap.Print(0);
				cout << "\n";
			}

		}
	}

	cout << "Done\n";//DEBUG
	return 0;
}