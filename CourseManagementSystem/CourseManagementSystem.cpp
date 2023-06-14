#include <iostream>
#include <string>
using namespace std;
struct student_profile {
	string name = " ", id;
	double gpa = 0.0;
	int roll = 0;
}student[100];
struct course {
	string name, instructor, id;
	student_profile enrolled_students[10];
	int roll = 0;
}c[20], c1[5];
int totalnoOfstudents, totalnoOfcourses;
void enter()
{
	bool founded = false;
	string id;
	cout << "Enter Id of the course you want to enroll to :\t ";
	cin >> id;
	for (int j = 0; j < 5; ++j) {
		if (id == c1[j].id) {
			founded = true;
			for (int k = 0; k < 10; ++k) {
				if (c1[j].enrolled_students[k].name == " ") {
					student[totalnoOfstudents].roll = totalnoOfstudents + 1;
					cout << "\nEnter the Data of student : " << endl << endl;
					cout << "Enter name: ";
					cin >> student[totalnoOfstudents].name;
					cout << "Enter ID: ";
					cin >> student[totalnoOfstudents].id;
					cout << "Enter student GPA: ";
					cin >> student[totalnoOfstudents].gpa;

					c1[j].enrolled_students[k].name = student[totalnoOfstudents].name;
					c1[j].enrolled_students[k].gpa = student[totalnoOfstudents].gpa;
					c1[j].enrolled_students[k].id = student[totalnoOfstudents].id;
					c1[j].enrolled_students[k].roll = k + 1;
					totalnoOfstudents++;
					cout << endl;
					cout << "[Successfully enrolled] " << endl;
					break;
				}
			}
			break;
		}
	}
	if (founded == false) {
		for (int j = 0; j < 20; ++j) {
			if (id == c[j].id) {
				founded = true;
				for (int k = 0; k < 10; ++k) {

					if (c[j].enrolled_students[k].name == " ") {
						student[totalnoOfstudents].roll = totalnoOfstudents + 1;
						cout << "\nEnter the Data of student : " << endl << endl;
						cout << "Enter name: ";
						cin >> student[totalnoOfstudents].name;
						cout << "Enter ID: ";
						cin >> student[totalnoOfstudents].id;
						cout << "Enter student GPA: ";
						cin >> student[totalnoOfstudents].gpa;
						c[j].enrolled_students[k].name = student[totalnoOfstudents].name;
						c[j].enrolled_students[k].gpa = student[totalnoOfstudents].gpa;
						c[j].enrolled_students[k].id = student[totalnoOfstudents].id;
						c[j].enrolled_students[k].roll = k + 1;
						totalnoOfstudents++;

						cout << "[Successfully enrolled] " << endl;
						break;

					}

				}
				break;
			}
		}
	}
	if (founded == false)
		cout << " [NOT FOUNDED] " << endl;
}
void enter_course() {
	int choice = 0;
	cout << "How many courses do you want to enter?" << endl;
	cin >> choice;
	if (totalnoOfcourses == 0)
	{
		totalnoOfcourses += choice;
		for (int i = 0; i < choice; i++) {
			c[i].roll = i + 1;
			cout << "\nEnter the Data of course " << i + 1 << " :" << endl;
			cout << "Enter course name : ";
			cin >> c[i].name;
			cout << "Enter course ID : ";
			cin >> c[i].id;
			cout << "Enter instructor name : ";
			cin >> c[i].instructor;
		}
	}
	else
	{


		for (int i = totalnoOfcourses; i < choice + totalnoOfcourses; i++)
		{
			c[i].roll = i + 1;
			cout << "\nEnter the Data of course " << i + 1 << " : " << endl;
			cout << "Enter course name : ";
			cin >> c[i].name;
			cout << "Enter course ID : ";
			cin >> c[i].id;
			cout << "Enter istructor name :  ";
			cin >> c[i].instructor;
		}	    totalnoOfcourses += choice;
	}
}
void show()
{
	if (totalnoOfstudents == 0)
	{
		cout << "No data is entered" << endl;
	}
	else {
		string id;
		cout << "Enter Id of the student you want to show : ";
		cin >> id;

		for (int i = 0; i < totalnoOfstudents; i++)
		{
			if (id == student[i].id) {
				cout << "\nData of the Student : " << endl;
				cout << "Roll no : " << student[i].roll << endl;
				cout << "Name : " << student[i].name << endl;
				cout << "ID : " << student[i].id << endl;
				cout << "GPA : " << student[i].gpa << endl;
			}

		}
	}
}
void show_course() {
	cout << "{A} Pre-existing courses : " << endl;
	for (int i = 0; i < 3; ++i) {
		cout << "Course no." << i + 1 << " : " << endl << endl;
		cout << "Name : " << c1[i].name << endl;
		cout << "Id : " << c1[i].id << endl;
		cout << "Instructor name : " << c1[i].instructor << endl;
		cout << "Enrolled students : " << endl;
		for (int k = 0; k < 10; ++k) {
			if (c1[i].enrolled_students[k].name != " ") {
				cout << "Student " << k + 1 << endl;
				cout << "Name : " << c1[i].enrolled_students[k].name << endl;
				cout << "Grade : " << c1[i].enrolled_students[k].gpa << endl;
			}
		}
		cout << "-------------------------------" << endl;
	}

	cout << "{B} Courses you added recently" << endl;
	if (totalnoOfcourses == 0)
		cout << "[You haven't added any courses] " << endl;
	else {
		for (int i = 0; i < totalnoOfcourses; ++i) {
			cout << "Course no." << i + 1 << " : " << endl << endl;
			cout << "Name : " << c[i].name << endl;
			cout << "Id : " << c[i].id << endl;
			cout << "Instructor name : " << c[i].instructor << endl;
			cout << "Enrolled students : " << endl;
			for (int k = 0; k < 10; ++k) {
				if (c[i].enrolled_students[k].name != " ") {
					cout << "Student " << k + 1 << endl;
					cout << "Name : " << c[i].enrolled_students[k].name << endl;
					cout << "Grade : " << c[i].enrolled_students[k].gpa << endl;
				}
			}
			cout << "---------------------------------" << endl;

		}
	}


}

