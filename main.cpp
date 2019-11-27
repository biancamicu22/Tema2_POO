#include <iostream>
#include <math.h>
#include <cstdlib>
#include <string.h>
#include <time.h>

using namespace std;

class Complex
{
private:
    float real;
    float imaginar;

public:
    Complex();
    Complex(float);
    Complex(float, float);
    Complex(const Complex&);
    ~Complex();

    void citire();
    void afisare();
    void modul();

    friend ostream& operator << (ostream&, Complex&);
    friend istream& operator >> (istream&, Complex&);
    friend Complex operator +(Complex, Complex);
    friend Complex operator -(Complex, Complex);
    friend Complex operator *(Complex, Complex);
    friend Complex operator *(Complex, int);
    friend Complex operator /(Complex, Complex);
    friend Complex operator !=(Complex, int);
    friend Complex operator ==(Complex, int);
    friend bool operator!=(Complex, Complex);
    friend bool operator==(Complex, Complex);

    Complex& operator=(const Complex&);
};

Complex::Complex()
{
    this->real = this->imaginar = 0;
}

Complex::Complex(float valoare)
{
    this->real = valoare;
    this->imaginar = 0;
}

Complex::Complex(float r, float i)
{
    this->real = r;
    this->imaginar = i;
}

Complex::Complex(const Complex& z)
{
    this->real = z.real;
    this->imaginar = z.imaginar;
    cout<<endl;
    cout<<"Constructor copiere Complex"<<endl;
}

Complex::~Complex()
{
    cout<<"D"<<endl;
}

void Complex::citire()
{
    cout<<"Partea reala a numarului complex este real = "<<endl;
    cin>>real;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout<<"Ai introdus tipul de data gresit!"<<endl;
        cout<<"Partea reala corecta a numarului complex este real ="<<endl;
        cin>>real;
    }
    cout<<"Partea imaginara a numarului complex este imaginar = "<<endl;
    cin>>imaginar;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout<<"Ai introdus tipul de data gresit!"<<endl;
        cout<<"Partea imaginara corecta a numarului complex este complex ="<<endl;
        cin>>imaginar;
    }
}

void Complex::afisare()
{
    if(this->real == 0 && imaginar > 0)
        cout<<"i*"<<this->imaginar;
    else if(this->real == 0 && this->imaginar < 0)
        cout<<"-i*"<<-this->imaginar;
    if(this->real == 0 && this->imaginar == 0)
        cout<<0;
    if(this->imaginar == 0 && this->real > 0)
        cout<<this->real;
    else if(this->imaginar == 0 && this->real < 0)
        cout<<this->real;
    if(this->real != 0 && this->imaginar < 0)
        cout<<this->real<<"-i*"<<-this->imaginar;
    else if(this->real !=0 && this->imaginar >0)
        cout<<this->real<<"+i*"<<this->imaginar;
}

istream& operator >>(istream& in, Complex& z)
{
    cout<<"Partea reala a numarului complex este real = ";
    in>>z.real;
    if(in.fail())
    {
        in.clear();
        in.ignore();
        cout<<"Ai introdus tipul de data gresit!"<<endl;
        cout<<"Partea reala corecta +a numarului complex este real ="<<endl;
        in>>z.real;
    }
    cout<<"Partea imaginara a numarului complex este imaginar = ";
    in>>z.imaginar;
    if(in.fail())
    {
        in.clear();
        in.ignore();
        cout<<"Ai introdus tipul de data gresit!"<<endl;
        cout<<"Partea imaginara corecta a numarului complex este complex ="<<endl;
        in>>z.imaginar;
    }
    return in;
}

ostream& operator << (ostream& out, Complex& z)
{
    if(z.real == 0 && z.imaginar > 0)
        out<<"i*"<<z.imaginar;
    else if(z.real == 0 && z.imaginar < 0)
        out<<"-i*"<<-z.imaginar;
    if(z.real == 0 && z.imaginar == 0)
        out<<0;
    if(z.imaginar == 0 && z.real > 0)
        out<<z.real;
    else if(z.imaginar == 0 && z.real < 0)
        out<<z.real;
    if(z.real != 0 && z.imaginar < 0)
        out<<z.real<<"-i*"<<-z.imaginar;
    else if(z.real !=0 && z.imaginar >0)
        out<<z.real<<"+i*"<<z.imaginar;
    return out;
}

void Complex::modul()
{
    float aux;
    aux = sqrt(this->real*this->real + this->imaginar*this->imaginar);
    cout<<"Modulul numarului complex este: "<<aux;
}

Complex operator +(Complex z1, Complex z2)
{
    Complex z;
    z.real = z1.real + z2.real;
    z.imaginar = z1.imaginar + z2.imaginar;
    return z;
}

Complex operator -(Complex z1, Complex z2)
{
    Complex z;
    z.real = z1.real - z2.real;
    z.imaginar = z1.imaginar - z2.imaginar;
    return z;
}

