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
	bool search(int rollno, Node** previous, Node** current);
	bool listEmpty();
	bool delNode(int rollno);
	void traverse();
};
void CircularLinkedList::addNode() { 
	
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student: ";
	cin >> nim;
	cout << "\nEnter the name of the student: ";
	cin >> nm;
	Node* newNode = new Node(); //Allocate memory for the new node.
	newNode->rollNumber = nim; //Assign value to the data field of the new node.
	newNode->name = nm; //Assign value to the data field of the new node.

	//insert a node in the beginning 
	if (LAST->next == NULL || nim <= LAST->next->rollNumber) {
		if (LAST->next != NULL && nim == LAST->next->rollNumber)
		{
			cout << "Duplicate number not allowed" << endl;
			return;
		}
		newNode->next = LAST->next; //Make the next field of the new node point to the successor of LAST.
		LAST->next = newNode; //Make the next field of LAST point to the new node.
		return;
	}
	//insert a node beetween two node 
		Node* latif = LAST->next; // Make current point to the first node.
		Node* fauzi = NULL; // Make previous point to NULL

		while ((latif != NULL) && (nim >= latif->rollNumber)) //Repeat steps 4 and 5 until current.info > newnode.info or previous = LAST.
		{
			fauzi = latif;//Make previous point to current.
			latif = fauzi->next;//Make current point to the next node in sequence
		}

		if (latif->next != NULL && nim == latif->next->rollNumber) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
	//End of the list
		newNode->next = LAST->next; //Make the next field of the new node point to the successor of LAST.
		LAST->next = newNode; //Make the next field of LAST point to the new node
		LAST = newNode; //Mark LAST point to the new node.


	
	
	
	
}
bool CircularLinkedList::search(int rollno, Node** previous, Node** current) {
	*previous = LAST->next;
	*current = LAST->next;
	while (*current != LAST) {
		if (rollno == (*current)->rollNumber) {
			return true;
		}
		*previous = *current;
		*current = (*current)->next;
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
bool CircularLinkedList::delNode(int rollno) {
	Node* fauzi;
	Node* latif;
		fauzi = latif = NULL;
	//Beginning of the list
	if (search(rollno, &fauzi, &latif) == false)
		return false;
	{
		LAST = NULL;
	}
	latif = LAST->next;//Make current point to the successor of LAST
	LAST->next = latif->next; //Make the next field of LAST point to the successor of current.

	//beetween two node
	fauzi = LAST->next;//Make previous point to the successor of LAST.
	latif = LAST->next;//Make current point to the successor of LAST.
	while (search(rollno, &fauzi, &latif) == false || fauzi != LAST) //Repeat steps 4 and 5 until either the node is found, or previous = LAS
	{
		fauzi = latif;//Make previous point to current
		latif = latif->next;//Make current point to the next node in sequence.
	}

	//End of the list

	latif = LAST; //. Make current point to LAST.
	fauzi = LAST->next; //Make previous point to the successor of LAST 
	while (fauzi->next != LAST) //Repeat step c until the successor of previous becomes LAST
	{
		fauzi = fauzi->next;//Make the previous point to the next node in its sequence.
	}
	fauzi->next = LAST->next;//Make the next field of previous point to the successor of LAST.
	fauzi = LAST;//Mark previous as LAST.



}
void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
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
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': { obj.addNode();
			}
			case '2': {obj.delNode();
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