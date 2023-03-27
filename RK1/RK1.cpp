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
using namespace std;

// 1

class WorkWithFile {
private:
    char* dataOfFile;
    void readFromFile(const char* fileName) {
        dataOfFile = new char[1000]{'\0'};
        FILE* fLog;
        fLog = fopen(fileName, "r");
        for (int i = 0; fscanf(fLog, "%c\t", &dataOfFile[i]) != EOF; i++) {}
        fclose(fLog);
        strcat(dataOfFile, "\0");
    }	
    void prepareTestFile(const char* fileName) {
        FILE* fLog;
        fLog = fopen(fileName, "a");
        int size = 0;
        int used[1000];
        for (; dataOfFile[size] != '\0'; size++) {
            used[size] = 0;
        }
        int min = 0;
        char sym, comp;
        for (; min < size; min++) {
            if (used[min] != 1) {
                sym = dataOfFile[min];
                int count = 0;
                for (int i = 0; i < size; i++) {
                    comp = dataOfFile[i];
                    if (sym == comp) {
                        count++;
                        used[i] = 1;
                    }
                }
                fprintf(fLog, "[%c]\t[%d]\n", sym, count);
            }
            
        }

        fclose(fLog);
    }
public:
    WorkWithFile() {
        writeStatInfoToFile("result_sourceFile_task1");
    }
    ~WorkWithFile() {
        delete dataOfFile;
    }

    void writeStatInfoToFile(const char* outFile) {
        readFromFile("sourceFile_task1");
        prepareTestFile(outFile);
    }
};

void task_1(void) {
    WorkWithFile pin;
}

// 2

char* convertDecToBin(int number) {
    int c[64], j = 0;
    unsigned __int64 a = number;
    for (int i = 64; i > 0; i--) {
        c[j] = (a & 1);
        a = a >> 1;
        j++;
    }
    j--;
    char add[64] = "";
    char* ans;
    for (int i = 0; j > 0; j--, i++) {
        add[i] = (int)'0' + c[j];
    }
    strcat(add, "\0");
    ans = add;
    return ans;
}

void writeToFile(const char& fileName, const char* strNum) {
    FILE* fLog;
    char str[65] = "";
    strcpy(str, strNum);
    fLog = fopen(&fileName, "a");
    for (int i = 0; i < 64; i++)
        fprintf(fLog, "%c", str[i]);
    fprintf(fLog, "\n");
    fclose(fLog);
}

void task_2(void) {
    int a = -4, b = 255, c = 0;
    char name[] = "result_task2\0";
    char* ans = convertDecToBin(a);
    writeToFile(name[0], ans);
    ans = convertDecToBin(b);
    writeToFile(name[0], ans);
    ans = convertDecToBin(c);
    writeToFile(name[0], ans);
}

// 3

char* convertBinToHex(const char* binNum) {
    int add = 0;
    int count = 0;
    for(; count < strlen(binNum); count += 4) {}
    add = count - strlen(binNum);
    char right[255] = "";
    for (int i = 0; i < add; i++) {
        strcat(right, "0");
    }
    strcat(right, binNum);
    binNum = right;
    char hex[255] = "";
    for (int j = 4; binNum[j - 1] != '\0'; j += 4) {
        char temp[5] = "";
        for (int i = 0; i < 4; i++) {
            temp[i] = binNum[j - 4 + i];
        }
        if (strcmp(temp, "0000") == 0)  strcat(hex, "0");
        if (strcmp(temp, "0001") == 0)  strcat(hex, "1");
        if (strcmp(temp, "0010") == 0)  strcat(hex, "2");
        if (strcmp(temp, "0011") == 0)  strcat(hex, "3");
        if (strcmp(temp, "0100") == 0)  strcat(hex, "4");
        if (strcmp(temp, "0101") == 0)  strcat(hex, "5");
        if (strcmp(temp, "0110") == 0)  strcat(hex, "6");
        if (strcmp(temp, "0111") == 0)  strcat(hex, "7");
        if (strcmp(temp, "1000") == 0)  strcat(hex, "8");
        if (strcmp(temp, "1001") == 0)  strcat(hex, "9");
        if (strcmp(temp, "1010") == 0)  strcat(hex, "A");
        if (strcmp(temp, "1011") == 0)  strcat(hex, "B");
        if (strcmp(temp, "1100") == 0)  strcat(hex, "C");
        if (strcmp(temp, "1101") == 0)  strcat(hex, "D");
        if (strcmp(temp, "1110") == 0)  strcat(hex, "E");
        if (strcmp(temp, "1111") == 0)  strcat(hex, "F");
    }
    char* ans = hex;
    return ans;
}

