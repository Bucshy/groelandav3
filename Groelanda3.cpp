#include <iostream>
using namespace std;
int citir(int v[], int n)
{if (n!=0){
citire(v,n-1);
cin>>v[n];
}
}
int afisar(int v[],int n)
{if (n!=0){
afisare(v,n-1);
cout<<v[n]<<" ";
}
}
int main()
{
    int n,v[21];
    cin>>n;
    citire(v,n);
    afisare(v,n);
    return 0;
}

void citire(int v[],int n)
{
    if (n!=0){
    citire(v,n-1);
    cin>>v[n];
}
}
void afisare(int v[],int n)
{if (n!=0){
afisare(v,n-1);
cout<<v[n]<<" ";
}
}
int numarare1(int v[],int st,int dr)
{   
    if(st==dr)
    return v[st];
    else{
        int mij=(st+dr)/2;
       if (numarare1(v,st,mij)==numarare1(v,mij+1,dr))
       return 1;
    }
}
int gh=1,gj=2;
int numarare(int v[],int n)
{
    if(numarare1(v,n,gj)==numarare1(v,n-1,gh))
    return 1+numarare(v,n);

}
int suma1(int v[],int st,int dr)
{   if(st==dr) return v[st];
    else 
    {
        int mij=(st+dr)/2;
        return suma1(v,st,mij)+suma1(v,mij+1,dr);
    }

}
int suma(int v[],int n, int i, int j)
{ 
    return(suma1(v,1,i-1)+suma1(v,j+1,n));
}
void num(int v[],int n)
{
    if (n!=0){
    num(v,n-1);
    cin>>v[n];
    if(v[n]<v[1])
    v[n]=0;
    cout<<v[n]<<" ";
}
}
int oglindit(int n)
{
    int p=0;
    if(n)
    p=p+n%10;
    return p+(oglindit(n/10)*10);
}
void muta(int v[],int n)
{
    v[n]=v[n+1];
    muta(v,n+1);
}
int elimina(int v[],int n)
{   
    if(v[n]==oglindit(v[n]))
    muta(v,n);

}
void afisare1(int v[],int n)
{if (n!=0){
afisare(v,n-1);
if(oglindit(v[n]))
muta(v,n);
cout<<v[n]<<" ";
}
}
int main()
{
    cout<<"Bun venit in meniu"<<endl;
    cout<<"Pentru a alege o cerinta, alege un numar de la 1 la 4,inclusiv, pentru a selecta o cerinta"<<endl;
    cout<<"1-cerinta 1 numarare"<<endl<<"2=cerinta 2 suma"<<endl<<"3-cerinta 3 num"<<endl<<"4-cerinta 4 elimina"<<endl;
    cout<<"Introduce cerinta!"<<endl;
    int i,v[10001],n,m,q;
    cin>>i;
    if(i==1)
    {   cout<<"introdu cifra"<<endl;
        cin>>n;
        cout<<"introdu elementele sirului"<<endl;
        citire(v,n);
        cout<<"rezultatul este"<<" "<<numarare(v,n);
    }
    if(i==2){
        cout<<"introdu cifra"<<endl;
        cin>>n;
        cout<<"introdu elementele sirului"<<endl;
        citire(v,n);
        cout<<"introdu intervalul interzis"<<endl;
        cin>>m>>q;
        cout<<"rezultatul este"<<" "<<suma(v,n,m,q);
    }
    if(i==3)
    {   
        cout<<"introdu cifra"<<endl;
        cin>>n;
        cout<<"introdu elementele sirului"<<endl;
        num(v,n);
    }
    if(i==4)
    { 
        cout<<"introdu cifra"<<endl;
        cin>>n;
        cout<<"introdu elementele sirului"<<endl;
        citire(v,n);
        elimina(v,n);
        cout<<"sirul fara palindrom este"<<" ";
        afisare1(v,n);
    }
    return 0;
}
int CautareBinara(int Left, int Right, int x)
{   int V[122];
    if(Left > Right)
        return -1;
    else
    {
        int Mid =(Left+Right)/2;
        if(x == V[Mid])
            return Mid;
        if(x < V[Mid])
            return CautareBinara(Left, Mid-1, x);
        else
            return CautareBinara(Mid+1, Right, x);
    }
}

