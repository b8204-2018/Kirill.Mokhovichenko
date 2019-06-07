#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <vector>

using namespace std;

class TaskFormat{
public:
    virtual double calculateTask(int *variabels) = 0;

};



class DirectoreFile{
private:
    string *nameFiles;
public:
    DirectoreFile(size_t amount){
        nameFiles = new string[amount];
    }

    void addFile(string nameFile){
        ifstream yourFile;
        yourFile.open(nameFile, ios_base::in);
        if (yourFile.is_open()){
            size_t format(0);
            yourFile >> format;
            yourFile.close();
            this->nameFiles[format - 1] = nameFile;
        }
        else{
            cout << "Error, File not found!";
            yourFile.close();
        }
    }

    string getFiles(size_t HowFormatSolve){
        return nameFiles[HowFormatSolve - 1];
    }

};

class ReaderFile{
public:

    string takeExample(DirectoreFile DirectoreFiles, size_t HowFormatSolve){
        string example;
        ifstream yourFile;
        yourFile.open(DirectoreFiles.getFiles(HowFormatSolve), ios_base::in);
        if (yourFile.is_open()){
            size_t format(0);
            yourFile >> format;
            yourFile >> example;
            yourFile.close();
        }
        else{
            cout << "Error, File not found!";
            yourFile.close();
        }
        return example;
    }

};

class WriteAnAnswer{
public:

    void printSolveOnTheScreen(double answer) {
        cout << answer << endl;
    }

    void printSolveOnTheFile(string nameFile, double answer){
        ofstream outputFile;
        ifstream outputFileForCheck;
        string str;
        outputFile.open(nameFile, ios_base::app);
        outputFileForCheck.open(nameFile, ios_base::in);
        if (outputFileForCheck.is_open()) {
            outputFile << answer;
            outputFile << endl;
        }
        outputFile.close();
        outputFileForCheck.close();
    }

};

class DirectoreTasks{
private:
    vector<TaskFormat*> formats;
public:

    void addTaskFormat(TaskFormat &newFormatTask) {
        formats.push_back(&newFormatTask);
    }

    TaskFormat* getFormatTask(size_t HowFormatSolve){
        return formats[HowFormatSolve - 1];
    }

};

class Parser{
public:

    int *takeVariabels(string exercize){
        int *var;


        return var;
    }

};

class CalculateTask{
private:
    TaskFormat *CurrentTaskFormat;
public:

    CalculateTask(TaskFormat &f) {
        CurrentTaskFormat = &f;
    }

    void setFormatTask(DirectoreTasks &DirectoreTasks, DirectoreFile &DirectoreFiles, size_t HowFormatSolve) {
        CurrentTaskFormat = DirectoreTasks.getFormatTask(HowFormatSolve);
    }

    double calculateThisTask(DirectoreFile DirectoreFiles, DirectoreTasks DirectoreTasks, ReaderFile Reader, Parser ParserVariabels, size_t HowFormatSolve){
        setFormatTask(DirectoreTasks, DirectoreFiles, HowFormatSolve);
        return CurrentTaskFormat->calculateTask(ParserVariabels.takeVariabels(Reader.takeExample(DirectoreFiles, HowFormatSolve)));
    }

};

class Task1 : public TaskFormat{
public:

    double calculateTask(int *variabels) override {
        double answer;
        if ((variabels[1] * variabels[1] - 4 * variabels[0] * variabels[2]) >= 0) {
            answer = ((-1 * variabels[1] + sqrt(variabels[1] * variabels[1] - 4 * variabels[0] * variabels[2])) / (2 * variabels[0]));
            answer = ((-1 * variabels[1] - sqrt(variabels[1] * variabels[1] - 4 * variabels[0] * variabels[2])) / (2 * variabels[0]));
        }
        return answer;
    }

};

class Task2 : public  TaskFormat{
public:

    double calculateTask(int *variabels) override {
        double answer;
        answer = (variabels[0] + variabels[1]);
        return answer;
    }

};

class Task3 : public  TaskFormat{
public:

    double calculateTask(int *variabels) override {
        double answer;
        answer = (variabels[0] - variabels[1]);
        return answer;
    }

};

