
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

    // Validate matches watched
    if (cin.fail() || tennismatches < 0)
    {
        cout << "Invalid input. Please enter a whole number 0 or greater.\n";
        return 1;
    }

    // weekly tennis practice hours
    cout << "Please enter how many hours do you practice tennis every week? ";
    cin >> practiceHoursPerWeek;

    // Validate practice hours
    if (cin.fail() || practiceHoursPerWeek < 0 ||
        practiceHoursPerWeek > 168)
    {
        cout << "Invalid input. Please enter hours from 0 to 168.\n";
        return 1;
    }

    //  how many matches the user plays per month
    cout << "How many matches do you play every month? ";
    cin >> matchesPerMonth;

    // Validate matches played
    if (cin.fail() || matchesPerMonth < 0)
    {
        cout << "Invalid input. Enter a whole number 0 or greater.\n";
        return 1;
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

    // Save the formatted summary to report.txt
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

    // Close the report file
    reportFile.close();

    cout << "\nYour report has been saved to report.txt.\n";
    cout << "Thank you for using the Tennis Report!\n";

    return 0;
}