void QuickSort(int v[], int st, int dr)
{
	if(st < dr)
	{
		//pivotul este inițial v[st]
		int m = (st + dr) / 2;
		int aux = v[st];
		v[st] = v[m];
		v[m] = aux;
		int i = st , j = dr, d = 0;
		while(i < j)
		{
			if(v[i] > v[j])
			{
				aux = v[i]; 
				v[i] = v[j];
				v[j] = aux;
				d = 1 - d;
			}
			i += d;
			j -= 1 - d;
		}
		QuickSort(v, st , i - 1);
		QuickSort(v, i + 1 , dr);
	}
}
int tmp[21];
void MergeSort(int v[], int st, int dr)
{
	if(st < dr)
	{
		int m = (st + dr) / 2;
		MergeSort(v, st , m);
		MergeSort(v, m + 1 , dr);
		//Interclasare
		int i = st, j = m + 1, k = 0;
		while( i <= m && j <= dr )
			if( v[i] < v[j])
				tmp[++k] = v[i++];
			else
				tmp[++k] = v[j++];
		while(i <= m)
			tmp[++k] = v[i++];
		while(j <= dr)
			tmp[++k] = v[j++];
		for(i = st , j = 1 ; i <= dr ; i ++ , j ++)
			v[i] = tmp[j];
	}
}
int cmmdcRec(a, b) {
    if(a == 0 || b == 0) {
        //Primul caz de bază: cmmdc(a, 0) = 0
        return 0;
    }
    if(a == b) {
        //Al doilea caz de bază: cmmdc(a, a) = a
        return a;
    }
    //Conform observației de mai sus,
    //cmmdc(a, b) = cmmdc(a - b, b), pt a > b
    //cmmdc(a, b) = cmmdc(a, b - a), pt a < b
    if(a > b) {
        return cmmdcRec(a - b, b);
    } else {
        return cmmdcRec(a, b - a);
    }
}
int fact(int n)
{if(n==0)
      return 1;
   else return n*fact(n-1);
}
int suma (int n) 
{ if(n==0)return 0; 
   else return suma (n-1) + n; } 
int main() 
{ int n; 
cin>>n;
cout<<suma(n);
return 0;
}
///Suma a n numere citite de la tastatura

int suma (int n)
{int a;
    if(n==0)return 0;
    else {cin>>a;
        return suma (n-1) + a;}
}
int main()
{
    int n; cin>>n;
    cout<<suma(n);
    return 0;
}
///Suma cifrelor unui numar

int suma (int n)
{
    if(n==0)return 0;
    else
        return suma (n/10) + n%10;
}
int main()
{
    int n; cin>>n;
    cout<<suma(n);
    return 0;
}
///Suma elementelor unui vector

int v[50],n,i;

int vector(int v[50], int n)
{
    if(n==0) return 0;
    else return v[n-1]+vector(v, n-1);
}
int main()
{
    int i;
    cin>>n;
    for (i=0; i<n; i++)
         cin>>v[i];
    cout<<vector(v,n);
    return 0;
}
///divide et impera
int Suma(int V[], int st, int dr)
{
    if(st == dr)
        return V[st]; // problemă elementară
    else
    {
        int m = (st + dr) / 2; // împărțim problema în subprobleme
        int s1 = Suma(V, st, m); // rezolvăm prima subproblemă
        int s2 = Suma(V, m + 1, dr); // rezolvăm a doua subproblemă
        return s1 + s2; // combinăm rezultatele
    }
}
int main()
{
    int V[101], n;
    //citire n si V
    cout << Suma(V,1,n);
    return 0;
}
///suma divide et impera


using namespace std;

