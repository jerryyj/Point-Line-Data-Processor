#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <iomanip>
#include <utility>
#include <cmath>
#include <algorithm>
#include <fstream>
#include "Point2D.h"
#include "Point3D.h"
#include "Line2D.h"
#include "Line3D.h"
#include "MyTemplates.h"
using namespace std;

// Declare prototype functions
void displayMainMenu();
void displayFilterCriteriaSubMenu();
void inputFilteringCriteria();
void displaySortingCriteriaSubMenu();
void inputSortingCriteria();
void displaySortingOrderSubMenu();
void inputSortingOrder();
void storeData();
void readData();
void viewData();
void sortData();
void generateCleanFile();
string dataToString();
vector<int> getIntFromString (string);

// Declare global variables
vector <Point2D> pt2DList;
vector <Point3D> pt3DList;
vector <Line2D> line2DList;
vector <Line3D> line3DList;
string filterCriteria = "Point2D";
string sortingCriteria = "x-ordinate";
string sortingOrder = "ASC";

int main()
{
    // Declare option variable to store user input for menu option
    int option = -1;

    do
    {
        displayMainMenu();

        cout << "Please enter your choice: ";
        cin >> option;

        cin.clear(); // reset failbit
		cin.ignore(10000, '\n'); // clear input buffer

        // swtich-case statement to branch out options
        switch (option)
        {
            case 1:
			{
                readData();
                cout << endl << "Going back to main menu ..." << endl;
			} 
				break;
			case 2:
			{
				inputFilteringCriteria();
                cout << "Filter criteria successfully set to '" << filterCriteria << "'!" << endl;
			}
				break;
			case 3:
			{
                inputSortingCriteria();
				cout << "Filter criteria successfully set to '" << sortingCriteria << "'!" << endl;
			}
				break;
			case 4:
			{
                inputSortingOrder();
                cout << "Sorting order successfully set to '" << sortingOrder << "'!" << endl;
			}
				break;
			case 5:
			{
                viewData();
                cout << endl << "Press <enter> to go back to main menu ...";
                cin.ignore(10000, '\n'); // Ignore up to 10000 characters until user presses enter
			}
				break;
            case 6:
            {
                storeData();
                cout << endl << "Going back to main menu ..." << endl;
            }
                break;
            case 7:
            {
                generateCleanFile();
                cout << endl << "Going back to main menu ..." << endl;
            }
                break;
            case 8:
            {
                cout << endl << "Exiting program..." << endl << endl;
            }
                break;
            default:
            {
                cout << endl << "Please enter a valid option (1 - 8)" << endl;
            }
                break;
        }
    }while (option != 8);

    return 0;
}

// Function to display main menu
void displayMainMenu()
{
    // DIsplay header
	cout << endl;
	cout << "Welcome to Point/Line Data Processing Program!" << endl;

    // Display menu options
	cout << endl;
    cout << "1)" << '\t' << "Read in data" << endl;
	cout << "2)" << '\t' << "Specify filtering criteria (current : " << filterCriteria << ")" << endl;
	cout << "3)" << '\t' << "Specify sorting criteria (current : " << sortingCriteria << ")" << endl;
	cout << "4)" << '\t' << "Specify sorting order (current : " << sortingOrder << ")" << endl;
    cout << "5)" << '\t' << "View data" << endl;
    cout << "6)" << '\t' << "Store data" << endl;
    cout << "7)" << '\t' << "Generate cleaned data file" << endl;
    cout << "8)" << '\t' << "Quit" << endl;
    cout << endl;
}