void task_3(void) {
    const char* bin1 = "11001000110101111";  // не хватает 3-х нулей слева (191AF)
    char* ans = convertBinToHex(bin1);
    char name[] = "result_task2";
    writeToFile(name[0], ans);
    const char* bin2 = "1111111111111111111111111111111111111111111111111111111111111000"; // 64 бита (FFFFFFFFFFFFFFF8)
    ans = convertBinToHex(bin2);
    writeToFile(name[0], ans);
    const char* bin3 = "10000001"; // 81
    ans = convertBinToHex(bin3);
    writeToFile(name[0], ans);
}

// 4

void buildTree(int height) {
    for (int i = height - 1, count = 1; i > 0; i--, count += 2) {
        cout << setw(i);
        for (int i = count; i > 0; i--)
            cout << "*";
        cout << endl;
    }
}

void task_4(void) {
    int a = 10;
    buildTree(a);
}

// 5

void randFill(float* ar, int N) {
    for (int i = 0; i < N; i++) {
        ar[i] = ((float)rand() / (float)RAND_MAX * (-40) + 20);
    }
}

void writeToFile5(vector<float> avg) {
    FILE* fLog;
    fLog = fopen("result_task5", "a");
    for (int i = 0; i < avg.size(); i++) {
        fprintf(fLog, "[%d]:\t[%f]\n", i, avg[i]);
    }
    fclose(fLog);
}

vector<float> averStr2DArray(const float* ar, int colCount, int rowCount) {
    vector<float> avgs;
    for (int i = 0; i < rowCount; i++) {
        float sum = 0;
        for (int j = 0; j < colCount; j++) {
            sum += *(ar + i * colCount + j);
        }
        float avg = sum / colCount;
        avgs.emplace_back(avg);
    }
    return avgs;
}

void task_5(void) {
    float ar[5][7];
    for (int i = 0; i < 5; i++) {
        randFill(ar[i], 7);
    }
    vector<float> avg = averStr2DArray(*ar, 7, 5);
    writeToFile5(avg);
}

// 6

struct Node {
    Node* next;
    Node* prev;
    int nameNode;	//имя узла
    static int countNodes;
    Node() {
        next = nullptr;
        prev = nullptr;
        this->nameNode = 0;
    }
    Node(int _nameNode) {
        countNodes++;
        this->nameNode = _nameNode + 1;
        next = nullptr;
        prev = nullptr;
    }
    ~Node() {
        countNodes--;
    }
};
int Node::countNodes = 0;
class LinkedList {
private:
    Node* Head;
    Node* Tail;
public:
    LinkedList() {
        /*this->Head->next = Tail;
        this->Tail->prev = Head;
        Head->prev = nullptr;
        Tail->next = nullptr;*/
        Head = nullptr;
        Tail = nullptr;
    }
    ~LinkedList() {
        Node* el = Tail;
        Node* trash = el;
        for (int i = 0; i < Node::countNodes; i++) {
            trash = el;
            el = el->prev;
            delete trash;
        }
        Node::countNodes = 0;
    }
    void push_back(int nameNode) {
        if (Head == nullptr) {
            Head = new Node(nameNode);
            Tail = new Node();
            Head->prev = nullptr;
            Head->next = Tail;
            Tail->prev = Head;
            Tail->next = nullptr;
            return;
        }
        Node* temp = new Node(nameNode);
        Tail->next = temp;
        Tail->nameNode = temp->nameNode;
        temp->prev = Tail;
        temp->next = nullptr;
        Tail = temp;
    }
    void insert(int nameNode, int position) {
        if (position < 0 || position > Node::countNodes) {
            return;
        }
        Node* el = new Node(nameNode);
        Node* tempN;
        Node* tempP;
        el->next = Head;
        Head = el;
        for (int i = 0; i < position; i++) {
            if (i == 0) {
                tempN = el->next;
                el->next = el->next->next;
                tempN->next = el;
                el->prev = tempN;
                Head = tempN;
            }
            else {
                tempN = el->next;
                tempP = el->prev;
                el->next = el->next->next;
                el->next->prev = el;
                tempN->next = el;
                el->prev = tempN;
                tempP->next = tempN;
                tempN->prev = tempP;
            }
        }
    }
    void writeToFileFromTail() {
        FILE* fLog;
        fLog = fopen("result_task6", "a");
        Node* el = Tail->prev;
        for (int i = 0; i < Node::countNodes; i++) {
            fprintf(fLog, "%d;\t", el->nameNode);
            el = el->prev;
        }
        fprintf(fLog, "\n");
        fclose(fLog);
    }
    void writeToFileFromHead() {
        FILE* fLog;
        fLog = fopen("result_task6", "a");
        Node* el = Head;
        for (int i = 0; i < Node::countNodes; i++) {
            fprintf(fLog, "%d;\t", el->nameNode);
            el = el->next;
        }
        fprintf(fLog, "\n");
        fclose(fLog);
    }
};

