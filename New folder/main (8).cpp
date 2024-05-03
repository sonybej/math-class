#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;



int average(int sum, int numberstudents) {

int avg = sum / numberstudents;
return avg;
}

void write(string filename, vector<string> StudentName, vector<int> StudentGrade) {

ofstream file(filename);
if (file.is_open() == false) {
cerr << "File could not open" << endl;
return;
}
//meter informacion de cada student
for (int i = 0; i != StudentName.size(); i++) {

}
}

int main() {

int numberstudents;

int sum = 0;
int answer;
string name;
int grade;

vector<string> StudentName;
vector<int> StudentGrade;

cout << "For Math class enter (1) for exit enter -1 " << endl;
cin >> answer;
cout << "How many students do you have in you class " << endl;
cin >> numberstudents;

if (answer ==1) {
for (int i = 0; i < numberstudents; i++) {
cout << "Enter first name of student " << endl;
cin >> name;
StudentName.push_back(name);
cout << "Enter grade of student " << endl;
cin >> grade;
StudentGrade.push_back(grade);
sum += grade;
}
ofstream file("FolderMath.txt", ios::app);

if (file.is_open() == false) {
cerr << "File could not open" << endl;
return -1;
}
write("FolderMath.txt", StudentName, StudentGrade);

}
else {
return -1;
}

cout<<"Average: "<< average(sum, numberstudents);
}