// Function to read text file data
void readData()
{
    // Declare c-string variable with a size of 201 to store file name
	char fileName[201];

    // Get user input for file name up to length of 200
    cout << endl;
	cout << "Please enter filename: ";	
	cin.getline(fileName, 201);
	cout << endl;

    fstream inputFile (fileName, fstream::in);

    if (!inputFile.is_open())
    {
        cout << "Failed to open data file. Returning to main menu ..." << endl;
        return;
    }
	string aLine;
    int noOfRecordsRead = 0;
    int noOfRecordsInitial = pt2DList.size() + pt3DList.size() + line2DList.size() + line3DList.size();

    // Read each line of info
    while (getline (inputFile, aLine))
    {
        // Ignore empty lines
		if (aLine.size() == 0)
			continue;

        // If line describes Point2D info
        if (aLine.find("Point2D") != string::npos)
        {
            string dataStr = aLine.substr(string("Point2D").length(), string::npos);

            // Get list of points data from string
            vector <int> pointsData = getIntFromString(dataStr);

            // Initialize Point2D object and add it to global list
            Point2D p1(pointsData[0], pointsData[1]);
            pt2DList.push_back(p1);
            noOfRecordsRead++; // Increment no. of records
        }
        // If line describes Point3D info
        else if (aLine.find("Point3D") != string::npos)
        {
            string dataStr = aLine.substr(string("Point3D").length(), string::npos);

            // Get list of points data from string
            vector <int> pointsData = getIntFromString(dataStr);

            // Initialize Point3D object and add it to global list
            Point3D p1(pointsData[0], pointsData[1], pointsData[2]);
            pt3DList.push_back(p1);
            noOfRecordsRead++; // Increment no. of records
        }
        // If line describes Line2D info
        else if (aLine.find("Line2D") != string::npos)
        {
            string dataStr = aLine.substr(string("Line2D").length(), string::npos);

            // Get list of points data from string
            vector <int> pointsData = getIntFromString(dataStr);

            // Initialize Line2D object and add it to global list
            Point2D p1(pointsData[0], pointsData[1]);
            Point2D p2(pointsData[2], pointsData[3]);
            Line2D l1(p1, p2);
            line2DList.push_back(l1);
            noOfRecordsRead++; // Increment no. of records
        }
        // If line describes Line3D info
        else if (aLine.find("Line3D") != string::npos)
        {
            string dataStr = aLine.substr(string("Line3D").length(), string::npos);

            // Get list of points data from string
            vector <int> pointsData = getIntFromString(dataStr);

            // Initialize Line3D object and add it to global list
            Point3D p1(pointsData[0], pointsData[1], pointsData[2]);
            Point3D p2(pointsData[3], pointsData[4], pointsData[5]);
            Line3D l1(p1, p2);
            line3DList.push_back(l1);
            noOfRecordsRead++; // Increment no. of records
        }
    }

    // Remove duplicate records from each list
    sort(pt2DList.begin(), pt2DList.end(), Point2D::comparePointsAscending); // sort the vector using comparator function
	auto pt2DListEnd = unique(pt2DList.begin(), pt2DList.end(), Point2D::compareEqualPoints); // call unique function to remove duplicate elements and return an iterator to the last element not removed
	pt2DList.erase(pt2DListEnd, pt2DList.end()); // Remove empty elements within the vector
    
    sort(pt3DList.begin(), pt3DList.end(), Point3D::comparePointsAscending); // sort the vector using comparator function
	auto pt3DListEnd = unique(pt3DList.begin(), pt3DList.end(), Point3D::compareEqualPoints); // call unique function to remove duplicate elements and return an iterator to the last element not removed
	pt3DList.erase(pt3DListEnd, pt3DList.end()); // Remove empty elements within the vector

    sort(line2DList.begin(), line2DList.end(), Line2D::compareLinesAscending); // sort the vector using comparator function
	auto line2DListEnd = unique(line2DList.begin(), line2DList.end(), Line2D::compareEqualLines); // call unique function to remove duplicate elements and return an iterator to the last element not removed
	line2DList.erase(line2DListEnd, line2DList.end()); // Remove empty elements within the vector

    sort(line3DList.begin(), line3DList.end(), Line3D::compareLinesAscending); // sort the vector using comparator function
	auto line3DListEnd = unique(line3DList.begin(), line3DList.end(), Line3D::compareEqualLines); // call unique function to remove duplicate elements and return an iterator to the last element not removed
	line3DList.erase(line3DListEnd, line3DList.end()); // Remove empty elements within the vector

    // Compute number of duplicate records removed and number of unique records stored
    int noOfUniques = (pt2DList.size() + pt3DList.size() + line2DList.size() + line3DList.size()) - noOfRecordsInitial;
    int noOfDuplicates = noOfRecordsRead - noOfUniques;

    // Display info to user
    cout << noOfRecordsRead << " records read in successfully!" << endl;
    cout << noOfDuplicates << " duplicate records removed!" << endl;
    cout << noOfUniques << " unique records added and stored!" << endl;
}

