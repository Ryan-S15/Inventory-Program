#include <iostream>
#include <vector>
#include <string>

using namespace std;

//declaring all of the functions being used throughout the program
void displayIntro (); //displays the welcome intro and waits for the user to press 1 to continue
void displayCategory (string title, vector<int>& ids, vector<string>& names, vector<int>& stock); //displays one category's parts with their ID, name and stock
void displayFullInventory (vector<int>& Rid, vector<string>& resistors, vector<int>& Rstock,
                           vector<int>& Cid, vector<string>& capacitors, vector<int>& Cstock,
                           vector<int>& Hid, vector<string>& henrys, vector<int>& Hstock,
                           vector<int>& Pid, vector<string>& pots, vector<int>& Pstock,
                           vector<int>& ICid, vector<string>& icChips, vector<int>& ICstock,
                           vector<int>& Lid, vector<string>& leds, vector<int>& Lstock,
                           vector<int>& Sid, vector<string>& switches, vector<int>& Sstock,
                           vector<int>& Bid, vector<string>& batteries, vector<int>& Bstock); //displays the entire inventory of every category
void modifyCategory (string title, vector<int>& ids, vector<string>& names, vector<int>& stock); //handles the add/remove flow for one category
void initializeIds (vector<int>& ids, int count, int& nextId); //fills an ID vector with sequential unique numbers
void buildAllIds (vector<int>& Rid, vector<string>& resistors,
                  vector<int>& Cid, vector<string>& capacitors,
                  vector<int>& Hid, vector<string>& henrys,
                  vector<int>& Pid, vector<string>& pots,
                  vector<int>& ICid, vector<string>& icChips,
                  vector<int>& Lid, vector<string>& leds,
                  vector<int>& Sid, vector<string>& switches,
                  vector<int>& Bid, vector<string>& batteries); //builds the ID vectors for all categories in order
void programCheck (int& programCompletion); //asks the user if they want to keep using the program or exit
void clearInputBuffer (); //clears the input buffer for clean input
int searchList (vector<string>& list, string value); //textbook linear search, returns index or -1
int getMenuChoice (int low, int high); //prompts the user for a number in [low, high] with full input validation
int getCategoryChoice (); //prompts the user to pick one of the 8 categories with validation

