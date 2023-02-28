#include "pch.h"
#include "Lab1_SheichukOlexandr.h"
#include <windows.h>
#include <crtdbg.h>
#include <fstream>
#include <conio.h>
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;

void CoutArray(int arr[], int length)
{
    cout << "Array: \n";
    for (size_t i = 0; i < length; i++)
        cout << "element #" << i + 1 << " -> " << arr[i] << endl;
}


int* enterArrayManualy(int& length)
{
    cout << "Enter number of array elements -> ";
    cin >> length;
    int* Arr = new int[length];
    cout << "Enter each element of the array in turn:\n";
    for (size_t i = 0; i < length; i++)
    {
        cout << "element #" << i + 1 << " -> ";
        cin >> Arr[i];
    }
    return Arr;
}

int* filesFillArray(int& length)
{
    string FILE_NAME = "";
    cout << "Enter file name -> ";
    cin >> FILE_NAME;
    ifstream inputFile(FILE_NAME);
    if (!inputFile.is_open()) {
        cerr << "Error: could not open file" << endl;
    }
    inputFile >> length;
    int* Arr = new int[length];
    cout << "Enter each element of the array in turn:\n";
    for (size_t i = 0; i < length; i++)
    {
        inputFile >> Arr[i];
        cout << "element #" << i + 1 << " -> " << Arr[i] << endl;
    }
    return Arr;
}

int* randomFillArray(int& length)
{
    srand(time(nullptr));
    int MAX_VAL = -1000;
    int MIN_VAL = 100;
    cout << "Enter number of array elements -> ";
    cin >> length;
    int* Arr = new int[length];
    cout << "Random array filling:\n";
    for (size_t i = 0; i < length; i++)
    {
        Arr[i] = rand() % (MAX_VAL - MIN_VAL + 1) + MIN_VAL;
        cout << "element #" << i + 1 << " -> " << Arr[i] << endl;
    }
    return Arr;
}

int* EnterTypeMenu(int& length)
{
    while (true)
    {
        int input;
        cout << "Menu for selecting an array input method:" << endl;
        cout << "1. Manual filling array" << endl;
        cout << "2. Random filling array" << endl;
        cout << "3. File filling array" << endl;
        cout << "Selection: ";
        cin >> input;

        switch (input) {
        case 1:
            return enterArrayManualy(length);
        case 2:
            return randomFillArray(length);
        case 3:
            return filesFillArray(length);
        default:
            MessageBox(NULL, L"Would you please look carefully at the menu, sir, and see that there are only three items. Would you be so kind as to enter everything correctly?", L"The most upstanding citizen", MB_ICONERROR);
            system("cls");
            break;
        }
    }
}

void firstTask()
{
    int length = 0;
    int* Arr = EnterTypeMenu(length);
    for (size_t i = 0; i < length; i++)
    {
        if (length / 2 >= i)
            Arr[i] *= 2;
        else
            Arr[i] *= 3;
    }
    CoutArray(Arr, length);
    delete[] Arr;

}

void secondTask()
{
    int length = 0;
    int* Arr = EnterTypeMenu(length);
    bool Status = false;
    int min = 9999999999;
    int minInc = 0;
    for (size_t i = 0; i < length; i++)
    {
        if (Status)
        {
            if (Arr[i] > 0 && Arr[i] % 2 == 0)
            {
                if (min > Arr[i])
                {
                    min = Arr[i];
                    minInc = i;
                }
            }
        }
        else
            if (Arr[i] < 0)
                Status = true;
    }
    CoutArray(Arr, length);
    if (minInc == 0)
    {
        cout << "No elements were found that satisfy the conditions of the problem!!!" << endl;
    }
    else
    {
        cout << "Minimun positive even element -> " << min << endl;
        cout << "Position of minimum element -> " << minInc + 1 << endl;
    }
    delete[] Arr;

}

int main()
{
    int flag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
    flag |= _CRTDBG_LEAK_CHECK_DF;
    _CrtSetDbgFlag(flag);
    while (true)
    {
        int input;
        cout << "MAIN MENU: " << endl;
        cout << "1. firstTask" << endl;
        cout << "2. secondTask" << endl;
        cout << "3. thirdTask" << endl;
        cout << "4. EXIT" << endl;
        cout << "Selection: ";
        cin >> input;
        system("cls");
        switch (input) {
        case 1:
            firstTask();
            system("pause");
            system("cls");
            break;
        case 2:
            secondTask();
            system("pause");
            system("cls");
            break;
        case 3:
            thirdTask();
            system("pause");
            system("cls");
            break;
        case 4:
            return 0;
        default:
            MessageBox(NULL, L"Would you please look carefully at the menu, sir, and see that there are only three items. Would you be so kind as to enter everything correctly?", L"The most upstanding citizen", MB_ICONERROR);
            system("cls");
            break;
        }
    }

    system("pause");
    return 0;
}