int suma(int v[], int st, int dr)
{

    if(st==dr)
        return v[st];
    else{
        int mij=(st+dr)/2;
        int S1=suma(v,st,mij);
        int S2=suma(v,mij+1,dr);
        return S1+S2;

    }
}
int main()
{
int a[1001],n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
        int st=0;
        int dr=n-1;
        cout<<suma(a,st,dr);

    return 0;
}
///elemente impare divide et impera de#include <iostream>
using namespace std;
int bibus(int v[],int st,int dr)
{
    if(st==dr) 
    return v[st]%2==1;
    else {
        int mij=(st+dr)/2;
        return bibus(v,st,mij)+bibus(v,mij+1,dr);
}
}
int main()
{
    int n,v[20001];
    cin>>n;
    for(int i=0;i<n;i++) 
    cin>>v[i];
    if(bibus(v,0,n-1))
    cout<<"DA";
    else 
    cout<<"NU";
    return 0;
///suma elemente vector divide et impera 
#include <bits/stdc++.h>

using namespace std;

int suma(int v[], int st, int dr)
{

    if(st==dr){
        if(v[st]%2==0)
        return v[st];
        else return 0;
    }
    else{
        int mij=(st+dr)/2;
        int S1=suma(v,st,mij);
        int S2=suma(v,mij+1,dr);
        return S1+S2;

    }
}
int main()
{
int a[1001],n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
        int st=0;
        int dr=n-1;
        cout<<suma(a,st,dr);

    return 0;
}
///expista prime divide et impera
bool prim (int n) { 
    for(int d=2;d*d<=n;d++) 
    if(n%d==0)
    {
        return 0;
        break;
    }
    return 1;
}
int bibus(int v[],int st,int dr)
{
    if(st==dr) 
    return prim(v[st])==1;
    else {
        int mij=(st+dr)/2;
        return bibus(v,st,mij)+bibus(v,mij+1,dr);
}
}
int main()
{
    int n,v[2001];
    cin>>n;
    for(int i=0;i<n;i++) 
    cin>>v[i];
    if(bibus(v,0,n-1))
    cout<<"DA";
    else 
    cout<<"NU";
    return 0;
}   

///prim maxim divide et impera
#include <bits/stdc++.h>
using namespace std;
bool imp(int n)
{int d=2;
    for(d;d*d<=n;d++)
        if(n%d==0)
    {return 0;
    break;
    }
    return 1;
}
int maxi(int a, int b)
{
    if(a>b)
        return a;
    else return b;

}
int nrimp(int v[],int st,int dr)
{  int max=0;
    if(st==dr){
        if(imp(v[st])&& v[st]>max){
        return v[st];
        max=v[st];
        }
    }
    else
    {
        int mij=(st+dr)/2;
        int s1=nrimp(v,st,mij);
        int s2=nrimp(v,mij+1,dr);
        return maxi(s1,s2);

    }
}

int main()
{
    int a[1001],n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<nrimp(a,1,n-1);
    return 0;
}
/// toate egale divide et imp
int bibus(int v[],int st,int dr)
{
    if(st==dr) return 1;
    else {
        int mij=(st+dr)/2;
        if(bibus(v,st,mij)==bibus(v,mij+1,dr) && v[mij]==v[mij+1])
        return 1;
        else return 0;
    }
}
int main()
{
    int n,v[2001];
    cin>>n;
    for(int i=0;i<n;i++) 
    cin>>v[i];
    if(bibus(v,0,n-1))
    cout<<"DA";
    else 
    cout<<"NU";
    return 0;
}  
/* Se citește de la tastatură numărul n și un număr p cu valoarea 1 sau 2 și apoi n șiruri de tip nume prenume media1 media2 media3 separate prin spații.
Pentru p=1, se va afișa numărul elevilor care au media generală mai mare sau egală decât media clasei.
Pentru p=2, se va afișa pe primul rând media clasei și pe următoarele n rânduri, numele, prenumele și media generală a fiecărui elev, separate printr-un singur spațiu, sortat descrescător după medie; la medii egale se sortează crescător după nume, iar la nume egale crescător după prenume.*/
struct date
{
    char nume[101],prenume[101];
    int media1,media2,media3;
    double media;
} q[100001];

int main()
{
    int n,p;
    double media_clasei=0;
    cin>>n>>p;
    for(int i=0; i<n; i++)
    {
        cin>>q[i].nume>>q[i].prenume>>q[i].media1>>q[i].media2>>q[i].media3;
        q[i].media=(double)(q[i].media1+q[i].media2+q[i].media3)/3;
        media_clasei+=q[i].media;
    }
    media_clasei=(double)media_clasei/n;
    int k=0;
    if(p==1)
    {
        for(int i=0; i<n; i++)
        {
            if(q[i].media>media_clasei)
                k++;
        }
        cout<<k;
    }
    if(p==2)
    {
        cout<<fixed<<setprecision(2)<<media_clasei<<endl;
        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(q[i].media<q[j].media)
                    swap(q[i],q[j]);
                else if(q[i].media==q[j].media && strcmp(q[i].nume,q[j].nume)>0)
                    swap(q[i],q[j]);
                else if(q[i].media==q[j].media && strcmp(q[i].nume,q[j].nume)==0 && strcmp(q[i].prenume,q[j].prenume)>0)
                    swap(q[i],q[j]);
            }

        }
        for(int i=0; i<n; i++)
            cout<<q[i].nume<<" " <<q[i].prenume<<" "<<fixed<<setprecision(2)<<q[i].media<<"\n";
    }
    return 0;
}
/* La o serbare sunt n grupe de copii care poartă p tipuri de uniforme. Scrieţi un program care să afişeze pe ecran tipurile de uniforme în ordinea descrescătoare a numărului total de copii ce poartă fiecare tip de uniformă. Afişarea se va face pe o singură linie, valoriile fiind separate printr-un spaţiu.*/
ifstream fin("serbare.in");
ofstream fout("serbare.out");
 
