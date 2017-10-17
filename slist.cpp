/* This is a program that allows you to add, print, and remove students information
 *Trevor Horine
 *10/13/2017*/
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

struct student{
  char fname[81];
  char lname[81];
  int idnum;
  float gpa;
};

//methods
void add(vector<student*> &students);
void remove(vector<student*> &students);
void list(vector<student*> &students);

//main method
int main(){
  char operation[10];
  bool working = true;
  vector<student*> students;
  //allows continued use
  while(working == true){
    cout << "Do you want to add, remove, or list students? Or do you want to quit?" << endl;
    cin >> operation;
    if(strcmp(operation, "add") == 0){
      add(students);
    }
    else if(strcmp(operation, "remove") == 0){
      remove(students);
    }
    else if(strcmp(operation, "list") == 0){
      list(students);
    }
    else if(strcmp(operation, "quit") == 0){
      working = false;
    }
    else{
      cout << "Please pick add, remove, list, or quit!" << endl;
    }
  }
}
// adds students
void add(vector<student*> &students){
   student* n = new student;
   //ask for the values to be recorded for the student
   cout << "What is the first name of the student?" << endl;
   cin >> n -> fname;
   cout << "What is the last name of the student?" << endl;
   cin >> n -> lname;
   cout << "What is the ID number of the student?" << endl;
   cin >> n -> idnum;
   cout << "What is the GPA of the student?" << endl;
   cin >> n -> gpa;
   students.push_back(n);
}
//removes students
void remove(vector<student*> &students){
  cout << "Enter a id number to remove a student from the face of the earth." << endl;
  int temp;
  cin >> temp;
  //removes matching student from vector
  for(vector<student*>::iterator it = students.begin(); it != students.end(); it++){
    if((*it)->idnum = temp){
      delete students[it-students.begin()];
      students.erase(it);
      break;
    }
  }
    
}
// list studetnts in program
void list(vector<student*> &students){
  cout << "Students" << endl;
  //print students
  for(vector<student*>::iterator it = students.begin(); it != students.end(); it++){
    cout << ' ' << (*it)-> fname;
    cout << ' ' << (*it)-> lname;
    cout << ' ' << "ID Number: "<< (*it)-> idnum;
    cout << ' ' << "GPA: " << (*it)-> gpa << endl;
  }
}
