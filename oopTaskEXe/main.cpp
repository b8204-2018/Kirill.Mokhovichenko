#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <vector>
#include <stack>
#include <exception>

using namespace std;

class SolverTaskFormat {
public:
    virtual double *calculateTask(double *variabels) = 0;
};

class CollectionFiles {
private:
    vector<string> nameFiles;
public:
    int addFile(const string nameFile) {
        ifstream yourFile;
        yourFile.open(nameFile, ios_base::in);
        if (!yourFile.is_open())
            throw invalid_argument(nameFile);
        if (yourFile.is_open()) {
            size_t format(0);
            yourFile >> format;
            yourFile.close();
            nameFiles.push_back(nameFile);
            return 1;
        }
    }

    string getFile(size_t HowFormatSolve) const {
        ifstream yourFile;
        yourFile.open(nameFiles[HowFormatSolve - 1], ios_base::in);
        if (!yourFile.is_open())
            throw length_error(to_string(HowFormatSolve));
        yourFile.close();
        return nameFiles[HowFormatSolve - 1];
    }
};

class ReaderFile {
public:
    string takeExample(const CollectionFiles &CollectionFiles, size_t HowFormatSolve) const {
        string example;
        ifstream yourFile;
        yourFile.open(CollectionFiles.getFile(HowFormatSolve), ios_base::in);
        if (!yourFile.is_open())
            throw invalid_argument(CollectionFiles.getFile(HowFormatSolve));
        if (yourFile.is_open()) {
            size_t format(0);
            yourFile >> format;
            yourFile >> example;
            yourFile.close();
        }
        return example;
    }

    int howFormatTaskInFile(const CollectionFiles &CollectionFiles, size_t HowFormatSolve) const {
        size_t format(0);
        ifstream yourFile;
        yourFile.open(CollectionFiles.getFile(HowFormatSolve), ios_base::in);
        if (!yourFile.is_open())
            throw invalid_argument(CollectionFiles.getFile(HowFormatSolve));
        if (yourFile.is_open()) {
            yourFile >> format;
            yourFile.close();
        }
        return format;
    }
};

class InterfacePrintAnswer {
public:
    virtual void printSolver(double *answer, string nameFile) = 0;
};

class PrintSolver {
    InterfacePrintAnswer *Writer;
public:

    void setWriter(InterfacePrintAnswer &Writer) {
        this->Writer = &Writer;
    }

    void printSolver(double *answer, string nameFile){
        Writer->printSolver(answer, nameFile);
    }
};

class WriteOnTheScreen : public InterfacePrintAnswer {
public:
    void printSolver(double *answer, string nameFile) {
        cout << "Решение из файла: \"" << nameFile << "\"" << endl;
        for (size_t i = 1; i <= answer[0]; i++) {
            cout << "Ответ " << i << " :  " << answer[i] << endl;
        }
        cout << endl;
    }

};

class WriteOnTheFile : public InterfacePrintAnswer {
private:
    string nameFile;
public:
    WriteOnTheFile(string nameFile) {
        this->nameFile = nameFile;
    }

    void printSolver(double *answer, string numbFile) {
        ofstream outputFile;
        ifstream outputFileForCheck;
        string str;
        outputFile.open(nameFile, ios_base::app);
        outputFileForCheck.open(nameFile, ios_base::in);
        if (outputFileForCheck.is_open()) {
            outputFile << "Решение из файла: \"" << numbFile << "\"" << endl;
            for(size_t i = 1; i <= answer[0]; i++) {
                outputFile << "Ответ " << i << " :  " << answer[i] << endl;
            }
            outputFile << endl;
        }
        outputFile.close();
        outputFileForCheck.close();
    }

    void setFile(string nameFile){
        this->nameFile = nameFile;
    }
};

class SolversCollection {
private:
    vector<SolverTaskFormat*> formats;
public:
    void addTaskFormat(SolverTaskFormat &newFormatTask) {
        formats.push_back(&newFormatTask);
    }

    SolverTaskFormat* getFormatTask(size_t HowFormatSolve) const {
        if (formats[HowFormatSolve - 1] == nullptr)
            throw out_of_range(to_string(HowFormatSolve));
        return formats[HowFormatSolve - 1];
    }
};