void search()
{
	bool found = false;
	string id;
	cout << "Enter the Id no of student you search for " << endl;
	cin >> id;
	cout << "This student has enrolled to these courses :" << endl;
	for (int i = 0; i < 3; ++i) {
		for (int k = 0; k < 10; ++k) {
			if (c1[i].enrolled_students[k].id == id) {
				found = true;
				cout << c1[i].name << endl;
			}
		}
	}
	for (int i = 0; i < 20; ++i) {
		for (int k = 0; k < 10; ++k) {
			if (c[i].enrolled_students[k].id == id) {
				found = true;
				cout << c[i].name << endl;
			}
		}
	}
	if (found == false)
		cout << "[This student has not enrolled to any courses]" << endl;

}

void search_course() {
	bool found = false;
	string id;
	cout << "Enter id of the course you search for : ";
	cin >> id;
	for (int i = 0; i < 3; ++i) {
		if (id == c1[i].id) {
			found = true;
			cout << "Name : " << c1[i].name << endl;
			cout << "Id : " << c1[i].id << endl;
			cout << "Instructor : " << c1[i].instructor << endl;
			cout << "Enrolled students : " << endl;
			for (int k = 0; k < 10; ++k) {
				if (c1[i].enrolled_students[k].name != " ") {
					cout << "Student " << k + 1 << endl;
					cout << "Name : " << c1[i].enrolled_students[k].name << endl;
					cout << "Grade : " << c1[i].enrolled_students[k].gpa << endl;
				}
			}
			break;
		}
	}

	if (found == false) {
		for (int i = 0; i < 20; ++i) {
			if (id == c[i].id) {
				found = true;
				cout << "Name : " << c[i].name << endl;
				cout << "Id : " << c[i].id << endl;
				cout << "Instructor : " << c[i].instructor << endl;
				cout << "Enrolled students : " << endl;
				for (int k = 0; k < 10; ++k) {
					if (c[i].enrolled_students[k].name != " ") {
						cout << "Student " << k + 1 << endl;
						cout << "Name : " << c[i].enrolled_students[k].name << endl;
						cout << "Grade : " << c[i].enrolled_students[k].gpa << endl;
					}
				}
				break;
			}
		}
	}
	if (found == false)
		cout << "[NOT FOUNDED]" << endl;
}
void update()
{
	if (totalnoOfstudents == 0)
	{
		cout << "[There is no data to update]" << endl;
	}
	else {
		string id;
		cout << "Enter the Id of the student you want to update" << endl;
		cin >> id;
		for (int i = 0; i < totalnoOfstudents; i++)
		{
			if (id == student[i].id)
			{
				cout << "\nPrevious data: " << endl << endl;
				cout << "Data of Student " << i + 1 << endl;
				cout << "Name : " << student[i].name << endl;
				cout << "student ID : " << student[i].id << endl;
				cout << "GPA : " << student[i].gpa << endl;
				cout << "\nEnter new data:" << endl << endl;
				cout << "Enter name : ";
				cin >> student[i].name;
				cout << "Enter ID : ";
				cin >> student[i].id;
				cout << "Enter student GPA : ";
				cin >> student[i].gpa;

			}
		}
	}
}
void edit_course() {
	bool found = false;
	string id;
	cout << "Enter id of the course you want to edit : ";
	cin >> id;
	for (int i = 0; i < 3; ++i) {
		if (id == c1[i].id) {
			found = true;
			cout << "\nPrevious Data of course " << i + 1 << ": " << endl << endl;
			cout << "Course Name : " << c1[i].name << endl;
			cout << "course ID : " << c1[i].id << endl;
			cout << "Instructor : " << c1[i].instructor << endl;
			cout << "\nEnter new data :" << endl << endl;
			cout << "Enter new course name : ";
			cin >> c1[i].name;
			cout << "Enter new ID : ";
			cin >> c1[i].id;
			cout << "Enter new instructor name : ";
			cin >> c1[i].instructor;
			cout << "\n[successfully updated]" << endl;
			break;
		}
	}

	if (found == false) {
		for (int i = 0; i < 20; ++i) {
			if (id == c[i].id) {
				found = true;
				cout << "\nPrevious Data of course " << i + 1 << ": " << endl << endl;
				cout << "Course Name : " << c[i].name << endl;
				cout << "course ID : " << c[i].id << endl;
				cout << "Instructor : " << c[i].instructor << endl;
				cout << "\nEnter new data :" << endl << endl;
				cout << "Enter the new course name : ";
				cin >> c[i].name;
				cout << "Enter new ID : ";
				cin >> c[i].id;
				cout << "Enter new instructor name : ";
				cin >> c[i].instructor;
				cout << "\n[successfully updated]" << endl;
				break;
			}
		}
	}
	if (found == false)
		cout << "[THERE IS NO MATCHING ID]" << endl;

}

