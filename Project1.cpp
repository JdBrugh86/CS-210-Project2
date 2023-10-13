/* Jonathan Brugh
 * CS-210
 * Eric Gregori
 * 09/17/2023
 * Project 1
 * Program collects input from user and allows hour, minutes, and seconds
 * to be added in increments of 1
 */

#include <iostream>
#include <iomanip>

using namespace std;                                       // Fixme: Avoid global "using namespace" to avoid namespace conflicts

class ClockFunctions {
    // User requires access to only setting time.
    public:
    // Public functions
        void SetTime();

    private:
    // Private functions
        void TopBottomDisplayBorder();
        void ClocksSpace();
        void TopBottomClockBorder();
        void LeftMenuSpace();
        void LeftMenuBorder();
        void Clock24(int, string);
        void AddHour(int, string&);
        void AddMinute(int, string&);
        void AddSecond(int);
        void DisplayClock();
        void DisplayMenu();
        void MenuErrorCheck();
        void ClearScreen();
        int HourErrorCheck(int&);
        int MinutesErrorCheck(int&);
        int SecondsErrorCheck(int&);
        string AmOrPmErrorCheck(string&);

    // Private variables
        int inHour, inMinutes, inSeconds, menuSelection, hour24;
        string dayOrNight;
};

// Collects user input, sends to error check, and sets time of day
// Fixme: Add int type error check
void ClockFunctions::SetTime() {

    // Sets hour
    cout << "Enter hour of day:" << endl;
    cin >> inHour;
    HourErrorCheck(inHour);

    // Sets minutes
    cout << "Enter minutes:" << endl;
    cin >> inMinutes;
    MinutesErrorCheck(inMinutes);

    // Sets seconds
    cout << "Enter seconds:" << endl;
    cin >> inSeconds;
    SecondsErrorCheck(inSeconds);

    // Sets morning or afternoon
    cout << "AM or PM?" << endl;
    cin >> dayOrNight;
    AmOrPmErrorCheck(dayOrNight);
    
    // Sends input to Clock24 to set 24 hour clock,
    // "clears" screen for presentation,
    // and displays both clocks and user menu
    Clock24(inHour, dayOrNight);
    ClearScreen();
    DisplayClock();
}

// The following 3 functions check for errors in user input
// Validates correct hour input, passes "inHour" reference
int ClockFunctions::HourErrorCheck(int& hourToCheck){
    if ((hourToCheck < 1) || (hourToCheck > 12)) {
        while ((hourToCheck < 1) || (hourToCheck > 12)) {
            cout << "Input error" << endl;
            cout << "Enter hour of day:" << endl;
            cin >> hourToCheck;
        }
    }
    return hourToCheck;
}

// Validates correct minutes input, passes "inMinutes" reference
int ClockFunctions::MinutesErrorCheck(int& minutesToCheck) {
    if ((minutesToCheck < 1) || (minutesToCheck > 59)) {
        while ((minutesToCheck < 1) || (minutesToCheck > 59)) {
            cout << "Input error" << endl;
            cout << "Enter minutes:" << endl;
            cin >> minutesToCheck;
        }
    }
    return minutesToCheck;
}

// Validates correct seconds input, passes "inSeconds" reference
int ClockFunctions::SecondsErrorCheck(int& secondsToCheck) {
    if ((secondsToCheck < 1) || (secondsToCheck > 59)) {
        while ((secondsToCheck < 1) || (secondsToCheck > 59)) {
            cout << "Input error" << endl;
            cout << "Enter seconds:" << endl;
            cin >> secondsToCheck;
        }
    }
    return secondsToCheck;
}

// Validates correct morning or afternoon input and converts to a standard that program uses, "A M" or "P M"
// Passes "dayOrNight" reference
string ClockFunctions::AmOrPmErrorCheck(string& timeOfDay) {
    while ((timeOfDay != "am") && (timeOfDay != "AM") && (dayOrNight != "pm") && (dayOrNight != "PM")) {
        cout << "Input error" << endl;
        cout << "AM or PM?" << endl;
        cin >> timeOfDay;
    }

    if ((timeOfDay == "am") || (timeOfDay == "AM")) {
        timeOfDay = "A M";
    }

    else {
        timeOfDay = "P M";
    }
    return timeOfDay;
}

// Sets hour of 24 hour clock
void ClockFunctions::Clock24(int hour12, string nightOrDay) {

    // Sets morning time of 24 hour clock, ensures "12AM" = "00"
    if (nightOrDay == "A M") {
        switch (hour12) {
            case 12:
            hour24 = 00;
            break;

            default:
            hour24 = hour12;
            break;
        }
    }

    // Sets afternoon time (+12) of 24 hour clock, ensures "12 Noon" = "12"
    else {
        switch (hour12) {
            case 12:
            hour24 = 12;
            break;
            default:
            hour24 = hour12 + 12;
            break;
        }      
    }
}

// Creates line of 26 '*', used in top and bottom of clocks and menu borders
void ClockFunctions::TopBottomDisplayBorder() {
    cout << setfill('*') << setw(26) << "";
}

// Adds 5 space gap, used between clock displays
void ClockFunctions::ClocksSpace() {
    cout << setfill(' ') << setw(5) << "";
}

// Top and bottom clock borders
void ClockFunctions::TopBottomClockBorder() {
    TopBottomDisplayBorder();
    ClocksSpace();
    TopBottomDisplayBorder();
    cout << endl;
    cout << setfill(' ');
}