Complex operator *(Complex z1, Complex z2)
{
    Complex z;
    z.real = z1.real * z2.real - z1.imaginar * z2.imaginar;
    z.imaginar = z1.imaginar * z2.real + z1.real * z2.imaginar;
    return z;
}

Complex operator* (Complex z, int nr)
{
    z.real = nr*z.real;
    z.imaginar = nr*z.imaginar;
    return z;
}

Complex operator /(Complex z1, Complex z2)
{
    Complex z;
    z.real = (z1.real * z2.real + z1.imaginar * z2.imaginar) / (z2.real * z2.real + z2.imaginar * z2.imaginar);
    z.imaginar = (z2.real * z1.imaginar - z1.real * z2.imaginar) / (z2.real * z2.real + z2.imaginar * z2.imaginar);
    return z;
}

Complex& Complex::operator=(const Complex& z)
{
    if(this!=&z)
    {
        real = z.real;
        imaginar = z.imaginar;
    }
    return *this;
}

Complex operator ==(Complex z1, int nr)
{
    int ok=0;
    if(z1.real==0)
    {
        if(z1.imaginar==nr)
        {
            ok=1;
        }
    }
    else if(z1.imaginar==0)
    {
        if(z1.real==nr)
        {
            ok=1;
        }
    }
    else if(z1.real==0 && z1.imaginar==0)
    {
        if(z1.real==nr)
        {
            ok=1;
        }
    }
    return ok;
}

Complex operator !=(Complex z1, int nr)
{
    int ok=0;
    if(z1.imaginar==0)
    {
        if(z1.real==nr)
        {
            ok=1;
        }
    }
    else if(z1.real==0 && z1.imaginar==0)
    {
        if(z1.real==nr)
        {
            ok=1;
        }
    }
    return ok;
}

bool operator !=(Complex z1, Complex z2)
{
    if(z1.real==z2.real && (z1.imaginar==z2.imaginar)==0)
        return false;
    else if(z1.imaginar==z2.imaginar && (z1.real==z2.real)==0)
        return false;
    else if(z1.real==z2.real && z1.imaginar==z2.imaginar)
        return false;
    return true;
}

bool operator ==(Complex z1, Complex z2)
{
    if(z1.imaginar==0 && z2.imaginar==0)
    {
        if(z1.real!=z2.real)
            return false;
    }
    else if(z1.real==0 && z2.real==0)
    {
        if(z1.imaginar!=z2.imaginar)
            return false;
    }
    else if(z1.real!=z2.real && z1.imaginar!=z2.imaginar)
        return false;
    return true;
}



class Matrice
{
public:
    Complex **v;

public:
    Matrice();
    virtual void citire_matrice()=0;
    virtual void afisare_matrice()=0;
};

Matrice::Matrice()
{
    v=NULL;
}

class Matrice_oarecare : public Matrice
{
protected:
    int linie;
    int coloana;
public:
    Matrice_oarecare():Matrice()
    {
        this->linie=0;
        this->coloana=0;
    }

    Matrice_oarecare(int linie, int coloana):Matrice()
    {
        this->linie=linie;
        this->coloana=coloana;

        this->v= new Complex*[this->linie+1];
        for(int i=1; i<=this->linie; i++)
            v[i]=new Complex[coloana+1];
        for(int i=1; i<=linie; i++)
            for(int j=1; j<=coloana; j++)
                this->v[i][j]=0;
    }

    Matrice_oarecare(const Matrice_oarecare& M):Matrice()
    {
        this->linie=linie;
        this->coloana=coloana;
        this->v= new Complex*[this->linie+1];
        for(int i=1; i<=this->linie; i++)
            v[i]=new Complex[coloana+1];
        for(int i=1; i<=linie; i++)
            for(int j=1; j<=coloana; j++)
                this->v[i][j]=M.v[i][j];
        cout<<"Constructor copiere matrice oarecare";
    }

    ~Matrice_oarecare()
    {
        for(int i=1; i<=linie; i++)
            delete[] v[i];
        delete[] v;
        cout<<"Destructor matrice oarecare"<<endl;
    }

    void citire_matrice()
    {
        if(linie == coloana)
        {
            cout<<"Nu se poate!"<<endl;
            cin>>linie>>coloana;
            citire_matrice();
        }
        cout<<"Matrice creata este de forma ("<<linie<<","<<coloana<<")"<<endl;
        for(int i=1; i<=linie; i++)
            for(int j=1; j<=coloana; j++)
                cin>>v[i][j];
    }

    void afisare_matrice()
    {
        cout<<"Matricea este de tip oarecare"<<endl;
        int i,j;
        if(linie == 0 && coloana == 0)
            cout<<"Matricea este nula"<<endl;
        else
        {
            cout<<"Matricea creata este:"<<endl;
            for(i=1; i<=linie; i++)
            {
                for(j=1; j<=coloana; j++)
                    cout<<v[i][j]<<"   ";
                cout<<endl;
            }
        }
    }