// Function to display filtering criteria sub-menu options
void displayFilterCriteriaSubMenu()
{
    // Display header
    cout << endl << "[ Specifying filtering criteria (current : " << filterCriteria << ") ]" << endl << endl;
    
    // Display menu options
    cout << "   a)" << "      " << "Point2D records" << endl;
    cout << "   b)" << "      " << "Point3D records" << endl;
    cout << "   c)" << "      " << "Line2D records" << endl;
    cout << "   d)" << "      " << "Line3D records" << endl;
    cout << endl;
}

// Function to get user input for filtering criteria
void inputFilteringCriteria()
{
    // Declare variable to store char user input
    char filterOption;

    do
    {
        displayFilterCriteriaSubMenu();

        cout << "Please enter your criteria (a - d) : ";
        cin >> filterOption;
        cin.ignore(10000, '\n'); // clear input buffer

        switch (filterOption)
        {
            // Set filtering criteria to Point2D records and change default sorting criteria accordingly
            case 'a':
            {
                filterCriteria = "Point2D";
                sortingCriteria = "x-ordinate";
            }
                break;
            // Set filtering criteria to Point3D records and change default sorting criteria accordingly
            case 'b':
            {
                filterCriteria = "Point3D";
                sortingCriteria = "x-ordinate";
            }
                break;
            // Set filtering criteria to Line2D records and change default sorting criteria accordingly
            case 'c':
            {
                filterCriteria = "Line2D";
                sortingCriteria = "Pt. 1";
            }
                break;
            // Set filtering criteria to Line3D records and change default sorting criteria accordingly
            case 'd':
            {
                filterCriteria = "Line3D";
                sortingCriteria = "Pt. 1";
            }
                break;
        }
    }while(!(filterOption >= 'a' && filterOption <= 'd'));
}
// Function to display sorting criteria sub-menu options
void displaySortingCriteriaSubMenu()
{
    // Display header
    cout << endl << "[ Specifying sorting criteria (current : " << sortingCriteria << ") ]" << endl << endl;

    // Display menu options based on filtering criteria
    if (filterCriteria == "Point2D")
    {
        cout << "   a)" << "      " << "X-ordinate value" << endl;
        cout << "   b)" << "      " << "Y-ordinate value" << endl;
        cout << "   c)" << "      " << "distance from origin from Origin value" << endl;
        cout << endl;
    }
    else if (filterCriteria == "Point3D")
    {
        cout << "   a)" << "      " << "X-ordinate value" << endl;
        cout << "   b)" << "      " << "Y-ordinate value" << endl;
        cout << "   c)" << "      " << "Z-ordinate value" << endl;
        cout << "   d)" << "      " << "distance from origin from Origin value" << endl;
        cout << endl;
    }
    else if (filterCriteria == "Line2D" || filterCriteria == "Line3D")
    {
        cout << "   a)" << "      " << "Pt. 1's (x, y) values" << endl;
        cout << "   b)" << "      " << "Pt. 2's (x, y) values" << endl;
        cout << "   c)" << "      " << "Length value" << endl;
        cout << endl;
    }
}

// Function to get user input for sorting criteria
void inputSortingCriteria()
{
    // Declare variable to store char user input
    char sortCriteriaOption;

    do
    {
        displaySortingCriteriaSubMenu();

        if (filterCriteria == "Point3D")
            cout << "Please enter your criteria (a - d) : ";
        else
            cout << "Please enter your criteria (a - c) : ";

        cin >> sortCriteriaOption;
        cin.ignore(10000, '\n'); // clear input buffer

        switch (sortCriteriaOption)
        {
            // Set sorting criteria according to selected filter criteria
            case 'a':
            {
                if (filterCriteria == "Point2D" || filterCriteria == "Point3D")
                    sortingCriteria = "x-ordinate";
                else
                    sortingCriteria = "Pt. 1";
            }
                break;
            case 'b':
            {
                if (filterCriteria == "Point2D" || filterCriteria == "Point3D")
                    sortingCriteria = "y-ordinate";
                else
                    sortingCriteria = "Pt. 2";
            }
                break;
            case 'c':
            {
                if (filterCriteria == "Point2D")
                    sortingCriteria = "Dist. From Origin";
                else if (filterCriteria == "Point3D")
                    sortingCriteria = "z-ordinate";
                else
                    sortingCriteria = "Length";
            }
                break;
            case 'd':
            {
                if (filterCriteria != "Point3D")
                    sortCriteriaOption = 'X';
                else
                    sortingCriteria = "Dist. From Origin";
            }
                break;
        }
    }while(!(sortCriteriaOption >= 'a' && sortCriteriaOption <= 'd'));
}

