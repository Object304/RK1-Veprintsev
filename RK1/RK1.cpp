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
    void readFromFile(const char* fileName) {    //функция чтения из файла
        FILE* fLog;
        char data[255] = "";
        fLog = fopen(fileName, "r");
        for (int i = 0; fscanf(fLog, "%c\t", &data[i]) != EOF; i++) {}
        fclose(fLog);
        dataOfFile = data;
    }	
    void prepareTestFile(const char* fileName) {	//функция для создания тестового файла
        char data[255] = "";
        strcpy(data, dataOfFile);
        FILE* fLog;
        fLog = fopen(fileName, "a");
        int size = 0;
        int used[255];
        for (; data[size] != NULL; size++) {
            used[size] = 0;
        }

        int min = 0;
        char sym, comp;
        for (; min < size; min++) {
            if (used[min] != 1) {
                sym = data[min];
                int count = 0;
                for (int i = 0; i < size; i++) {
                    comp = data[i];
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
    ~WorkWithFile() {}

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
    for (int i = 0; i < j; i++, j--)
        swap(c[i], c[j]);
    char add[2] = "";
    char ans[65] = "";
    for (int i = 0; i < 64; i++) {
        _itoa(c[i], add, 10);
        strcat(ans, add);
    }
    strcat(ans, "\0");
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
    for (int j = 4; binNum[j - 1] != NULL; j += 4) {
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

void writeToFile(const char* fileName, int writeAppend, const char* hexNum, const char* binNum) {
    char hex[255];
    strcpy(hex, hexNum);
    FILE* fLog;
    fLog = fopen(fileName, "a");
    fprintf(fLog, "{");
    for (int i = 0; i < writeAppend; i++)
        fprintf(fLog, "%c", binNum[i]);
    fprintf(fLog, "}");
    fprintf(fLog, "\t");
    fprintf(fLog, "{");
    for (int i = 0; i < writeAppend / 4 + writeAppend % 4; i++)
        fprintf(fLog, "%c", hex[i]);
    fprintf(fLog, "}");
    fprintf(fLog, "\n");
    fclose(fLog);
}

void task_3(void) {
    const char* bin1 = "11001000110101111";  // не хватает 3-х нулей слева (191AF)
    char* ans = convertBinToHex(bin1);
    writeToFile("result_task3", strlen(bin1), ans, bin1);
    const char* bin2 = "1111111111111111111111111111111111111111111111111111111111111000"; // 64 бита (FFFFFFFFFFFFFFF8)
    ans = convertBinToHex(bin2);
    writeToFile("result_task3", strlen(bin2), ans, bin2);
    const char* bin3 = "10000001"; // 81
    ans = convertBinToHex(bin3);
    writeToFile("result_task3", strlen(bin3), ans, bin3);
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

void writeToFile5(int num, float val) {
    FILE* fLog;
    fLog = fopen("result_task5", "a");
    fprintf(fLog, "[%d]:\t[%f]\n", num, val);
    fclose(fLog);
}

vector<pair<int/*номер строки*/, float /*среднее значение*/>> averStr2DArray(const float* ar, int colCount, int rowCount) {
    vector<pair<int, float>> pairs;
    for (int i = 0; i < rowCount; i++) {
        float sum = 0;
        for (int j = 0; j < colCount; j++) {
            sum += *(ar + i * colCount + j);
        }
        float avg = sum / colCount;
        pairs.emplace_back(i, avg);
    }
    return pairs;
}

void task_5(void) {
    float ar[5][7];
    for (int i = 0; i < 5; i++) {
        randFill(ar[i], 7);
    }
    vector<pair<int, float>> pairs = averStr2DArray(*ar, 7, 5);
    for (auto p : pairs) {
        writeToFile5(p.first, p.second);
    }
}

// 6

struct Node {
    Node* next;
    Node* prev;
    int nameNode;
    static int countNodes;
};
class LinkedList {
private:
    Node* Head;
    Node* Tail;
public:
    LinkedList() {
        for (int i = 0; i < 5; i++) {
            push_back(i);
        }
    }
    ~LinkedList() {}

    //void append(List <T>& lst, T el) {
    //    ListNode <T>* l = createnode(el);
    //    if (lst.head == nullptr)
    //        lst.head = l;
    //    else {
    //        ListNode <T>* p = lst.head;
    //        while (p->next != nullptr)
    //            p = p->next;
    //        p->next = l;
    //    }
    //    lst.len++;
    //}
    
    void push_back(int nameNode) {
        int ar[5] = { 11, 12, 13, 14, 15 };
        //Node* l = 11;
    }
    void writeToFileFromTail() {}
    void writeToFileFromHead() {}
};

void task_6(void) {
    LinkedList lst;
}

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

    return 0;
}