    friend ostream& operator << (ostream& out, Matrice_oarecare& M)
    {
        cout<<"Matricea este de tip oarecare"<<endl;
        int i,j;
        if(M.linie == 0 && M.coloana == 0)
            out<<"Matricea este nula"<<endl;
        else
        {
            out<<"Matricea creata este:"<<endl;
            for(i=1; i<=M.linie; i++)
            {
                for(j=1; j<=M.coloana; j++)
                    out<<M.v[i][j]<<"   ";
                out<<endl;
            }
        }
        return out;
    }

    friend istream& operator >> (istream& in, Matrice_oarecare& M)
    {
        cout<<"Matrice creata este de forma ("<<M.linie<<","<<M.coloana<<")"<<endl;
        for(int i=1; i<=M.linie; i++)
            for(int j=1; j<=M.coloana; j++)
                in>>M.v[i][j];
        return in;
    }

    Matrice_oarecare& operator=(const Matrice_oarecare& M)
    {
        if(this!=&M)
        {
            cout<<M.linie<<M.coloana<<endl;
            if(linie!=M.linie || coloana!=M.coloana)
            {
                cout<<"Dimensiunile matricelor nu coincid"<<endl;

            }
            else
            {
                for(int i=1; i <=linie; i++)
                    for(int j=1; j<=coloana; j++)
                        this->v[i][j]=M.v[i][j];
            }
        }
        return *this;
    }

    friend Matrice_oarecare& operator+(const Matrice_oarecare&, const Matrice_oarecare&);


    bool triunghiulara_inferior(Matrice_oarecare& M)
    {
        return false;
    }

    bool triunghiulara_superior(Matrice_oarecare& M)
    {
        return false;
    }

    void verificare(Matrice_oarecare& M)
    {
        if(!triunghiulara_inferior(M) && !triunghiulara_superior(M))
            cout<<"Matricea oarecare nu poate fi triunghiulara"<<endl;
        if(linie!=coloana)
            cout<<"Matricea oarecare nu poate fi diagonala"<<endl;
    }
};




class Matrice_patratica : public Matrice
{
protected:
    int dim;
public:
    Matrice_patratica():Matrice()
    {
        this->dim=0;
    }

    Matrice_patratica(int dim):Matrice()
    {
        this->dim=dim;
        this->v= new Complex*[this->dim+1];
        for(int i=1; i<=this->dim; i++)
            v[i]=new Complex[dim+1];
        for(int i=1; i<=dim; i++)
            for(int j=1; j<=dim; j++)
                this->v[i][j]=0;
    }

    Matrice_patratica(const Matrice_patratica& M):Matrice()
    {
        this->dim=dim;
        this->v= new Complex*[this->dim+1];
        for(int i=1; i<=this->dim; i++)
            v[i]=new Complex[dim+1];
        for(int i=1; i<=dim; i++)
            for(int j=1; j<=dim; j++)
                this->v[i][j]=M.v[i][j];
        cout<<"Constructor copiere matrice patratica";
    }

    ~Matrice_patratica()
    {
        for(int i=1; i<=dim; i++)
            delete[] v[i];
        delete[] v;
        cout<<"Destructor matrice patratica"<<endl;
    }

    /*Complex determinant(int dim, Matrice_patratica& M)
    {
        Complex det(0,0);
        Complex a,b,c,d;
        Matrice_patratica submatrice(dim);
        if (this->dim == 2)
        {
            c = M.v[0][0] * M.v[1][1] - (M.v[1][0] * M.v[0][1]);
            return c;
        }
        else
        {
            for (int x = 1; x <= dim; x++)
            {
                int subi = 0;
                for (int i = 1; i < dim; i++)
                {
                    int subj = 0;
                    for (int j = 1; j <= dim; j++)
                    {
                        if (j == x)
                            continue;
                        submatrice.v[subi][subj] = v[i][j];
                        subj++;
                    }
                    subi++;
                }
                det = det + (pow(-1, x) * v[0][x] * determinant(dim-1, submatrice));
            }
        }
        return det;
    }*/

    /*Complex determinant(Matrice_patratica &matrix)
    {
        Complex det(1,0);
        for (int i = 1; i < dim; ++i)
        {
            Complex pivotElement = v[i][i];
            int pivotRow = i;
            for (int row = i + 1; row < dim; ++row)
            {
                if (v[row][i] > pivotElement)
                {
                    pivotElement = v[row][i];
                    pivotRow = row;
                }
            }
            if (pivotElement == 0)
            {
                return 0;
            }
            if (pivotRow != i)
            {
                v[i].swap(v[pivotRow]);
                det *= -1;
            }
            det *= pivotElement;

            for (int row = i + 1; row < dim; ++row)
            {
                for (int col = i + 1; col < dim; ++col)
                {
                    v[row][col] -= v[row][i] * v[i][col] / pivotElement;
                }
            }
        }

        return det;
    }*/