// Function to display sorting order sub-menu options
void displaySortingOrderSubMenu()
{
    // Display header
    cout << endl << "[ Specifying sorting order (current : " << sortingOrder << ") ]" << endl << endl;

    // Display menu options
    cout << "   a)" << "      " << "ASC (Ascending order)" << endl;
    cout << "   b)" << "      " << "DSC (Descending order)" << endl;
    cout << endl;
}

// Function to input sorting order 
void inputSortingOrder()
{
    // Declare variable to store char user input
    char sortingOrderOption;

    do
    {
        displaySortingOrderSubMenu();

        cout << "Please enter your criteria (a - b) : ";
        cin >> sortingOrderOption;
        cin.ignore(10000, '\n'); // clear input buffer

        if (sortingOrderOption == 'a')
            sortingOrder = "ASC";
        else if (sortingOrderOption == 'b')
            sortingOrder = "DSC";

    }while(sortingOrderOption != 'a' && sortingOrderOption != 'b');
}

// Function to sort data by the specified criterias and order
void sortData()
{
    if (filterCriteria == "Point2D")
    {
        if (sortingCriteria == "x-ordinate")
        {
            if (sortingOrder == "ASC")
                sort(pt2DList.begin(), pt2DList.end(), Point2D::compareXAscending);
            else
                sort(pt2DList.begin(), pt2DList.end(), Point2D::compareXDescending);
        }
        else if (sortingCriteria == "y-ordinate")
        {
            if (sortingOrder == "ASC")
                sort(pt2DList.begin(), pt2DList.end(), Point2D::compareYAscending);
            else
                sort(pt2DList.begin(), pt2DList.end(), Point2D::compareYDescending);
        }
        else
        {
            if (sortingOrder == "ASC")
                sort(pt2DList.begin(), pt2DList.end(), Point2D::compareDistAscending);
            else
                sort(pt2DList.begin(), pt2DList.end(), Point2D::compareDistDescending);
        }
    }
    else if (filterCriteria == "Point3D")
    {
        if (sortingCriteria == "x-ordinate")
        {
            if (sortingOrder == "ASC")
                sort(pt3DList.begin(), pt3DList.end(), Point3D::compareXAscending);
            else
                sort(pt3DList.begin(), pt3DList.end(), Point3D::compareXDescending);
        }
        else if (sortingCriteria == "y-ordinate")
        {
            if (sortingOrder == "ASC")
                sort(pt3DList.begin(), pt3DList.end(), Point3D::compareYAscending);
            else
                sort(pt3DList.begin(), pt3DList.end(), Point3D::compareYDescending);
        }
        else if (sortingCriteria == "z-ordinate")
        {
            if (sortingOrder == "ASC")
                sort(pt3DList.begin(), pt3DList.end(), Point3D::compareZAscending);
            else
                sort(pt3DList.begin(), pt3DList.end(), Point3D::compareZDescending);
        }
        else
        {
            if (sortingOrder == "ASC")
                sort(pt3DList.begin(), pt3DList.end(), Point3D::compareDistAscending);
            else
                sort(pt3DList.begin(), pt3DList.end(), Point3D::compareDistDescending);
        }
    }
    else if (filterCriteria == "Line2D")
    {
        if (sortingCriteria == "Pt. 1")
        {
            if (sortingOrder == "ASC")
                sort(line2DList.begin(), line2DList.end(), Line2D::comparePoint1Ascending);
            else
                sort(line2DList.begin(), line2DList.end(), Line2D::comparePoint1Descending);
        }
        else if (sortingCriteria == "Pt. 2")
        {
            if (sortingOrder == "ASC")
                sort(line2DList.begin(), line2DList.end(), Line2D::comparePoint2Ascending);
            else
                sort(line2DList.begin(), line2DList.end(), Line2D::comparePoint2Descending);
        }
        else
        {
            if (sortingOrder == "ASC")
                sort(line2DList.begin(), line2DList.end(), Line2D::compareLengthAscending);
            else
                sort(line2DList.begin(), line2DList.end(), Line2D::compareLengthDescending);
        }
    }
    else
    {
        if (sortingCriteria == "Pt. 1")
        {
            if (sortingOrder == "ASC")
                sort(line3DList.begin(), line3DList.end(), Line3D::comparePoint1Ascending);
            else
                sort(line3DList.begin(), line3DList.end(), Line3D::comparePoint1Descending);
        }
        else if (sortingCriteria == "Pt. 2")
        {
            if (sortingOrder == "ASC")
                sort(line3DList.begin(), line3DList.end(), Line3D::comparePoint2Ascending);
            else
                sort(line3DList.begin(), line3DList.end(), Line3D::comparePoint2Descending);
        }
        else
        {
            if (sortingOrder == "ASC")
                sort(line3DList.begin(), line3DList.end(), Line3D::compareLengthAscending);
            else
                sort(line3DList.begin(), line3DList.end(), Line3D::compareLengthDescending);
        }
    }
}

