#include <iostream>

#define CREATE_OPERATOR_DEC(OP)\
  FP_Number& operator OP##=(const FP_Number& x);

#define CREATE_OPERATOR_IMP(OP) \
  FP_Number& FP_Number::operator OP##= (const FP_Number& x) \
  {     _d = _d OP x._d; \
        return *this; \
  }

class FP_Number
{
public:
  FP_Number(double d) : _d(d){}

  FP_Number operator+(const FP_Number& fpNum) const{
    return FP_Number(fpNum._d + _d);
  }
  FP_Number operator-(const FP_Number& fpNum) const{
    return FP_Number(fpNum._d - _d);
  }
  FP_Number operator*(const FP_Number& fpNum) const{
    return FP_Number(fpNum._d * _d);
  }
  FP_Number operator/(const FP_Number& fpNum) const{
    return FP_Number(fpNum._d / _d);
  }

  CREATE_OPERATOR_DEC(+)
  CREATE_OPERATOR_DEC(-)
  CREATE_OPERATOR_DEC(*)
  CREATE_OPERATOR_DEC(/)
public:
  double get() const {return _d;}
private:
  double _d;
};

CREATE_OPERATOR_IMP(+)
CREATE_OPERATOR_IMP(-)
CREATE_OPERATOR_IMP(*)
CREATE_OPERATOR_IMP(/)

int main(){
  FP_Number f1(3.5), f2(4.5);

  std::cout<<(f1+f2).get()<<std::endl;

  std::cout<<f1.get()<<std::endl;
 
  std::cout<<(f1+=5).get()<<std::endl;
}

