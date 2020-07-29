/* Library management program to get the data and display with additional feature of modify the data for the price up and down.*/

#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<process.h>
class book
{
int bno;
char bname[50],autname[50];
float price;
public:
  void enter()
  {
cout<<"\nbook no=";
cin>>bno;
cout<<"\nenter book name=";
cin>>bname;
cout<<"\nauthur name=";
cin>>autname;
cout<<"\nprice=";
cin>>price;
 }
  void display()
  {
 cout<<"\nbook no="<<bno<<"\nbookname"<<bname<<"\nbookauthur="<<autname<<
"\nprice"<<price;
    }
    char* authname()
    {
    return autname;
    }
    void update(int n)
    {
    price=price+n;
    }
};
void readfile()
{
 book b;
 ifstream fin("book.dat",ios::binary|ios::in);
 while(fin.read((char*)&b,sizeof(b)))
 {
  b.display();
  if(fin.eof()) 
  break;
 }
fin.close();
}
void writefile()
{
  book b;
  ofstreamfout("book.dat",ios::binary|ios::app);
  b.enter();
  fout.write((char*)&b,sizeof(b));
  fout.close();
 }
void modify()
{
  int n;
  book b;
  ifstream file("book.dat",ios::binary|ios::in) ;
  ofstreamfout("book.dat",ios::binary|ios::ate);
  char aut[50];
  cout<<"\nauth name=";
  cin>>aut;
  int x=0,pos;
  while(file.read((char*)&b,sizeof(b)))
 {
  if (strcmpi(b.authname(),aut)==0)
 {
   x=1;
   cout<<"\nenter amount to be added=";
   cin>>n;
   b.update(n);
   pos = (file.tellg()-sizeof(b));
   fout.seekp( pos,ios::beg);
   fout.write((char*)&b,sizeof(b));
 }
 if(file.eof())
 break;
}
if(x==0)
 cout<<"\nrecord not found";
 file.close();
}
void main()
{
clrscr();
int menu;
do
{
 cout<<"\n1.write 2.read 3.modify 4.exit";
 cin>>menu;
 switch(menu)
 {
  case 1:writefile();break;
  case 2:readfile();break;
  case 3:modify();break;
  case 4:exit(0);break;
 }
}while(menu!=4);
getch();
}
