#include <iostream>
using namespace std;

int main()
{
    // tennis information
    int tennismatches;
    int practiceHoursPerWeek;
    int matchesPerMonth;

	// Ask the user about their tennis habits
    cout << "how many time did you watch tennis matches per month? ";
    cin >> tennismatches;

    cout << "How many hours do you practice tennis every week? ";
    cin >> practiceHoursPerWeek;

    cout << "How many matches do you play every month? ";
    cin >> matchesPerMonth;

    // Calculate yearly practice hours
    int yearlyPracticeHours = practiceHoursPerWeek * 52;

    // Display a summary
    cout << "\n===== Tennis Summary =====\n";
    cout << "Your favorite tennis player is " << tennismatches << ". ";
    cout << "You practice tennis for " << practiceHoursPerWeek
         << " hours each week and play "
         << matchesPerMonth << " matches each month. ";
    cout << "That adds up to approximately "
         << yearlyPracticeHours
         << " hours of practice each year!" << endl;

    return 0;
}
