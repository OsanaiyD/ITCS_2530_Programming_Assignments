
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

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

    // report file
    ofstream reportFile("report.txt");

    // Welcome page
    cout << "===============================================\n";
    cout << "          WELCOME TO THE TENNIS REPORT\n";
    cout << "===============================================\n\n";

    //  player's name
    cout << "please type your full name: ";
    getline(cin, playerName);

    //Ask the user about their tennis habits
    cout << "How many tennis matches do you watch per month? ";
    cin >> tennismatches;

  
    // The While loop
    while (cin.fail() || tennismatches < 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "This was a invalid input. please enter a number 0 or higher than 0";
        cin >> tennismatches;
    }

    // weekly tennis practice hours
    cout << "Please enter how many hours do you practice tennis every week? ";
    cin >> practiceHoursPerWeek;

    //The while loop
    while (cin.fail() || practiceHoursPerWeek < 0 || practiceHoursPerWeek > 168)
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "This was a invalid input. Please enter a number from 0 to 168";
        cin >> practiceHoursPerWeek;
    }

    //  how many matches the user plays per month
    cout << "How many matches do you play every month? ";
    cin >> matchesPerMonth;

    // The while loop
    while (cin.fail() || matchesPerMonth < 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "This was a invalid input. Please enter a number from 0 or higher than 0";
        cin >> matchesPerMonth;
    }

    // Calculate yearly practice hours and average matches per week
    yearlyPracticeHours = practiceHoursPerWeek * 52;
    averageMatchesPerWeek = matchesPerMonth / 4.0;

    // Set decimal formatting for the console
    cout << fixed << setprecision(2);

    // Display the summary on the screen
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

    // Save to report.txt
    reportFile << fixed << setprecision(2);

    reportFile << "===============================================\n";
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

    // if/else statement
    cout << "\nTENNIS PRACTICE EVALUATION\n";

    if (practiceHoursPerWeek >= 6 && matchesPerMonth >= 5)
    {
        cout << "You are a regular tennis player!\n";
        reportFile << "You are a regular tennis player!\n";
    }
    else
    {
        cout << "You can still improve your tennis skills by practicing more.\n";
        reportFile << "You can still improve your tennis skills by practicing more.\n";
    }

    // 2 if/else statement
    cout << "\nTENNIS INTEREST EVALUATION\n";

    if (tennismatches >= 3 && matchesPerMonth >= 2)
    {
        cout << "You have a good interest in tennis!\n";
        reportFile << "You have a good interest in tennis!\n";
    }
    else
    {
        cout << "Try watching or playing more tennis matches!\n";
        reportFile << "Try watching or playing more tennis matches!\n";
    }
    


    // the do while loop 
    do
    {
        // show the options menu
        cout << "\n===============================================\n";
        cout << "              TENNIS OPTIONS MENU\n";
        cout << "===============================================\n";
        cout << "1. View Weekly Practice Information\n";
        cout << "2. View Match Information\n";
        cout << "3. Exit Program\n";
        cout << "Enter your choice: ";

        cin >> dashboard;

        // Validate dashboard 
        while (cin.fail() || dashboard < 1 || dashboard > 3)
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid menu choice. Enter 1, 2, or 3: ";
            cin >> dashboard;
        }

        // select a option
        switch (dashboard)
        {
        case 1:
            cout << "\nWEEKLY PRACTICE INFORMATION\n";
            cout << "Practice hours per week: "
                << practiceHoursPerWeek << '\n';
            cout << "Practice hours per year: "
                << yearlyPracticeHours << '\n';

            reportFile << "\nWEEKLY PRACTICE INFORMATION\n";
            reportFile << "Practice hours per week: "
                << practiceHoursPerWeek << '\n';
            reportFile << "Practice hours per year: "
                << yearlyPracticeHours << '\n';

            //for loop
            cout << "\nFIVE-WEEK PRACTICE SUMMARY\n";
            reportFile << "\nFIVE-WEEK PRACTICE SUMMARY\n";
            totalPracticeHours = 0;

            for (week = 1; week <= 5; week++)
            {
                totalPracticeHours += practiceHoursPerWeek;

                cout << "Week " << week
                    << " | Practice Hours: " << practiceHoursPerWeek
                    << " | Total Hours: " << totalPracticeHours
                    << '\n';

                reportFile << "Week " << week
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

            reportFile << "\nMATCH INFORMATION\n";
            reportFile << "Matches watched per month: "
                << tennismatches << '\n';
            reportFile << "Matches played per month: "
                << matchesPerMonth << '\n';
            reportFile << "Average matches per week: "
                << averageMatchesPerWeek << '\n';
            break;

        case 3:
            cout << "\nThank you for using the Tennis Report!\n";
            reportFile << "\nUser selected Exit Program.\n";
            break;
        }
	} while (dashboard != 3);
    // Close the report file
    reportFile.close();

    cout << "\nYour report has been saved to report.txt.\n";
    cout << "Thank you for using the Tennis Report!\n";

    return 0;
}
