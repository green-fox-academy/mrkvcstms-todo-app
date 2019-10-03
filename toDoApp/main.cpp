#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

void instructions();


int main(int argc, char* argv[]) {

    if (argv[1] == string("todo")){
        if (argc == 2){
            instructions();
        }
    }


    return 0;
}

void instructions()
{
    cout << "Command Line Todo application\n";
    cout << "=============================\n\n";
    cout << "Command line arguments:\n";
    cout << "\t-l   Lists all the tasks\n";
    cout << "\t-a   Adds a new task\n";
    cout << "\t-r   Removes a task\n";
    cout << "\t-c   Completes a task\n";
}