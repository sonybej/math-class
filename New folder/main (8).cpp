#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int average(int sum, int numberstudents) {
  int avg = sum / numberstudents;
  return avg;
}

void write(string filename, vector<string> StudentName, vector<int> StudentGrade) {
  ofstream file(filename);
  if (!file.is_open()) {
    cerr << "File could not open" << endl;
    return;
  }
  for (int i = 0; i < StudentName.size(); i++) {
    file << "Student Name: " << StudentName[i] << ", Grade: " << StudentGrade[i] << endl;
  }
  file.close();
}

int main() {
  int numberstudents;
  int sum = 0;
  int answer;
  string name;
  int grade;
  vector<string> StudentName;
  vector<int> StudentGrade;

  cout << "For Math class enter (1) to start, or enter -1 to exit." << endl;
  cin >> answer;

  if (answer == 1) {
    cout << "How many students do you have in your class?" << endl;
    cin >> numberstudents;

    if (numberstudents == -1) {
      cout << "Exiting program." << endl;
      return 0; // Exit the program gracefully
    }

    for (int i = 0; i < numberstudents; i++) {
      cout << "Enter the first name of student " << i + 1 << ":" << endl;
      cin >> name;
      StudentName.push_back(name);
      cout << "Enter the grade of student " << i + 1 << ":" << endl;
      cin >> grade;
      StudentGrade.push_back(grade);
      sum += grade;
    }
    ofstream file("FolderMath.txt", ios::app);
    if (!file.is_open()) {
      cerr << "File could not open" << endl;
      return -1;
    }
    write("FolderMath.txt", StudentName, StudentGrade);
  } else if (answer == -1) {
    cout << "Exiting program." << endl;
    return 0; // Exit the program gracefully
  } else {
    cout << "Invalid input. Exiting program." << endl;
    return -1; // Exit with an error status
  }

  cout << "Average grade: " << average(sum, numberstudents) << endl;
  return 0;
}
