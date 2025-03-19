#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;
using namespace chrono;

class LoveProgram {
private:
    vector<string> heart = {
        "\033[31m", // Red color
    
      "   ***     *** ",
      " ******   ****** ",
      "******** ********",
      "*****************",
      " *************** ",
      "  *************  ",
      "   ***********   ",
      "     *******     ",
      "       ***       ",
      "        *        ",
        "\033[0m" // Reset color
    };

    void clearScreen() {
        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif
    }

    void delay(int ms) {
        #ifdef _WIN32
        Sleep(ms);
        #else
        usleep(ms * 1000);
        #endif
    }

    void animateHeart() {
        clearScreen();
        for(const auto& line : heart) {
            cout << string(10, ' ') << line << endl;
            delay(100);
        }
    }

    void printMessage() {
        vector<string> message = {
            "\033[1;35mFor my Beloved girl:\033[0m",
            "Jika dunia ini adalah sebuah program,",
            "Kaulah algoritma yang sempurna",
            "Yang mengoptimalkan setiap detik hidupku.",
            "",
            "Seperti loop tak berhingga,",
            "Cintaku padamu takkan pernah berakhir.",
            "",
            "\033[5;36mSemangat nugasnya sayangkuu <3 \033[0m" // Blinking effect
        };

        for(const auto& line : message) {
            cout << string(5, ' ') << line << endl;
            delay(1500);
        }
    }

public:
    void run() {
        animateHeart();
        delay(2000);
        clearScreen();
        printMessage();
        delay(3000);
        createPulseEffect();
    }

    void createPulseEffect() {
        for(int i=0; i<3; i++) {
            clearScreen();
            cout << "\n\n\033[1;31m"; // Bright red
            cout << string(15, ' ') << "   I LOVE YOU   \n\n";
            cout << "\033[0m";
            delay(500);
            
            clearScreen();
            cout << "\n\n\033[1;35m"; // Bright magenta
            cout << string(15, ' ') << "  FOREVER  \n\n";
            cout << "\033[0m";
            delay(500);
        }
    }
};

int main() {
    LoveProgram program;
    program.run();
    return 0;
}