    /*Matrice_patratica& submatrice(int n, int lin, int col, Matrice_patratica& a, Matrice_patratica& b)
    {
    int i, j, c=-1, x=0;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if(i!=lin && j!=col)
            {
                c++;
                if(c==(n-1))
                {
                    c=0;
                    x++;
                }
                b.v[x][c]=a.v[i][j];
            }
    return b;
    }*/

    /*Complex determinant(Matrice_patratica &a,int n)
    {
        int i=0,j=0,se=1;
        Complex t,det;
        Matrice_patratica b(n);
        if(a.dim==1)
            {cout<<"Determinantul:";
            return a.v[i][j];
            }
        if(a.dim==2)
            {cout<<"Determinantul:";
            return a.v[i][j]*a.v[i+1][j+1]-a.v[i+1][j]*a.v[i][j+1];
            }
        if(a.dim==3)
            {cout<<"Determinantul:";
            return a.v[i][j]*a.v[i+1][j+1]*a.v[i+2][j+2]+a.v[i+1][j+2]*a.v[i][j+1]*a.v[i+2][j]+a.v[i+1][j]*a.v[i][j+2]*a.v[i+2][j+1]-a.v[i+2][j+1]*a.v[i][j]*a.v[i+1][j+2]-a.v[i+2][j]*a.v[i][j+2]*a.v[i+1][j+1]-a.v[i+2][j+2]*a.v[i+1][j]*a.v[i][j+1];
            }
        for(j=0; j<a.dim; j++)
        {
            submatrice(a.dim,0,j,a,b);
            t=a.v[0][j]*se;
            se=-se;
            t=t*determinant(a,a.dim-1);
            det=det+t;
        }
        cout<<"Determinantul urat";
        return det;
    }*/

    void citire_matrice()
    {
        cout<<"Matrice creata este de forma ("<<dim<<","<<dim<<")"<<endl;
        for(int i=1; i<=dim; i++)
            for(int j=1; j<=dim; j++)
                cin>>v[i][j];
    }

    void afisare_matrice()
    {
        cout<<"Matricea este de tip patratica"<<endl;
        int i,j;
        if(dim == 0)
            cout<<"Matricea este nula"<<endl;
        else
        {
            cout<<"Matricea creata este:"<<endl;
            for(i=1; i<=dim; i++)
            {
                for(j=1; j<=dim; j++)
                    cout<<v[i][j]<<"   ";
                cout<<endl;
            }
        }
    }

    friend ostream& operator << (ostream& out, Matrice_patratica& M)
    {
        cout<<"Matricea este de tip patratica"<<endl;
        int i,j;
        if(M.dim == 0)
            out<<"Matricea este nula"<<endl;
        else
        {
            out<<"Matricea creata este:"<<endl;
            for(i=1; i<=M.dim; i++)
            {
                for(j=1; j<=M.dim; j++)
                    out<<M.v[i][j]<<"   ";
                out<<endl;
            }
        }
        return out;
    }

    friend istream& operator >> (istream& in, Matrice_patratica& M)
    {
        cout<<"Matrice creata este de forma ("<<M.dim<<","<<M.dim<<")"<<endl;
        for(int i=1; i<=M.dim; i++)
            for(int j=1; j<=M.dim; j++)
                in>>M.v[i][j];
        return in;
    }

    Matrice_patratica& operator=(const Matrice_patratica& M)
    {
        if(this!=&M)
        {
            if(dim != M.dim)
                cout<<"Dimensiunile matricelor nu coincid"<<endl;
            else
            {
                for(int i=1; i <=dim; i++)
                    for(int j=1; j<=dim; j++)
                        this->v[i][j]=M.v[i][j];
            }
        }
        return *this;
    }

    bool triunghiulara_superior()
    {
        int i,j;
        ///superior triunghiulara
        for(i=2; i<=dim; i++)
            for(j=1; j<i; j++)
                if(v[i][j]!=Complex(0,0))
                {
                    //cout<<"Matricea nu este triunghiulara"<<endl;
                    return false;
                }
                else if(v[i][j]==Complex(0,0))
                {
                    //cout<<"Matricea este triunghiulara"<<endl;
                    return true;
                }
    }

    bool triunghiulara_inferior()
    {
        ///inferior triunghiulara
        int i,j;
        for(i=1; i<dim; i++)
            for(j=i+1; j<=dim; j++)
                if(v[i][j]!=Complex(0,0))
                {
                    //cout<<"Matricea nu este triunghiulara"<<endl;
                    return false;
                }
                else if(v[i][j]==Complex(0,0))
                {
                    //cout<<"Matricea este triunghiulara"<<endl;
                    return true;
                }
    }

    bool diagonala()
    {
        int i,j;
        for(i=1; i<=dim; i++)
            for(j=1; j<=dim; j++)
                if(i==j)
                {
                    if(v[i][j]==Complex(0,0))
                    {
                        //cout<<"Matricea triunghiulara nu e diagonala"<<endl;
                        return false;
                    }
                    else if(v[i][j]!=Complex(0,0))
                    {
                        //cout<<"Matricea triunghiulara e diagonala"<<endl;
                        return true;
                    }
                }
    }

