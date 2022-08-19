#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

struct SmallData{
    SmallData(int n, double r, char s){
        num = n;
        real = r;
        stafur = s;
    }
    int num;
    double real;
    char stafur;
    
    friend ostream &operator<<(ostream &out, const SmallData &sd){
        out << "num: " << sd.num << " real: " << sd.real << " stafur: " << sd.stafur;
        return out;
    }
};


class DataClass{
public:
    DataClass(int number){
        this->number = number;
    }

    int serialize(char* &buffer){
        //HERE JUST BUILDING THE LENGTH TO MAKE BUFFER OF CORRECT SIZE
        int total_length = sizeof(int);
        total_length += sizeof(int);
        for(std::string tmp : our_data){
            total_length += tmp.length() + sizeof(int);
        }

        //MAKE THE BUFFER
        buffer = new char[total_length];
        //SET ANOTHER VARIABLE TO BUFFER TO SAVE ORIGINAL BEGINNING IN buffer
        char *curr_p = buffer;

        //THE NUMBER IS COPIED INTO THE FIRST BYTES OF THE BUFFER
        *((int *)curr_p) = this->number;
        curr_p += sizeof(int);
        //EVERYTIME WE PUT SOMETHING IN THE BUFFER WE SHOULD MOVE THE CURRENT LOCATION

        //PUTTING THE NUMBER OF STRINGS INTO THE BUFFER FOR EASIER DESERIALIZATION
        *((int *)curr_p) = our_data.size();
        curr_p += sizeof(int);

        //FOR EACH STRING IN OUR DATA
        for(std::string tmp : our_data){

            //PUTTING THE LENGTH OF THE STRING FOR EASIER DESERIALIZATION
            *((int *)curr_p) = tmp.length();
            curr_p += sizeof(int);

            //COPYING THE STRING ITSELF INTO THE CORRECT LOCATION IN THE BUFFER
            strcpy(curr_p, tmp.c_str());
            curr_p += tmp.length();
        }

        //RETURN THE LENGTH FOR WRITING/SENDING
        return total_length;
    }

    void deserialize(char *buffer, int length){
        //FIRST BYTES ARE THE NUMBER
        this->number = *((int *)(buffer));
        buffer += sizeof(int);
        //EVERYTIME WE READ SOMETHING FROM THE BUFFER WE SHOULD MOVE THE CURRENT LOCATION

        //READING THE NUMBER OF STRINGS FROM THE BUFFER FOR EASIER DESERIALIZATION
        int str_count = *((int *)(buffer));
        buffer += sizeof(int);

        //THAT MANY TIMES
        for(int i = 0; i < str_count; i++){

            //READING THE LENGTH OF THE STRING FOR EASIER DESERIALIZATION
            int str_len = *((int *)(buffer));
            buffer += sizeof(int);

            //MAKE NEW STRING
            std::string tmp_str;
            //FOR THE LENGTH OF THE STRING
            for(int j = 0; j < str_len; j++){
                //ADD A SINGLE CHARACTER
                tmp_str.push_back(*(buffer++));
            }
            //NULL-TERMINATE THE STRING
            tmp_str.push_back('\0');
            //PUT THE STRING INTO OUR DATA
            our_data.push_back(tmp_str);

            //THIS IS NOT A GREAT WAY TO COPY STRINGS BUT WE NEEDED SOMETHING TO WORK
        }
    }

    void fill_our_data(){
        std::string tmp_str;
        cout << "next string ('q' to stop): ";
        cin >> tmp_str;
        while(tmp_str != "q"){
            our_data.push_back(tmp_str);
            cout << "next string: ";
            cin >> tmp_str;
        }
    }

    friend ostream &operator<<(ostream &out, const DataClass &dc){
        out << "the number: " << dc.number << endl;
        for(auto tmp : dc.our_data){
            out << tmp << endl;
        }
        return out;
    }

private:
    int number;
    std::vector<std::string> our_data;
};


int main(int argc, char *argv[]){

    SmallData sd(234, 0.4443, 'f');
    cout << "SmallData before: " << sd << endl;

    ofstream fout("smalldatafile.srz", ios::binary);
    fout.write((char *)&sd, sizeof(SmallData));
    fout.close();

    DataClass dc(543);
    dc.fill_our_data();
    cout << "DataClass before: " << dc << endl;

    char *some_buffer;
    int some_length = dc.serialize(some_buffer);

    SmallData sd2(0, 0.0, '\0');
    ifstream fin("smalldatafile.srz", ios::binary);
    fin.read((char *)&sd2, sizeof(SmallData));
    cout << "SmallData after: " << sd2 << endl;

    DataClass dc2(0);
    dc2.deserialize(some_buffer, some_length);
    cout << "DataClass after: " << dc2 << endl;



    return 0;
}