#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <fstream>
#include <iostream>
#include <locale>
#include <Windows.h>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <vector>
#include <bitset>
#include <tuple>
#include <map>
#include <list>
#include <iterator>

#ifndef UNTITLED_TASKS_RK1_H
#define UNTITLED_TASKS_RK1_H

using namespace std;

// 1

class WorkWithFile {
private:
    char* dataOfFile;
    void readFromFile(const char* fileName);
    void prepareTestFile(const char* fileName);
public:
    WorkWithFile();
    ~WorkWithFile();
    void writeStatInfoToFile(const char* outFile);
};

// 2

char* convertDecToBin(int number);
void writeToFile(const char& fileName, const char* strNum);

// 3

char* convertBinToHex(const char* binNum);

// 4 

void buildTree(int height);

// 5

void randFill(float* ar, int N);
void writeToFile5(vector<float> avg);
vector<float> averStr2DArray(const float* ar, int colCount, int rowCount);

// 6, 7

struct Node;
class LinkedList {
private:
    Node* Head;
    Node* Tail;
public:
    LinkedList();
    ~LinkedList();
    void push_back(int nameNode);
    void insert(int nameNode, int position);
    void writeToFileFromTail();
    void writeToFileFromHead();
};

// 8

class StudentInfo {
private:
    char num[4] = "304";
    std::tuple<std::string, std::string, char*> infoStudent = make_tuple("Veprinzev", "Saveliy", num);
    std::map<string, std::pair<std::list<int>, float>> subjMark;
public:
    int addMark(const string& subjName, int mark, bool addSubj = false);
    int addSubj(const string& subjName);
    float getAverMark(const string& subjName);
    void printInfoStudent(bool writeFile = false);
    void writeAllInfoToFile();
};
#endif