#define MAXCHAR 8


typedef struct  {
    char name[MAXCHAR];
    int length;
} drec;

typedef struct  {
    char flag;
    char name[MAXCHAR];
    int address;
} erec;

typedef struct  {
    char flag;
    int address;
} rrec;

typedef struct  {
    int address;
    drec cont;
} dtab;
