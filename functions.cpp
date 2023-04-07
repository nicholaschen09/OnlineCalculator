/******************************************/
/** Author: Daniel and Nicholas        	 **/
/** Course: ICS3U1-1                     **/
/** Date: Jan 18, 2023              		 **/
/** Final Summative Project        			 **/
/** File: functions.cpp                  **/
/** Functions                        		 **/
/******************************************/
#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;


// Function Prototypes
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


// Functions

// This is the main menu function that calls each sub menu according to input 
void menu(){
    clear();
    // Print options
    cout << "Trignometry Calculator" << endl;
    cout << "Main Menu:" << endl;
    cout << "1. SOHCAHTOA Calculator" << endl;
    cout << "2. Sine Law Calculator" << endl;
    cout << "3. Cosine Law Calculator" << endl;
    cout << "4. Triangle Area Calculator" <<  endl;
    cout << "5. Triangle Perimeter Calculator" <<  endl;
    cout << "6. Identify Triangle by Side Length" <<  endl;
    cout << "7. Identify Triangle by Angle" <<  endl;
    cout << "8. Trig Ratio Chart" << endl;
    cout << "9. Trig Ratio Practice" << endl;
    cout << "10. Quit" << endl;
    cout << "Option(1~10): ";
    int option;
    cin >> option;
    // Calls the menu according to user input
    switch(option){
        case 1:
            SOHCAHTOA_menu();
            break;
        case 2:
            sine_law_menu();
            break;
        case 3:
            cosine_law_menu();
            break;
        case 4:
            area_menu();
            break;
        case 5:
            perimeter_menu();
            break;
        case 6:
            identify_by_side_menu();
            break;
        case 7:
            identify_by_angle_menu();
            break;
        case 8:
            print_trig_ratio();
            break;
        case 9:
            trig_ratio_check();
            break;
        case 10:
            cout << "Bye!" << endl;
            exit(0);
        default: // If input is not one of the option
            cout << "Input Error" << endl << endl;
            cin.ignore(1, '\n');
            next();
    }
    menu();
}//..end of menu()

// This function takes base and height from the user and output the area
void area_menu(){
    clear();
    cout << "Triangle Area" << endl;
    cout << "Enter the base and height length:" << endl;
    double base, height;
    cout << "Base: ";
    cin >> base;
    cout << "Height: ";
    cin >> height;
    double triangleArea = area(base, height);
    // Check if the input is invalid
    if (triangleArea == -1){
        cout << "Input Error" << endl;
    }
    else{
        cout << "The area of triangle is " << triangleArea << endl << endl;
    }
    cin.ignore(1, '\n');
    next();
    menu();
}//..end of area_menu()
// This function calculates and returns triangle's area
double area(double base, double height) {
    double triangleArea = (base * height)/2;
    // Check if triangle area is in the valid range
    if (triangleArea <= 0)
        return -1;
    return triangleArea;
}//..end of area()
// This function takes in 3 side and output the perimeter
void perimeter_menu(){
    clear();
    cout << "Triangle Perimeter" << endl;
    cout << "Enter the side lengths:" << endl;
    double side1, side2, side3;
    cout << "Side 1: ";
    cin >> side1;
    cout << "Side 2: ";
    cin >> side2;
    cout << "Side 3: ";
    cin >> side3;
    double trianglePerimeter = perimeter(side1, side2, side3);
    // Check if input is a triangle
    if (isTriangle(side1,side2, side3, "side")){
        cout << "The perimeter of the triangle is " << trianglePerimeter << endl << endl;
        cin.ignore(1, '\n');
        next();
    }
    menu();
}//..end of perimeter_menu()
// This function calculates and returns triangle's perimeter
double perimeter(double side1, double side2, double side3){
    double perimeter = side1 + side2 + side3;
    return perimeter;
}//..end of perimeter()
// This function takes in 3 angles and output the type of triangle
void identify_by_angle_menu(){
    clear();
    cout << "Identify Triangle by Angle" << endl;
    double angle1, angle2, angle3;
    cout << "Angle 1: ";
    cin >> angle1;
    cout << "Angle 2: ";
    cin >> angle2;
    cout << "Angle 3: ";
    cin >> angle3;
    // Check if it is a triangle
    if (isTriangle(angle1, angle2, angle3, "angle")){
        cout << "It is a "<< identify_by_angle(angle1, angle2, angle3) << " triangle" << endl << endl;
        next();
    }
    cin.ignore(1, '\n');
    menu();
}//..end of identify_by_angle_menu()
// This function takes in 3 angles and return the type of triangle
string identify_by_angle(double angle1, double angle2, double angle3){
    if (angle1==90 or angle2==90 or angle3==90)
        return "right";
    else if (max(angle1, max(angle2, angle3))>90)
        return "obtuse";
    else
        return "acute";
}//..end of identify_by_angle()
// This function takes in 3 sides and output the type of triangle
void identify_by_side_menu(){
    clear();
    cout << "Identify Triangle by Side" << endl;
    double side1, side2, side3;
    cout << "Side 1: ";
    cin >> side1;
    cout << "Side 2: ";
    cin >> side2;
    cout << "Side 3: ";
    cin >> side3;
    // Check if it is a triangle
    if (isTriangle(side1, side2, side3, "side")){
        cout << "It is a "<< identify_by_side(side1, side2, side3) << " triangle" << endl << endl;
        cin.ignore(1, '\n');
        next();
    }
    menu();
}//..end of identify_by_side_menu()
// This function takes in 3 sides and return the type of triangle
string identify_by_side(double side1, double side2, double side3){
    if (side1 == side2 and side2 == side3)
        return "equilateral";
    else if (side1 == side2 or side2 == side3 or side3 == side1)
        return "isosceles";
    else
        return "scalene";
}//..end of identify_by_side()