struct uniforme
{
  int p; // tipuri de uniforme
  int c; // numarul de copii
  int n; // grupe de copii
} u[1000];
 
int main()
{
  fin >> u[0].n >> u[0].p;
  int maxi = 0;
  for (int i = 1; i <= u[0].n; i++)
  {
    fin >> u[i].n >> u[i].p;
    u[u[i].p].c += u[i].n;
    if (u[u[i].p].c > maxi)
      maxi = u[u[i].p].c;
  }
  for (int i = maxi; i >= 1; i--)
    for (int j = 1; j <= u[0].p; j++)
      if (i == u[j].c)
        fout << j << " ";
  return 0;
}

/* Se dau două numere n p și o listă de n elemente cu urcările în autobuz a mai multor persoane a căror structura este prenume nume bilet_platit, fiecare intrare fiind plasată pe câte o linie. Câmpurile prenume și nume sunt șiruri de caractere, iar bilet_platit este un număr care poate fi 0 sau 1; 0 dacă persoana respectivă nu a plătit biletul sau 1 dacă a plătit biletul. Pentru fiecare bilet neplătit se va contoriza o penalizare persoanei.
Se cere :
a) Prenumele, numele și numărul de penalizări al persoanei care are număr maxim de penalizări. Dacă există mai multe persoane cu număr maxim de penalizări se cere afișarea persoanei care apare prima în ordine alfabetică.
b) Ordonarea listei de persoane descrescător după numărul de penalizări, la număr de penalizări egale, crescător după prenume, la prenume identice, crescător după nume.*/

int n, p, cnt;
 
ifstream fin("ratc2.in");
ofstream fout("ratc2.out");
 
struct co
{
    string nume, prenume;
    int pe;
} v[101];
 
void invart(co a, co b)
{
    swap(a, b);
}
 
int main()
{
    fin >> n >> p;
    for (int i = 1; i <= n; ++i)
    {
        string a, b;
        fin >> a >> b;
        bool val;
        fin >> val;
        bool gasit = false;
        for (int j = 1; j <= cnt; ++j)
        {
            if (a == v[j].prenume && b == v[j].nume)
                v[j].pe += !val, gasit = true;
        }
        if (!gasit)
            v[++cnt].prenume = a, v[cnt].nume = b, v[cnt].pe = !val;
    }
    for (int i = 1; i < cnt; ++i)
        for (int j = i + 1; j <= cnt; ++j)
            if (v[i].pe < v[j].pe)
                swap(v[i], v[j]);
            else if (v[i].pe == v[j].pe && v[i].prenume > v[j].prenume)
                swap(v[i], v[j]);
            else if (v[i].pe == v[j].pe && v[i].prenume == v[j].prenume && v[i].nume > v[j].nume)
                swap(v[i], v[j]);
    if (p == 1)
        fout << v[1].prenume << ' ' << v[1].nume << ' ' << v[1].pe;
    else
        for (int i = 1; i <= cnt; ++i)
            fout << v[i].prenume << ' ' << v[i].nume << ' ' << v[i].pe << endl;
    return 0;
}