// Function to return the specified data in string format
string dataToString()
{
    // Declare stringstream object
    ostringstream ss;

    // Set decimal points of floating point numbers to be in a fixed format
    ss << fixed;

    if (filterCriteria == "Point2D")
    {
        // Format header
        ss << setw(5) << "X" << setw(6) << "Y" << "    " << "Dist. Fr Origin" << endl;
        ss << setfill('-') << setw(40) << "" << setfill(' ') << endl;

        // Format data values
        for (Point2D pt : pt2DList)
        {
            ss << "[" << setw(4) << pt.getX() << ", " << setw(4) << pt.getY() << "]   " // format point x,y values
            << setprecision(3) << pt.getScalarValue() << endl; // format distance from origin value
        }
    }
    else if (filterCriteria == "Point3D")
    {
        // Format header
        ss << setw(5) << "X" << setw(6) << "Y" << setw(6) << "Z" << "    " << "Dist. Fr Origin" << endl;
        ss << setfill('-') << setw(40) << "" << setfill(' ') << endl;

        // Format data values
        for (Point3D pt : pt3DList)
        {
            ss << "[" << setw(4) << pt.getX() << ", " << setw(4) << pt.getY() << ", " << setw(4) << pt.getZ() << "]   "; // format point x,y,z values
            ss << setprecision(3) << pt.getScalarValue() << endl; // format distance from origin value
        }
    }
    else if (filterCriteria == "Line2D")
    {
        // Format header
        ss << setw(5) << "P1-X" << setw(6) << "P1-Y" << "    " << setw(5) << "P2-X" << setw(6) << "P2-Y" << "    " << "Length" << endl;
        ss << setfill('-') << setw(45) << "" << setfill(' ') << endl;

        // Format data values
        for (Line2D line : line2DList)
        {
            Point2D pt1 = line.getPt1();
            Point2D pt2 = line.getPt2();

            ss << "[" << setw(4) << pt1.getX() << ", " << setw(4) << pt1.getY() << "]   "; // format point 1 x,y values
            ss << "[" << setw(4) << pt2.getX() << ", " << setw(4) << pt2.getY() << "]   "; // format point 2 x,y values
            ss << setprecision(3) << line.getScalarValue() << endl; // format length value
        }
    }
    else
    {
        // Format header
        ss << setw(5) << "P1-X" << setw(6) << "P1-Y" << setw(6) << "P1-Z" << "    "; // Point 1 header
        ss << setw(5) << "P2-X" << setw(6) << "P2-Y" << setw(6) << "P2-Z" << "    " << "Length" << endl; // Point 2 and Length header
        ss << setfill('-') << setw(55) << "" << setfill(' ') << endl;

        // Format data values
        for (Line3D line : line3DList)
        {
            Point3D pt1 = line.getPt1();
            Point3D pt2 = line.getPt2();

            ss << "[" << setw(4) << pt1.getX() << ", " << setw(4) << pt1.getY() << ", " << setw(4) << pt1.getZ() << "]   "; // format point 1 x,y,z calues
            ss << "[" << setw(4) << pt2.getX() << ", " << setw(4) << pt2.getY() << ", " << setw(4) << pt2.getZ() << "]   "; // format point 2 x,y,z calues
            ss << setprecision(3) << line.getScalarValue() << endl; // format length value
        }
    }

    return ss.str();
}

