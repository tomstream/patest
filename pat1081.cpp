#include <iostream>
#include <string>
#include <sstream>
using namespace std;


class Fraction
{
private:
    long denominator;//分母
    long numerator;//分子
    
public:
    Fraction(const Fraction& f);//copy constructor
    Fraction(const long& n, const long& d = 1);
    
    ~Fraction();
    
    const Fraction& reduceFractions();
    
    friend const Fraction operator+(const Fraction&, const Fraction&);
    friend void print(const Fraction& f);
};


Fraction::Fraction(const long& n, const long& d)
{
    denominator = d;
    numerator = n;
}

Fraction::~Fraction()
{
}


const Fraction& Fraction::reduceFractions()
{
    if (numerator == 0)
    {
        denominator = 1; return *this;
    }
    if(numerator%denominator==0)
    {
        numerator/=denominator;
        denominator=1;return *this;
    }
    long tmpBigger = abs(denominator),	//temporary variable which denote the bigger one
    tmpSmaller = abs(numerator);  //temporary variable which denote the smaller one
    if (tmpBigger < tmpSmaller)std::swap(tmpBigger, tmpSmaller);
    long mode = tmpBigger%tmpSmaller;
    while (mode!=0 && tmpSmaller % mode != 0)
    {
        tmpBigger = tmpSmaller;
        tmpSmaller = mode;
        mode = tmpBigger%tmpSmaller;
    }
    
    denominator /= mode;
    numerator /= mode;
    return *this;
}



const Fraction operator+(const Fraction& f1, const Fraction& f2)
{
    const Fraction ret(f1.denominator*f2.numerator + f1.numerator*f2.denominator, f1.denominator*f2.denominator);
    return ret;
}



void print(const Fraction& f)
{
    long inte=f.numerator/f.denominator;
    long mode=f.numerator%f.denominator;
    if(inte<0)cout<<'-';
    
    if(inte!=0
            &&mode!=0)
    {
        cout<<inte<<" "<<abs(mode)<<"/"<<f.denominator;
    }
    else
    {
        cout << abs(f.numerator);
        if(f.denominator!=1){cout << "/";
        cout << f.denominator;
        }
    }
}
std::pair<bool, int> toInt(const char* c)
{
    bool isPositive = true;
    int retNum = 0;
    std::pair<bool, int> ret(false, 0);
    if (c == NULL || *c == '\0')return std::move(ret);
    if (*c == '-')
    {
        isPositive = false;
        c++;
    }
    else if (*c == '+')
        c++;
    for (; *c != '\0'; c++)
        if (isdigit(*c))
            retNum = retNum * 10 + *c - '0';
        else
            return ret;
    ret.first = true;
    ret.second = (isPositive) ? retNum : -retNum;
    return std::move(ret);
}


const Fraction get(string s)
{
    string tmp1,tmp2;
    if(s.find('/')==s.npos)
    {
            return Fraction(toInt(s.c_str()).second);
    }
    else
    {
        stringstream ss;
        ss<<s;
        getline(ss,tmp1,'/');
        getline(ss, tmp2, '/');
        return Fraction(toInt(tmp1.c_str()).second,toInt(tmp2.c_str()).second);
    }
}

int main()
{
    int N;string ins;
    cin>>N;
    Fraction fra(0,1);
    for(int i=0;i<N;i++)
    {
        cin>>ins;
        fra=fra+get(ins);
    }
    print(fra.reduceFractions());
}