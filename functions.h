/******************************************/
/** Author: Daniel and Nicholas        	 **/
/** Course: ICS3U1-1                     **/
/** Date: Jan 18, 2023              		 **/
/** Final Summative Project        			 **/
/** File: functions.h                    **/
/** Function Prototypes              		 **/
/******************************************/
#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;
void menu();

double area(double, double);
void area_menu();

double perimeter (double, double, double);
void perimeter_menu();

string identify_by_angle(double, double, double);
void identify_by_angle_menu();
string identify_by_side(double, double, double);
void identify_by_side_menu();

double SOH(double, double, double);
double CAH(double, double, double);
double TOA(double, double, double);
string SOH_input(double&, double&, double&);
string CAH_input(double&, double&, double&);
string TOA_input(double&, double&, double&);
void SOHCAHTOA_menu();

bool isTriangle(double, double, double, const string&);
void clear();
void next();

double sine_law(double, double, double, const string&);
void sine_law_menu();
double cosine_law(double, double, double, const string&);
void cosine_law_menu();

struct Question{
    string question;
    string ans;
};
void print_trig_ratio();
void trig_ratio_check();
void print_question(vector<Question>);

double r1(double);
double d2r(double);
double sind(double);
double cosd(double);
double tand(double);