// This function prints out the menu of SOHCAHTOA
void SOHCAHTOA_menu(){
    clear();
    cout << "SOHCAHTOA Calculator" << endl;
    cout << "1. Sine" << endl;
    cout << "2. Cosine" << endl;
    cout << "3. Tangent" << endl;
    cout << "4. Back to main menu" << endl;
    cout << "Option(1~4): ";
    int option;
    cin >> option;
    double angle=-1, opposite=-1, hypotenuse=-1, adjacent=-1, ans;
    string unknown;
    // Check which function it will call
    switch(option){
        case 1:
            unknown = SOH_input(angle, opposite, hypotenuse);
            ans = SOH(opposite, hypotenuse, angle);
            break;

        case 2:
            unknown = CAH_input(angle, adjacent, hypotenuse);
            ans = CAH(adjacent, hypotenuse, angle);
            break;

        case 3:
            unknown = TOA_input(angle, opposite, adjacent);
            ans = TOA(opposite, adjacent, angle);
            break;

        case 4:
            menu();

        default:
            SOHCAHTOA_menu();
    }
    // Check if answer is valid
    if (ans == -1){
        cout << "Input Data Error" << endl;
        next();
        SOHCAHTOA_menu();
    }
    else
        cout << "The unknown " << unknown << " is " << ans << endl << endl;
    next();
    menu();
}//..end of SOHCAHTOA_menu()
// This function takes in opposite, hypotenuse side, or angle and returns the unknown
double SOH(double opposite=-1, double hypotenuse=-1, double angle=-1){
    // Check only two value are given
    if (opposite == -1 and hypotenuse == -1 and angle == -1) // There cannot be three value given
        return -1;
    if (opposite != -1 and hypotenuse != -1 and angle != -1) // There cannot be no unknown
        return -1;
    // By subtracting the max and min from the total, it finds the middle value. If the middle value == -1, there are 2 unknowns
    if (angle + opposite + hypotenuse - min(opposite, min(hypotenuse, angle)) - max(opposite, max(hypotenuse, angle)) == -1) // There cannot be 2 unknown
        return -1;
    // Check and return the apporpriate unknown
    else if (opposite == -1)
        return (double)r1((double)sind(angle) * (double)hypotenuse);
    else if (hypotenuse == -1) {
        return (double)r1((double) opposite / sind(angle));
    }
    else
        return (double)r1(asin((double)opposite/(double)hypotenuse)*180.0/M_PI);
}//..end of SOH()
// This function takes in adjacent, hypotenuse side, or angle and returns the unknown
double CAH(double adjacent=-1, double hypotenuse=-1, double angle=-1){
    // Check only two value are given
    if (adjacent == -1 and hypotenuse == -1 and angle == -1) // There cannot be three value given
        return -1;
    if (adjacent != -1 and hypotenuse != -1 and angle != -1) // There cannot be no unknown
        return -1;
    if (angle + adjacent + hypotenuse - min(adjacent, min(hypotenuse, angle)) - max(adjacent, max(hypotenuse, angle)) == -1) // There cannot be 2 unknown
        return -1;
    // Check and return the apporpriate unknown
    else if (adjacent == -1)
        return (double)r1((double)cosd(angle) * (double)hypotenuse);
    else if (hypotenuse == -1)
        return (double)r1((double)adjacent / cosd(angle));
    else
        return (double)r1(acos((double)adjacent/(double)hypotenuse)*180.0/M_PI);
}//..end of CAH()
// This function takes in opposite, adjacent side, or angle and returns the unknown
double TOA(double opposite=-1, double adjacent=-1, double angle=-1){
      // Check only two value are given
    if (opposite == -1 and adjacent == -1 and angle == -1) // There cannot be three value given
        return -1;
    if (opposite != -1 and adjacent != -1 and angle != -1) // There cannot be no unknown
        return -1;
    if (angle + adjacent + opposite - min(adjacent, min(opposite, angle)) - max(adjacent, max(opposite, angle)) == -1) // There cannot be 2 unknown
        return -1;
    // Check and return the apporpriate unknown
    else if (opposite == -1)
        return (double)r1((double)tan(angle) * (double)adjacent);
    else if (adjacent == -1)
        return (double)r1((double)opposite / (double)tan(angle));
    else
        return (double)r1(atan((double)opposite/(double)adjacent)*180.0/M_PI);
}//..end of TOA()

