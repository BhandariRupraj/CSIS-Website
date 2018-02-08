//
/// \file hw2.cpp
/// \author Nathan Eloe
/// \brief A functionized version of assignment 1
//

#include <iostream>
#include <string>
using namespace std;

//
/// \brief greets the user by name
/// \pre None
/// \post outputs a greeting message to the screen
//
void greet(const string & user);

//
/// \brief prints a signoff message
/// \pre None
/// \post outputs a signoff message to the screen
//
void signoff();

//
/// \brief gets an x, y, and z point from the user and sets the coordinates
/// \pre None
/// \post x_coord, y_coord, and z_coordinate contain the points input by the user
//
void get_point(float & x_coord, float & y_coord, float & z_coord);

//
/// \brief performs a single iteration of the point transformation
/// \pre None
/// \post x_coord, y_coord, and z_coord updated according to the *dot functions
//
void step_point(const float key, float & x_coord, float & y_coord, float & z_coord);

//
/// \brief tracks the target for a number of iterations
/// \pre iterations > 0
/// \post Outputs the final location of the target to the screen
//
void track_point(const int iterations, const float key,
		 float x_coord, float y_coord, float z_coord);

//
/// \brief prints a prettily formatted point
/// \pre None
/// \post outputs a formatted point to the screen
//
void print_point(const float x_coord, const float y_coord, const float z_coord);

//change functions
/// \brief calculates the change in the specified coordinate
/// \pre None
/// \post returns the change as specified by the equation for the coordinate
//
float x_dot(const float x_coord, const float y_coord);
float y_dot(const float x_coord, const float y_coord, const float z_coord);
float z_dot(const float x_coord, const float y_coord, const float z_coord);

//Some other helper functions

//
/// \brief Prompts the user for a positive integer until one is input
/// \pre None
/// \post Prompts the user
/// \post Gets input from cin
/// \post returns the user input
//
int get_positive();

//
/// \brief Prompts the user to input a number in a range (NON INCLUSIVE)
/// \pre low_bound < hi_bound
/// \post Prompts the user
/// \post Gets input from cin
/// \post returns the user input
//
float get_in_range(const float lo_bound, const float hi_bound);

//CONSTANTS
const int SIGMA = 10;
const int RHO = 28;
const float BETA = 8.0 / 3;

int main()
{
  bool finished = false;
  string user;
  char choice;
  
  float x_coord = 0.0;
  float y_coord = 0.0;
  float z_coord = 0.0;
  float key = 0.1;
  
  int iterations;
  
  cout << "--- Enter username to continue: ";
  cin >> user;
  
  greet(user);
  
  while(!finished)
  {
    cout << "Which action would you like to take?" << endl
         << "------------------------------------" << endl
	 << "1) Enter a new point" << endl
	 << "2) Change the security key" << endl
	 << "3) Track the bad guy" << endl
	 << "4) View current start point and key" << endl
	 << "5) Sign off" << endl
	 << "  > ";
    cin >> choice;
    
    switch (choice)
    {
      case '1': case 'E': case 'e':
	get_point(x_coord, y_coord, z_coord);
	break;
      case '2': case 'C': case 'c':
	cout << "Enter the security key for the target:" << endl;
	key = get_in_range(0.0, 1.0);
	break;
      case '3': case 'T': case 't':
	cout << "How many iterations would you like?" << endl;
	iterations = get_positive();
	track_point(iterations, key, x_coord, y_coord, z_coord);
	break;
      case '4': case 'V': case 'v':
	cout << "Target's key: " << key << endl;
	cout << "Target's starting location: ";
	print_point(x_coord, y_coord, z_coord);
	cout << endl;
	break;
      case '5': case 'S': case 's':
	finished = true;
      default:
	cout << "Invalid choice" << endl;
    }
  }
  signoff();
  return 0;
}

void greet(const string& user)
{
  cout << "Greetings " << user << " and welcome to the beta version of the\n"
       << "\t bad guy locator" << endl;
  return;
}

void get_point(float & x_coord, float & y_coord, float & z_coord)
{
  cout << "Please provide the following initial data;" << endl;
  cout << "  x coordinate: ";
  cin >> x_coord;
  cout << "  y coordinate: ";
  cin >> y_coord;
  cout << "  z coordinate: ";
  cin >> z_coord;
  return;
}

void step_point(const float key, float & x_coord, float & y_coord, float & z_coord)
{
  float new_x, new_y, new_z;
  new_x = x_coord + key * x_dot(x_coord, y_coord);
  new_y = y_coord + key * y_dot(x_coord, y_coord, z_coord);
  new_z = z_coord + key * z_dot(x_coord, y_coord, z_coord);
  
  x_coord = new_x;
  y_coord = new_y;
  z_coord = new_z;
  return;
}

void track_point(const int iterations, const float key,
		 float x_coord, float y_coord, float z_coord)
{
  for (int iter = 0; iter < iterations; iter++)
	  step_point(key, x_coord, y_coord, z_coord);
  cout << "Your target is at ";
  print_point(x_coord, y_coord, z_coord);
  cout << endl;
  return;
}

void print_point(const float x_coord, const float y_coord, const float z_coord)
{
  cout << "(" << x_coord << ", " << y_coord << ", " << z_coord << ")";
}

float x_dot(const float x_coord, const float y_coord)
{
  return SIGMA * (y_coord - x_coord);
}

float y_dot(const float x_coord, const float y_coord, const float z_coord)
{
  return x_coord * (RHO - z_coord) - y_coord;
}

float z_dot(const float x_coord, const float y_coord, const float z_coord)
{
  return x_coord * y_coord - BETA * z_coord;
}

int get_positive()
{
  int input = -1;
  while (input <= 0)
  {
    cout << "Please input a positive integer: ";
    cin >> input;
    if (input <= 0)
      cout << "Invalid input, please try again." << endl;
  }
  return input;
}

float get_in_range(const float lo_bound, const float hi_bound)
{
  float input = lo_bound;
  while (input <= lo_bound || input >= hi_bound)
  {
    cout << "Please input a number between " << lo_bound << " and "
         << hi_bound << " (non-inclusive): ";
    cin >> input;
    if (input <= lo_bound || input >= hi_bound)
      cout << "Invalid input, please try again." << endl;
  }
  return input;
}

void signoff()
{
  cout << "Good bye!" << endl;
  return;
}