    void verificare()
    {
        if(triunghiulara_inferior() && triunghiulara_superior())
        {
            if(diagonala())
                cout<<"Matricea triunghiulara e diagonala"<<endl;
            else
                cout<<"Matricea triunghiulara nu e diagonala"<<endl;
        }
        else if(triunghiulara_inferior()==1 && triunghiulara_superior()==0)
        {
            cout<<"Matricea este triunghiulara, dar nu si diagonala"<<endl;
        }
        else if(triunghiulara_inferior()==0 && triunghiulara_superior()==1)
        {
            cout<<"Matricea este triunghiulara, dar nu si diagonala"<<endl;
        }
        else
        {
            cout<<"Matricea nu e triunghiulara si nici diagonala"<<endl;
        }
    }
};

void meniu_complex();
void meniu_matrice_oarecare();
void meniu_matrice_patratica();
void N_matrici();

void meniu_complex()
{
    int alegere,x,y;
    Complex z;
    cin>>z;
    z.afisare();
    cout<<endl;

    while (1)
    {
        cout<<endl<<"Operatii posibile asupra numarului complex:"<<endl;

        cout<<"1.Creare numar complex"<<endl;

        cout<<"2.Afisare numar complex"<<endl;

        cout<<"3.Modulul unui numar complex"<<endl;

        cout<<"4.Adunarea a doua numere complexe"<<endl;

        cout<<"5.Scaderea a doua numere complexe"<<endl;

        cout<<"6.Inmultirea a doua numere complexe"<<endl;

        cout<<"7.Inmultirea unui numar complex cu un scalar"<<endl;

        cout<<"8.Impartirea a doua numere complexe"<<endl;

        cout<<"9.Operatia de atribuire"<<endl;

        cout<<"10.Matrice oarecare"<<endl;

        cout<<"11.Matrice patratica"<<endl;

        cout<<"12.Crearea a n obiecte de tip matrice oarecare si matrice patratica"<<endl;

        cout<<"13.Iesire"<<endl;

        cout<<endl;

        cout<<"Ce operatie doriti sa efectuati?"<<endl;

        cin>>alegere;

        switch(alegere)
        {
        case 1:

        {
            //cout<<"Posibilitati:"<<endl;
            /*cout<<"1. Creare numar complex doar cu parte reala"<<endl;
            cout<<"Partea reala a numarului dorit este:"<<endl;
            cin>>x;
            Complex b(x);
            cout<<"Afisare numar complex:"<<endl;
            b.afisare();
            cout<<endl;*/

            cout<<"2. Creare numar complex"<<endl;
            cout<<"Partea reala a numarului complex este:"<<endl;
            cin>>x;
            cout<<"Partea imaginara a numarului complex este:"<<endl;
            cin>>y;
            Complex c(x,y);
            cout<<"Afisare numar complex:"<<endl;
            c.afisare();
            cout<<endl;

            /*cout<<"3. Creare numar complex cu ajutorul functiei de citire"<<endl;
            Complex z;
            z.citire();
            cout<<"Afisare numar complex:"<<endl;
            z.afisare();
            cout<<endl;
            //cin>>z;
            //cout<<z;*/

            break;
        }

        case 2:

            cout<<"Afisare numar complex:"<<endl;
            z.afisare();
            cout<<endl;
            break;

        case 3:

            z.modul();
            cout<<endl;
            break;

        case 4:

        {
            Complex z1, z2;
            cout<<"Cele doua numere pe care vreti sa le adunati:"<<endl;
            cin>>z1;
            z2.citire();
            Complex z;
            z = z1 + z2;
            cout<<"Rezultatul final:"<<endl;
            z.afisare();
            cout<<endl;
            break;
        }

        case 5:

        {
            Complex z1, z2;
            cout<<"Cele doua numere pe care vreti sa le scadeti:"<<endl;
            cin>>z1;
            z2.citire();
            Complex z;
            z = z1 - z2;
            cout<<"Rezultatul final:"<<endl;
            z.afisare();
            cout<<endl;
            break;
        }

        case 6:

        {
            Complex z1, z2;
            cout<<"Cele doua numere pe care vreti sa le inmultiti:"<<endl;
            cin>>z1;
            z2.citire();
            Complex z;
            z = z1 * z2;
            cout<<"Rezultatul final:"<<endl;
            z.afisare();
            cout<<endl;
            break;
        }

        case 7:

        {
            Complex z;
            cin>>z;
            cout<<"Scalarul este:"<<endl;
            cin>>x;
            z = z*x;
            cout<<z;
            cout<<endl;
            break;
        }

        case 8:

        {
            Complex z1, z2;
            cout<<"Cele doua numere pe care vreti sa le impartiti:"<<endl;
            cin>>z1;
            z2.citire();
            Complex z;
            z = z1 / z2;
            cout<<"Rezultatul final:"<<endl;
            z.afisare();
            cout<<endl;
            break;
        }

        case 9:

        {
            Complex z1;
            Complex z2;
            z1.citire();
            //cin>>z1;
            z2.citire();
            //cin>>z2;
            z1=z2;
            cout<<"Numarul modificat este:"<<endl;
            z1.afisare();
            cout<<endl;

            break;
        }

        case 10:

            meniu_matrice_oarecare();
            break;

        case 11:

            meniu_matrice_patratica();
            break;

        case 12:

            N_matrici();
            break;

        case 13:

            cout<<endl;
            cout<<"Iesire din program..."<<endl;
            exit(1);
            break;

        default:

            cout<<"Nu s-a putut efectua operatia. Incercati din nou!"<<endl;
        }
    }
}