// Spaces menu display from left, mostly centers with clocks display
void ClockFunctions::LeftMenuSpace() {
    cout << setfill(' ') << setw(15) << "";
}

// Left menu border
void ClockFunctions::LeftMenuBorder() {
    cout << '*' << setfill(' ') << setw(24);
}

// Displays clocks side by side, both clocks have '*' border with 5 spaces between bordered clocks
// Used "https://stackoverflow.com/questions/37623646/adding-a-border" for aid in creating borders
void ClockFunctions::DisplayClock() {
    TopBottomClockBorder();
    cout << left << setw(6) << '*' << "12-Hour Clock" << right << setw(7) << '*';
    ClocksSpace();
    cout << left << setw(7) << '*' << "24-Hour Clock" << right << setw(6) << '*' << endl;
    cout << left << setw(6) << '*';
    printf("%.02d:%.02d:%.02d", inHour, inMinutes, inSeconds);
    cout << ' ' << dayOrNight;
    cout << right << setw(8) << '*' << setfill(' ') << setw(5) << "" << left << setw(9) << '*';
    printf("%.02d:%.02d:%.02d", hour24, inMinutes, inSeconds);
    cout << right << setw(9) << '*' << endl;
    TopBottomClockBorder();
    DisplayMenu();
}

// Displays menu and allows menu option selection, menu has border of '*'
void ClockFunctions::DisplayMenu() {
    cout << left;
    LeftMenuSpace();
    TopBottomDisplayBorder();
    cout << endl;
    LeftMenuSpace();
    LeftMenuBorder();
    cout << " 1 - Add One Hour " << '*' << endl;  // Menu option 1, adds 1 hour to both clocks
    LeftMenuSpace();
    LeftMenuBorder();
    cout << " 2 - Add One Minute" << '*' << endl; // Menu option 2, adds 1 minute to both clocks
    LeftMenuSpace();
    LeftMenuBorder();
    cout << " 3 - Add One Second" << '*' << endl; // Menu option 3, adds 1 second to both clocks
    LeftMenuSpace();
    LeftMenuBorder();
    cout << " 4 - Exit Program" << '*' << endl;   // Menu option 4, exits program and "clears" screen using 40 spaces
    LeftMenuSpace();
    TopBottomDisplayBorder();
    cout << endl;

    // Each menu selection below, except option 4, displays clocks and menu again
    // Menu option 4 exits program and "clears" screen
    cin >> menuSelection;
    switch (menuSelection) {
        // Add hour
        case 1:
            AddHour(1, dayOrNight);
            ClearScreen();
            DisplayClock();
            break;

        // Add minute
        case 2:
            AddMinute(1,dayOrNight);
            ClearScreen();
            DisplayClock();
            break;

        // Add second
        case 3:
            AddSecond(1);
            ClearScreen();
            DisplayClock();
            break;

        // Exits program
        case 4:
            for (int i = 0; i < 40; ++i) {
                cout << endl;
            }
            return;
            break;

        // Sends input to menu error check, clears screen, and displays clocks again
        default:
            ClearScreen();
            MenuErrorCheck();
            DisplayClock();
            break;
    }
}

// Displays menu selection error message
void ClockFunctions::MenuErrorCheck() {
    LeftMenuSpace();
    cout << setfill('*') << setw(37) << "" << endl;
    LeftMenuSpace();
    LeftMenuBorder();
    cout << " Menu selection unknown.";
    cout << right << setfill(' ') << setw(12) << '*' << endl;
    LeftMenuSpace();
    LeftMenuBorder();
    cout << " Please select from options below.";
    cout << right << setfill(' ') << setw(2) << '*' << endl;
    LeftMenuSpace();
    LeftMenuBorder();
    cout << " Current time:";
    cout << right << setfill(' ') << setw(12) << '*' << endl;
    LeftMenuSpace();
    cout << setfill('*') << setw(37) << "" << endl;
}

// Adds 1 hour to both clocks, passes "dayOrNight" reference
void ClockFunctions::AddHour(int addHour, string& nightDay) {
    inHour += addHour;
    hour24 += 1;
    
    // Ensures new 12 hour cycle
    if (inHour == 13) {
        inHour = 01;
    }

    // Changes "A M" to "P M" and vice versa
    if (inHour == 12) {
            if (nightDay == "A M") {
                nightDay = "P M";
            }

            else if (nightDay == "P M") {
                nightDay = "A M";
            }
        }
    Clock24(inHour, nightDay);
}

// Adds 1 minute to both clocks, passes "dayOrNight" reference
void ClockFunctions::AddMinute(int addMinute, string& nightDay) {
    inMinutes += addMinute;
    
    if (inMinutes == 60) {
        AddHour(1, nightDay);
        inMinutes = 00;
    }
}

// Adds 1 second to both clocks
void ClockFunctions::AddSecond(int addSecond) {
    inSeconds += addSecond;

    if (inSeconds == 60) {
        AddMinute(1, dayOrNight);
        inSeconds = 00;
    }
}

// "Clears" screen using 40 new lines
void ClockFunctions::ClearScreen() {
    for (int i = 0; i < 40; ++i) {
        cout << endl;
    }
}

int main() {
    ClockFunctions project1;
    project1.SetTime();

    return 0;
}
