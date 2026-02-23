#include <iostream>
#include <fstream>
#include<string>
#include <cstdlib>

using namespace std;
int ID;

struct todo {
    int id;
    string task;
};

// Function prototypes  // 
void addtodo() {
    system("cls");
    cout<<"\t*******************************************************************"<<endl;
	cout<<"\t*                      To Do List Application                     *"<<endl;
    cout<<"\t*******************************************************************"<<endl<<endl<<endl<<endl;
    todo todo;
    cout << "\n\tEnter new task: ";
    cin.get();
    getline(cin, todo.task);
    ID++;

    ofstream write;
    write.open("todo.txt", ios::app);
    write << "\n" << ID;
    write << "\n" << todo.task ;
    write.close();


    write.open("id.txt");
    write << ID;
    write.close();

    char ch;
    cout<<"\n\tDo you want to add more task? y/n: ";
    cin>> ch;


    if(ch == 'y'){
        addtodo();
    }
    else{
        cout << "\n\tTask has been added successfully"; 
        return;
    }
}

// Function to print the todo task // 

void print(todo s) { 
    cout << "\n\tID is : " << s.id;
    cout << "\n\tTask is : " << s.task;
}


void readData() {
    system("cls");
    cout<<"\t*******************************************************************"<<endl;
	cout<<"\t*                      To Do List Application                     *"<<endl;
    cout<<"\t*******************************************************************"<<endl<<endl<<endl<<endl;
    todo todo; 
    ifstream read;
    read.open("todo.txt");
    cout << "\n\t------------------Your current Tasks in the list--------------------";

    while (!read.eof()) {
        read >> todo.id;
        read.ignore();
        getline(read, todo.task);
        print(todo);
    }
    read.close();
}


int searchData() {
    system("cls");
    cout<<"\t*******************************************************************"<<endl;
	cout<<"\t*                      To Do List Application                     *"<<endl;
    cout<<"\t*******************************************************************"<<endl<<endl<<endl<<endl;
    int id;
    cout << "\n\tEnter task id: ";
    cin >> id;
    todo todo;
    ifstream read;
    read.open("todo.txt");

    while (!read.eof()) {
        read >> todo.id;
        read.ignore();
        getline(read, todo.task);
        if (todo.id == id) {
            print(todo);
            return id;
        }
    }
}


void deleteData() {
    system("cls");
    cout<<"\t*******************************************************************"<<endl;
	cout<<"\t*                      To Do List Application                     *"<<endl;
    cout<<"\t*******************************************************************"<<endl<<endl<<endl<<endl;
    int id = searchData();
    cout << "\n\tDo you want to delete this task (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        todo todo;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("todo.txt");

        while (!read.eof()) {
            read >> todo.id;
            read.ignore();
            getline(read, todo.task);
            if (todo.id != id) {
                tempFile << "\n" << todo.id;
                tempFile << "\n" << todo.task;
            }
        }
        read.close();
        tempFile.close();
        remove("todo.txt");
        rename("temp.txt", "todo.txt");
        cout << "\n\tTask deleted successfuly";
    }
    else {
        cout << "\n\tRecord not deleted";
    }
}


void updateData() {
    system("cls");
    cout<<"\t*******************************************************************"<<endl;
	cout<<"\t*                      To Do List Application                     *"<<endl;
    cout<<"\t*******************************************************************"<<endl<<endl<<endl<<endl;
    int id = searchData();
    cout << "\n\n\tYou want to update this task (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        todo newData;
        cout << "\n\tEnter todo task : ";
        cin.get();
        getline(cin, newData.task);
        todo todo;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("todo.txt");

        while (!read.eof()) {
            read >> todo.id;
            read.ignore();
            getline(read, todo.task);
            if (todo.id != id) {
                tempFile << "\n" << todo.id;
                tempFile << "\n" << todo.task;
            }
            else {
                tempFile << "\n"<< todo.id;
                tempFile << "\n"<< newData.task;
            }
        }
        read.close();
        tempFile.close();
        remove("todo.txt");
        rename("temp.txt", "todo.txt");
        cout << "\n\tTask updated successfuly";
    }
    else {
        cout << "\n\tRecord not deleted";
    }
}
int main()
{
    system("cls");
    cout<<"\t*******************************************************************"<<endl;
	cout<<"\t*                      To Do List Application                     *"<<endl;
    cout<<"\t*******************************************************************"<<endl<<endl<<endl<<endl;
    ifstream read;
    read.open("id.txt");
    if (!read.fail()) {
        read >> ID;
    }
    else {
        ID = 0;
    }
    read.close();

    while (true) {
        cout<<endl;
        cout << "\n\t1.Add Task";
        cout << "\n\t2.Display Task";
        cout << "\n\t3.Search Task";
        cout << "\n\t4.Delete Task";
        cout << "\n\t5.Update Task";

        int choice;
        cout << "\n\n\tEnter choice : ";
        cin >> choice;
        switch (choice) {
        case 1:
            addtodo();
            break;
        case 2:
            readData();
            break;
        case 3:
            searchData();
            break;
        case 4:
            deleteData();
            break;
        case 5:
            updateData();
            break;
        }
    }

}
