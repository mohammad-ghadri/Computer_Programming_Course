
#include "stdafx.h"
#include <iostream>
#include <string>
#include "ConsoleApplication4.h"
using namespace std ;
//input students identity card number
void codef (int code[100],int counter1) {
	int i=0;
		for (i = 0; i < counter1; i++) {
			cout << "		Please Enter student's code:" << endl;
			cout << "		student's code Number" << i+1 << " is: " <<endl;
			cin >> code[i];
		}
} 

// input lesson name
void lessonf(string lesson [100], int counter2) {
	int i = 0;
	for (i = 0; i < counter2; i++) {
		cout << "		Please Enter lessons's name:" << endl;
		cin >> lesson[i];
	}
}
//input credit for each lesson
int unitf(int unit[100] , int counter2,string lesson[100]) {
	int i = 0;
	float sumunit=0 ;
	for (i = 0; i < counter2; i++) {
		cout << "		Enter "<< lesson[i] << "'s unit:" << endl;
		cin >> unit[i] ;
		sumunit += unit[i];
	}
	return sumunit;
}
float mark[100][100];
//computing GPA fpr each person
void markf(float num[100], int counter1,int code[100], int unit[100],int counter2, float sunit) {
	int i, j;
	float avg = 0;
	for (i = 0; i < counter1;i++) {
		for (j = 0; j < counter2; j++) {
			cout<<"		Plaese Enter the marks{range;(0,100)} of each student according the lesson's serialization:"<<endl;
			cin >> mark[i][j];
			avg += (mark[i][j]*unit[j]);
		}
		avg = avg / sunit;
		num[i] = avg;
		avg = 0;
	}
}
//finding max & min GPA
			void rank1f(float num [100], int counter1 , int code [100]){
				int i = 0;
				int j = 0;
				float m = 0;
				for (i = 0; i < counter1; i++) {
					if (m <num[i]) {
						m = num[i];
						j += 1;
					}
				}
				cout << "rank 1 is:" << code[j]<<"; with average="<< num[j] << endl;
			}
			void ranknf(float num[100], int counter1, int code [100]) {
				int i = 0;
				int j = 0;
				float m = 100;
				for (i = 0; i < counter1; i++) {
					if (m >num[i]) {
						m = num[i];
						j += 1;
					}
				}
				cout << "lastest rank is:" << code[j] << "; with average=" << num[j] << endl;
			}
			//sorting
			void sortf(float num[100], int counter1, int code[100]) {
				int i = 0;
				int j = 0;
				int m = 0;
				for (i = m; i < counter1; i++) {
					for (j = i + 1; j <= counter1; j += 1) {
						if (num[i] > num[j]) {
							num[i] += num[j];
							num[j] = num[i] - num[j];
							num[i] = num[i] - num[j];
							code[i] += code[j];
							code[j] = code[i] - code[j];
							code[i] = code[i] - code[j];
						}
					}
					m += 1;
				}
			}
			void printf(float num[100], int counter1,int code[100]) {
				int i = 0;
				for (i = 0; i < counter1; i++) {
					cout << i+1 << "." << code[i]<<"  WITHE AVRAGE=" << num[i] << "  and  ";
					if (num[i] > 95) {
						cout << "grade A++" << endl;
					}
					else if (num[i] > 90) {
						cout << "grade A+" << endl;
					}
					else if(num[i] > 80) {
						cout << "grade B+" << endl;
					}
					else if (num[i] > 70) {
						cout << "grade C+" << endl;
					}
					else if (num[i] > 60) {
						cout << "grade A" << endl;
					}
					else if (num[i] > 60) {
						cout << "grade B" << endl;
					}
					else if (num[i] > 50) {
						cout << "grade C" << endl;
					}
					else {
						cout << "so bad,try harder";
					}
					cout << "" << endl;
				}
			}
			
			//find person with desired GPA
			bool mainfindf(float num[100], int counter1, float x) {
				int i = 0, m;
				while (i < counter1) {
					m = (i + counter1) / 2;
					if (num[m] == x) {
						return true;
					}
					else if (x > num[m]) {
						i = m + 1;
					}
					else {
						counter1 = m - 1;
					}
				}
			}

		    int findf(float num[100], int counter1,float x) {
				int i = 0,m;
				while (i < counter1) {
					m = (i + counter1) / 2;
					if (num[m] == x) {
						return m;
					}
					else if (x > num[m]) {
						i = m + 1;
					}
					else {
						counter1 = m - 1;
					}
				}
			}
			void cardf( float num[100], int counter1, int code[100], string lesson[100], int counter2, int unit[100]) {
				int i = 0;
				int j = 0;
				for (i = 0; i < counter1; i++) {
					cout << "code:" << code[i] << endl;
					cout << "avrage:" << num[i] << endl;
					for (j = 0; j < counter1; j++) {
						cout <<"lesson:"<< lesson[j] << " with unit =	" << unit[j] << "	" << mark[i][j] << endl;
					}
				}
			}  