class Parser {
    int isNum(char symbol) const {                // Ну да у Полины, а кому сейчас легко?
        if (symbol >= 48 && symbol <= 57) {
            return -(48 - symbol);
        }
        return -1;
    }
public:
    double *takeVariabels(string exercize) const {
        double *vars = new double[5];
        int count = 0, i = 0;
        while (exercize[i] != '\0') {
            if (isNum(exercize[i]) == -1) {
                if ((exercize[i] == 'x') && (exercize[i + 1] == '2'))
                    i++;
                i++;
            }
            else {
                int temp = 0;
                int j = i;
                for (j; isNum(exercize[j]) != -1; j++) {
                    temp = temp * 10 + isNum(exercize[j]);
                }
                if (i > 0) {
                    if (exercize[i - 1] == '-') {
                        temp = -temp;
                    }
                }
                vars[count] = temp;
                count++;
                i = j;
            }
        }
        return vars;
    }
};

class CalculateTask {
private:
    SolverTaskFormat *CurrentTaskFormat;
public:
    CalculateTask(SolverTaskFormat &f) {
        CurrentTaskFormat = &f;
    }

    void setFormatTask(const SolversCollection &SolversCollection, const CollectionFiles &CollectionFiles, const ReaderFile &Reader, size_t HowFormatSolve) {
        CurrentTaskFormat = SolversCollection.getFormatTask(Reader.howFormatTaskInFile(CollectionFiles, HowFormatSolve));
    }

    double *calculateThisTask(const CollectionFiles &CollectionFiles, const SolversCollection &SolversCollection, const ReaderFile &Reader, const Parser &ParserVariabels, size_t HowFormatSolve) {
        setFormatTask(SolversCollection, CollectionFiles,  Reader, HowFormatSolve);
        return CurrentTaskFormat->calculateTask(ParserVariabels.takeVariabels(Reader.takeExample(CollectionFiles, HowFormatSolve)));
    }
};

class SolverTask1 : public SolverTaskFormat {
public:
    double *calculateTask(double *variabels) override {
        double *answer = new double[3];
        answer[0] = 2;
        if ((variabels[1] * variabels[1] - 4 * variabels[0] * variabels[2]) >= 0) {
            answer[1] = (-1 * variabels[1] + sqrt(variabels[1] * variabels[1] - 4 * variabels[0] * variabels[2])) / (2 * variabels[0]);
            answer[2] = (-1 * variabels[1] - sqrt(variabels[1] * variabels[1] - 4 * variabels[0] * variabels[2])) / (2 * variabels[0]);
        }
        return answer;
    }
};

class SolverTask2 : public SolverTaskFormat {
public:
    double *calculateTask(double *variabels) override {
        double *answer = new double[2];
        answer[0] = 1;
        answer[1] = (variabels[0] + variabels[1]);
        return answer;
    }
};

class SolverTask3 : public SolverTaskFormat{
public:
    double *calculateTask(double *variabels) override {
        double *answer = new double[2];
        answer[0] = 1;
        answer[1] = (variabels[0] - variabels[1]);
        return answer;
    }
};

class SolverTask4 : public SolverTaskFormat{
public:
    double *calculateTask(double *variabels) override {
        double *answer = new double[2];
        answer[0] = 1;
        answer[1] = (variabels[0] * variabels[1]);
        return answer;
    }
};

class SolverTask5 : public  SolverTaskFormat {
public:
    double *calculateTask(double *variabels) override {
        double *answer = new double[2];
        answer[0] = 1;
        answer[1] = (variabels[0] / variabels[1]);
        return answer;
    }
};

class SolverTask6 : public SolverTaskFormat {
public:
    double *calculateTask(double *variabels) override {
        double *answer = new double[2];
        answer[0] = 1;
        answer[1] = (((-1 * variabels[1]) + variabels[2]) / variabels[0]);
        return answer;
    }
};

class SolverTaskOPZ : public SolverTaskFormat {
public:
    double *calculateTask(double *variabels) override {
        double *answer = new double[2];
//        int calculate(string str_in) {
//            Stack<int> val_stack; //стек
//            int n1, n2, res;
//            for(i = 0; i<str_in.length(); ++i) {
//                if(isNumber(str_out[i])) {
//                    val_stack.push(str_out[i]);
//                }
//                else {
//                    n2 = val_stack.pop();
//                    n1 = val_stack.pop();
//                    switch(str_out[i]) {
//                        case '+': res = n1 + n2; break;
//                        case '-': res = n1 - n2; break;
//                        case '*': res = n1 * n2; break;
//                        case '/': res = n1 / n2; break;
//                        default: cout<<"Ошибка !\n";
//                    }
//                    val_stack.push(res);
//                }
//            }
//            return val_stack.pop();
//        }
        return answer;
    }
};

