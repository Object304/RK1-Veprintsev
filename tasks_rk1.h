#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <fstream>
#include <iostream>
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
#include <string>
#include <cassert>

using namespace std;

// 1

void task_1(void);
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

void task_2(void);
char* convertDecToBin(int number);
void writeToFile(const char& fileName, const char* strNum);

// 3

void task_3(void);
char* convertBinToHex(const char* binNum);

// 4 

void task_4(void);
void buildTree(int height);

// 5

void task_5(void);
void randFill(float* ar, int N);
void writeToFile5(vector<float> avg);
vector<float> averStr2DArray(const float* ar, int colCount, int rowCount);

// 6, 7

void task_6(void);
void task_7(void);
struct Node {
	Node* next;
	Node* prev;
	int nameNode;	//имя узла
	static int countNodes;
	Node();
	Node(int _nameNode);
	~Node();
};
class LinkedList {
private:
    Node* Head;
    Node* Tail;
	int size;
public:
    LinkedList();
    ~LinkedList();
    void push_back(int nameNode);
    void insert(int nameNode, int position);
    void writeToFileFromTail();
    void writeToFileFromHead();
	int& operator[](int);
	bool operator==(const LinkedList& el1);
};

// 8

void task_8(void);
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

// 9

void task_9(void);

template<class T>
class IData {
protected:
	T* ar;
	int size1;
	int datalen;
public:
	virtual bool addToEnd(T el) {
		return false;
	}
	virtual bool getFromEnd(T& el) {
		return false;
	}
	virtual bool getFromBegin(T& el) {
		return false;
	}
	IData() {
		datalen = 0;
		size1 = 16;
		ar = new T[16];
	}
	~IData() {
		delete[] ar;
	}
};

template<class T>
class Filo : public IData<T> {	
public:
	Filo() : IData<T>() {}

	bool addToEnd(T el) {
		if (IData<T>::datalen == IData<T>::size1) {
			return false;
		}
		IData<T>::ar[IData<T>::datalen++] = el;
		return true;
	}

	bool getFromEnd(T& el) {
		if (IData<T>::datalen == 0) {
			return false;
		}
		el = IData<T>::ar[--IData<T>::datalen];
		return true;
	}
};

template<class T>
class Fifo : public IData<T> {
private:
	void move() {
		for (int i = 0; i < IData<T>::datalen; i++) {
			IData<T>::ar[i] = IData<T>::ar[i + 1];
		}
	}
public:
	Fifo() : IData<T>() {}

	bool addToEnd(T el) {
		if (IData<T>::datalen == IData<T>::size1) {
			return false;
		}
		IData<T>::ar[IData<T>::datalen++] = el;
		return true;
	}

	bool getFromBegin(T& el) {
		if (IData<T>::datalen == 0) {
			return false;
		}
		el = IData<T>::ar[0];
		IData<T>::datalen--;
		move();
		return true;
	}
};

template<class T>
class RingBuffer : public IData<T> {
private:
	int end = 0, begin = 0;
public:
	RingBuffer() : IData<T>() {}

	bool addToEnd(T el) {
		if (IData<T>::datalen == IData<T>::size1) {
			return false;
		}
		IData<T>::ar[end++] = el;
		IData<T>::datalen++;
		if (end == IData<T>::size1) {
			end = 0;
		}
		
		return true;
	}

	bool getFromBegin(T& el) {
		if (IData<T>::datalen == 0)
			return false;
		el = IData<T>::ar[begin++];
		IData<T>::datalen--;
		if (begin == IData<T>::size1) {
			begin = 0;
		}
		return true;
	}
};

bool check(string brack);

// 10

void task_10(void);
void frameWork(void);