void meniu_matrice_oarecare()
{
    int alegere,x,y,x1,y1;
    cout<<"Numarul de linii: ";
    cin>>x;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout<<"Ai introdus tipul de data gresit!"<<endl;
        cout<<"Numarul corect de linii = ";
        cin>>x;
    }
    cout<<"Numarul de coloane: ";
    cin>>y;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout<<"Ai introdus tipul de data gresit!"<<endl;
        cout<<"Numarul corect de coloane = ";
        cin>>y;
    }
    if(x < 0 || y < 0)
    {
        cout<<"Dimensiunile nu pot fi negative!"<<endl;
        cout<<"Numarul de linii = ";
        cin>>x;
        cout<<"Numarul de coloane = ";
        cin>>y;
    }
    else if(x == y)
    {
        cout<<"Matricea este oarecare!"<<endl;
        cout<<"Numarul de linii = ";
        cin>>x;
        cout<<"Numarul de coloane = ";
        cin>>y;
    }
    Matrice_oarecare M(x,y);
    M.citire_matrice();
    M.afisare_matrice();


    while (1)
    {
        cout<<endl<<"Operatii posibile asupra matricii oarecare:"<<endl;

        cout<<"1.Creare matrice oarecare"<<endl;

        cout<<"2.Afisare matrice oarecare"<<endl;

        cout<<"3.Operatia de atribuire"<<endl;

        cout<<"4.Verificare matrice triunghiulara si diagonala"<<endl;

        cout<<"5.Complex"<<endl;

        cout<<"6.Matrice patratica"<<endl;

        cout<<"7.Crearea a n obiecte de tip matrice oarecare si matrice patratica"<<endl;

        cout<<"8.Iesire"<<endl;

        cout<<endl;

        cout<<"Ce operatie doriti sa efectuati?"<<endl;

        cin>>alegere;

        switch(alegere)
        {
        case 1:

        {
            cout<<"Posibilitati:"<<endl;
            cout<<"1. Apelare prin functii"<<endl;
            Matrice *M;
            cout<<"Numarul de linii = ";
            cin>>x;
            cout<<"Numarul de coloane =";
            cin>>y;
            Matrice_oarecare mat(x,y);
            if(x < 0 || y < 0)
            {
                cout<<"Dimensiunile nu pot fi negative!"<<endl;
                cout<<"Numarul de linii = ";
                cin>>x;
                cout<<"Numarul de coloane = ";
                cin>>y;
                Matrice_oarecare mat(x,y);
                continue;
            }
            else if(x == y)
            {
                cout<<"Matricea este oarecare!"<<endl;
                cout<<"Numarul de linii = ";
                cin>>x;
                cout<<"Numarul de coloane = ";
                cin>>y;
                Matrice_oarecare mat(x,y);
                continue;
            }
            M=&mat;
            M->citire_matrice();
            M->afisare_matrice();
            cout<<endl;
        }
            /*Matrice_oarecare X(2,2);
            X.citire_matrice();
            X.afisare_matrice();
            cout<<endl;*/

            /*cout<<"2. Apelare prin operatori supraincarcati"<<endl;
            Matrice_oarecare X(1,2);
            cin>>X;
            cout<<X;
            cout<<endl;*/

        break;

        case 2:

            cout<<"Afisare matrice oarecare:"<<endl;
            M.afisare_matrice();
            cout<<endl;
            break;

        case 3:

        {
            cout<<"Numarul de linii pentru prima matrice: "<<endl;
            cin>>x;
            cout<<"Numarul de coloane pentru a doua matrice: "<<endl;
            cin>>y;
            Matrice_oarecare X(x,y);
            cout<<"Numarul de linii pentru a doua matrice: "<<endl;
            cin>>x1;
            cout<<"Numarul de linii pentru a doua matrice: "<<endl;
            cin>>y1;
            Matrice_oarecare Y(x1,y1);
            cin>>X;
            cin>>Y;
            cout<<X;
            cout<<Y;
            Y=X;
            cout<<"Matricea modificata este:"<<endl;
            cout<<Y;
            cout<<endl;
            break;
        }

        case 4:

        {
            Matrice_oarecare M(2,3);
            M.verificare(M);
            cout<<endl;
            break;
        }

        case 5:

        {
            meniu_complex();
            break;
        }

        case 6:

        {
            meniu_matrice_patratica();
            break;
        }

        case 7:

        {
            N_matrici();
            break;
        }


        case 8:

            cout<<endl;
            cout<<"Iesire din program..."<<endl;
            exit(1);
            break;

        default:

            cout<<"Nu s-a putut efectua operatia. Incercati din nou!"<<endl;
        }
    }
}

