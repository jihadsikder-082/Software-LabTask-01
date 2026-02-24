#include<iostream>
using namespace std;

class DNode {
public:
    char data;
    DNode* next;
    DNode* pre;
    DNode(char value) {
        data = value;
        next = nullptr;
        pre = nullptr;
    }
};

void insertAtLast(DNode* &head, char value) {
    DNode* newNode = new DNode(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    DNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->pre = temp;
}

void display(DNode* head) {
    while (head != nullptr) {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL\n";
}

bool isPalindrome(DNode* head) {
    if (!head || !head->next) return true;

    DNode* left = head;
    DNode* right = head;
    while (right->next != nullptr) {
        right = right->next;
    }

    while (left != right && left->pre != right) {
        if (left->data != right->data)
            return false;
        left = left->next;
        right = right->pre;
    }

    return true;
}

int main() {
    DNode* head = nullptr;
    string input = "racecar";

    for (char c : input) {
        insertAtLast(head, c);
    }

    cout << "Doubly Linked List: ";
    display(head);

    if (isPalindrome(head))
        cout << "The list is a palindrome.\n";
    else
        cout << "The list is not a palindrome.\n";

    return 0;
}
