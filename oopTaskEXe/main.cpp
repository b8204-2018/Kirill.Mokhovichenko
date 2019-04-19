#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <vector>

using namespace std;

class TaskFormat{
public:
    virtual void calculateTask() = 0;
    virtual void getConstantsFromFile(string file) = 0;
    virtual void printSolveOnTheScreen() = 0;
    virtual void printSolveOnTheFile(string file) = 0;
};

class CalculateTask{
private:
    vector<TaskFormat*> formats;
    TaskFormat *CurrentTaskFormat;
public:
    CalculateTask(TaskFormat &f) {
        CurrentTaskFormat = &f;
    }

    void addTaskFormat(TaskFormat &newFormatTask) {
        formats.push_back(&newFormatTask);
    }

    void setFormatTask(size_t HowFormatSolve) {
        CurrentTaskFormat = formats[HowFormatSolve - 1];
    }

    void printerAnswerOnTheScreen() {
        CurrentTaskFormat->calculateTask();
        CurrentTaskFormat->printSolveOnTheScreen();
    }

    void printerAnswerOnTheFile(string nameFile){
        CurrentTaskFormat->printSolveOnTheFile(nameFile);
    }
};

class Task1 : public TaskFormat{
private:
    int a, b, c;
    double x1, x2;
public:
    void getConstantsFromFile(string name) override {
        ifstream yourFile;
        yourFile.open(name, ios_base::in);
        if (yourFile.is_open()){
            size_t i = 0, numbConst = 0;
            string str, constantValue;
            getline(yourFile, str);
            getline(yourFile, str);
            str += " \n";
            while(str[i] != '\n'){
                constantValue += str[i];
                if ((str[i] == 'x')||(str[i] == '=')||(str[i+1] == '\n')){
                    numbConst++;
                    if (numbConst == 1){
                        a = stoi(constantValue);
                    }
                    if (numbConst == 2){
                        b = stoi(constantValue);
                    }
                    if (numbConst == 3){
                        c = stoi(constantValue);
                    }
                    if ((str[i] == 'x')&&(numbConst == 1)){
                        i++;
                    }
                    constantValue.clear();
                }
                i++;
            }
            yourFile.close();
        }
    }

    void calculateTask() override {
        if((b*b - 4*a*c) >= 0){
            calculateX1();
            calculateX2();
        }
    }

    void calculateX1(){
        if((b*b - 4*a*c) >= 0){
            x1 = ( -1*b + sqrt(b*b - 4*a*c) ) / (2 * a);
        }
    }

    void calculateX2(){
        if((b*b - 4*a*c) >= 0){
            x2 = ( -1*b - sqrt(b*b - 4*a*c) ) / (2 * a);
        }
    }

    void printSolveOnTheScreen() override {
        cout << "Solve task1 :" << endl;
        cout << a << "x2+" << b << "x+" << c << "=0" << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
        cout << endl;
    }

    void printSolveOnTheFile(string file) override {
        ofstream outputFile;
        ifstream outputFileForCheck;
        string str;
        outputFile.open(file, ios_base::app);
        outputFileForCheck.open(file, ios_base::in);
        if (outputFileForCheck.is_open()) {
            outputFile << "Solve task1 :" << endl;
            outputFile << a << "x2+" << b << "x+" << c << "=0" << endl;
            outputFile << "x1 = " << x1 << endl;
            outputFile << "x2 = " << x2 << endl;
            outputFile << endl;
        }
        outputFile.close();
        outputFileForCheck.close();
    }
};

class Task2 : public  TaskFormat{
private:
    int a,b;
    double d;
public:
    void getConstantsFromFile(string name) override {
        ifstream yourFile;
        yourFile.open(name, ios_base::in);
        if (yourFile.is_open()){
            size_t i = 0, numbConst = 0;
            string str, constantValue;
            getline(yourFile, str);
            getline(yourFile, str);
            str += " \n";
            while(str[i] != '\n'){
                constantValue += str[i];
                if ((str[i] == '+')||(str[i+1] == '\n')){
                    numbConst++;
                    if (numbConst == 1){
                        a = stoi(constantValue);
                    }
                    if (numbConst == 2){
                        b = stoi(constantValue);
                    }
                    constantValue.clear();
                }
                i++;
            }
            yourFile.close();
        }
    }

    void calculateTask() override {
        d = a + b;

    }

    void printSolveOnTheScreen() override {
        cout << "Solve task2 :" << endl;
        cout << a << "+" << b << "=" << d << endl;
        cout << endl;
    }

    void printSolveOnTheFile(string file) override {
        ofstream outputFile;
        ifstream outputFileForCheck;
        string str;
        outputFile.open(file, ios_base::app);
        outputFileForCheck.open(file, ios_base::in);
        if (outputFileForCheck.is_open()) {
            outputFile << "Solve task2 :" << endl;
            outputFile << a << "+" << b << "=" << d << endl;
            outputFile << endl;
        }
        outputFile.close();
        outputFileForCheck.close();
    }
};

