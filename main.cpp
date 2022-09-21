#include <iostream>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::stoi;
using std::string;
using std::stringstream;

// using namespace std;

//* LIMPIAR CONSOLA
void clear()
{
    cout << "\x1B[2J\x1B[H";
}

class Date
{
private:
    int date;
    int Anio,
        Mes,
        Dia;

public:
    Date(string date);
    ~Date()
    {
        cout << "Destructor";
    }
    int VerificarFecha();
    int VerificarBisiesto();
    void imprimirFecha();
};

Date::Date(string date)
{
    //* Dividir fecha

    stringstream input_stringstream(date); // Convertir la cadena a un stream

    string strAnio, strMes, strDia;

    char delimitador = '/';
    getline(input_stringstream, strAnio, delimitador);
    getline(input_stringstream, strMes, delimitador);
    getline(input_stringstream, strDia, delimitador);

    //* Convertir a entero

    this->Dia = stoi(strDia);
    this->Mes = stoi(strMes);
    this->Anio = stoi(strAnio);
}

int Date::VerificarFecha()
{
    //! Año
    if (this->Anio < 1)
    {
        this->Anio = 1;
    }
    if (this->Anio > 2100)
    {
        this->Anio = 2100;
    }
    //! Mes
    if (this->Mes < 1 || this->Mes > 12)
    {
        this->Mes = 12;
    }
    //! Dias
    if (this->Mes == 1 || this->Mes == 3 || this->Mes == 5 || this->Mes == 7 || this->Mes == 8 || this->Mes == 10 || this->Mes == 12)
    {
        if (this->Dia < 1)
        {
            this->Dia = 1;
        }
        if (this->Dia > 31)
        {
            this->Dia = 31;
        }
    }
    if (this->Mes == 2)
    {
        if (this->Dia < 1)
        {
            this->Dia = 1;
        }
        if (this->Dia > 28)
        {
            this->Dia = 28;
        }
    }
    if (this->Mes == 4 || this->Mes == 6 || this->Mes == 9 || this->Mes == 11)
    {
        if (this->Dia < 1)
        {
            this->Dia = 1;
        }
        if (this->Dia > 30)
        {
            this->Dia = 30;
        }
    }
}

int Date::VerificarBisiesto()
{
    if (this->Anio % 4 == 0 and this->Anio % 100 != 0 or this->Anio % 400 == 0)
    {
        cout << "El anio " << this->Anio << " SI es Bisiesto" << endl;
    }
    else
    {
        cout << "El anio " << this->Anio << " NO es Bisiesto" << endl;
    }
}

void Date::imprimirFecha()
{
    cout << endl;
    cout << "Fecha desglozada" << endl;
    cout << "Dia: " << this->Dia << endl;
    cout << "Mes: " << this->Mes << endl;
    cout << "Anio: " << this->Anio << endl;
}

int main()
{
    string date;
    char opc;

    while (opc != 'q')
    {
        cout << "Ingresa una fecha con el siguiente formato: 2020/09/20" << endl;
        cin >> date;
        cout << endl;

        Date *_Date = new Date(date);

        _Date->VerificarFecha();
        _Date->VerificarBisiesto();

        _Date->imprimirFecha();

        delete _Date;

        cout << endl;
        cout << "Desea repetir el programa?  SI = s | No = q";
        cin >> opc;

        clear();
    }
    return 0;
}

// Verficar el formato (Talvez Proximamente)
/*

#include <iomanip>
using std::get_time;

bool VerificarFormato(string &posible_fecha)
{
    std::stringstream fecha;
    std::tm tm;

    fecha << posible_fecha;

    return static_cast<bool>(fecha >> get_time(&tm, "%d/%m/%Y"));
}
*/