void meniu_matrice_patratica()
{
    int alegere,x,x1;
    cout<<"Dimensiunea matricei este: ";
    cin>>x;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout<<"Ai introdus tipul de data gresit!"<<endl;
        cout<<"Dimensiunea corecta a matricei: ";
        cin>>x;
    }
    if(x < 0)
    {
        cout<<"Dimensiunea nu pot fi negativa!"<<endl;
        cout<<"Dimensiunea matricei este = ";
        cin>>x;
    }
    Matrice_patratica M(x);
    M.citire_matrice();
    M.afisare_matrice();

    while (1)
    {
        cout<<endl<<"Operatii posibile asupra matricii patratice:"<<endl;

        cout<<"1.Creare matrice patratica"<<endl;

        cout<<"2.Afisare matrice patratica"<<endl;

        cout<<"3.Operatia de atribuire"<<endl;

        cout<<"4.Verificare matrice triunghiulara si diagonala"<<endl;

        cout<<"5.Complex"<<endl;

        cout<<"6.Matrice oarecare"<<endl;

        cout<<"7.Crearea a n obiecte de tip matrice oarecare si matrice patratica"<<endl;

        cout<<"8.Iesire"<<endl;

        cout<<endl;

        cout<<"Ce operatie doriti sa efectuati?"<<endl;

        cin>>alegere;

        switch(alegere)
        {
        case 1:

        {
            cout<<"Posibilitati:"<<endl;
            cout<<"1. Apelare prin functii"<<endl;
            cout<<"Dimensiunea matricei =  ";
            cin>>x;
            Matrice_patratica mat(x);
            if(x < 0)
            {
                cout<<"Dimensiunea nu pot fi negativa!"<<endl;
                cout<<"Dimensiunea matricei este = ";
                cin>>x;
            }
            M.citire_matrice();
            M.afisare_matrice();
            cout<<endl;
        }
            /*Matrice_oarecare X(2,2);
            X.citire_matrice();
            X.afisare_matrice();
            cout<<endl;*/

            /*cout<<"2. Apelare prin operatori supraincarcati"<<endl;
            Matrice_oarecare X(1,2);
            cin>>X;
            cout<<X;
            cout<<endl;*/

        break;

        case 2:

            cout<<"Afisare matrice patratica:"<<endl;
            M.afisare_matrice();
            cout<<endl;
            break;

        case 3:

        {
            cout<<"Dimensiunea primei matrici: "<<endl;
            cin>>x;
            Matrice_patratica X(x);
            cout<<"Dimensiunea celei de-a doua matrici: "<<endl;
            cin>>x1;
            Matrice_patratica Y(x1);
            if(x != x1)
            {
                cout<<"Matricile nu se pot compara!"<<endl;
                return;
            }
            cin>>X;
            cin>>Y;
            cout<<X;
            cout<<Y;
            Y=X;
            cout<<"Matricea modificata este:"<<endl;
            cout<<Y;
            cout<<endl;
            break;
        }

        case 4:

        {
            cout<<"Dimensiunea matricei pe care vrei sa o testezi: "<<endl;
            cin>>x;
            Matrice_patratica M(x);
            cin>>M;
            cout<<M;
            M.verificare();
            cout<<endl;
            break;
        }

        case 5:

        {
            meniu_complex();
            break;
        }

        case 6:

        {
            meniu_matrice_oarecare();
            break;
        }

        case 7:

        {
            N_matrici();
            break;
        }

        case 8:

            cout<<endl;
            cout<<"Iesire din program..."<<endl;
            exit(1);
            break;

        default:

            cout<<"Nu s-a putut efectua operatia. Incercati din nou!"<<endl;
        }
    }
}

void N_matrici()
{
    srand(time(NULL));
    Matrice **v;
    int n,x,y,nr,x1;
    cout<<"Introduceti numarul de obiecte: "<<endl;
    cin>>n;
    v = new Matrice* [n];
    int i;
    for(i=1; i<=n; i++)
    {
        nr=rand()%100+1;
        cout<<nr<<endl;
        if(nr%2==0)
        {
            x=rand()%6+1;
            y=rand()%6+1;
            cout<<"cazul 1"<<endl;
            cout<<x<<" "<<y<<endl;
            if(x == y)
            {
                cout<<"Matricea a fost transformata in matrice patratica!"<<endl;
                v[i] = new Matrice_patratica(x);
            }
            else
            {
                cout<<"cazul 2"<<endl;
                v[i] = new Matrice_oarecare(x,y);
            }
        }
        else
        {
            cout<<"cazul 3"<<endl;
            x1=rand()%5+1;
            v[i] = new Matrice_patratica(x1);
        }
        v[i]->citire_matrice();
    }

    for(i=1; i<=n; i++)
        v[i]->afisare_matrice();
}