class Task4 : public  TaskFormat{
public:

    double calculateTask(int *variabels) override {
        double answer;
        answer = (variabels[0] * variabels[1]);
        return answer;
    }

};

class Task5 : public  TaskFormat{
public:

    double calculateTask(int *variabels) override {
        double answer;
        answer = (variabels[0] / variabels[1]);
        return answer;
    }

};

class Task6 : public  TaskFormat{
public:

    double calculateTask(int *variabels) override {
        double answer;
        answer = (((-1 * variabels[1]) + variabels[2]) / variabels[0]);
        return answer;
    }

};

class TaskOPZ : public TaskFormat{
public:

    double calculateTask(int *variabels) override {
        double answer;

        return answer;
    }

};

int main() {
    Task1 TaskExe1;
    Task2 TaskExe2;
    Task3 TaskExe3;
    Task4 TaskExe4;
    Task5 TaskExe5;
    Task6 TaskExe6;

    size_t amount = 7;

    DirectoreFile DirectoreFiles(amount);
    // Добавляем в вектор файлов, которые можно решить
    DirectoreFiles.addFile("/home/kirillpavyk/DirectoreHome/ProjectC++Repozitorii/Kirill.Mokhovichenko/oopTaskEXe/file/exer1.txt");      // vector<string> files; formats[0]
    DirectoreFiles.addFile("/home/kirillpavyk/DirectoreHome/ProjectC++Repozitorii/Kirill.Mokhovichenko/oopTaskEXe/file/exer2.txt");      // vector<string> files; formats[1]
    DirectoreFiles.addFile("/home/kirillpavyk/DirectoreHome/ProjectC++Repozitorii/Kirill.Mokhovichenko/oopTaskEXe/file/exer3.txt");      // vector<string> files; formats[2]
    DirectoreFiles.addFile("/home/kirillpavyk/DirectoreHome/ProjectC++Repozitorii/Kirill.Mokhovichenko/oopTaskEXe/file/exer4.txt");      // vector<string> files; formats[3]
    DirectoreFiles.addFile("/home/kirillpavyk/DirectoreHome/ProjectC++Repozitorii/Kirill.Mokhovichenko/oopTaskEXe/file/exer5.txt");      // vector<string> files; formats[4]
    DirectoreFiles.addFile("/home/kirillpavyk/DirectoreHome/ProjectC++Repozitorii/Kirill.Mokhovichenko/oopTaskEXe/file/exer6.txt");      // vector<string> files; formats[5]
    DirectoreFiles.addFile("/home/kirillpavyk/DirectoreHome/ProjectC++Repozitorii/Kirill.Mokhovichenko/oopTaskEXe/file/output.txt");     // vector<string> files; formats[6]

    DirectoreTasks DirectoreTasks;
    // Добавляем в вектор форматов перимеры, которые можно решить из файлов
    DirectoreTasks.addTaskFormat(TaskExe1);    // vector<TaskFormats*> formats; formats[0]
    DirectoreTasks.addTaskFormat(TaskExe2);    // vector<TaskFormats*> formats; formats[1]
    DirectoreTasks.addTaskFormat(TaskExe3);    // vector<TaskFormats*> formats; formats[2]
    DirectoreTasks.addTaskFormat(TaskExe4);    // vector<TaskFormats*> formats; formats[3]
    DirectoreTasks.addTaskFormat(TaskExe5);    // vector<TaskFormats*> formats; formats[4]
    DirectoreTasks.addTaskFormat(TaskExe6);    // vector<TaskFormats*> formats; formats[5]

    ReaderFile ReadingClass;
    WriteAnAnswer WriteClass;
    Parser ParserVariabels;

    CalculateTask CalculatorTasks(TaskExe1);

    for (size_t i = 1; i < amount; i++) {
        WriteClass.printSolveOnTheScreen(CalculatorTasks.calculateThisTask(DirectoreFiles, DirectoreTasks, ReadingClass, ParserVariabels, i));
        WriteClass.printSolveOnTheFile(DirectoreFiles.getFiles(amount), CalculatorTasks.calculateThisTask(DirectoreFiles, DirectoreTasks, ReadingClass, ParserVariabels, i));
    }


    return 0;
}