class Task3 : public  TaskFormat{
private:
    double a,b;
    double d;
public:
    void getConstantsFromFile(string name) override {
        ifstream yourFile;
        yourFile.open(name, ios_base::in);
        if (yourFile.is_open()){
            size_t i = 0, numbConst = 0;
            string str, constantValue;
            getline(yourFile, str);
            getline(yourFile, str);
            str += " \n";
            while(str[i] != '\n'){
                constantValue += str[i];
                if ((str[i] == '-')||(str[i+1] == '\n')){
                    numbConst++;
                    if (numbConst == 1){
                        a = stoi(constantValue);
                    }
                    if (numbConst == 2){
                        b = stoi(constantValue);
                    }
                    constantValue.clear();
                }
                i++;
            }
            yourFile.close();
        }
    }

    void calculateTask() override {
        d = a - b;
    }

    void printSolveOnTheScreen() override {
        cout << "Solve task3 :" << endl;
        cout << a << "-" << b << "=" << d << endl;
        cout << endl;
    }

    void printSolveOnTheFile(string file) override {
        ofstream outputFile;
        ifstream outputFileForCheck;
        string str;
        outputFile.open(file, ios_base::app);
        outputFileForCheck.open(file, ios_base::in);
        if (outputFileForCheck.is_open()) {
                    outputFile << "Solve task3 :" << endl;
                    outputFile << a << "-" << b << "=" << d << endl;
                    outputFile << endl;
        }
        outputFile.close();
        outputFileForCheck.close();
    }
};

class Task4 : public  TaskFormat{
private:
    double a,b;
    double d;
public:
    void getConstantsFromFile(string name) override {
        ifstream yourFile;
        yourFile.open(name, ios_base::in);
        if (yourFile.is_open()){
            size_t i = 0, numbConst = 0;
            string str, constantValue;
            getline(yourFile, str);
            getline(yourFile, str);
            str += " \n";
            while(str[i] != '\n'){
                constantValue += str[i];
                if ((str[i] == '*')||(str[i+1] == '\n')){
                    numbConst++;
                    if (numbConst == 1){
                        a = stoi(constantValue);
                    }
                    if (numbConst == 2){
                        b = stoi(constantValue);
                    }
                    constantValue.clear();
                }
                i++;
            }
            yourFile.close();
        }
    }

    void calculateTask() override {
        d = a*b;
    }

    void printSolveOnTheScreen() override {
        cout << "Solve task4 :" << endl;
        cout << a << "*" << b << "=" << d << endl;
        cout << endl;
    }

    void printSolveOnTheFile(string file) override {
        ofstream outputFile;
        ifstream outputFileForCheck;
        string str;
        outputFile.open(file, ios_base::app);
        outputFileForCheck.open(file, ios_base::in);
        if (outputFileForCheck.is_open()) {

            outputFile << "Solve task4 :" << endl;
            outputFile << a << "*" << b << "=" << d << endl;
            outputFile << endl;
        }
        outputFile.close();
        outputFileForCheck.close();
    }
};

class Task5 : public  TaskFormat{
    double a,b;
    double d;
public:
    void getConstantsFromFile(string name) override {
        ifstream yourFile;
        yourFile.open(name, ios_base::in);
        if (yourFile.is_open()){
            size_t i = 0, numbConst = 0;
            string str, constantValue;
            getline(yourFile, str);
            getline(yourFile, str);
            str += " \n";
            while(str[i] != '\n'){
                constantValue += str[i];
                if ((str[i] == '/')||(str[i+1] == '\n')){
                    numbConst++;
                    if (numbConst == 1){
                        a = stoi(constantValue);
                    }
                    if (numbConst == 2){
                        b = stoi(constantValue);
                    }
                    constantValue.clear();
                }
                i++;
            }
            yourFile.close();
        }
    }

    void calculateTask() override {
        d = a/b;
    }

    void printSolveOnTheScreen() override {
        cout << "Solve task5 :" << endl;
        cout << a << "/" << b << "=" << d << endl;
        cout << endl;
    }

    void printSolveOnTheFile(string file) override {
        ofstream outputFile;
        ifstream outputFileForCheck;
        string str;
        outputFile.open(file, ios_base::app);
        outputFileForCheck.open(file, ios_base::in);
        if (outputFileForCheck.is_open()) {
            outputFile << "Solve task5 :" << endl;
            outputFile << a << "/" << b << "=" << d << endl;
            outputFile << endl;
        }
        outputFile.close();
        outputFileForCheck.close();
    }
};