/* Dându-se N intervale [a, b], calculați numărul maxim de astfel de intervale care se intersectează în cel puțin un punct.*/
ifstream fin("intervale.in");
ofstream fout("intervale.out");
//problema 3975 gasita pe github, fara fisiere;
int inc[100000];
int fina[100000];
int main()
{
  int n;
  fin >> n;
  for (int i = 0; i < n; i++)
  {
    fin >> inc[i] >> fina[i];
  }

  sort(inc, inc + n);
  sort(fina, fina + n);

  int ctr = 0, maxi = 0;
  int indice_inc = 0, indice_fin = 0;

  while (indice_inc < n && indice_fin < n)
  {
    if (inc[indice_inc] <= fina[indice_fin])
    {
      ctr++;
      indice_inc++;
    }
    else
    {
      ctr--;
      indice_fin++;
    }

    if (ctr > maxi)
    {
      maxi = ctr;
    }
  }

  fout << maxi;

  fin.close();
  fout.close();

  return 0;
}

/* Se consideră două evenimente a căror durată este exprimată fiecare prin câte trei numere naturale: ore (h), minute (m) şi secunde (s). Să se scrie în fișierul de ieșire: a) pe primele două linii, duratele în formatul h: m: s; b) pe următoarele două linii, duratele exprimate în secunde, corespunzătoare fiecărui eveniment, pe rânduri separate; c) pe următoarea linie suma obţinută din adunarea duratelor celor două evenimente, exprimată în ore, minute, secunde, în formatul h: m: s.*/
ifstream fin("ore.in");
ofstream fout("ore.out");

struct ore
{
  int h, m, s, r;
} o[1000];

int main()
{
  for (int i = 1; i <= 2; i++)
  {
    fin >> o[i].h >> o[i].m >> o[i].s;
    fout << o[i].h << ": " << o[i].m << ": " << o[i].s << endl;
    o[i].r = o[i].h * 3600 + o[i].m * 60 + o[i].s;
    o[0].r += o[i].r;
  }
  o[0].s = o[0].r % 60;
  o[0].m = ((o[0].r - 3) / 60) % 60;
  o[0].r = (o[0].r - 3) / 60;
  o[0].h = o[0].r / 60;
  for (int i = 1; i <= 2; i++)
    fout << o[i].r << endl;
  fout << o[0].h << ": " << o[0].m << ": " << o[0].s << endl;
  return 0;
}

/* Se dau n, reprezentând numărul de elevi apoi, pe câte un rând, datele fiecărui elev: codul (număr natural de maxim 4 cifre), media la informatică (număr natural de la 1 la 10) și numărul de absențe. Definiți un tip structură pentru a putea memora datele unui elev și rezolvați cerințele:
a) memorați datele tuturor elevilor într-un vector de structuri de tipul definit;
b) afișați numărul de elevi cu media 10
c) afișați media clasei (se va afișa doar partea întreagă a ei).
d) afișați primii doi elevi după absențe (elevii cu cele mai multe absențe). Dacă sunt mai mulți elevi cu același număr de absențe se afișează în ordine crescătoare a codului. Dacă sunt mai mult de doi elevi număr maxim de absențe se afișează doar doi.*/
ifstream fin("qclasa.in");
ofstream fout("qclasa.out");

struct date_elev
{
  int cod, medinfo, nrabs;
} e[40];

int main()
{
  int n, medclasa = 0, ok = 0;
  fin >> n;
  for (int i = 1; i <= n; i++)
  {
    fin >> e[i].cod >> e[i].medinfo >> e[i].nrabs;
    if (e[i].medinfo == 10)
      ok++;
    medclasa += e[i].medinfo;
  }
  for (int i = 1; i < n; i++)
    for (int j = i + 1; j <= n; j++)
    {
      if (e[i].nrabs < e[j].nrabs)
        swap(e[i], e[j]);
      else if (e[i].nrabs == e[j].nrabs)
        if (e[i].cod > e[j].cod)
          swap(e[i], e[j]);
    }
  fout << ok << endl;
  fout << (int)(medclasa / n) << endl;
  fout << e[1].cod << " " << e[1].medinfo << " " << e[1].nrabs << endl;
  fout << e[2].cod << " " << e[2].medinfo << " " << e[2].nrabs << endl;
  return 0;
}

