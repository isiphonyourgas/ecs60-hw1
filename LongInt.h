//Jason Wong, Jacob Mederos


using namespace std;

class LongInt
{
public:
  LongInt();
  friend istream &operator >> (istream &, LongInt & );
  friend ostream &operator << (ostream &, const LongInt & );
  friend LongInt &operator + (LongInt &, LongInt &);
  void setback( LongInt );
  ~LongInt();

  int content;
  LongInt *next, *back;
private:
 // unsigned int content;
//  LongInt *next, *back;
};
