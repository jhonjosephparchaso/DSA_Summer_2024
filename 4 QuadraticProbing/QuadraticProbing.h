#ifndef Quadratic_Probing
#define Quadratic_Probing
#define MAX 10

typedef struct {
    char fName[20];
    char lName[20];
} studName;

typedef struct {
    int month;
    int year;
} bday;

typedef enum {
    EMPTY = 0,
    OCCUPIED = 1,
    DELETED = -1
} SlotStatus;

typedef struct {
    studName name;
    bday birthdate;
    int age;
    int idNum;
    SlotStatus status;
} studentInfo;

typedef struct {
    studentInfo arr[MAX];
} closedHash;

void initHash(closedHash* CH);
int hash(int key);
void insert(closedHash* CH, studentInfo student);
void delete(closedHash* CH, int idNum);
void display(closedHash CH);

#endif