/* Se dau n numere naturale. Să se afișeze acestea în ordinea crescătoare a numărului de divizori ai fiecăruia, la același număr de divizori crescător după cifra de control, la aceeași cifră de control crescător după prima cifră, iar dacă și prima cifră este aceeași atunci numerele se vor afișa în ordinea crescătoare a valorii lor.*/

ifstream fin("sort_div.in");
ofstream fout("sort_div.out");

int n;
struct poz
{
    int val, nrdiv, control, primacif;
} a[10001];

int div(int n)
{
    int d = 2, P = 1;
    while (n > 1)
    {
        int p = 0;
        while (n % d == 0)
            p++, n /= d;
        if (p)
            P *= (p + 1);
        d++;
        if (d * d > n)
            d = n;
    }
    return P;
}

int Pcif(int n)
{
    while (n > 9)
        n /= 10;
    return n;
}

int comp(poz a, poz b)
{
    if (a.nrdiv < b.nrdiv)
        return 1;
    else if (a.nrdiv == b.nrdiv && a.control < b.control)
        return 1;
    else if (a.nrdiv == b.nrdiv && a.control == b.control && a.primacif < b.primacif)
        return 1;
    else if (a.nrdiv == b.nrdiv && a.control == b.control && a.primacif == b.primacif && a.val < b.val)
        return 1;
    else
        return 0;
}

int main()
{
    fin >> n;
    for (int i = 1; i <= n; i++)
    {
        fin >> a[i].val;
        a[i].nrdiv = div(a[i].val);
        a[i].control = a[i].val % 9;
        if (a[i].control == 0)
            a[i].control = 9;
        a[i].primacif = Pcif(a[i].val);
    }
    sort(a + 1, a + n + 1, comp);
    for (int i = 1; i <= n; i++)
        fout << a[i].val << " ";
}

/* Se dau coordonatele carteziene a n puncte în plan. Să se determine distanța maximă dintre un punct dat și originea sistemului de coordonate și numărul de puncte situate la acea distanță față de origine.*/
struct punct{int x , y;};
double dist00(punct p)
{
    return sqrt(p.x*p.x+p.y*p.y);///distanta de la p la origine
}
int main()
{
    int n , c = 0 ;
    punct P[101];
    double dmax = 0;
    cin >> n;
    for(int i = 1 ; i <= n ; ++i)
        cin >> P[i].x >> P[i].y;
    for(int i = 1 ; i <= n ; ++i)
    {
        double d = dist00(P[i]);
        if(d > dmax) dmax = d , c = 1;
        else if(d==dmax) c++;
    }
    cout << dmax << " " << c;
}
//Să se determine maximul a două fracţii date.
int cmmdc (int x, int y)
{
    int r=x%y;
    while (r!=0)
    {
        x=y;
        y=r;
        r=x%y;
    }
    return y;
}

int main()
{
    float a,b,c,d;
    cin>>a>>b>>c>>d;
    float fr1=a/b,fr2=c/d;
    if (fr1>fr2) cout<<a/cmmdc(a,b)<<" "<<b/cmmdc(a,b);
    else cout<<c/cmmdc(c,d)<<" "<<d/cmmdc(c,d);
}
/* Într-un grup sunt N prieteni. Când se întâlnesc se salută, fiecare dând mână cu toți ceilalți. Câte strângeri de mână au loc?*/
int main()
{
  long long int n,r;
  cin >> n;
  r=n*(n-1)/2;
  cout << r;
  return 0;
}

//cel mai mare element prim din sir rec
bool prim(int n){
    if(n<2) return false;
    for(int d=2;d*d<=n;d++)
        if(n%d==0)
            return false;
        return true;
        }