void deleterecord()
{
	if (totalnoOfstudents == 0)
	{
		cout << "No data to delete" << endl;
	}
	else {
		int a;
		cout << "Press 1 to delete all students" << endl;
		cout << "Press 2 to delete specific student" << endl;
		cin >> a;
		if (a == 1)
		{
			totalnoOfstudents = 0;
			cout << "All record is deleted..!!" << endl;
		}
		else if (a == 2)
		{
			string id;
			cout << "Enter the Id of the student you want to delete: " << endl;
			cin >> id;
			for (int i = 0; i < totalnoOfstudents; i++)
			{
				if (id == student[i].id)
				{
					for (int j = i; j < totalnoOfstudents; j++)
					{
						student[j].roll = student[j + 1].roll;
						student[j].name = student[j + 1].name;
						student[j].id = student[j + 1].id;
						student[j].gpa = student[j + 1].gpa;
					}
					totalnoOfstudents--;
					cout << "Your required record is deleted" << endl;
				}
				break;
			}
		}


		else
		{
			cout << "[Invalid input]" << endl;
		}
	}
}
void delete_course() {
	if (totalnoOfcourses == 0)
	{
		cout << "You haven't added any courses" << endl;
	}
	else {
		int a;
		cout << "Press 1 to delete all courses" << endl;
		cout << "Press 2 to delete specific course" << endl;
		cin >> a;
		if (a == 1)
		{
			totalnoOfcourses = 0;
			cout << "\n[successfully deleted]" << endl;
		}
		else if (a == 2)
		{
			string id;
			cout << "Enter the id of the course you want to delete" << endl;
			cin >> id;
			for (int i = 0; i < totalnoOfcourses; i++)
			{
				if (id == c[i].id)
				{
					for (int j = i; j < totalnoOfcourses; j++)
					{
						c[j].roll = c[j + 1].roll;
						c[j].name = c[j + 1].name;
						c[j].id = c[j + 1].id;
						c[j].instructor = c[j + 1].instructor;
						for (int k = 0; k < 10; ++k) {
							c[j].enrolled_students[k] = c[j + 1].enrolled_students[k];
						}
					}
					totalnoOfcourses--;
					cout << "\n[successfully deleted]" << endl;
					break;
				}
			}
		}


		else
		{
			cout << "[Invalid input]";
		}
	}
}

