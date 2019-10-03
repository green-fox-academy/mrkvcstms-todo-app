#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

#include <fstream>

void instructions();
int countLines();
void listTasks();
void addNewTask(string whatToAdd);

int main(int argc, char* argv[])
{
    cout << endl;

    if (argv[1] == string("todo")){
        if (argc == 2){
            instructions();
        } else if (string(argv[2]) == "-l"){
            listTasks();
        } else if (string(argv[2]) == "-a") {
            if (argc == 4) addNewTask(argv[3]);
            else cout << "No new tasks to add!" << endl;
        }
    }

    cout << endl;
    return 0;
}

void instructions()
{

    cout << "Command Line Todo application\n";
    cout << "=============================\n\n";
    cout << "Command line arguments:\n";
    cout <<     "\t-l   Lists all the tasks\n";
    cout <<     "\t-a   Adds a new task\n";
    cout <<     "\t-r   Removes a task\n";
    cout <<     "\t-c   Completes a task\n";

}

int countLines()
{

    std::ifstream inputStream;
    inputStream.open("toDoList.txt");

    int numLines = 0;
    std::string temp;
    while (getline(inputStream, temp)) {
        ++numLines;
    }
    inputStream.close();
    return numLines;
}

void listTasks()
{

    int lineCounter = countLines();
    std::string lines;

    std::ifstream inputFile;
    inputFile.open("toDoList.txt");

    if (lineCounter == 0) {
        std::cout << "No todos for today! (+:";
    } else {
        for (int i = 0; i < lineCounter; ++i) {
            std::getline(inputFile, lines);
            std::cout << i + 1 << " - " << lines << std::endl;
        }
    }

    inputFile.close();
}

void addNewTask(string whatToAdd)
{
    std::ofstream myFile;
    myFile.open("toDoList.txt", std::ios_base::app);
    myFile << endl << whatToAdd;
    myFile.close();

    cout << "New task added!" << endl;
}