#include <fstream>
#include <iostream>

#include <fstream>

using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

using namespace std;
struct Student
{
    int index;
    int id;
    string firstName;
    string lastName;
    int mark;
};
void generateBinary(string textFile, string binaryFile)
{
    Student s;
    ifstream textF(textFile, std::ios::in);
    if (textF.is_open())
    {
        ofstream outFile(binaryFile, std::ios::out | std::ios::binary);
        if (outFile.is_open())
        {
            cout << "Opened bin file" << std::endl;
            while (textF >> s.index >> s.id >> s.firstName >> s.lastName >> s.mark)
            {
                outFile.write(reinterpret_cast<const char *>(&s), sizeof(Student));
            }

            outFile.close();
        }
        else
        {
            cout << "Error opening binary file 3" << std::endl;
        }
        textF.close();
    }
    else
    {
        cout << "Error opening text file ! 11" << std::endl;
    }
}

void generateTextFromBin(string binartFileName, string textFileName)
{
    Student s;
    ifstream binFile(binartFileName, std::ios::binary);
    if (binFile.is_open())
    {
        ofstream textFile(textFileName, std::ios::out);
        if (textFile.is_open())
        {
            while (binFile.read(reinterpret_cast<char *>(&s), sizeof(Student)))
            {
                textFile << s.index << " "
                         << s.id << " "
                         << s.firstName << " "
                         << s.lastName << " "
                         << s.mark
                         << std::endl;
            }
            textFile.close();
        }
        else
        {
            cout << "Error opening text file 1" << std::endl;
        }
        binFile.close();
    }
    else
    {
        cout << "Error opening binary file 2" << std::endl;
    }
}
int main()
{
    cout << "input Text file name:" << endl;
    string textFile;
    cin >> textFile;
    cout << "input Binary file name:" << endl;
    string binaryFile;
    cin >> binaryFile;
    cout << "input generated Text file name:" << endl;
    string textFile2;
    cin >> textFile2;
    const string folder = "ex1/";
    generateBinary(folder + textFile, folder + binaryFile);
    generateTextFromBin(folder + binaryFile, folder + textFile2);
    
    return EXIT_SUCCESS;
}