int main()
{
	system("CLS");
	system("color F4");
	c1[0] = { "Electronics", "DR:Mai" , "124" };
	c1[0].enrolled_students[0] = { "Ahmed" , "2018" , 3.7 };
	c1[0].enrolled_students[1] = { "Mai", "2525", 2.6 };
	c1[0].enrolled_students[2] = { "Laila", "2019" , 3.7 };
	c1[1] = { "Programming", "DR:Sally", "150" };
	c1[1].enrolled_students[0] = { "Andro", "2000" , 3.2 };
	c1[1].enrolled_students[1] = { "Yasmine", "1700" , 3.7 };
	c1[1].enrolled_students[2] = { "seif" , "3030", 3.3 };
	c1[2] = { "Calculus II" , "DR:Mohamed", "125" };
	c1[2].enrolled_students[0] = { "Naira", "8888", 2.8 };
	c1[2].enrolled_students[1] = { "Adham" , "1000" , 3.5 };
	c1[2].enrolled_students[2] = { "Ali", "2000" , 3.2 };
	int value;
	cout << endl << endl;
	cout << "                                  # COURSE MANAGEMENT SYSTEM #\n";
	cout << "                        ------------------------------------------------\n\n";
	while (true)
	{
		cout << endl << endl;
		cout << "     - Press {1} to enroll to a specific course" << endl;
		cout << "     - Press {2} to display student data" << endl;
		cout << "     - Press {3} to search for a student" << endl;
		cout << "     - Press {4} to edit student data" << endl;
		cout << "     - Press {5} to delete student data" << endl;
		cout << "     - Press {6} to add extra course" << endl;
		cout << "     - Press {7} to display all courses" << endl;
		cout << "     - Press {8} to search for a course by Id " << endl;
		cout << "     - Press {9} to edit course " << endl;
		cout << "     - Press {10} to delete course you recently added " << endl;
		cout << "     - Press {0} to exit" << endl << endl;
		cout << "     --------------------------------------------------------\n\n";
		cin >> value;
		if (value == 0) {
			cout << "[Program ended]\n";
			exit(0);
			break;
		}
		else {
			switch (value)
			{
			case 1:
				enter();
				break;
			case 2:
				show();
				break;
			case 3:
				search();
				break;
			case 4:
				update();
				break;
			case 5:
				deleterecord();
				break;
			case 6:
				enter_course();
				break;
			case 7:
				show_course();
				break;
			case 8:
				search_course();
				break;
			case 9:
				edit_course();
				break;
			case 10:
				delete_course();
				break;
			default:
				cout << "Invalid input" << endl;
				break;
			}
		}
	}
}

