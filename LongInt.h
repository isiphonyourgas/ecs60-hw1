//Jason Wong, Jacob Mederos


using namespace std;

class LongInt
{
public:
  LongInt();
  friend istream &operator >> (istream &, LongInt & );
  friend ostream &operator << (ostream &, const LongInt & );
  ~LongInt();

//  int content;
private:
  unsigned int content;
};