int main() {
    SolverTask1 TaskExe1;
    SolverTask2 TaskExe2;
    SolverTask3 TaskExe3;
    SolverTask4 TaskExe4;
    SolverTask5 TaskExe5;
    SolverTask6 TaskExe6;
    SolverTaskOPZ TaskExeOPZ;

    size_t amountFiles = 0;

    CollectionFiles CollectionsFiles;

    try {
        amountFiles += CollectionsFiles.addFile("/home/kirillpavyk/DirectoreHome/ProjectC++Repozitorii/Kirill.Mokhovichenko/oopTaskEXe/file/exer4.txt");
        amountFiles += CollectionsFiles.addFile("/home/kirillpavyk/DirectoreHome/ProjectC++Repozitorii/Kirill.Mokhovichenko/oopTaskEXe/file/exer1.txt");
        amountFiles += CollectionsFiles.addFile("/home/kirillpavyk/DirectoreHome/ProjectC++Repozitorii/Kirill.Mokhovichenko/oopTaskEXe/file/exer2.txt");
        amountFiles += CollectionsFiles.addFile("/home/kirillpavyk/DirectoreHome/ProjectC++Repozitorii/Kirill.Mokhovichenko/oopTaskEXe/file/exer7.txt");
        amountFiles += CollectionsFiles.addFile("/home/kirillpavyk/DirectoreHome/ProjectC++Repozitorii/Kirill.Mokhovichenko/oopTaskEXe/file/exer3.txt");
        amountFiles += CollectionsFiles.addFile("/home/kirillpavyk/DirectoreHome/ProjectC++Repozitorii/Kirill.Mokhovichenko/oopTaskEXe/file/exer6.txt");
        amountFiles += CollectionsFiles.addFile("/home/kirillpavyk/DirectoreHome/ProjectC++Repozitorii/Kirill.Mokhovichenko/oopTaskEXe/file/exer5.txt");


    }

    catch(invalid_argument(e)) {
        cout << "ERROR! \"" << e.what() << "\" file was not found!" << endl;
        return 0;
    }

    SolversCollection CollectionsSolversTask;

    CollectionsSolversTask.addTaskFormat(TaskExe1);    // vector<TaskFormats*> formats; formats[0]
    CollectionsSolversTask.addTaskFormat(TaskExe2);    // vector<TaskFormats*> formats; formats[1]
    CollectionsSolversTask.addTaskFormat(TaskExe3);    // vector<TaskFormats*> formats; formats[2]
    CollectionsSolversTask.addTaskFormat(TaskExe4);    // vector<TaskFormats*> formats; formats[3]
    CollectionsSolversTask.addTaskFormat(TaskExe5);    // vector<TaskFormats*> formats; formats[4]
    CollectionsSolversTask.addTaskFormat(TaskExe6);    // vector<TaskFormats*> formats; formats[5]
    CollectionsSolversTask.addTaskFormat(TaskExeOPZ);  // vector<TaskFormats*> formats; formats[6]

    string outputFile = "/home/kirillpavyk/DirectoreHome/ProjectC++Repozitorii/Kirill.Mokhovichenko/oopTaskEXe/file/output.txt";

    ReaderFile ReadingClass;

    PrintSolver PrintAnswer;
    WriteOnTheFile WriteFile(outputFile);
    WriteOnTheScreen WriteScreen;
    Parser ParserVariabels;
    CalculateTask CalculatorTasks(TaskExe1);

    PrintAnswer.setWriter(WriteFile);
    try {
        for (size_t i = 1; i <= amountFiles; i++)
            PrintAnswer.printSolver(CalculatorTasks.calculateThisTask(CollectionsFiles, CollectionsSolversTask, ReadingClass,ParserVariabels, i), CollectionsFiles.getFile(i));
    }
    catch(length_error(e)) {
        cout << "ERROR! \" The file from the directory of files was not found in the cell \"" << e.what() << "\", check that the function parameter is correct." << endl;
        return 0;
    }

    PrintAnswer.setWriter(WriteScreen);
    try {
        for (size_t i = 1; i <= amountFiles; i++)
            PrintAnswer.printSolver(CalculatorTasks.calculateThisTask(CollectionsFiles, CollectionsSolversTask, ReadingClass,ParserVariabels, i), CollectionsFiles.getFile(i));
    }
    catch(length_error(e)) {
        cout << "ERROR! \" The file from the directory of files was not found in the cell \"" << e.what() << "\", check that the function parameter is correct." << endl;
        return 0;
    }

}