int main()
{
    ///COMPLEX
    ///apelare constructor parametrizat cu o singura valoare (partea reala)
    /*Complex b(-7);
    b.afisare();
    cout<<endl;*/

    ///apelare constructor dublu parametrizat cu valori specifice pentru ambii termeni
    /*Complex c(10,-2);
    c.afisare();
    cout<<endl;
    Complex d(0,-5);
    d.afisare();
    cout<<endl;*/

    ///apelare functii supraincarcate citire si afisare
    /*Complex z;
    cin>>z;
    cout<<z;*/

    ///apelare functie modul
    /*Complex z;
    cin>>z;
    cout<<z;
    z.modul();*/

    ///apelare supraincarcare operatii + - * /
    /*Complex z1, z2;
    cin>>z1;
    z2.citire();
    Complex z, zz, zzz, zzzz;
    z = z1 + z2;
    zz = z1 - z2;
    zzz = z1 * z2;
    zzzz = z1 / z2;
    cout<<z<<endl;
    zz.afisare();
    cout<<endl;
    cout<<zzz<<endl;
    zzzz.afisare();
    cout<<endl;*/

    ///apelare supraincarcare operator =
    /*Complex z1;
    Complex z2;
    z1.citire();
    //cin>>z1;
    z2.citire();
    //cin>>z2;
    z1=z2;
    cout<<"Numarul modificat este:"<<endl;
    z1.afisare();
    cout<<endl;
    //cout<<z1;*/

    ///MATRICI OARECARE
    ///apelare constructori matrice oarecare
    /*
       Matrice *M;
       Matrice_oarecare mat(2,2);
       M=&mat;
       M->citire_matrice();
       M->afisare_matrice();
    */

    ///apelare constructori matrice oarecare
    /*
    Matrice_oarecare X(2,2);
    Matrice_oarecare Y(2,2);
    X.citire_matrice();
    X.afisare_matrice();
    */

    ///apelare supraincarcare << >> pentru matrice oarecare si operatorul=
    /*Matrice_oarecare X(1,2);
    Matrice_oarecare Y(2,2);
    cin>>X;
    cin>>Y;
    cout<<X;
    cout<<Y;
    Y=X;
    cout<<Y;*/

    ///apelare functie verificare matrice triunghiulara + diagonala
    /*Complex z;
    cin>>z;
    cout<<z;
    int nr=1;
    //z==nr;
    z!=nr;*/

    /*Matrice_oarecare M(2,3);
    M.verificare(M);*/

    ///apelare functie operator +
    /*Matrice_oarecare mat1(2,3);
    Matrice_oarecare mat2(1,3);
    Matrice_oarecare mat(2,3);
    cin>>mat1>>mat2;
    cout<<mat1<<endl;
    cout<<mat2<<endl;
    mat = mat1 + mat2;
    cout<<mat;*/



    ///MATRICI PATRATICE
    ///apelare functii citire si afisare
    /*Matrice *M;
    Matrice_patratica mat(3);
    M=&mat;
    M->citire_matrice();
    M->afisare_matrice();

    Matrice_patratica mati(1);
    mati.citire_matrice();
    mati.afisare_matrice();*/

    ///apelare functii supraincarcare citire si afisare
    /*Matrice_patratica m(2);
    cin>>m;
    cout<<m;*/

    ///apelare supraincarcare operator =
    /*Matrice_patratica M1(2);
    Matrice_patratica M2(2);
    cin>>M1;
    cin>>M2;
    M1=M2;
    cout<<"Dupa modificare"<<endl;
    cout<<M1;*/

    ///verificare matrice triunghiulara + diagonala
    /*Matrice_patratica M(2);
    cin>>M;
    M.verificare();*/

    ///apelare determinant matrice patratica
    /*Matrice_patratica M1(2);
    Complex x;
    cin>>M1;
    cout<<M1;
    x = M1.determinant(2,M1);
    cout<<x;*/

    int alegere;

    while (1)
    {
        cout<<"Operatii posibile:"<<endl;

        cout<<"1.Numere complexe"<<endl;

        cout<<"2.Matrice oarecare"<<endl;

        cout<<"3.Matrice patratica"<<endl;

        cout<<"4.Crearea a n obiecte de tip matrice oarecare si matrice patratica"<<endl;

        cout<<"5.Iesire"<<endl;

        cout<<endl;

        cout<<"Ce operatie doriti sa efectuati?"<<endl;

        cin>>alegere;

        switch(alegere)
        {
        case 1:

            meniu_complex();
            break;

        case 2:

            meniu_matrice_oarecare();
            break;

        case 3:
            meniu_matrice_patratica();
            break;

        case 4:
            N_matrici();
            break;

        case 5:

            cout<<endl;
            cout<<"Iesire din program..."<<endl;
            exit(1);
            break;

        default:

            cout<<"Nu s-a putut efectua operatia! Incercati din nou!"<<endl;

        }
    }

    return 0;
}
