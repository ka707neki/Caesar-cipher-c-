#include <iostream>
#include <string>
#include <cctype>
#include <chrono>
#include <thread>
#include <limits>
using namespace std;

// ANSI color codes for terminal styling
namespace color {
    const string reset   = "\033[0m";
    const string bold    = "\033[1m";
    const string red     = "\033[31m";
    const string green   = "\033[32m";
    const string yellow  = "\033[33m";
    const string cyan    = "\033[36m";
    const string gray    = "\033[90m";
}

// Print text one character at a time for a "typing" effect
void typeText(const string& text, int delayMs = 20)
{
    for (char c : text)
    {
        cout << c << flush;                                   // flush so each char shows immediately
        this_thread::sleep_for(chrono::milliseconds(delayMs)); // small pause between characters
    }
}

// Draw a centered title inside a box
void printBanner(const string& title)
{
    const int width = 48;                          // inner width of the box
    int left  = (width - (int)title.size()) / 2;   // spaces before the title
    int right = width - (int)title.size() - left;  // spaces after the title

    cout << color::cyan << color::bold;
    cout << "\n  " << string(width + 2, '=') << "\n";
    cout << "  |" << string(width, ' ') << "|\n";
    cout << "  |" << string(left, ' ') << title << string(right, ' ') << "|\n";
    cout << "  |" << string(width, ' ') << "|\n";
    cout << "  " << string(width + 2, '=') << "\n\n" << color::reset;
}

// Shift every letter forward by `shift` positions (wraps around the alphabet)
string encrypt(string text, int shift)
{
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string result = "";

    for (char c : text)
    {
        if (isupper(c))
        {
            // Convert to 0-25, shift, wrap with % 26, convert back to 'A'-'Z'
            result += (c - 'A' + shift) % 26 + 'A';
        }
        else if (islower(c))
        {
            // Same idea, but look the letter up in the alphabet string
            result += alphabet[(c - 'a' + shift) % 26];
        }
        else
        {
            result += c; // digits, spaces and symbols stay unchanged
        }
    }
    return result;
}

// Decrypting = encrypting with the opposite shift (26 - shift)
string decrypt(string text, int shift)
{
    return encrypt(text, 26 - (shift % 26));
}

int main()
{
    printBanner("CAESAR CIPHER TOOL");

    char again = 'y';
    while (again == 'y' || again == 'Y')
    {
        string text;
        int shift;

        // --- Input ---
        cout << color::yellow << "  Enter text  : " << color::reset;
        getline(cin, text);

        cout << color::yellow << "  Enter shift : " << color::reset;
        while (!(cin >> shift))                         // keep asking until a valid number is typed
        {
            cin.clear();                                // reset the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // throw away the bad input
            cout << color::red << "  Please enter a number: " << color::reset;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');      // remove leftover newline before next getline

        // Normalize the shift to 0-25 (also fixes negative numbers)
        shift = ((shift % 26) + 26) % 26;

        // --- Processing ---
        string enc = encrypt(text, shift);
        string dec = decrypt(enc, shift);

        // --- Output with typing effect ---
        cout << "\n" << color::gray << "  " << string(50, '-') << color::reset << "\n";

        cout << color::green << color::bold << "  Encrypted : " << color::reset << color::green;
        typeText(enc);
        cout << color::reset << "\n";

        cout << color::cyan << color::bold << "  Decrypted : " << color::reset << color::cyan;
        typeText(dec);
        cout << color::reset << "\n";

        cout << color::gray << "  " << string(50, '-') << color::reset << "\n\n";

        // --- Repeat? ---
        cout << color::yellow << "  Try again? (y/n): " << color::reset;
        cin >> again;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\n";
    }

    cout << color::cyan;
    typeText("  Goodbye! \n");
    cout << color::reset;
    return 0;
}
