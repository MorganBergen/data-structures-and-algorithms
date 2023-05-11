#include <iostream>
#include "LinkedList.h"

using namespace std;

void PrintP( MyLinkedList<int> L, MyLinkedList<int> P ) {
	auto itrL = L.begin();
	auto itrP = P.begin();
	int counter = 0;

	while (itrL != L.end() && itrP != P.end()) {
		if (*itrL == counter) {
			cout << *itrP << endl;
			itrL++;
		}
		itrP++;
		counter++;
	}
}

int main() {
	MyLinkedList<int> L, P;

	for ( int i = 0; i < 101; i++ ) {
		P.push_back( i );
	}

	int i = 0;
	while (i < 105) {
		if (i % 5 == 0) {
			L.push_back( i );
		}
		i++;
	}

	PrintP(L, P);

	return 0;
}	
