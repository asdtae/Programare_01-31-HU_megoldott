#include <iostream>
#include <string>
#include <cstring>
#include <random>

using namespace std;

#define Black "\033[30m"
#define Red "\033[31m"
#define Green "\033[32m"
#define Yellow "\033[33m"
#define Blue "\033[34m"
#define Magenta "\033[35m"
#define Cyan "\033[36m"
#define White "\033[37m"

#define Bright_Black "\033[90m"
#define Bright_Red "\033[91m"
#define Bright_Green "\033[92m"
#define Bright_Yellow "\033[93m"
#define Bright_Blue "\033[94m"
#define Bright_Magenta "\033[95m"
#define Bright_Cyan "\033[96m"
#define Bright_White "\033[97m"

void fel01(int i, int b)
{
    int temp[b];

    for(int j=0; j<b; j++)
    {
        temp[j] = 0;
    }

    while(i <= b)
    {

        cout<<i<<' ';
        i++;
    }
    cout<<"\n";

}

void drawUI() {
    char buffer[50];
    char felbuffer[50];

    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> randDist(0, 15);

    const char* colors[16] = {
            Black, Red, Green, Yellow, Blue, Magenta, Cyan, White,
            Bright_Black, Bright_Red, Bright_Green, Bright_Yellow,
            Bright_Blue, Bright_Magenta, Bright_Cyan, Bright_White
    };
    string title_color = colors[randDist(mt)];

    string
    title="\n\n      8888888b.                                                                                          .d8888b.   d888          .d8888b.   d888         888    888 888     888         \n"
              "      888   Y88b                                                                                        d88P  Y88b d8888         d88P  Y88b d8888         888    888 888     888         \n"
              "      888    888                                                                                        888    888   888              .d88P   888         888    888 888     888         \n"
              "      888   d88P 888d888 .d88b.   .d88b.  888d888 8888b.  88888b.d88b.   8888b.  888d888 .d88b.         888    888   888             8888\"    888         8888888888 888     888         \n"
              "      8888888P\"  888P\"  d88\"\"88b d88P\"88b 888P\"      \"88b 888 \"888 \"88b     \"88b 888P\"  d8P  Y8b        888    888   888              \"Y8b.   888         888    888 888     888         \n"
              "      888        888    888  888 888  888 888    .d888888 888  888  888 .d888888 888    88888888        888    888   888  888888 888    888   888  888888 888    888 888     888         \n"
              "      888        888    Y88..88P Y88b 888 888    888  888 888  888  888 888  888 888    Y8b.            Y88b  d88P   888         Y88b  d88P   888         888    888 Y88b. .d88P         \n"
              "      888        888     \"Y88P\"   \"Y88888 888    \"Y888888 888  888  888 \"Y888888 888     \"Y8888 88888888 \"Y8888P\"  8888888        \"Y8888P\"  8888888       888    888  \"Y88888P\" 88888888 \n"
              "                                      888                                                                                                                                                \n"
              "                                 Y8b d88P                                                                                                                                                \n"
              "                                  \"Y88P\"\n";

    string separator = "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    printf("%s%s %s",title_color.c_str() ,title.c_str(), separator.c_str());

    while (true) {
        title_color = colors[randDist(mt)];
        printf("%s> ",Bright_White);
        if (fgets(buffer, sizeof(buffer), stdin) != nullptr) {
            buffer[strcspn(buffer, "\n")] = '\0';

            if (strcmp(buffer, "e") == 0) break;
            else if (strcmp(buffer, "cl") == 0) {
                system("CLS");
                printf("%s%s %s",title_color.c_str() ,title.c_str(), separator.c_str());
            }
            else if (strcmp(buffer, "help") == 0 || strcmp(buffer, "?") == 0) {
                printf("%sHelp:\n",Bright_White);
                printf("%scl%s         Clears the screen.\n",Bright_Cyan,Bright_White);
                printf("%sme%s         Quits the Programare_01_31_HU_megoldottt.exe program.\n",Bright_Cyan,Bright_White);
                printf("%sfel%s        Opens the feladat selector\n",Bright_Cyan,Bright_White);
                printf("%shelp%s / %s?%s   Provides Help information for commands.\n",Bright_Cyan,Bright_White,Bright_Cyan,Bright_White);
            }
            else if (strcmp(buffer, "fel") == 0)
            {
                while (true) {
                    printf("%sfel> %s",Bright_Cyan,Bright_White);
                    if (fgets(felbuffer, sizeof(felbuffer), stdin) != nullptr) {
                        felbuffer[strcspn(felbuffer, "\n")] = '\0';

                        if (strcmp(felbuffer, "e") == 0) break;
                        else if (strcmp(felbuffer, "cl") == 0) {
                            system("CLS");
                            printf("%s%s %s",title_color.c_str() ,title.c_str(), separator.c_str());
                        }
                        else if (strcmp(felbuffer, "help") == 0 || strcmp(felbuffer, "?") == 0) {
                            printf("%sFel_Help:%s\n",Bright_Cyan,Bright_White);
                            printf("%scl%s         Clears the screen.\n",Bright_Cyan,Bright_White);
                            printf("%sme%s         Quits the Programare_01_31_HU_megoldottt.exe program.\n",Bright_Cyan,Bright_White);
                            printf("%shelp%s / %s?%s   Provides Help information for %sfel%scommands.\n",Bright_Cyan,Bright_White,Bright_Cyan,Bright_White,Bright_Cyan,Bright_White);
                        }
                        else if (strcmp(felbuffer, "01") == 0) { fel01(4,30); }
                        else if (strcmp(felbuffer, "02") == 0) {  }
                        else if (strcmp(felbuffer, "03") == 0) { printf("nope lol"); }
                        else if (strcmp(felbuffer, "04") == 0) {  }
                        else if (strcmp(felbuffer, "05") == 0) {  }
                        else if (strcmp(felbuffer, "06") == 0) {  }
                        else if (strcmp(felbuffer, "07") == 0) {  }
                        else if (strcmp(felbuffer, "08") == 0) {  }
                        else if (strcmp(felbuffer, "09") == 0) {  }
                        else if (strcmp(felbuffer, "10") == 0) {  }
                        else if(strcmp(felbuffer, "") == 0) printf("");
                        else {
                            printf("%s'%s%s%s' is not recognized as an internal %sfel%scommand.%s\n",Bright_Red,Bright_White, felbuffer,Bright_Red,Bright_Cyan,Bright_Red,Bright_White);
                        }
                    }
                }
            }
            else if (strcmp(buffer, "") == 0) printf("");
            else {
                printf("%s'%s%s%s' is not recognized as an internal command.%s\n",Bright_Red,Bright_White, felbuffer,Bright_Red,Bright_White);
            }
        } else {
            printf("%sError reading input.%s\n",Bright_Red,Bright_White);
        }
    }
}

int main() {


    drawUI();

    //fgetc(stdin);
}