int bibus(int v[],int st, int dr)
{

    if(st==dr)
    {
        if(prim(v[st]))
            return v[st];
        else
            return 0;
    }
    else
    {
        int mij=(st+dr)/2;
        int p1=bibus(v,st,mij);
        int p2=bibus(v,mij+1,dr);
        if(p1>p2)
            return p1;
        else
            return p2;



    }
}
int main()
{
  int n,v[1001];
  cin>>n;

  v[0]=0;

  for(int i=1; i<=n; i++)
    cin>>v[i];

  cout<<bibus(v,1,n);

  return 0;
}

//suma cifrelor din sir, recursiv;
char a[201];

int SCif(char s[],int st, int dr)
{
    if(st==dr)
    {
        if(s[st]>='1' && s[st]<='9')
        return s[st]-'0';
        else
        return 0;
    }
    else
    {
        int mj=(st+dr)/2;
        int s1=SCif(s,st,mj);
        int s2=SCif(s,mj+1,dr);
        return s1+s2;
    }

}
int SC(char s[]){

  return SCif(s,0,strlen(s)-1);
}

//nr obtinut din ciferele pare retinute in tablou, recursiv;
void F(int n,int *a, int &k){
    if(n == -1)
        k = -1;
    else{
        F(n-1, a, k);
        if(a[n-1] % 2 == 0)
            if(k == -1)
                k = a[n-1];
            else
                k = k * 10 + a[n-1];
    }
}

//cmmdc devideetimpera al elementelor din acest sir;
int Cmmdc2(int a, int b)
{
    if(b == 0)
        return a;
    else
        return Cmmdc2(b , a % b);
}

int Cmmdc(int st, int dr)
{
    if(st == dr)
        return v[st];
    else
    {
        int mij = (st + dr) / 2;
        int x = Cmmdc(st ,mij); 
        int y = Cmmdc(mij + 1 , dr);
        return Cmmdc2(x , y);
    }
}

int main(){
    cin >> n;
    for(int i = 0 ; i < n ; i ++)
        cin >> v[i];
    cout << Cmmdc(0 , n - 1);
    return 0;
}

//suma elementelor pare din acest sir, devideAndConquer;
int suma(int a[], int st, int dr)
{
    if (st == dr) // pe
        if (a[st] % 2 == 0)
            return a[st];
        else
            return 0;
    else
    { // pn
        int mij = (st + dr) / 2;
        int S1 = suma(a, st, mij);
        int S2 = suma(a, mij + 1, dr);
        return S1 + S2;
    }
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    cout << suma(a, 1, n);

    return 0;
}

//suma elementelor din un tablou, devideAndConquer;
int suma(int a[], int st, int dr)
{
    if (st == dr) // pe
        return a[st];
    else
    { // pn
        int mij = (st + dr) / 2;
        int S1 = suma(a, st, mij);
        int S2 = suma(a, mij + 1, dr);
        return S1 + S2;
    }
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    cout << suma(a, 1, n);

    return 0;
}

//verifica daca sunt elemente impare in sir;
bool suma(int v[],int st, int dr){
    if(st==dr)
    if(v[st]%2!=0)
        return true;
    else
        return false;
    else{
    int mij=(st+dr)/2;
    return suma(v,st,mij) || suma(v,mij+1,dr);

    }
}
int main()
{
    int n,v[2002];
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    if(suma(v,1,n))
        cout<<"DA";
    else
        cout<<"NU";

    return 0;
}

//daca există elemente prime in sir;
bool prim(int n){
    if(n<2)
    return false;
    for(int d=2;d*d<n;d++)
        if(n%d==0)
            return false;
        return true;

}
bool div(int v[],int st, int dr){
    if(st==dr)
    return prim(v[st]);
    else{
    int mij=(st+dr)/2;
    return (div(v,st,mij) || div(v,mij+1,dr));

    }
}
int main()
{
    int n,v[201];
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>v[i];
    if(div(v,1,n))
        cout<<"DA";
    else
        cout<<"NU";

    return 0;
}

//cate elemente impare;
int bibus(int v[],int st, int dr){

    if(st==dr){
    if(v[st]%2!=0)
        return 1;
    else return 0;}
    else{
    int mij=(st+dr)/2;
    return bibus(v,st,mij) + bibus(v,mij+1,dr);

    }
}
int main()
{
    int n,v[1001];
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>v[i];

    cout<<bibus(v,1,n);

    return 0;
}

