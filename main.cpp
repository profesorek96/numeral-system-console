#include <iostream>
#include <algorithm>

using namespace std;


string konwersja_z_dec_na_dowolny(int liczba,int system){

string skon_liczba;
int znak;

while(liczba>0){
    znak=liczba%system;
    if(znak<=9)skon_liczba+=(znak+48);
    else skon_liczba+=(znak+55);
    liczba/=system;
}

reverse(skon_liczba.begin(), skon_liczba.end());
return skon_liczba;

}




int konwersja_z_dowolnego_na_dec(string liczba, int system){
int liczba_dec=0;
int potega=1;
for(int i=liczba.length()-1;i>=0;i--){
    if(liczba[i]>='0'&&liczba[i]<='9')liczba_dec+=(liczba[i]-48)*potega;
    else liczba_dec+=(liczba[i]-55)*potega;
    potega*=system;
}

return liczba_dec;



}


int main()
{
    int system,system_kon;
    int liczba_dec=0;
    int d;
    string liczba;
    cout<<"Numeral system:"<<endl;
    cout<<"Podaj liczbe:";
    cin>>liczba;
    cout<<"Podaj system jakiego jest podana liczba:";
    cin>>system;
    cout<<"Podaj system na ktory ma byc skonwertowana podana liczba:";
    cin>>system_kon;

   if(system==10){
        d=liczba.length();
        for(int i=0;i<d;i++){
        liczba_dec+=liczba[i]-48;
        liczba_dec*=10;
        }
        liczba_dec/=10;

        cout<<konwersja_z_dec_na_dowolny(liczba_dec,system_kon);

   }
    else if(system_kon==10)cout<<konwersja_z_dowolnego_na_dec(liczba,system);

    else cout<<konwersja_z_dec_na_dowolny(konwersja_z_dowolnego_na_dec(liczba,system),system_kon);



    cout<<endl;

    cout<<"Program zostal wykonany przez Krzysztofa Losa"<<endl;
    cout<<"profesorek96.blogspot.com"<<endl;


    cin.sync();
    cin.get();
    return 0;
}