void task_6(void) {
    LinkedList lst;
    int c[5] = { 7, 4, 3, 8, 5 };
    for (int i = 0; i < 5; i++) {
       lst.push_back(c[i]);
    }
    lst.writeToFileFromHead();
    lst.writeToFileFromTail();
}

// 7

void task_7(void) {
    LinkedList lst;
    int c[5] = { 7, 4, 3, 8, 5 }; // должно получиться (-7 8 5 -6 4 9 -1 6)
    for (int i = 0; i < 5; i++) {
        lst.push_back(c[i]);
    }
    lst.insert(-7, 2);
    lst.insert(-2, 5);
    lst.insert(-8, 0);
    lst.insert(999, -1); // некорректный ввод
    lst.insert(999, 9); // некорректный ввод
    lst.writeToFileFromHead();
}

//void task_test(void) {
//    LinkedList lst;
//    lst.insert(-8, 0);
//}

// 8
//
//class StudentInfo {
//private:
//    tuple<string /*фамилия*/, string /*имя*/, char* /*№ студ билета*/> info;
//    map<string/*название предмета*/, pair<list<int> /*список оценок*/, float /*средняя оценка*/>> subjMark;
//public:
//    /*	desription	:	добавления отметки по выбранному предмету
//        input		:	subjName - название предмета, mark -- оценка
//        output		:	0 - оценка добавлена, 1 - нет такого предмета
//        author		:
//        date		:
//    */
//    int addMark(const string& subjName, int mark);
//    /*	desription	:	добавления отметки по выбранному предмету
//        input		:	subjName - название предмета
//        output		:	0 - предмет добавлен, 1 - такой предмет уже есть
//        author		:
//        date		:
//
//    */
//    int addSubj(const string& subjName);
//    /*	desription	:	добавления нового предмета
//        input		:	subjName - название предмета
//        output		:	среднее значение оценки
//        author		:
//        date		:
//    */
//    float getAverMark(const string& subjName);
//    /*	desription	:	вычисления средней оценки по предметам
//        input		:	subjName - название предмета
//        output		:	среднее значение оценки
//        author		:
//        date		:
//    */
//    void printInfoStudent();
//    /*	desription	:	запись данных в файл формат файла
//                            [Фамилия] [имя] : [номер билета]
//                                [предмет 1]	:	[оценка 1], [оценка 2],... [оценка N] -- [среднее значение]
//                                [предмет 2]	:	[оценка 1], [оценка 2],... [оценка N] -- [среднее значение]
//        input		:	subjName - название предмета
//        output		:	среднее значение оценки
//        author		:
//        date		:
//    */
//    void writeAllInfoToFile();
//};
//
//void task_8(void) {
//
//}

int main()
{
    task_1();

    task_2();

    task_3();

    task_4();

    task_5();

    task_6();

    task_7();
    //task_test();
    return 0;
}
