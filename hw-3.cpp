#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <list>

using namespace std;

class Student {
public:
    int id;
    string name;
    string surname;

    Student() {}
    Student(int id, const string& name, const string& surname) : id(id), name(name), surname(surname) {}
};

class LinkedList {
private:
    struct Node {
        Student data;
        Node* next;
        Node(const Student& student) : data(student), next(nullptr) {}
    };
    Node* head;

public:
    LinkedList() : head(nullptr) {}
    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(const Student& student) {
        Node* newNode = new Node(student);
        newNode->next = head;
        head = newNode;
    }

    void display() const {
        Node* current = head;
        while (current) {
            cout << "ID: " << current->data.id << ", Ad: " << current->data.name << ", Soyad: " << current->data.surname << endl;
            current = current->next;
        }
    }
};

class HashTable {
private:
    unordered_map<int, Student> table;

public:
};

void readFromInput(LinkedList& list, HashTable& table) {
    int id;
    string name, surname;

    cout << "Öğrenci bilgilerini giriniz (ID, Ad, Soyad), çıkmak için -1 ID girin:\n";
    while (true) {
        cin >> id;
        if (id == -1)
            break;
        cin >> name >> surname;
        Student student(id, name, surname);
        list.insert(student);
    }
}

void writeToOutput(const LinkedList& list, const HashTable& table) {
    cout << "Öğrenci bilgileri:\n";
    list.display();
}

void updateStudent(LinkedList& list, HashTable& table, int id, const string& name, const string& surname) {

}

void deleteStudent(LinkedList& list, HashTable& table, int id) {

}

int main() {
    LinkedList list;
    HashTable table;

    readFromInput(list, table);

    updateStudent(list, table, 123, "Ali", "Yılmaz");
    updateStudent(list, table, 456, "Ayşe", "Kaya");

    writeToOutput(list, table);

    return 0;
}
