#include "Print.h"

int main()
{
    setlocale(LC_ALL, "");

    do
    {
        system("cls");
        printMain();
    } while (printRestart());

    return 0;
}
