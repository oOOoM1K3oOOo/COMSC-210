/*******************************************************************
Problem: Assignment 01N Part B - Cylinder Class
Question: Write a program that will record information about
          employees and will compute their paychecks. Each employee
          must be represented by a struct containing the last name,
          hours worked each day of the week, the hourly rate, and
          the pay for the week.

Name: Mykhaylo Ignatyev
ID: 1718264
Date: 02/02/2019

Status: 100% Complete
*******************************************************************/
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

const int WORK_DAYS = 5;
const int NUM_WORKERS = 4;
const int OVERPAY_MIN_HOURS = 40;
const double OVERPAY_RATE = 0.5;

struct Employee
{
  string lastName;
  int hoursWorked[WORK_DAYS];
  double hourlyRate;
  double weekPay;
};

// Assuming that the user entered for 5 days, so we skip user input
// validation 

void initialize(Employee workers[], const int &size)
{
  for (int i = 0; i < size; i++)
  {
    string sline = "";
    cout
      << "Please enter details for Employee " << (i + 1) << " of "
      << size << ":" << endl;

    cout << "++Last Name: ";
    getline(cin, workers[i].lastName);

    cout
      << "++Hours worked in weekdays, separated by a space (0-24): ";

    getline(cin, sline);
    stringstream ss(sline);
    int temp = 0;
    int day = 0;

    while (ss >> temp && day < WORK_DAYS)
    {
      workers[i].hoursWorked[day++] = temp;
      temp = 0;
    }

    cout
      << "++Hourly rate: ";
    getline(cin, sline);
    stringstream(sline) >> workers[i].hourlyRate;
  }
}

void compute(Employee &worker, const int &workDays)
{
  int hoursTotal = 0;

  for (int i = 0; i < workDays; i++)
  {
    hoursTotal += worker.hoursWorked[i];
  }

  worker.weekPay = worker.hourlyRate * (hoursTotal +
    (hoursTotal > OVERPAY_MIN_HOURS) *
    (hoursTotal - OVERPAY_MIN_HOURS) *
    OVERPAY_RATE);
}

void result(const Employee worker)
{
  int totalHours = 0;

  for (int hoursPerDay : worker.hoursWorked)
    totalHours += hoursPerDay;

  cout
    << "Last Name: " << worker.lastName << endl
    << "Total hours worked: " << totalHours << endl
    << "Hourly Rate: $" << worker.hourlyRate << endl
    << "Pay for the week: $" << worker.weekPay << endl
    << endl;

}

int main()
{
  Employee workers[NUM_WORKERS];

  initialize(workers, NUM_WORKERS);

  cout
    << endl
    << "Computing a week pay for each employee..."
    << endl;

  for (Employee worker : workers)
  {
    compute(worker, WORK_DAYS);

    result(worker);
  }
  return 0;
}