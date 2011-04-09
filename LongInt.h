//Jason Wong, Jacob Mederos


using namespace std;

class LongIntNode;

class LongIntNode
{
public:

//Constructor
  LongIntNode();

//Member Functions
  void set(int);
  void setnext(LongIntNode *);
  void setback(LongIntNode *);
  int get();
  LongIntNode* next();
  LongIntNode* back();

//Destructor
  ~LongIntNode();

//LongIntNode *forward, *backward;
private:
  int content;
  LongIntNode *forward;
  LongIntNode *backward;
};


class LongInt
{
public:

//Constructor
  LongInt();

//Overloaded Operators
  friend istream &operator >> (istream &, LongInt & );
  friend ostream &operator << (ostream &, const LongInt & );
  friend LongInt &operator + (LongInt &, LongInt &);

//Member Functions
  void insertFront(int);
  void insertBack(int);

//Destructor
  ~LongInt();

private:
  LongIntNode *head, *tail;
};
