#include "tasks_rk1.h"
using namespace std;

void task_1(void) {
    WorkWithFile pin;
}

void task_2(void) {
    int a = -4, b = 255, c = -1984;
    char name[] = "result_task2.txt";
    char* ans = convertDecToBin(a);
    writeToFile(name[0], ans);
    ans = convertDecToBin(b);
    writeToFile(name[0], ans);
    ans = convertDecToBin(c);
    writeToFile(name[0], ans);
}

void task_3(void) {
    const char* bin1 = "11001000110101111";  // не хватает 3-х нулей слева (191AF)
    char* ans = convertBinToHex(bin1);
    char name[] = "result_task2.txt";
    writeToFile(name[0], ans);
    const char* bin2 = "1111111111111111111111111111111111111111111111111111111111111000"; // 64 бита (FFFFFFFFFFFFFFF8)
    ans = convertBinToHex(bin2);
    writeToFile(name[0], ans);
    const char* bin3 = "10000001"; // 81
    ans = convertBinToHex(bin3);
    writeToFile(name[0], ans);
}

void task_4(void) {
    int a = 10;
    buildTree(a);
}

void task_5(void) {
    float ar[5][7];
    for (int i = 0; i < 5; i++) {
        randFill(ar[i], 7);
    }
    vector<float> avg = averStr2DArray(*ar, 7, 5);
    writeToFile5(avg);
}

void task_6(void) {
    LinkedList lst;
    int c[5] = { 7, 4, 3, 8, 5 };
    for (int i = 0; i < 5; i++) {
        lst.push_back(c[i]);
    }
    lst.writeToFileFromHead();
    lst.writeToFileFromTail();
}

void task_7(void) {                 //можно протестировать перегрузку операторов == и [] (у скобок [] есть assert!)
    LinkedList lst;
    int c[5] = { 7, 4, 3, 8, 5 }; // должно получиться (-8;	7;	4;	-7;	3;	8;	-2;	5;)
    for (int i = 0; i < 5; i++) {
        lst.push_back(c[i]);
    }
    lst.insert(-7, 2);
    lst.insert(-2, 5);
    lst.insert(-8, 0);
    lst.insert(999, -1); // некорректный ввод
    lst.writeToFileFromHead();
    lst.insert(999, 10); // некорректный ввод
    lst.writeToFileFromHead();
}

void task_8(void) {
    StudentInfo dat;
    dat.addMark("Science", 5, true);
    dat.addMark("English", 4, false);
    dat.addSubj("Physics");
    dat.addMark("Physics", 8, true);
    dat.addMark("Physics", 6, true);
    dat.addSubj("English");
    dat.addMark("Science", 10, false);
    dat.addMark("Science", 15, true);
    dat.addMark("English", 18, false);
    dat.addMark("Physics", 21, true);
    dat.addMark("Physics", 25, true);
    dat.addMark("Science", 37, false);
    dat.addMark("English", 76, true);
    dat.addMark("English", 81, false);
    dat.printInfoStudent(true);
    dat.printInfoStudent();
    dat.writeAllInfoToFile();
}

void task_9(void) {
    string s1 = "((()))[<<>>]{((()))}",
        s2 = "][",
        s3 = "[{]}",
        s4 = "(()",
        s5 = "(<<>{(())}[<<<>{}>()>]>)";
    cout << s1 << " -- " << boolalpha << check(s1) << endl;
    cout << s2 << " -- " << boolalpha << check(s2) << endl;
    cout << s3 << " -- " << boolalpha << check(s3) << endl;
    cout << s4 << " -- " << boolalpha << check(s4) << endl;
    cout << s5 << " -- " << boolalpha << check(s5) << endl;
}

int main()
{
    task_1();
    task_2();
    task_3();
    task_4();
    task_5();
    task_6();
    task_7();
    task_8();
    task_9();
    return 0;
}