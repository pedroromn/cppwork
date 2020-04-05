#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

// Function prototypes
void calculateAverage(ifstream& inp, double& courseAvg);
void printResult(ofstream& outp, string courseId,
                 int groupNo, double avg);

int main(){

  string courseId1;
  string courseId2;
  int numberOfCourses;
  double avg1;
  double avg2;
  double avgGroup1;
  double avgGroup2;
  ifstream group1;
  ifstream group2;
  ofstream outfile;

  group1.open("group1.txt");
  group2.open("group2.txt");

  if(!group1 || !group2){
    cout << "Unable to open files." << endl;
    cout << "Program terminates." << endl;
    return 1;
  }

  outfile.open("student.out");
  outfile << fixed << showpoint;
  outfile << setprecision(2);

  avgGroup1 = 0.0;
  avgGroup2 = 0.0;

  numberOfCourses = 0;

  outfile << "Course No     Group No    "
          << "Course Average" << endl;

  group1 >> courseId1;
  group2 >> courseId2;

  while (group1 && group2) { // mientras haya contenido para leer
    if(courseId1 != courseId2){
      cout << "Data error: Course IDs "
           << "do not match." << endl;
      cout << "Program terminates." << endl;
      return 1;
    }else{
      calculateAverage(group1, avg1);
      calculateAverage(group2, avg2);
      printResult(outfile, courseId1,
                  1, avg1);
      printResult(outfile, courseId2,
                  2, avg2);
      avgGroup1 = avgGroup1 + avg1;
      avgGroup2 = avgGroup2 + avg2;
      outfile << endl;
      numberOfCourses++;
    }

    group1 >> courseId1;
    group2 >> courseId2;
  } // el ciclo finaliza cuando llegue al final del archivo EOF.

  if(group1 && !group2){ // si alguno de los archivos no llegó a EOF
    cout << "Ran out of data for group 2 "
         << "before group 1." << endl;
  }else if(!group1 && group2){
    cout << "Ran out of data for group 1 "
         << "before group 2." << endl;
  }else{
    outfile << "Avg for group 1: "
            << avgGroup1 / numberOfCourses
            << endl;
    outfile << "Avg for group 2: "
            << avgGroup2 / numberOfCourses
            << endl;
  }

  group1.close();
  group2.close();
  outfile.close();

  return 0;
}

void calculateAverage(ifstream& inp, double& courseAvg){
  double totalScore = 0.0;
  int numberOfStudents = 0;
  int score;

  inp >> score;
  while (score != -999) {
    totalScore = totalScore + score;
    numberOfStudents++;
    inp >> score;
  }

  courseAvg = totalScore / numberOfStudents;
}

void printResult(ofstream& outp, string courseId, int groupNo,
                  double avg){
  if(groupNo == 1){
    outp << "      " << courseId << "  ";
  }else{
    outp << "           ";
  }

  outp << setw(8) << groupNo << setw(17) << avg << endl;
}
