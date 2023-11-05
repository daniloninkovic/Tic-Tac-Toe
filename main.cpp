#include <iostream>

using namespace std;

//X je broj 11//
//O je broj 12//

int matrica[3][3];
char brojpolja[10] = {'0','1','2','3','4','5','6','7','8','9'};
void ispis ()
{
    cout << "\n\n\Player 1 (X)   -   Player 2 (O)\n\n";

    cout << " _____ _____ _____"<<endl;
    cout << "|     |     |     |" << endl;
    cout << "|  " << brojpolja[1] << "  |  " << brojpolja[2] << "  |  " << brojpolja[3] << "  |  " << endl;

    cout << "|_____|_____|_____|" << endl;
    cout << "|     |     |     |" << endl;

    cout << "|  " << brojpolja[4] << "  |  " << brojpolja[5] << "  |  " << brojpolja[6] << "  |  " << endl;

    cout << "|_____|_____|_____|" << endl;
    cout << "|     |     |     |" << endl;

    cout << "|  " << brojpolja[7] << "  |  " << brojpolja[8] << "  |  " << brojpolja[9] << "  |  " << endl;

    cout << "|_____|_____|_____|" << endl << endl;
}
//U odnosu na broj u tabeli, funkcija racuna u kojoj je koloni broj//
int pretvorikolonu(int pozicija)
{
    if (pozicija%3==1)
    {
        return 0;
    }
    else if (pozicija%3==2)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}
//U odnosu na broj u tabeli, funkcija racuna u kom je redu broj//
int pretvorired(int pozicija)
{
    if(pozicija<=3)
    {
        return 0;
    }
    else if (pozicija<=6)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}
//Funkcija provera da li na kraju svakog unosenja broja postoji pobednik//
int provera(int red, int kolona, char simbol)
{
    int pom;
    if (simbol=='X')
    {
        pom = 11;
    }
    else
    {
        pom = 12;
    }
    if (matrica[0][kolona]==pom && matrica[1][kolona]==pom && matrica[2][kolona]==pom)
    {
        return 1;
    }
    if (matrica[red][0]==pom && matrica[red][1]==pom && matrica[red][2]==pom)
    {
        return 1;
    }
    if (matrica[0][0]==pom && matrica[1][1]==pom && matrica[2][2]==pom)
    {
        return 1;
    }
    if (matrica[2][0]==pom && matrica[1][1]==pom && matrica[0][2]==pom)
    {
        return 1;
    }
    return 0;
}
int main()
{
    ispis();
    int broj, kolona, red, igrac, unos, pom, brojac;
    char simbol;
    for(int i=0; i<9; i++)
    {
        brojac = 0;
        if(i%2==0)
        {
            igrac = 1;
            simbol = 'X';
            pom = 11;
        }
        else
        {
            igrac = 2;
            simbol = 'O';
            pom = 12;
        }
        cout << "Player " << igrac << ", enter the number: ";
        cin >> broj;
        //Proveravamo da li je uneti broj uopste u tablici//
        if (broj<1 || broj>9)
        {
            unos = 0;
            cout << "Error, please enter another field:" << endl;
        }
        kolona = pretvorikolonu(broj);
        red = pretvorired(broj);
        //Proveravamo da li je uneti broj vec prethodno unet u nekom od prethodnih koraka//
        if(matrica[red][kolona]==11 || matrica[red][kolona]==12)
        {
            unos = 0;
            cout << "Error, please enter another field:" << endl;
        }
        //Ako je broj vec unet, zahtevamo unosenje drugog broja//
        while(unos==0)
        {
            cin >> broj;
            kolona = pretvorikolonu(broj);
            red = pretvorired(broj);
            if (broj<1 || broj>9)
            {
                cout << "Error, please enter another field: " << endl;
            }
            else
            {
               if(matrica[red][kolona]==11 || matrica[red][kolona]==12)
               {
                   cout << "Error, please enter another field: " << endl;
               }
               else
               {
                //Ako je novi broj unet, a razlikuje se od svih prethodnih i u granicama je,//
                //postavljamo novu vrednost promenljive kako bismo izasli iz petlje//
                   unos = 1;
               }
            }
        }
        kolona = pretvorikolonu(broj);
        red = pretvorired(broj);
        matrica[red][kolona] = pom;
        brojpolja[broj] = simbol;
        ispis();
        //Proveramo da li je neki od postavljenih uslova zadovoljen i u zavisnosti//
        //od parnosti koraka odredjujemo koji je igrac pobedio i prekidamo kod//
        if (provera(red,kolona,simbol)==1)
        {
            cout << "Player " << igrac << " won.";
            break;
        }
        else
        {
            brojac++;
        }
    }
    if (brojac!=0)
    {
        cout << "Tied." << endl;
    }
    //Ukoliko ni jedan igrac nije pobedio, izbacujemo da je nereseno//
    return 0;
}
