#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::endl;
using std::vector;
#include <fstream>

void instructions();
int countLines();
void listTasks();
void addNewTask(string whatToAdd);
void removeTask(string num);
vector<string> createVector();
void taskDone(string num);
void printOutVector(vector<string> toPrint);

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

        } else if (string(argv[2]) == "-r") {
            if (argc == 4) removeTask(argv[3]);
            else cout << "No task to remove!" << endl;

        }else if (string(argv[2]) == "-c") {
            if (argc == 4) taskDone(argv[3]);
            else cout << "No task to be completed!" << endl;

        }
    }

    cout << endl;
    return 0;
}

void instructions()
{
    cout << "Command Line Todo application\n"
            "=============================\n\n"
            "Command line arguments:\n"
                "\t-l   Lists all the tasks\n"
                "\t-a   Adds a new task\n"
                "\t-r   Removes a task\n"
                "\t-c   Completes a task\n";
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
    myFile << endl << "[ ] " << whatToAdd;
    myFile.close();

    cout << "New task added!" << endl;
}

void removeTask(string num)
{
    if(std::stoi(num) <= countLines()) {
        vector<string> myVector = createVector();

        myVector.erase(myVector.begin() + std::stoi(num) - 1);

        printOutVector(myVector);

        cout << "Task removed!" << endl;
    } else cout << "There isn't that many tasks!" << endl;
}

void taskDone(string num)
{
    if(std::stoi(num) <= countLines()) {
        vector<string> myVector = createVector();

        myVector[std::stoi(num) - 1][1] = 'X';

        printOutVector(myVector);

        cout << "Task completed!" << endl;
    } else cout << "There isn't that many tasks!" << endl;
}

vector<string> createVector()
{
    vector<string> myVector;
    int lineCounter = countLines();
    std::string lines;

    std::ifstream inputFile;
    inputFile.open("toDoList.txt");

    for (int i = 0; i < lineCounter; ++i) {
        std::getline(inputFile, lines);
        myVector.push_back(lines);
    }

    inputFile.close();
    return myVector;
}

void printOutVector(vector<string> toPrint)
{
    std::ofstream myFile;
    myFile.open("toDoList.txt");
    for (int i = 0; i < toPrint.size() - 1; i++) {
        myFile << toPrint[i] << endl;
    }
    myFile << toPrint[toPrint.size() - 1];
    myFile.close();
}