int main(){
	cout << "Please Enter Your Name:" << endl;
	string name;
	cin >> name;
	cout << "Welcome Dear " << name << endl;
    A:cout << "How many students You have?(Please Enter integer number)" << endl;
	int counter1;
	cin >> counter1;
		if (counter1 > 0 && counter1 < 100000 ) {
		}
		else {
			cout << "Dear " << name << " The Enterd number is invalid , please try again" << endl;
			goto A;
		}
	int code[100];
	codef(code, counter1);
	B:cout << "How many lessons students have?(Please Enter integer number)" << endl;
	int counter2;
	cin >> counter2;
	if (counter1 > 0 && counter1 < 100000 ) {
	}
	else {
		cout << "Dear " << name << " The Enterd number is invalid , please try again" << endl;
		goto B;
	}
	string lesson[100];
	lessonf(lesson, counter2);
	int unit[100];
	float snit = 0;
	snit=unitf(unit, counter2,lesson);
	float num[100];
	markf(num, counter1, code, unit, counter2,snit);
	cout << "Do you want to know who's rank 1?" << endl;
	cout << "	If you enter '1'(mean:yes)/any other number mean:no)" << endl;
	int a;
	cin >> a;
	if (a == 1) {
		rank1f(num, counter1, code);
	}
	cout << "Do you want to know who's lastest rank ?" << endl;
	cout << "	If you enter '1'(mean:yes)/any other number mean:no)" << endl;
	cin >> a;
	if (a == 1) {
		ranknf(num, counter1, code);
	}
	sortf(num, counter1, code);
	cout << "Do you want to have description evaluation?(y/any other key)" << endl;
	cout << "	If you enter '1'(mean:yes)/any other number mean:no)" << endl;
	cin >> a;
	if (a == 1) {
		printf(num, counter1, code);
	}
	cout << "Do you want to find student(s) with special average?" << endl;
	cout << "	If you enter '1'(mean:yes)/any other number means:no)" << endl;
	cin >> a;
	if (a == 1) {
		cout << "Enter A Number:" << endl;
		float x;
		int m;
		cin >> x;
		if (mainfindf(num, counter1, x)) {
			m = findf(num, counter1, x);
			cout <<"Student: "<< code[m] << " has average " << x << endl;
		}
		else{
			cout << "Thers's no person with average="<< x << endl;
		}
	}
	cout << "Do you want to every student workbook?" << endl;
	cout << "	If you enter '1'(mean:yes)/any other number means:no)" << endl;
	cin >> a;
	if (a == 1) {
		cardf(num, counter1, code, lesson, counter2, unit);
	}
	cout << "				Thanks "<< name << endl;
	cout << "-----------------------------------------------------------------------" <<endl;
	cout << "				1.Programmer:mohammad.ghadri              	    		" << endl;
	cout << "				2.mohammadghadri18@gmail.com				            " << endl;
	cout << "				3.Project:students card   			                    " << endl;
	cout << "-----------------------------------------------------------------------" << endl;
	return 0;
}