// Function to display data on console
void viewData()
{
    // Call sort data function
    sortData();

    // Display filtering criteria, sorting criteria and sorting order
    cout << endl << "[ View data ... ]" << endl;
    cout << "filtering criteria : " << filterCriteria << endl;
    cout << "sorting criteria : " << sortingCriteria<< endl;
    cout << "sorting order : " << sortingOrder<< endl;
    cout << endl;

    cout << dataToString() << endl;
}

// Function to write and store data on text file
void storeData()
{
    // Declare c-string variable with a size of 201 to store file name
	char fileName[201];

    // Get user input for file name up to length of 200
    cout << endl;
	cout << "Please enter filename: ";	
	cin.getline(fileName, 201);
	cout << endl;

    // Create and open the file with specified file name
    ofstream outFile(fileName);

    if (outFile.is_open())
    {
        // Call sort function
        sortData();

        // Declare variable to count number of records to be stored
        int noOfRecords;

        if (filterCriteria == "Point2D")
            noOfRecords = pt2DList.size();
        else if (filterCriteria == "Point3D")
            noOfRecords = pt3DList.size();
        else if (filterCriteria == "Line2D")
            noOfRecords = line2DList.size();
        else
            noOfRecords = line3DList.size();

        outFile << dataToString();

        cout << noOfRecords << " records output successfully!" << endl;
        outFile.close();
    }
    else
        cout << "Failed to open file, going back to main menu ..." << endl;
}

// Function to generate a cleaned data file with formatting similar to the file that was read in
void generateCleanFile()
{
    // Declare c-string variable with a size of 201 to store file name
	char fileName[201];

    // Get user input for file name up to length of 200
    cout << endl;
	cout << "Please enter filename: ";	
	cin.getline(fileName, 201);
	cout << endl;

    // Create and open the file with specified file name
    ofstream outFile(fileName);

    if (outFile.is_open())
    {
        for (Point2D pt : pt2DList)
        {
            outFile << "Point2D, [" << pt.getX() << ", " << pt.getY() << "]" << endl;
        }

        for (Point3D pt : pt3DList)
        {
            outFile << "Point3D, [" << pt.getX() << ", " << pt.getY() << ", " << pt.getZ() << "]" << endl;
        }

        for (Line2D line : line2DList)
        {
            Point2D pt1 = line.getPt1();
            Point2D pt2 = line.getPt2();

            outFile << "Line2D, [" << pt1.getX() << ", " << pt1.getY() << "], [" << pt2.getX() << ", " << pt2.getY() << "]" << endl;
        }

        for (Line3D line : line3DList)
        {
            Point3D pt1 = line.getPt1();
            Point3D pt2 = line.getPt2();

            outFile << "Line3D, [" << pt1.getX() << ", " << pt1.getY() << ", " << pt1.getZ() << "], [";
            outFile << pt2.getX() << ", " << pt2.getY() << ", " << pt2.getZ() << "]" << endl;
        }

        int noOfRecords = pt2DList.size() + pt3DList.size() + line2DList.size() + line3DList.size();
        cout << noOfRecords << " records output successfully!" << endl;
        outFile.close();
    }
}

// Helper function to retrieve all integers from string
vector<int> getIntFromString (string str)
{
	// Declare vector to store integers
	vector<int> intList;
	
	// Variables to store beginning and ending index of numbers found
	size_t begin = 0, end = 0;
	while(begin != string::npos)
    {
		// FInd the first instance of digit within string
        begin = str.find_first_of("-0123456789", end);
        if(begin != string::npos) 
        {
			// FInd the index of the character after the number
            end = str.find_first_not_of("-0123456789", begin);

			// Get substring of number from beginning index and length
            string numTemp = str.substr(begin, end - begin);

			// Convert string to integer and store into vector
            int number = stoi(numTemp);
            intList.push_back(number);
        }
    }
	
	return intList;
};