class Task6 : public  TaskFormat{
    int a, b, c;
    double x;
public:
    void getConstantsFromFile(string name) override {
        ifstream yourFile;
        yourFile.open(name, ios_base::in);
        if (yourFile.is_open()){
            size_t i = 0, numbConst = 0;
            string str, constantValue;
            getline(yourFile, str);
            getline(yourFile, str);
            str += " \n";
            while(str[i] != '\n'){
                constantValue += str[i];
                if ((str[i] == 'x')||(str[i] == '=')||(str[i+1] == '\n')){
                    numbConst++;
                    if (numbConst == 1){
                        a = stoi(constantValue);
                    }
                    if (numbConst == 2){
                        b = stoi(constantValue);
                    }
                    if (numbConst == 3){
                        c = stoi(constantValue);
                    }
                    constantValue.clear();
                }
                i++;
            }
            yourFile.close();
        }
    }

    void calculateTask() override {
        x = ((-1*b) + c) / a;
    }

    void printSolveOnTheScreen() override {
        cout << "Solve task6 :" << endl;
        cout << a << "x+" << b << "=" << c << endl;
        cout << "x = " << x << endl;
        cout << endl;
    }

    void printSolveOnTheFile(string file) override {
        ofstream outputFile;
        ifstream outputFileForCheck;
        string str;
        outputFile.open(file, ios_base::app);
        outputFileForCheck.open(file, ios_base::in);
        if (outputFileForCheck.is_open()) {
            outputFile << "Solve task6 :" << endl;
            outputFile << a << "x+" << b << "=" << c << endl;
            outputFile << "x = " << x << endl;
            outputFile << endl;
        }
        outputFile.close();
        outputFileForCheck.close();
    }
};

size_t findOutTaskFromFile(string name){
    ifstream yourFile;
    yourFile.open(name, ios_base::in);
    if (yourFile.is_open()){
        size_t format(0);
        yourFile >> format;
        yourFile.close();
        return  format;
    }
    else{
        cout << "Error, File not found!";
        yourFile.close();
        return 0;
    }
}

void completeAllSampleFormats(CalculateTask &Calculator, TaskFormat *formatsTask,string *allFiles, size_t amount){
    for (size_t i = 0; i < amount - 1 ; i++){
        Calculator.addTaskFormat(formatsTask[i]);
        formatsTask[i].getConstantsFromFile(allFiles[i]);
    }
}

void solveAllTasksFormats(CalculateTask &Calculator, string *allFiles, size_t amount){
    for(size_t i = 0; i < amount - 1 ; i++){
        Calculator.setFormatTask(findOutTaskFromFile(allFiles[i]));
        Calculator.printerAnswerOnTheScreen();
        Calculator.printerAnswerOnTheFile(allFiles[amount - 1]);
    }
}

int main() {
    Task1 File1;
    Task2 File2;
    Task3 File3;
    Task4 File4;
    Task5 File5;
    Task6 File6;
    string file1, file2, file3, file4, file5, file6, outputFile;
    file1 = "C:/ProjectC++Repozitorii/Kirill.Mokhovichenko/oopTaskEXe/file/exer1.txt";
    file2 = "C:/ProjectC++Repozitorii/Kirill.Mokhovichenko/oopTaskEXe/file/exer2.txt";
    file3 = "C:/ProjectC++Repozitorii/Kirill.Mokhovichenko/oopTaskEXe/file/exer3.txt";
    file4 = "C:/ProjectC++Repozitorii/Kirill.Mokhovichenko/oopTaskEXe/file/exer4.txt";
    file5 = "C:/ProjectC++Repozitorii/Kirill.Mokhovichenko/oopTaskEXe/file/exer5.txt";
    file6 = "C:/ProjectC++Repozitorii/Kirill.Mokhovichenko/oopTaskEXe/file/exer6.txt";
    outputFile = "C:/ProjectC++Repozitorii/Kirill.Mokhovichenko/oopTaskEXe/file/output.txt";

    size_t howAmountFormatsTask = 7;
    string allFiles[7] = {file1, file2, file3, file4, file5, file6, outputFile};
    CalculateTask Calculator(File1);

    // Добавляем в вектор форматов перимеры, которые можно решить из файлов
    Calculator.addTaskFormat(File1);    // vector<TaskFormats*> formats; formats[0]
    Calculator.addTaskFormat(File2);    // vector<TaskFormats*> formats; formats[1]
    Calculator.addTaskFormat(File3);    // vector<TaskFormats*> formats; formats[2]
    Calculator.addTaskFormat(File4);    // vector<TaskFormats*> formats; formats[3]
    Calculator.addTaskFormat(File5);    // vector<TaskFormats*> formats; formats[4]
    Calculator.addTaskFormat(File6);    // vector<TaskFormats*> formats; formats[5]

    File1.getConstantsFromFile(file1);
    File2.getConstantsFromFile(file2);
    File3.getConstantsFromFile(file3);
    File4.getConstantsFromFile(file4);
    File5.getConstantsFromFile(file5);
    File6.getConstantsFromFile(file6);
    //completeAllSampleFormats(Calculator, allFormats , howAmountFormatsTask);
    solveAllTasksFormats(Calculator, allFiles, howAmountFormatsTask);

    return 0;
}