// These three functions take any of the two values, update, and return the unknown
string SOH_input(double &angle, double &opposite, double &hypotenuse){
    clear();
    string tmpAngle, tmpOpp, tmpHypo;
    cout << "SOH" << endl;
    cout << "Skip the Unknown" << endl;
    cout << "Angle: ";
    cin.ignore(1,'\n');
    getline(cin, tmpAngle);
    cout << "Opposite side: ";
    getline(cin, tmpOpp);
    cout << "Hypotenuse side: ";
    getline(cin, tmpHypo);
    // Check which is unknown
    if (!tmpAngle.empty())
        angle = stod(tmpAngle);
    if (!tmpOpp.empty())
        opposite = stod(tmpOpp);
    if (!tmpHypo.empty())
        hypotenuse = stod(tmpHypo);
    // Check if the answer is valid
    if (angle==-1)
        return "angle";
    if (opposite==-1)
        return "opposite";
    else
        return "hypotenuse";
}//..end SOH_input()
string CAH_input(double &angle, double &adjacent, double &hypotenuse){
    clear();
    string tmpAngle, tmpAdj, tmpHypo;
    cout << "CAH" << endl;
    cout << "Skip the Unknown" << endl;
    cout << "Angle: ";
    cin.ignore(1,'\n');
    getline(cin, tmpAngle);
    cout << "Adjacent side: ";
    getline(cin, tmpAdj);
    cout << "Hypotenuse side: ";
    getline(cin, tmpHypo);
    // Check which is unknown
    if (!tmpAngle.empty())
        angle = stod(tmpAngle);
    if (!tmpAdj.empty())
        adjacent = stod(tmpAdj);
    if (!tmpHypo.empty())
        hypotenuse = stod(tmpHypo);
    // Check if answer is valid
    if (angle==-1)
        return "angle";
    if (adjacent==-1)
        return "adjacent";
    else
        return "hypotenuse";
}//..end CAH_input()
string TOA_input(double &angle, double &opposite, double &adjacent){
    clear();
    string tmpAngle, tmpOpp, tmpAdj;
    cout << "TOA" << endl;
    cout << "Skip the Unknown" << endl;
    cout << "Angle: ";
    cin.ignore(1,'\n');
    getline(cin, tmpAngle);
    cout << "Opposite side: ";
    getline(cin, tmpOpp);
    cout << "Adjacent side: ";
    getline(cin, tmpAdj);
    // Check which is unknown
    if (!tmpAngle.empty())
        angle = stod(tmpAngle);
    if (!tmpOpp.empty())
        opposite = stod(tmpOpp);
    if (!tmpAdj.empty())
        adjacent = stod(tmpAdj);
    if (angle==-1)
        return "angle";
    // Checkif answer is valid
    if (opposite==-1)
        return "opposite";
    else
        return "adjacent";
}//..end TOA_input()

