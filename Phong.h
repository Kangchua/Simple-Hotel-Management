#include <iostream>
using namespace std;
class Phong 
{
    protected:
        string MaPh;
        string LoaiPh;
        int GiaPh;
        int SLMax;
        bool TT;
    public:
        Phong();
        Phong(const Phong&); 
        ~Phong();
        Phong(string, string, int, int, bool);
        friend ostream &operator<<(ostream&, const Phong&);
        friend istream &operator>>(istream&, Phong&);
        bool operator==(const Phong& ) const;
        bool operator==(const Phong& );
    std::string getMaPh() const;
    std::string getLoaiPh() const;
    int getGiaPh() const;
    int getSLMax() const;
    bool getTT() const;
    void setTT() ;
};

