#include "tasks_rk1.h"

using namespace std;

// 1

void WorkWithFile::readFromFile(const char* fileName) {
    dataOfFile = new char[1000] {'\0'};
    FILE* fLog;
    fLog = fopen(fileName, "r");
    for (int i = 0; fscanf(fLog, "%c\t", &dataOfFile[i]) != EOF; i++) {}
    fclose(fLog);
    strcat(dataOfFile, "\0");
}
void WorkWithFile::prepareTestFile(const char* fileName) {
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
WorkWithFile::WorkWithFile() {
    writeStatInfoToFile("result_sourceFile_task1");
}
WorkWithFile::~WorkWithFile() {
    delete dataOfFile;
}

void WorkWithFile::writeStatInfoToFile(const char* outFile) {
    readFromFile("sourceFile_task1");
    prepareTestFile(outFile);
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
    char add[65] = "";
    char* ans;
    for (int i = 0; j >= 0; j--, i++) {
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

// 3

char* convertBinToHex(const char* binNum) {
    int add = 0;
    int count = 0;
    for (; count < strlen(binNum); count += 4) {}
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

// 4

void buildTree(int height) {
    for (int i = height - 1, count = 1; i > 0; i--, count += 2) {
        cout << setw(i);
        for (int i = count; i > 0; i--)
            cout << "*";
        cout << endl;
    }
}

// 5

void randFill(float* ar, int N) {
    for (int i = 0; i < N; i++) {
        ar[i] = ((float)rand() / (float)RAND_MAX * (-40) + 20);
    }
}

void writeToFile5(std::vector<float> avg) {
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

// 6, 7

struct Node {
    Node* next;
    Node* prev;
    int nameNode;
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
LinkedList::LinkedList() {
    Head = new Node();
    Tail = new Node();
    Head->next = Tail;
    Tail->prev = Head;
    Head->prev = nullptr;
    Tail->next = nullptr;
}
LinkedList::~LinkedList() {
    Node* el = Tail;
    Node* trash = el;
    for (int i = 0; i < Node::countNodes + 1; i++) {
        trash = el;
        el = el->prev;
        delete trash;
    }
    delete el;
    Node::countNodes = 0;
}
void LinkedList::push_back(int nameNode) {
    if (Node::countNodes == 0) {
        Node* temp = new Node(nameNode);
        Head->nameNode = temp->nameNode;
        return;
    }
    Node* temp = new Node(nameNode);
    Tail->next = temp;
    Tail->nameNode = temp->nameNode;
    temp->prev = Tail;
    temp->next = nullptr;
    Tail = temp;
}
void LinkedList::insert(int nameNode, int position) {
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
void LinkedList::writeToFileFromTail() {
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
void LinkedList::writeToFileFromHead() {
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

// 8


int StudentInfo::addMark(const string& subjName, int mark, bool addSubj) {
    if (addSubj) {
        StudentInfo::addSubj(subjName);
    }
    while (true) {
        if (subjMark.find(subjName) != subjMark.end()) {
            std::map<string, std::pair<std::list<int>, float>>::iterator it;
            it = subjMark.find(subjName);
            it->second.first.push_back(mark);
            it->second.second = StudentInfo::getAverMark(subjName);
            subjMark.emplace(subjName, it->second);
            break;
        }
        else {
            StudentInfo::addSubj(subjName);
            continue;
        }
    }
    return 0;
}
int StudentInfo::addSubj(const string& subjName) {
    if (subjMark.find(subjName) == subjMark.end()) {
        subjMark[subjName];
        return 0;
    }
    return 1;
}
float StudentInfo::getAverMark(const string& subjName) {
    if (subjMark.find(subjName) == subjMark.end()) {
        return -1;
    }
    std::map<string, std::pair<std::list<int>, float>>::iterator it;
    it = subjMark.find(subjName);
    pair <list<int>, float> pairs = it->second;
    list<int> lst = pairs.first;
    list<int>::iterator p = lst.begin();
    float avg = 0;
    int i = 0;
    for (; i < lst.size(); i++, p++) {
        avg += *p;
    }
    avg /= i;
    return avg;
}
void StudentInfo::printInfoStudent(bool writeFile) {
    if (writeFile) {
        FILE* fLog;
        fLog = fopen("result_task8", "a");
        fprintf(fLog, "[%s %s %s]\n", get<0>(infoStudent).c_str(), get<1>(infoStudent).c_str(), get<2>(infoStudent));
        std::map<string, std::pair<std::list<int>, float>>::iterator it = subjMark.begin();
        for (int i = 0; i < subjMark.size(); i++, it++) {
            fprintf(fLog, "\t[%s] : ", it->first.c_str());
            pair <list<int>, float> pairs = it->second;
            list<int> lst = pairs.first;
            list<int>::iterator p = lst.begin();
            fprintf(fLog, "[%d", *p);
            p++;
            for (int j = 0; j < lst.size() - 1; j++, p++) {
                fprintf(fLog, ", %d", *p);
            }
            fprintf(fLog, "] -- [%f]\n", pairs.second);
        }
        fprintf(fLog, "\n");
        fclose(fLog);
        return;
    }
    cout << "[" << get<0>(infoStudent).c_str() << " " << get<1>(infoStudent).c_str() << " " << get<2>(infoStudent) << "]" << endl;
    std::map<string, std::pair<std::list<int>, float>>::iterator it = subjMark.begin();
    for (int i = 0; i < subjMark.size(); i++, it++) {
        cout << "\t[" << it->first.c_str() << "] : ";
        pair <list<int>, float> pairs = it->second;
        list<int> lst = pairs.first;
        list<int>::iterator p = lst.begin();
        cout << "[" << *p;
        p++;
        for (int j = 0; j < lst.size() - 1; j++, p++) {
            cout << ", " << *p;
        }
        cout << "] -- [" << pairs.second << "]" << endl;
    }
    cout << endl;
}
void StudentInfo::writeAllInfoToFile() {
    FILE* fLog;
    fLog = fopen("result_task8", "a");
    fprintf(fLog, "[%s] [%s] : [%s]\n", get<0>(infoStudent).c_str(), get<1>(infoStudent).c_str(), get<2>(infoStudent));
    std::map<string, std::pair<std::list<int>, float>>::iterator it = subjMark.begin();
    for (int i = 0; i < subjMark.size(); i++, it++) {
        fprintf(fLog, "\t[%s] :  ", it->first.c_str());
        pair <list<int>, float> pairs = it->second;
        list<int> lst = pairs.first;
        list<int>::iterator p = lst.begin();
        fprintf(fLog, "[%d]", *p);
        p++;
        for (int j = 0; j < lst.size() - 1; j++, p++) {
            fprintf(fLog, ", [%d]", *p);
        }
        fprintf(fLog, " -- [%f]\n", pairs.second);
    }
    fprintf(fLog, "\n");
    fclose(fLog);
}