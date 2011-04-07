//Jason Wong, Jacob Mederos


using namespace std;

class LongInt
{
public:

//Constructor
  LongInt();

//Overloaded Operators
  friend istream &operator >> (istream &, LongInt & );
  friend ostream &operator << (ostream &, const LongInt & );
  friend LongInt &operator + (LongInt &, LongInt &);

//Destructor
  ~LongInt();

private:
  unsigned int content;
  LongInt *next, *back;
};
