#include <iostream>
#include <fstream>

using namespace std;

void read_file_and_add(){
    std::string filename;
    cout << "Enter a filename: ";
    cin >> filename;
    ifstream fin(filename);

    int a, b;
    while(!fin.eof()){
        fin >> a;
        fin >> b;
        cout << "The sum of " << a << " and " << b << " is " << a + b << endl;
    }
}

int main(){
    read_file_and_add();
    return 0;
}