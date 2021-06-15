#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string calc(string FileName)
{
    ifstream fin(FileName);
    char temp;
    int N9 = 0;
    int N0 = 0;
    int N1 = 0;
    string res = "";

    while (fin >> temp)
    {
        if (temp == '9') N9++;
        if (temp == '0') N0++;
        if (temp == '1') N1++;
    }
    
    res += "0x" + to_string(N0);
    res += " ";
    res += "1x" + to_string(N1);
    res += " ";
    res += "9x" + to_string(N9);
    fin.close();
    return res;
}

class MyTest
{
public:
    void Test1();
    void Test2();
    void Test();
};
void MyTest::Test1()
{
    ofstream fout("test1.txt");
    fout << "0" << endl << "11" << endl << "999" << endl;
    if (calc("test1.txt") != "0x1 1x2 9x3") cout << "Test1 NOT OK" << endl;
    else cout << "Test1 OK" << endl;
    fout.close();
}
void MyTest::Test2()
{
    ofstream fout("test2.txt");
    fout << "0" << endl << "11" << endl << "99" << endl << "9"<<endl;
    if (calc("test2.txt") != "0x1 1x2 9x3") cout << "Test2 NOT OK" << endl;
    else cout << "Test2 OK" << endl;
    fout.close();
}
void MyTest::Test()
{
    Test1();
    Test2();
}

int main()
{
    string FileName;
    cin >> FileName;
    cout << calc(FileName) << endl;
    MyTest temp;
    temp.Test();
    return 0;
}