//verifica daca toate elementele din sir is pare;
bool bibus(int v[],int st, int dr)
{

    if(st==dr)
    {
        if(v[st]%2==0)
            return true;
        else return false;
    }
    else
    {
        int mij=(st+dr)/2;
        return (bibus(v,st,mij) && bibus(v,mij+1,dr));

    }
}
int main()
{
    int n,v[201];
    cin>>n;

    for(int i=1; i<=n; i++)
        cin>>v[i];

    if(bibus(v,1,n))
        cout<<"DA";
    else
        cout<<"NU";

    return 0;
}

//cel mai mare nr din sir;
int bibus(int v[],int st, int dr)
{

    if(st==dr)
    {
            if(v[st]>v[0])
             v[0]=v[st];
    }
    else
    {
        int mij=(st+dr)/2;
        bibus(v,st,mij);
        bibus(v,mij+1,dr);
        return v[0];



    }
}

//daca toate elementele din sir sunt egale;
bool bibus(int v[],int st, int dr)
{

    if(st==dr)
    {
            if(v[st]==v[1])
             return true;
             return false;
    }
    else
    {
        int mij=(st+dr)/2;
        return (bibus(v,st,mij) && bibus(v,mij+1,dr));


    }
}

//cautare binara recursiv;
int cautBinarPeX(int a[], int st, int dr, int x){

    if(st<=dr){
        int mij = (st+dr)/2;
        if(a[mij]==x)
            return 1;//daca vrem sa returnam ce am gasit dam return la mij;
        if[a[mij]<x]
            return cautBinarPeX(a,mij+1,dr,x);
        else
            return cautBinarPeX(a,st,mij-1,x);  
    }

    return 0;
}

//cea mai mică cifră pară a unui număr
#define ecifra n < 10
#define uc n % 10
#define par n % 2 == 0
#define impar n % 2 == 1
// Să se scrie o funcție C++ recursivă care să returneze
// cea mai mică cifră pară a unui număr natural transmis
// ca parametru
int cifminpar(int n)
{
    if (ecifra)
    {
        if (par)
            return n;
        else
            return -1;
    }
    int x = cifminpar(n / 10);
    if (impar)
        return x;
    else if (x < uc && x != -1)
        return x;
    else
        return uc;
}

//să determine cifra maximă și cifra minimă a unui număr
#define uc n % 10
void cifmaxmin(int n, int &max, int &min)
{
    if (n <= 9)
        max = min = n;
    else
    {
        cifmaxmin(n / 10, max, min);
        if (uc > max)
            max = uc;
        if (uc < min)
            min = uc;
    }
}

//prin parametrul k o valoare naturală egală cu numărul obţinut din cifrele pare memorate în tabloul a sau valoarea -1
//incepe de pe pozitia 0;
//il mai am la linia 462;
int F(int n , int a[] , int& k)
{
    k = -1;
    for(int i = 0 ; i < n ; ++i)
    {
        if(a[i]%2==0)
        {
            if(k==-1)
                k=0;
            k=k*10+a[i];
        }
    }
}

// parametrul c numărul de cifre ale lui n care sunt mai mari sau egale decât k
void cnt_cif(int x, int k, int &c)
{
    if (x <= 9)
    {
        if (x >= k)
            c = 1;
        else
            c = 0;
    }
    else
    {
        cnt_cif(x / 10, k, c);
        if (x % 10 >= k)
            c++;
    }
}

//număr natural nenul n, returnează cel mai mare divizor impar al său.
int DivImpRec(int n)
{
    if (n % 2 != 0)
        return n;
    return DivImpRec(n / 2);
}

//cautare binara recusiv;
int cb(int st, int dr, int x) // cautare binara
{
    if (st <= dr)
    {
        int mij = (st + dr) / 2;
        if (x == v[mij])
            return mij;
        if (x < v[mij])
            return cb(st, mij - 1, x);
        else
            return cb(mij + 1, dr, x);
    }
    return 0;
}

void factori_primi(int n, int f[])
{
    int d,p;
    d=2;
    while(n>1)
    {
        p=0;
        
        while(n%d==0)
        {
            p++;
            n=n/d;
        }
        
        if(p==1)
            f[d]++;
        
        d++;
    }
}