#include <iostream>
#include <string>
using namespace std;
class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};
class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** aflah, Node** azzam);
	bool listEmpty();
	bool delNode();
	void traverse();
};

void CircularLinkedList::addNode() {
	int angka;
	string nama;
	Node* nodeBaru = new Node();
	cout << "Masukan Angka :";
	cin >> angka;
	cout << "Masukan Nama :";
	cin >> nama;
	nodeBaru->rollNumber = angka;
	nodeBaru->name = nama;

	if (LAST == NULL) {
		LAST = nodeBaru;
		nodeBaru->next = nodeBaru;
	}
	else {
		Node* aflah = LAST->next;
		Node* azzam = LAST->next;

		while (azzam != LAST && azzam->rollNumber < nodeBaru->rollNumber) {
			aflah = azzam;
			aflah = azzam->next;
		}
		if (azzam == LAST && azzam->rollNumber < nodeBaru->rollNumber) {
			nodeBaru->next = azzam->next;
			azzam->next = nodeBaru;
			LAST = nodeBaru;
		}
		else {
			nodeBaru->next = azzam;
			aflah->next = nodeBaru;
		}
	}

	cout << "Record Berhasil Ditambahkan.\n";
}

bool CircularLinkedList::search(int rollno, Node** aflah, Node** azzam) {
	*aflah = LAST->next;
	*azzam = LAST->next;

	while (*azzam != LAST) {
		if (rollno == (*azzam)->rollNumber) {
			return true;
		}
		*aflah = *azzam;
		*azzam = (*azzam)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}

	else {
		return false;
	}
}

bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}

bool CircularLinkedList::delNode() {
	if (listEmpty()) {
		cout << "\nList Ini Kosong\n";
		return false;
	}
	int rollno;
	cout << "\nEnter roll number of the record to be deleted: ";
	cin >> rollno;

	Node* aflah;
	Node* azzam;

	if (!search(rollno, &aflah, &azzam)) {
		cout << "Record with roll number " << rollno << " not found.\n";
		return false;
	}
	if (azzam == LAST->next) {
		if (LAST == LAST->next) {
			LAST = NULL;
		}
		else {
			LAST->next = azzam->next;
		}
		delete azzam;
		cout << "Record deleted successfully.\n";
		return true;
	}
}	


void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList ini kosong\n";

	}

	else {
		cout << "\nRecords in the list are:\n";
		Node* currentNode = LAST->next;
		while (currentNode != LAST) {
			cout << currentNode->rollNumber << " " << currentNode->name << endl;
			currentNode = currentNode->next;

		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}

int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-4): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
			}
			case '2': {
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}