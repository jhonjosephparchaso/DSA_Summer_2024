#ifndef Open_Hash
#define Open_Hash
#define MAX 10

typedef struct {
    char fName[20];
    char lName[20];
} studName;

typedef struct {
    int month;
    int year;
} bday;

typedef struct {
    studName name;
    bday birthdate;
    int age;
    int idNum;
} studentInfo;

typedef struct node {
    studentInfo data;
    struct node* next;
} Node, *NodePtr;

typedef struct {
    NodePtr arr[MAX];
} openHash;

void initHash(openHash* OH);
int hash(int key);
void insert(openHash* OH, studentInfo student, int key);
void delete(openHash* OH, int idNum, int key);
void display(openHash OH);

#endif