// This function takes in 3 values return the unknown by using cosine law
double cosine_law(double side1, double side2, double unknownGiven, const string& solveFor){
    double ans;
    // Check if sides are valid
    if (side1 <= 0 or side2 <= 0 or unknownGiven <= 0)
        return -1;
    // Use side formula to solve the side
    if (solveFor == "side"){
        ans = sqrt(side1*side1 + side2*side2 - 2*side1*side2*cosd(unknownGiven));
    }
    // Use angle formula to solve the angle
    else
        ans = acos((side1*side1+side2*side2-unknownGiven*unknownGiven)/(2.0*side1*side2))*180.0/M_PI;
    return ans;

}//..end of consine_law()
// This function takes in 3 values and use cosine law to determine the unknown
void cosine_law_menu(){
    clear();
    cout << "Cosine Law Calculator" << endl;
    cout << "Which are you trying to find? Angle or Side (a/s): ";
    char input;
    double ans, side1, side2, unknownGiven;
    cin >> input;
    if (input != 'a' and input != 's'){
        cout << "That is not a valid option!"<< endl;
        cin.ignore(1, '\n');
        next();
        menu();
    }
    cout << "Enter Side 1: ";
    cin >> side1;
    cout << "Enter Side 2: ";
    cin >> side2;
    if (input == 'a'){
        cout << "Enter Opposite Side: ";
        cin >> unknownGiven;
        ans = cosine_law(side1, side2, unknownGiven, "angle");
    }

    else {
        cout << "Enter Opposite Angle: ";
        cin >> unknownGiven;
        ans = cosine_law(side1, side2, unknownGiven, "side");
    }

    if (ans==-1){
        cout << "Invalid Data!" << endl;
    }
    else
        cout << "The unknown is " <<ans << endl;
    cin.ignore(1, '\n');
    next();
    menu();
}//..end of cosine_law_menu()
// This function takes in 3 values and return the unknown by using sine law
double sine_law(double knownAngle, double knownSide, double unknownGiven, const string& solveFor){
    // Check if input is valid
    if (knownAngle <= 0 or knownSide <= 0 or unknownGiven <= 0)
        return -1;
    double ans;
    // Check which is finding (side/angle)
    if (solveFor == "side") {
        ans = sind(unknownGiven) / (sind(knownAngle) / knownSide);
    }

    else {
        ans = asin(unknownGiven * (sind(knownAngle) / knownSide)) * 180.0 / M_PI;
    }
    return ans;
}//..end of sine_law()
// This function takes in 3 values and use sine law to determine the unknown
void sine_law_menu(){
    clear();
    cout << "Sine Law Calculator" << endl;
    cout << "Which are you trying to find? Angle or Side (a/s): ";
    char input;
    double ans, knownAngle, knownSide, unknownGiven;
    cin >> input;
    if (input != 'a' and input != 's'){
        cout << "That is not a valid option!"<< endl;
        cin.ignore(1, '\n');
        next();
        menu();
    }
    cout << "Enter Known Pair Angle: ";
    cin >> knownAngle;
    cout << "Enter Known Pair Side: ";
    cin >> knownSide;
    if (input == 'a'){
        cout << "Enter Unknown Pair Side: ";
        cin >> unknownGiven;
        ans = sine_law(knownAngle, knownSide, unknownGiven, "angle");
    }

    else {
        cout << "Enter Unknown Pair Angle: ";
        cin >> unknownGiven;
        ans = sine_law(knownAngle, knownSide, unknownGiven, "side");
    }

    if (ans==-1){
        cout << "Invalid Data!" << endl;
    }
    else
        cout << "The unknown is " << ans << endl;
    cin.ignore(1, '\n');
    next();
    menu();
}//..end of sine_law_menu()

