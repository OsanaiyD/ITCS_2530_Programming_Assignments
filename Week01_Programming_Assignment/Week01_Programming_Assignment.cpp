
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

void changeColor()
{
	system("color 0A");
}

//Display
void displayBanner()
{
	cout << "===============================================\n";
	cout << "          WELCOME TO THE TENNIS REPORT\n";
	cout << "===============================================\n\n";
}

string getPlayerName()
{
	string playerName;
	
    cout << "Please type your full name: ";
	getline(cin, playerName);
	
	while (playerName.empty())
    {
        cout << "Invalid input. Please enter your full name: ";
        getline(cin, playerName);
    }
    
    return playerName;
}

int getValidMatchs(string prompt)
{
    int matches;

    cout << prompt;
    cin >> matches;

    while (cin.fail() || matches < 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Invalid input. Please enter a whole number 0 or greater: ";
        cin >> matches;
    }

    cin.ignore(1000, '\n');

    return matches;
}


double getValidPracticeHours(string prompt)
{
    double practiceHours;

    cout << prompt;
    cin >> practiceHours;

    while (cin.fail() || practiceHours < 0 || practiceHours > 168)
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Invalid input. Please enter a number from 0 to 168: ";
        cin >> practiceHours;
    }

    cin.ignore(1000, '\n');

    return practiceHours;
}

void collectInput(string& playerName, int& tennismatches, double& practiceHoursPerWeek, int& matchesPerMonth)
{
    playerName = getPlayerName();

    tennismatches = getValidMatches(
        "How many tennis matches do you watch per month? ");

    practiceHoursPerWeek = getValidPracticeHours(
        "How many hours do you practice tennis every week? ");

    matchesPerMonth = getValidMatches(
        "How many matches do you play every month? ");
}


void calculateStats(double practiceHoursPerWeek, int matchesPerMonth, double& yearlyPracticeHours, double& averageMatchesPerWeek)
{
    yearlyPracticeHours = practiceHoursPerWeek * 52;

    averageMatchesPerWeek = matchesPerMonth / 4.0;
}

// Display the tennis summary report
void displayReport(string playerName, int tennismatches,
    double practiceHoursPerWeek, int matchesPerMonth,
    double averageMatchesPerWeek, double yearlyPracticeHours)
{
    cout << fixed << setprecision(2);

    cout << "\n===============================================\n";
    cout << "                 TENNIS SUMMARY\n";
    cout << "===============================================\n";

    cout << left << setw(30) << "Player Name"
        << ": " << playerName << '\n';

    cout << left << setw(30) << "Matches Watched Per Month"
        << ": " << tennismatches << '\n';

    cout << left << setw(30) << "Practice Hours Per Week"
        << ": " << practiceHoursPerWeek << '\n';

    cout << left << setw(30) << "Matches Played Per Month"
        << ": " << matchesPerMonth << '\n';

    cout << left << setw(30) << "Average Matches Per Week"
        << ": " << averageMatchesPerWeek << '\n';

    cout << left << setw(30) << "Yearly Practice Hours"
        << ": " << yearlyPracticeHours << '\n';

    cout << "===============================================\n";

    // First if/else 
    cout << "\nTENNIS PRACTICE EVALUATION\n";

    if (practiceHoursPerWeek >= 6 && matchesPerMonth >= 5)
    {
        cout << "You are a regular tennis player!\n";
    }
    else
    {
        cout << "You can still improve your tennis skills by practicing more.\n";
    }

    // Second if/else 
    cout << "\nTENNIS INTEREST EVALUATION\n";

    if (tennismatches >= 3 && matchesPerMonth >= 2)
    {
        cout << "You have a good interest in tennis!\n";
    }
    else
    {
        cout << "Try watching or playing more tennis matches!\n";
    }
}


