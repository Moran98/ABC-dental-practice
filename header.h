//STRUCT
struct node {
  char fname;
  char lname;
  int DOB;
  char gender;
  char email;
  char nextOfkin;
  float weight;
  float height;
  char allergies;
  char smoke;
  char alcohol;
  char exercise;
  char password;
  int age;
  int PPS;
  char mobileNum;
  char ID;
  int value;
  struct node* NEXT;
  struct node* PREV;
};

//FUNCTIONS
int exitProgram(char choice);

void AddElementAtStart(struct node** top);
void AddElementAtEnd(struct node* top);
void AddElementAtPos(struct node* top, int position);


void DeleteElementAtStart(struct node** top);
void DeleteElementAtEnd(struct node* top);
void DeleteElementAtPos(struct node* top, int position);

int Listlength(struct node* top);
void DisplayList(struct node* top);
int searchList(struct node* top, char searchID[10]);
