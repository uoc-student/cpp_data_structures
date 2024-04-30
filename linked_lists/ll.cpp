#include <iostream>


using namespace std;


class Node {
public:
    Node* next;
    int value;

    Node(int value = 0) {
        this->value = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int length;

public:
    LinkedList(int value = 0) {
        if (value == 0) {
            head = nullptr;
            tail = nullptr;
            length = 0;
        } else {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }
    }

    ~LinkedList() {
        Node* tmp = head;

        while (head) {
            head = head->next;
            delete tmp;
            tmp = head;
        }

        head = nullptr;
        tail = nullptr;
    }

    int getLength() {
        return length;
    }

    int getHead() {
        return head->value;
    }

    int getTail() {
        return tail->value;
    }

    bool isEmpty() {
        if (length == 0) return true;
        return false;
    }

    void printList() {
        if (length == 0) {
            cout << "List is empty!" << endl;
        }

        Node* tmp = head;

        cout << "Printing list: ";

        for (int i = 0; i < length; i++) {
            cout << tmp->value << " -> ";
            tmp = tmp->next;
        }
        cout << endl;
    }

    // craetes a node and inserts it at a given index
    void insert(int value, int index) {
        if (index < 0 || index > length) {
            cout << "Index out of bounds!" << endl;
            return;
        }

        Node* newNode = new Node(value);

        if (length == 0) {
            head = newNode;
            tail = newNode;
        } else if (index == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node *tmp = head;

            for (int i = 0; i < index - 1; i++) {
                tmp = tmp->next;
            }
            newNode->next = tmp->next;
            tmp->next = newNode;

            if (index == length) {
                tail = newNode;
            }
        }
        length++;
    }

    // remove a node at a given index
    void remove(int index) {
        if (index < 0 || index >= length) {
            cout << "Index out of bounds!!" << endl;
            return;
        }

        Node* tmp = head;
        Node* node_to_delete = nullptr;

        if (index == 0) {
            head = head->next;
            delete tmp;
        } else {
             for (int i = 0; i < index - 1; i++) {
                tmp = tmp->next;
            }
             node_to_delete = tmp->next;
             tmp->next = tmp->next->next;
             node_to_delete->next = nullptr;
             delete node_to_delete;

             if (index == length - 1) {
                 tail = tmp;
             }
        }
        length--;
    }

};


int main() {
    LinkedList* ll = new LinkedList();
    cout << "isEmpty(): " << ll->isEmpty() << endl;

    cout << "inserting 0..." << endl;
    ll->insert(0, 0);
    cout << "Head: " << ll->getHead() << endl;
    cout << "Tail: " << ll->getTail() << endl;
    cout << "Length: " << ll->getLength() << endl;
    cout << "isEmpy(): " << ll->isEmpty() << endl;
    ll->printList();
    cout << "*************" << endl;

    ll->insert(-1, 0);
    cout << "inserting -1 at index 0..." << endl;
    cout << "Head: " << ll->getHead() << endl;
    cout << "Tail: " << ll->getTail() << endl;
    cout << "Length: " << ll->getLength() << endl;
    ll->printList();
    cout << "*************" << endl;

    ll->insert(1, 2);
    cout << "inserting 1 at index 2..." << endl;
    cout << "Head: " << ll->getHead() << endl;
    cout << "Tail: " << ll->getTail() << endl;
    cout << "Length: " << ll->getLength() << endl;
    ll->printList();
    cout << "*************" << endl;

    ll->insert(5, 1);
    cout << "inserting 5 at index 1..." << endl;
    cout << "Head: " << ll->getHead() << endl;
    cout << "Tail: " << ll->getTail() << endl;
    cout << "Length: " << ll->getLength() << endl;
    ll->printList();
    cout << "*************" << endl;

    ll->insert(-10, 0);
    cout << "inserting -10 at index 0..." << endl;
    cout << "Head: " << ll->getHead() << endl;
    cout << "Tail: " << ll->getTail() << endl;
    cout << "Length: " << ll->getLength() << endl;
    ll->printList();
    cout << "*************" << endl;

    ll->insert(-5, 5);
    cout << "inserting -5 at index 5..." << endl;
    cout << "Head: " << ll->getHead() << endl;
    cout << "Tail: " << ll->getTail() << endl;
    cout << "Length: " << ll->getLength() << endl;
    ll->printList();
    cout << "*************" << endl;

    ll->insert(-11, 5);
    cout << "inserting -11 at index 5..." << endl;
    cout << "Head: " << ll->getHead() << endl;
    cout << "Tail: " << ll->getTail() << endl;
    cout << "Length: " << ll->getLength() << endl;
    ll->printList();
    cout << "*************" << endl;

    ll->insert(15, 1);
    cout << "inserting 15 at index 1..." << endl;
    cout << "Head: " << ll->getHead() << endl;
    cout << "Tail: " << ll->getTail() << endl;
    cout << "Length: " << ll->getLength() << endl;
    ll->printList();
    cout << "*************" << endl;

    ll->remove(0);
    cout << "delete at index 0..." << endl;
    cout << "Head: " << ll->getHead() << endl;
    cout << "Tail: " << ll->getTail() << endl;
    cout << "Length: " << ll->getLength() << endl;
    ll->printList();
    cout << "*************" << endl;

    ll->remove(6);
    cout << "delete at index 6..." << endl;
    cout << "Head: " << ll->getHead() << endl;
    cout << "Tail: " << ll->getTail() << endl;
    cout << "Length: " << ll->getLength() << endl;
    ll->printList();
    cout << "*************" << endl;

    ll->remove(2);
    cout << "delete at index 2..." << endl;
    cout << "Head: " << ll->getHead() << endl;
    cout << "Tail: " << ll->getTail() << endl;
    cout << "Length: " << ll->getLength() << endl;
    ll->printList();
    cout << "*************" << endl;
}