// Save report file
void saveReport(string playerName, int tennismatches,
    double practiceHoursPerWeek, int matchesPerMonth,
    double averageMatchesPerWeek, double yearlyPracticeHours)
{
    ofstream reportFile("report.txt");

    if (reportFile.is_open())
    {
        reportFile << fixed << setprecision(2);

        reportFile << "\n===============================================\n";
        reportFile << "                 TENNIS SUMMARY\n";
        reportFile << "===============================================\n";

        reportFile << left << setw(30) << "Player Name"
            << ": " << playerName << '\n';

        reportFile << left << setw(30) << "Matches Watched Per Month"
            << ": " << tennismatches << '\n';

        reportFile << left << setw(30) << "Practice Hours Per Week"
            << ": " << practiceHoursPerWeek << '\n';

        reportFile << left << setw(30) << "Matches Played Per Month"
            << ": " << matchesPerMonth << '\n';

        reportFile << left << setw(30) << "Average Matches Per Week"
            << ": " << averageMatchesPerWeek << '\n';

        reportFile << left << setw(30) << "Yearly Practice Hours"
            << ": " << yearlyPracticeHours << '\n';

        reportFile << "===============================================\n";

        // First if/else report
        reportFile << "\nTENNIS PRACTICE EVALUATION\n";

        if (practiceHoursPerWeek >= 6 && matchesPerMonth >= 5)
        {
            reportFile << "You are a regular tennis player!\n";
        }
        else
        {
            reportFile << "You can still improve your tennis skills by practicing more.\n";
        }

        // Second if/else report
        reportFile << "\nTENNIS INTEREST EVALUATION\n";

        if (tennismatches >= 3 && matchesPerMonth >= 2)
        {
            reportFile << "You have a good interest in tennis!\n";
        }
        else
        {
            reportFile << "Try watching or playing more tennis matches!\n";
        }

        reportFile.close();
    }
    else
    {
        cout << "Unable to save the report file.\n";
    }
}

// Display and validate the tennis menu
int displayMenu()
{
    int dashboard;

    cout << "\n===============================================\n";
    cout << "              TENNIS OPTIONS MENU\n";
    cout << "===============================================\n";
    cout << "1. View Weekly Practice Information\n";
    cout << "2. View Match Information\n";
    cout << "3. Exit Program\n";
    cout << "Enter your choice: ";

    cin >> dashboard;

    while (cin.fail() || dashboard < 1 || dashboard > 3)
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Invalid menu choice. Enter 1, 2, or 3: ";
        cin >> dashboard;
    }

    cin.ignore(1000, '\n');

    return dashboard;
}




int main()
{
    //tennis information
    string playerName;
    double yearlyPracticeHours;
    double averageMatchesPerWeek;
    int tennismatches;
    double practiceHoursPerWeek;
    int matchesPerMonth;
    int dashboard;
    int week;
    double totalPracticeHours = 0;




    // Call the console color function
    changeColor();

    // Call the welcome banner function
    displayBanner();

    // Collect tennis information
    collectInput(playerName, tennismatches,
        practiceHoursPerWeek, matchesPerMonth);

    // Calculate tennis statistics
    calculateStats(practiceHoursPerWeek, matchesPerMonth,
        yearlyPracticeHours, averageMatchesPerWeek);

    // Display tennis report
    displayReport(playerName, tennismatches,
        practiceHoursPerWeek, matchesPerMonth,
        averageMatchesPerWeek, yearlyPracticeHours);

    // Repeat menu until the user exits
    do
    {
        dashboard = displayMenu();

        // Select menu option
        switch (dashboard)
        {
        case 1:
            cout << "\nWEEKLY PRACTICE INFORMATION\n";

            cout << "Practice hours per week: "
                << practiceHoursPerWeek << '\n';

            cout << "Practice hours per year: "
                << yearlyPracticeHours << '\n';

            // For loop: Display five weeks of practice
            cout << "\nFIVE-WEEK PRACTICE SUMMARY\n";

            totalPracticeHours = 0;

            for (int week = 1; week <= 5; week++)
            {
                totalPracticeHours += practiceHoursPerWeek;

                cout << "Week " << week
                    << " | Practice Hours: " << practiceHoursPerWeek
                    << " | Total Hours: " << totalPracticeHours
                    << '\n';
            }

            break;

        case 2:
            cout << "\nMATCH INFORMATION\n";

            cout << "Matches watched per month: "
                << tennismatches << '\n';

            cout << "Matches played per month: "
                << matchesPerMonth << '\n';

            cout << "Average matches per week: "
                << averageMatchesPerWeek << '\n';

            break;

        case 3:
            cout << "\nThank you for using the Tennis Report!\n";
            break;
        }

    } while (dashboard != 3);

    // Save report to file
    saveReport(playerName, tennismatches,
        practiceHoursPerWeek, matchesPerMonth,
        averageMatchesPerWeek, yearlyPracticeHours);

    cout << "\nYour report has been saved to report.txt.\n";
    cout << "Thank you for using the Tennis Report!\n";

    return 0;


}
