#include <iostream>
#include <fstream>

using namespace std;

void calc(string FileName)
{
    ifstream fout(FileName);
    char temp;
    int N9 = 0;
    int N0 = 0;
    int N1 = 0;
    while (fout >> temp)
    {
        if (temp == '9') N9++;
        if (temp == '0') N0++;
        if (temp == '1') N1++;
    }
    cout << "0x" << N0 << " ";
    cout << "1x" << N1 << " ";
    cout << "9x" << N9 << " ";
}

int main()
{
    string FileName;
    cin >> FileName;
    calc(FileName);
    return 0;
}