// This function takes a vector with type Question and print out each question
void print_question(vector<Question> set){
    clear();
    string question = set.front().question;
    string ans = set.front().ans;
    set.push_back(set.front());
    set.erase(set.begin());
    string input;
    cout << question;
    cin >> input;
    // Check if input match with the correct answer
    if (input == ans)
        cout << "Correct!" << endl;
    else{
        cout << "Wrong! The correct answer is ";
        if ((int)question[question.size()-1] == -102)
          cout << "√";
        cout << ans << endl;
      }
    // Continue ask user to input an option until a valid one
    while (input != "y" && input != "n"){
        cout << "Continue? (y/n): ";
        cin >> input;
        if (input == "n")
            menu();
        else if (input == "y")
            print_question(set);
        else
            cout << "That is not an option!" << endl;
    }
}//..end of print_question
// This function reads the input file and convert the question set into a vector
void trig_ratio_check(){
    cout << "Trig Ratio practice" << endl;
    string inputFile = "QuestionSet.txt";
    ifstream file("QuestionSet.txt");
    cout << "d1" << endl;
    string line;
    vector<Question> set;
    // Read file
    while (getline(file, line)) {
        cout << line << endl;
        if (line == "\n")
            continue;
        // Split the question and the answer
        string question = line.substr(0, line.find(','));
        string ans = line.substr(line.find(',')+1, line.length());
        Question q;
        q.question = question;
        q.ans = ans;
        set.push_back(q);
    }
    file.close();
    // Random sort the questions
    auto rng = default_random_engine{};
    shuffle(begin(set), end(set), rng);
    print_question(set);
}//..end of trig_ratio_check()
// THis function prints out a chart of trig ratio stored in a 2-D array
void print_trig_ratio(){
    clear();
    const int row = 5, col = 6;
    string ratio[row][col] = {
            {"Angle", "0", " 30 ", " 45 ", " 60 ", "90 "},
            {"Ratio", "0", " π/6", " π/4", " π/3", "π/2"},
            {" sin ", "0", " 1/2", "1/√2", "√3/2", " 1 "},
            {" cos ", "1", "√3/2", "1/√2", "1/2 ", " 0 "},
            {" tan ", "0", "1/√3", " 1  ", " √3 ", "UND"}};
    cout << "--------------------------------------------------" << endl;
    for (auto & r : ratio){ // for each row array in ratio
        for (auto & c : r){  // for each column value in row
            cout << c << "  |  ";
        }
        cout << endl;
        cout << "-------------------------------------------------" << endl;
    }
    cin.ignore(1, '\n');
    next();
    menu();
}//..end of print_trig_ratio

// This function takes in 3 sides or 3 angles and chech if it form an triangle
bool isTriangle(const double a, const double b, const double c, const string& type){
    bool valid = true;
    // Check which type it is verifying
    if (type=="side"){
        if ((a+b)<=c)
            valid = false;
        if ((a+c)<=b)
            valid = false;
        if ((b+c)<=a)
            valid = false;
    }
    else{
        if (a+b+c==180 and a>0 and b>0 and c>0)
            ;
        else
            valid = false;
    }
    if (valid)
        return true;
    cout << "It is not a triangle" << endl;
    cin.ignore(1, '\n');
    next();
    return false;
}//..end of isTriangle()
// This function clears the console
void clear(){
    system("clear");
}//..end of clear()
// This function wait for user to continue
void next(){
    cout << "Press 'Enter' key to continue...";
    int c = getchar();
}//..end of next()
// This function round to the whole number
double r1(double n){
    return round(n);
}//..end of r1()
// This function convert degree to radian
double d2r(double d) {
    return (d / 180.0) * ((double) M_PI);
}//..end of d2r
// This function calculates the sin value in degrees
double sind(double x) {
    // Check if it is infinte
    if (!isfinite(x)) {
        return sin(x);
    }
    // Check if it is negative
    if (x < 0.0) {
        return -sind(-x);
    }
    // Convert the degree into the range of -45 to 45 for better precision
    int quo;
    double x90 = remquo(fabs(x), 90.0, &quo);
    switch (quo % 4) {
        case 0:
            // Use * 1.0 to avoid -0.0
            return sin(d2r(x90)* 1.0);
        case 1:
            return cos(d2r(x90));
        case 2:
            return sin(d2r(-x90) * 1.0);
        case 3:
            return -cos(d2r(x90));
    }
    return 0.0;
}//..end of sind()
// This function calculates the cos value in degrees
double cosd(double x) {
    if (!isfinite(x)) {
        return cos(x);
    }
    if (x < 0.0) {
        return cosd(x);
    }
    int quo;
    double x90 = remquo(fabs(x), 90.0, &quo);
    switch (quo % 4) {
        case 0:
            //Use * 1.0 to avoid -0.0
            return cos(d2r(x90));
        case 1:
            return -sin(d2r(x90)* 1.0);
        case 2:
            return -cos(d2r(x90) );
        case 3:
            return sin(d2r(x90)* 1.0);
    }
    return 0.0;
}//..end of cosd()
// This function calcualtes the tan value in degrees
double tand(double x) {
    if (!isfinite(x)) {
        return tan(x);
    }
    if (x < 0.0) {
        return -tand(-x);
    }
    int quo;
    double x90 = remquo(fabs(x), 90.0, &quo);
    return tan(d2r(x90)*1.0);
}//..end of tand()