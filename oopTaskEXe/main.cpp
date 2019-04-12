#include <iostream>
#include "string.h"
#include <fstream>
#include <math.h>
#include <vector>

using namespace std;

class TaskFormat{
public:
    virtual double calculateTask() = 0;
    virtual void getConstantsFromFile(string file) = 0;
};

class PrintAnswer{
public:
    virtual void printerAnswer() = 0;
};

class CalculateTask : public PrintAnswer {
private:
    vector<TaskFormat*> formats;
    TaskFormat *CurrentTaskFormat;
public:
    CalculateTask(TaskFormat &f){
        CurrentTaskFormat = &f;
    }

    void addTaskFormat(TaskFormat &newFormatTask){
        formats.push_back(&newFormatTask);
    }

    void setFormatTask(size_t HowFormatSolve) {
        CurrentTaskFormat = formats[HowFormatSolve - 1];
    }

    void printerAnswer() {
        cout << CurrentTaskFormat->calculateTask() << endl;
    }
};

class Task1 : public TaskFormat{
private:
    double a, b, c, x1, x2;
public:
    void getConstantsFromFile(string file) override {

    }

    double calculateTask() override {
        if((b*b - 4*a*c) >= 0){
            calculateX1();
            calculateX2();
        }
        else{
            try {
                throw 666;
            }
            catch(int i){
                cout << "Error №" << i << " - diskriminant men'she 0. Resheniia net." << endl;
            }
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

    void printAnswer(){
        cout << "X1 = " << x1 << endl;
        cout << "X2 = " << x2 << endl;
    }



};

class Task2 : public  TaskFormat{
private:
    double a,b;
public:
    void getConstantsFromFile(string file) override {

    }

    double calculateTask() override {
        double d;
        d = a + b;
        return d;
    }
};

class Task3 : public  TaskFormat{
private:
    double a,b;
public:
    void getConstantsFromFile(string file) override {

    }

    double calculateTask() override {
        double d;
        d = a - b;
        return d;
    }
};

class Task4 : public  TaskFormat{
private:
    double a,b;
public:
    void getConstantsFromFile(string file) override {

    }

    double calculateTask() override {
        double d;
        d = a*b;
        return d;
    }
};

class Task5 : public  TaskFormat{
    double a,b;
public:
    void getConstantsFromFile(string file) override {

    }

    double calculateTask() override {
        double d;
        d = a/b;
        return d;
    }
};

class Task6 : public  TaskFormat{
    double a,b;
public:
    void getConstantsFromFile(string file) override {

    }

    double calculateTask() override {
        double x;
        x = (-1*b) / a;
        return x;
    }
};

size_t changeTaskFromFile(string name){
    ifstream yourFile;
    yourFile.open(name, ios_base::in);
    if (yourFile.is_open()){
        size_t format(0);
        yourFile >> format;
        cout << "Format task: " << format << endl;
        yourFile.close();
        return  format;
    }
    else{
        cout << "Error, File not found!";
        yourFile.close();
        return 0;
    }
}


int main() {
    Task1 File1;
    Task2 File2;
    Task3 File3;
    Task4 File4;
    Task5 File5;
    Task6 File6;
    string file1,file2,file3,file4,file5,file6;
    file1 = "C:/ProjectC++Repozitorii/Kirill.Mokhovichenko/oopTaskEXe/file/exer1.txt";
    file2 = "C:/ProjectC++Repozitorii/Kirill.Mokhovichenko/oopTaskEXe/file/exer2.txt";
    file3 = "C:/ProjectC++Repozitorii/Kirill.Mokhovichenko/oopTaskEXe/file/exer3.txt";
    file4 = "C:/ProjectC++Repozitorii/Kirill.Mokhovichenko/oopTaskEXe/file/exer4.txt";
    file5 = "C:/ProjectC++Repozitorii/Kirill.Mokhovichenko/oopTaskEXe/file/exer5.txt";
    file6 = "C:/ProjectC++Repozitorii/Kirill.Mokhovichenko/oopTaskEXe/file/exer6.txt";

    CalculateTask Calculator(File1);
    // Добавляем в вектор форматов перимеры, которые можно решить из файлов
    Calculator.addTaskFormat(File6);    // vector<TaskFormats*> formats; formats[5]
    Calculator.addTaskFormat(File5);    // vector<TaskFormats*> formats; formats[4]
    Calculator.addTaskFormat(File4);    // vector<TaskFormats*> formats; formats[3]
    Calculator.addTaskFormat(File3);    // vector<TaskFormats*> formats; formats[2]
    Calculator.addTaskFormat(File2);    // vector<TaskFormats*> formats; formats[1]
    Calculator.addTaskFormat(File1);    // vector<TaskFormats*> formats; formats[0]

    //Узнаем какой формат примера в файле file1, и ставим в "Калькуляторе" какой пример решаем. (Устанавливаем формат)
    Calculator.setFormatTask(changeTaskFromFile(file1));
    //Выводим ответ примера.
    Calculator.printerAnswer();

    Calculator.setFormatTask(changeTaskFromFile(file2));
    Calculator.printerAnswer();

    Calculator.setFormatTask(changeTaskFromFile(file3));
    Calculator.printerAnswer();

    Calculator.setFormatTask(changeTaskFromFile(file4));
    Calculator.printerAnswer();

    Calculator.setFormatTask(changeTaskFromFile(file5));
    Calculator.printerAnswer();

    Calculator.setFormatTask(changeTaskFromFile(file6));
    Calculator.printerAnswer();
    
    return 0;
}