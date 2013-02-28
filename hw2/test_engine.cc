#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

string expected_results[10];

void load_result_file(char const *file_name)
{
    ifstream r_file(file_name);
    int line_num = 0;
    while (getline(r_file, expected_results[line_num++]))
    {
        if (line_num == 10) break;
    }
    r_file.close();
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout<<"usage:test expected_file"<<endl;
        return 1;
    }
    load_result_file(argv[1]);
    {
        int cnt = 0;
        int sum = 0;   
        string line;
        while (getline(cin, line))
        {
            if (line == expected_results[cnt++]) sum += 2;
        }
        cout<<sum<<endl;
    }
    return 0;
}