int main()
{
    int programCompletion = 0;
    displayIntro();

    //category data (every row from the supplied spreadsheet)
    vector<string> resistors = {
        "1 ohm","1.2 ohm","1.5 ohm","1.8 ohm","2.2 ohm","2.7 ohm","3.3 ohm",
        "3.9 ohm","4.7 ohm","5.6 ohm","6.8 ohm","8.2 ohm","10 ohm","12 ohm",
        "15 ohm","18 ohm","22 ohm","27 ohm","33 ohm","39 ohm","47 ohm","56 ohm",
        "68 ohm","82 ohm","100 ohm","120 ohm","150 ohm","180 ohm","200 ohm",
        "220 ohm","270 ohm","300 ohm","330 ohm","390 ohm","470 ohm","560 ohm",
        "620 ohm","680 ohm","820 ohm","1k ohm","1.2k ohm","1.5k ohm","1.8k ohm",
        "2.2k ohm","2.7k ohm","3.3k ohm","3.9k ohm","4.7k ohm","5.6k ohm",
        "6.8k ohm","8.2k ohm","10k ohm","12k ohm","15k ohm","16k ohm","18k ohm",
        "22k ohm","27k ohm","33k ohm","39k ohm","47k ohm","56k ohm","68k ohm",
        "75k ohm","82k ohm","100k ohm","120k ohm","150k ohm","180k ohm",
        "220k ohm","270k ohm","330k ohm","390k ohm","470k ohm","560k ohm",
        "680k ohm","820k ohm","1M ohm","4.7M ohm","10M ohm","22M ohm"
    };
    vector<int> Rstock = {
        64,98,98,100,82,100,87,90,98,91,93,81,59,95,83,87,91,82,261,79,143,23,
        81,75,24,18,519,450,31,26,459,214,595,23,357,359,266,26,35,43,390,62,
        255,353,291,306,103,428,275,225,194,223,64,71,1,279,350,87,118,92,295,
        93,86,114,82,253,92,169,90,75,90,386,75,216,94,103,92,92,1,7,37
    };

    vector<string> capacitors = {
        "474k Radial","105K Radial","102K Radial","224K Radial","104K Radial",
        "473K Radial","103K Radial","101K Radial",".1 J Radial","47 Micro F",
        "1 Micro F","220 Micro F","4.7 Micro F Ax","4.7 Micro F","330 Micro F",
        "470 Micro F","22 Micro F","10 Micro F","4700 Micro F","47 Micro F (2)",
        "1000 Micro F","2200 Micro F","100 Micro F Ax","33 Micro F","100 Micro F"
    };
    vector<int> Cstock = {
        25,91,149,7,2,14,14,2,2,111,203,17,111,253,0,47,946,700,0,481,31,38,2,308,271
    };

    vector<string> henrys = {
        "10 uH","22 uH","47 uH","220 uH","1 mH","2.2 mH","4.7 mH",
        "10 mH","22 mH","33 mH","47 mH","100 mH"
    };
    vector<int> Hstock = {81,88,90,60,48,42,45,33,64,50,59,76};

    vector<string> pots = {
        "1k ohm pot","5k ohm pot","50k ohm pot","100k ohm pot",
        "1M ohm pot","2M ohm pot"
    };
    vector<int> Pstock = {1,6,1,11,1,1};

    vector<string> icChips = {
        "7409","4001","4017","4029","74157","9526","7420","74595","7719","4511",
        "9525","74151","74193","4011","7488","7489","7402","7411","7409 (2)",
        "7490","9226","7414","7400","7408","7402 (2)","74147","74037","7432",
        "7486","7451","MH7489","7932","7485","74138","7474","74154","74125",
        "74190","7430","74191","74107","74192","74148","7495","7447","7442",
        "74121","7475","74163","74150","74164"
    };
    vector<int> ICstock = {
        7,5,8,2,3,3,2,1,4,2,5,1,2,8,1,26,89,84,7,9,3,146,77,4,9,14,28,42,89,27,
        197,75,70,33,47,84,25,42,74,74,56,283,64,69,30,3,51,47,22,30,136
    };

    vector<string> leds = {"white","red","green","yellow"};
    vector<int>    Lstock = {66,368,102,73};

    vector<string> switches = {"8 prong","4 prong","3 prong","2 prong"};
    vector<int>    Sstock = {1,2,10,1};

    vector<string> batteries = {"9V","1.5 V"};
    vector<int>    Bstock = {5,3};

    //ID vectors run in parallel with each names/stock pair
    vector<int> Rid, Cid, Hid, Pid, ICid, Lid, Sid, Bid;
    buildAllIds(Rid, resistors, Cid, capacitors, Hid, henrys, Pid, pots,
                ICid, icChips, Lid, leds, Sid, switches, Bid, batteries);

    while (programCompletion != 2) { //loops as long as the user wants to keep using the program
        int topChoice = 0;
        cout << "\nDo you want to:" << endl;
        cout << "  1 - See the full inventory" << endl;
        cout << "  2 - Add/remove a part" << endl;
        cout << "  3 - Exit" << endl;
        topChoice = getMenuChoice(1, 3);

        if (topChoice == 1) { //display full inventory then loop back
            displayFullInventory(Rid, resistors, Rstock,
                                 Cid, capacitors, Cstock,
                                 Hid, henrys, Hstock,
                                 Pid, pots, Pstock,
                                 ICid, icChips, ICstock,
                                 Lid, leds, Lstock,
                                 Sid, switches, Sstock,
                                 Bid, batteries, Bstock);
        } else {
            if (topChoice == 2) { //add/remove path from the flowchart
                int checkAnother = 1;
                while (checkAnother == 1) {
                    cout << "\nWhich part do you want to add/remove?" << endl;
                    int cat = getCategoryChoice();

                    if (cat == 1) {
                        modifyCategory("Resistors", Rid, resistors, Rstock);
                    } else {
                        if (cat == 2) {
                            modifyCategory("Capacitors", Cid, capacitors, Cstock);
                        } else {
                            if (cat == 3) {
                                modifyCategory("LEDs", Lid, leds, Lstock);
                            } else {
                                if (cat == 4) {
                                    modifyCategory("IC Chips", ICid, icChips, ICstock);
                                } else {
                                    if (cat == 5) {
                                        modifyCategory("Batteries", Bid, batteries, Bstock);
                                    } else {
                                        if (cat == 6) {
                                            modifyCategory("Potentiometers", Pid, pots, Pstock);
                                        } else {
                                            if (cat == 7) {
                                                modifyCategory("Switches", Sid, switches, Sstock);
                                            } else {
                                                modifyCategory("Henrys", Hid, henrys, Hstock);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }

                    cout << "\nCheck another part?" << endl;
                    cout << "  1 - Yes" << endl;
                    cout << "  2 - No, back to main menu" << endl;
                    checkAnother = getMenuChoice(1, 2);
                }
            } else {
                programCompletion = 2;
            }
        }

        if (programCompletion != 2) { //ask whether to keep going or exit (only if user did not just pick Exit)
            programCheck(programCompletion);
        }
    }

    cout << "\nThank you for using the Inventory Program!" << endl;
}

void displayIntro () { //displays the welcome intro and waits for the user to press 1 to continue
    int readyChoice = 0;
    cout << "----------------------------------------------" << endl;
    cout << "|                                            |" << endl;
    cout << "|   Welcome to the Electrical Components     |" << endl;
    cout << "|         Inventory Management Program       |" << endl;
    cout << "|                                            |" << endl;
    cout << "|        - Use full screen console -         |" << endl;
    cout << "|                                            |" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "\n---------------------------------------------" << endl;
    cout << "|        Once you're ready, press 1.        |" << endl;
    cout << "---------------------------------------------" << endl;
    cin >> readyChoice;
    while (!cin or readyChoice != 1) { //invalid input/fail check for ready prompt
        cout << "Invalid Input. When ready, input 1.\n";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> readyChoice;
    }
    cin.ignore(10000, '\n');
    cout << "\n";
}

void displayCategory (string title, vector<int>& ids, vector<string>& names, vector<int>& stock) { //displays one category's parts with their ID, name and stock
    cout << "\n----- " << title << " -----" << endl;
    if (names.size() == 0) {
        cout << "  (empty)" << endl;
        return;
    }
    for (int i = 0; i < names.size(); i++) {
        cout << "  ID: " << ids[i] << " | " << names[i] << " : " << stock[i] << endl;
    }
}

void displayFullInventory (vector<int>& Rid, vector<string>& resistors, vector<int>& Rstock,
                           vector<int>& Cid, vector<string>& capacitors, vector<int>& Cstock,
                           vector<int>& Hid, vector<string>& henrys, vector<int>& Hstock,
                           vector<int>& Pid, vector<string>& pots, vector<int>& Pstock,
                           vector<int>& ICid, vector<string>& icChips, vector<int>& ICstock,
                           vector<int>& Lid, vector<string>& leds, vector<int>& Lstock,
                           vector<int>& Sid, vector<string>& switches, vector<int>& Sstock,
                           vector<int>& Bid, vector<string>& batteries, vector<int>& Bstock) { //displays the entire inventory of every category
    cout << "\n==========================================" << endl;
    cout << "             FULL INVENTORY" << endl;
    cout << "==========================================" << endl;
    displayCategory("Resistors", Rid, resistors, Rstock);
    displayCategory("Capacitors", Cid, capacitors, Cstock);
    displayCategory("Henrys (Inductors)", Hid, henrys, Hstock);
    displayCategory("Potentiometers", Pid, pots, Pstock);
    displayCategory("IC Chips", ICid, icChips, ICstock);
    displayCategory("LEDs", Lid, leds, Lstock);
    displayCategory("Switches", Sid, switches, Sstock);
    displayCategory("Batteries", Bid, batteries, Bstock);
    cout << "==========================================" << endl;
}

void modifyCategory (string title, vector<int>& ids, vector<string>& names, vector<int>& stock) { //handles the add/remove flow for one category
    displayCategory(title, ids, names, stock);

    cout << "\nEnter the exact part name to add/remove: ";
    string partName;
    clearInputBuffer();
    getline(cin, partName);

    int idx = searchList(names, partName); //textbook linear search to locate the part
    if (idx == -1) {
        cout << "Part \"" << partName << "\" not found in " << title << "." << endl;
        return;
    }

    cout << "How many do you need? ";
    int needed = 0;
    cin >> needed;
    while (!cin or needed < 0) { //invalid input/fail check for quantity
        cout << "Invalid input. Enter a number that is 0 or greater: ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> needed;
    }
    cin.ignore(10000, '\n');

    cout << "We currently have " << stock[idx] << " of " << names[idx];
    cout << " (ID: " << ids[idx] << ") in stock." << endl;

    cout << "\nDo you want to:" << endl;
    cout << "  1 - Add " << needed << " of " << names[idx] << endl;
    cout << "  2 - Remove " << needed << " of " << names[idx] << endl;
    int choice = getMenuChoice(1, 2);

    if (choice == 1) { //add 1 of specified part, repeated 'needed' times (per the flowchart)
        for (int i = 0; i < needed; i++) {
            stock[idx] = stock[idx] + 1;
        }
        cout << "Added " << needed << " unit(s)." << endl;
    } else { //remove 1 at a time, stop if stock hits 0
        int removed = 0;
        for (int i = 0; i < needed; i++) {
            if (stock[idx] > 0) {
                stock[idx] = stock[idx] - 1;
                removed = removed + 1;
            }
        }
        cout << "Removed " << removed << " unit(s).";
        if (removed < needed) {
            cout << " (Stock reached 0 before all could be removed.)";
        }
        cout << endl;
    }

    cout << "Total " << names[idx] << " (ID: " << ids[idx];
    cout << ") left after change: " << stock[idx] << endl;
}

void initializeIds (vector<int>& ids, int count, int& nextId) { //fills an ID vector with sequential unique numbers
    ids.clear();
    for (int i = 0; i < count; i++) {
        ids.push_back(nextId);
        nextId = nextId + 1;
    }
}

void buildAllIds (vector<int>& Rid, vector<string>& resistors,
                  vector<int>& Cid, vector<string>& capacitors,
                  vector<int>& Hid, vector<string>& henrys,
                  vector<int>& Pid, vector<string>& pots,
                  vector<int>& ICid, vector<string>& icChips,
                  vector<int>& Lid, vector<string>& leds,
                  vector<int>& Sid, vector<string>& switches,
                  vector<int>& Bid, vector<string>& batteries) { //builds the ID vectors for all categories in order
    int nextId = 1;
    initializeIds(Rid, resistors.size(), nextId);
    initializeIds(Cid, capacitors.size(), nextId);
    initializeIds(Hid, henrys.size(), nextId);
    initializeIds(Pid, pots.size(), nextId);
    initializeIds(ICid, icChips.size(), nextId);
    initializeIds(Lid, leds.size(), nextId);
    initializeIds(Sid, switches.size(), nextId);
    initializeIds(Bid, batteries.size(), nextId);
}

int searchList (vector<string>& list, string value) { //textbook linear search, returns index or -1
    int index = 0;
    int position = -1;
    bool found = false;
    while (index < list.size() and !found) {
        if (list[index] == value) {
            found = true;
            position = index;
        }
        index = index + 1;
    }
    return position;
}

void programCheck (int& programCompletion) { //asks the user if they want to keep using the program or exit
    cout << "\n\nWould you like to do something else?\n\n1 - Yes\n2 - No\n";
    cin >> programCompletion;
    while (!cin or programCompletion > 2 or programCompletion < 1) { //invalid input/fail check for continue prompt
        cout << "Invalid Input. Would you like to do something else?\n\n1 - Yes\n2 - No\n";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> programCompletion;
    }
    if (programCompletion == 1) {
        cout << "\n------------------------------------------\n" << endl;
    }
}

void clearInputBuffer () { //clears the input buffer for clean input
    cin.clear();
    cin.ignore(10000, '\n');
}

int getMenuChoice (int low, int high) { //prompts the user for a number in [low, high] with full input validation
    int choice = 0;
    cout << "Enter choice (" << low << "-" << high << "): ";
    cin >> choice;
    while (!cin or choice < low or choice > high) { //invalid input/fail check for menu choice
        cout << "Invalid input. Enter a number (" << low << "-" << high << "): ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> choice;
    }
    return choice;
}

int getCategoryChoice () { //prompts the user to pick one of the 8 categories with validation
    cout << "  1 - Resistors" << endl;
    cout << "  2 - Capacitors" << endl;
    cout << "  3 - LEDs" << endl;
    cout << "  4 - IC chips" << endl;
    cout << "  5 - Batteries" << endl;
    cout << "  6 - Potentiometers" << endl;
    cout << "  7 - Switches" << endl;
    cout << "  8 - Henrys (Inductors)" << endl;
    return getMenuChoice(1, 8);
}
