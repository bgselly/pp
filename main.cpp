#include <iostream>
#include <cmath>

using namespace std;

template <typename T>
class NombreComplexe{
    private:
        T reel;
        T imaginaire;
    public:
        NombreComplexe();
        NombreComplexe(T,T);
        NombreComplexe( NombreComplexe&);
        void afficher();
        NombreComplexe operator+ (const NombreComplexe& );
        NombreComplexe operator-(const NombreComplexe& );
        NombreComplexe operator* (const NombreComplexe& );
        NombreComplexe operator/ (const NombreComplexe& );
        bool operator== (const NombreComplexe&);
        bool operator!= (const NombreComplexe&);
        bool operator< (const NombreComplexe&);
        bool operator> (const NombreComplexe&);
        bool operator<= (const NombreComplexe&);
        bool operator>= (const NombreComplexe&);
};

template <typename T>
NombreComplexe<T>::NombreComplexe(){
    reel=0;
    imaginaire=0;
}

template <typename T>
NombreComplexe<T>::NombreComplexe(T r,T i){
    reel=r;
    imaginaire=i;
}

template <typename T>
NombreComplexe<T>::NombreComplexe(NombreComplexe& other){
    reel=other.reel;
    imaginaire=other.imaginairei;
}

template <typename T>
void NombreComplexe<T>::afficher(){
    cout<<reel<<(imaginaire >=0 ? "+": "-" )<<imaginaire<< "i"<<endl;
}

template <typename T>
NombreComplexe<T> NombreComplexe<T>::operator+(const NombreComplexe& N){
    return NombreComplexe(reel+N.reel ,imaginaire+N.imaginire);
}

template <typename T>
NombreComplexe<T> NombreComplexe<T>::operator-(const NombreComplexe& N){
    return NombreComplexe(reel-N.reel ,imaginaire-N.imaginire);
}

template <typename T>
NombreComplexe<T> NombreComplexe<T>::operator*(const NombreComplexe& N){
    return NombreComplexe(reel*N.reel ,imaginaire*N.imaginire);
}

template <typename T>
NombreComplexe<T> NombreComplexe<T>::operator/(const NombreComplexe& N){
    return NombreComplexe(reel/N.reel ,imaginaire/N.imaginire);
}

template <typename T>
bool NombreComplexe<T>::operator==(const NombreComplexe& autre){
    return reel == autre.reel && imaginaire == autre.imaginaire;
}


template <typename T>
bool NombreComplexe<T>::operator!=(const NombreComplexe& autre){
    return !(*this == autre);
}


template <typename T>
bool NombreComplexe<T>::operator<(const NombreComplexe& autre){
    return (reel < autre.reel) || (reel == autre.reel && imaginaire < autre.imaginaire);
}


template <typename T>
bool NombreComplexe<T>::operator>(const NombreComplexe& autre){
    return autre < *this;
}


template <typename T>
bool NombreComplexe<T>::operator<=(const NombreComplexe& autre){
    return !(autre < *this);
}


template <typename T>
bool NombreComplexe<T>::operator>=(const NombreComplexe& autre){
    return !(*this < autre);
}

using NombreComplexeInt = NombreComplexe<int>;

int main() {
    NombreComplexeInt c1(3, 4);
    NombreComplexeInt c2(1, 2);

    cout << "c1 : ";
    c1.afficher();

    cout << "c2 : ";
    c2.afficher();

    NombreComplexeInt c3 = c1 + c2;
    cout << "c1 + c2 : ";
    c3.afficher();

    NombreComplexeInt c4 = c1 - c2;
    cout << "c1 - c2 : ";
    c4.afficher();

    NombreComplexeInt c5 = c1 * c2;
    cout << "c1 * c2 : ";
    c5.afficher();

    NombreComplexeInt c6 = c1 / c2;
    cout << "c1 / c2 : ";
    c6.afficher();

    cout << "c1 == c2 : " << (c1 == c2 ? "true" : "false") << endl;
    cout << "c1 != c2 : " << (c1 != c2 ? "true" : "false") << endl;
    cout << "c1 < c2 : " << (c1 < c2 ? "true" : "false") << endl;
    cout << "c1 > c2 : " << (c1 > c2 ? "true" : "false") << endl;
    cout << "c1 <= c2 : " << (c1 <= c2 ? "true" : "false") << endl;
    cout << "c1 >= c2 : " << (c1 >= c2 ? "true" : "false") << endl;

    return 0;
}



