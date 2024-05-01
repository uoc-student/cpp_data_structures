#include <iostream>
#include <climits>

using namespace std;


class Node {
public:
    Node* next;
    Node* prev;
    int value;

    Node(int value) {
        next = nullptr;
        prev = nullptr;
        this->value = value;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    DoublyLinkedList(Node* node) {
        if (node == nullptr) {
            cout << "Node is empty!\nEmpty list created" << endl;
            head = nullptr;
        } else {
            head = node;
        }
    }

    ~DoublyLinkedList() {
        Node* tmp = head;
        while (head) {
            head = head->next;
            delete tmp;
            tmp = head;
        }
    }

    void printList() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* tmp = head;

        cout << "Printing List: " << endl;
        while (tmp) {
            cout << tmp->value << " -> ";
            tmp = tmp->next;
        }
        cout << endl;
    }

    int getLength() {
        int length = 0;
        Node* tmp = head;

        while (tmp) {
            length++;
            tmp = tmp->next;
        }
        return length;
    }

    int getValue(int index) {
        int length = getLength();
        if (index < 0 || index >= length || length == 0)  return INT_MIN;

        Node* tmp = head;
        for (int i = 0; i < index; i++) {
            tmp = tmp->next;
        }
        return tmp->value;
    }

    bool insert(Node* node, int index) {
        int length = getLength();
        if (index < 0 || index > length) return false;

        Node* tmp = head;

        if (index == 0) {
            if (length != 0) {
                node->next = head;
                head->prev = node;
            }
            head = node;
            return true;
        }

        if (index == length) {
            for (int i = 0; i < index - 1; i++) {
                tmp = tmp->next;
            }
            node->prev = tmp;
            tmp->next = node;
        } else {
            for (int i = 0; i < index; i++) {
                tmp = tmp->next;
            }
            tmp->prev->next = node;
            node->prev = tmp->prev;
            tmp->prev = node;
            node->next = tmp;
        }
        return true;
    }

    bool remove(int index) {
        int length = getLength();
        if (index < 0 || index >= length || length == 0) return false;

        Node* tmp = head;

        if (index == 0) {
            if (length == 1) {
                delete head;
                head = nullptr;
            } else {
                head = tmp->next;
                head->prev = nullptr;
                tmp->next = nullptr;
                delete tmp;
            }
            return true;
        }

        for (int i = 0; i < index; i++) {
            tmp = tmp->next;
        }

        if (index == length - 1) {
            tmp->prev->next = nullptr;
            tmp->prev = nullptr;
            delete tmp;
        } else {
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            tmp->next = nullptr;
            tmp->prev = nullptr;
            delete tmp;
        }
        return true;
    }
};


int main() {
    cout << "Creating DoublyLinkedList...\n";
    DoublyLinkedList* dll = new DoublyLinkedList();
    cout << "Length: " << dll->getLength() << endl;

    Node* node_0 = new Node(0);
    cout << "Inserting node 0 to pos 0...\n";+
    dll->insert(node_0, 0);
    cout << "Length: " << dll->getLength() << endl;
    dll->printList();

    Node* node_1 = new Node(1);
    cout << "Inserting node 1 to pos 1...\n";
    dll->insert(node_1, 1);
    cout << "Length: " << dll->getLength() << endl;
    dll->printList();

    Node* node_2 = new Node(2);
    cout << "Inserting node 2 to pos 1...\n";
    dll->insert(node_2, 1);
    cout << "Length: " << dll->getLength() << endl;
    dll->printList();

    Node* node_3 = new Node(3);
    cout << "Inserting node 3 to pos 3...\n";
    dll->insert(node_3, 3);
    cout << "Length: " << dll->getLength() << endl;
    dll->printList();

    Node* node_5 = new Node(5);
    cout << "Inserting node 5 to pos 0...\n";
    dll->insert(node_5, 0);
    cout << "Length: " << dll->getLength() << endl;
    dll->printList();

    Node* node_10 = new Node(10);
    cout << "Inserting node 10 to pos 4...\n";
    dll->insert(node_10, 4);
    cout << "Length: " << dll->getLength() << endl;
    dll->printList();

    Node* node_15 = new Node(15);
    cout << "Inserting node 15 to pos 6...\n";
    dll->insert(node_15, 6);
    cout << "Length: " << dll->getLength() << endl;
    dll->printList();

    cout << "Removing index 0...\n";
    dll->remove(0);
    cout << "Length: " << dll->getLength() << endl;
    dll->printList();

    cout << "Removing index 5...\n";
    dll->remove(5);
    cout << "Length: " << dll->getLength() << endl;
    dll->printList();

    cout << "Removing index 2...\n";
    dll->remove(2);
    cout << "Length: " << dll->getLength() << endl;
    dll->printList();

    cout << "Remove everything...\n";
    dll->remove(0);
    dll->remove(0);
    dll->remove(0);
    dll->printList();
    dll->remove(0);
    dll->printList();
    return 0;
}
