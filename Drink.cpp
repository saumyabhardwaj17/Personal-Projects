/*
A MENU BASED PROGRAM TO PERFORM THE FOLLOWING OPERATIONS ON A BINARY FILE DRINK.DAT
1-READ THE CONTENTS
2-WRITE THE CONTENTS
3-SEARCH THE CONTENT
4- COPY ONLY THOSE RECORDS WHOSE  PRICE IS MORE THAN 10 TO MYDRINK.DAT. ASLO DISPLAY CONTENTS OF MYDRINKS.DAT
FILE CONTAINS OBJECT OF CLASS DRINK
*/


#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
class mydrink
{
int drinkno;
char dname[20];
int qty;
float price;
public:void input()
       {
cout<<"\nenter drink no=";
cin>>drinkno;
cout<<"\nenter drink name=";
cin>>dname;
cout<<"\nenter quantity=";
cin>>qty;
cout<<"\nenter price=";
cin>>price;
       }
       void show()
       {
cout<<"\ndrink no:"<<drinkno<<"\nname:"<<dname<<"\nquantity:"<<qty<<"\nprice:"<<price;
       }
       int getprice()
       {
	return price;
       }
       int getdrinkno()
       {
       return drinkno;
       }
};
void writefile()
{
  mydrinki;
  ofstreamfout("drink.dat",ios::binary|ios::app);
  i.input();
  fout.write((char*)&i,sizeof(i));
  fout.close();
}
void readfile()
{
  mydrinki;
  ifstream fin("drink.dat",ios::binary|ios::in);
  while(fin.read((char*)&i,sizeof(i)))
 {
  i.show();
  if(fin.eof())
  break;
 }
fin.close();
}
void searchbyno()
{
 ifstream fin("drink.dat",ios::binary|ios::in);
 int no;
 cout<<"\ninput drink no to be searched=";
 cin>>no;
 mydrinki;
 while (!fin.eof())
{
  fin.read((char*)&i,sizeof(i));
 if(i.getdrinkno()==no)
 i.show();
 else
  cout<<"\ndrink not found";
 if(fin.eof())
 break;
}
fin.close();
}
void copy()
{
 mydrinki;
 ifstream fin("drink.txt");
 ofstreamfout("mydrink.txt");
 while(fin.eof()==0)
{
  fin.read((char*)&i,sizeof(i));
  if(i.getprice()>10)
  {
   fout.write((char*)&i,sizeof(i));
   i.show();
 }
if(fin.eof())
break;
}
fin.close();
}
void main()
{
 clrscr();
 int x;
 do
{
  cout<<"\n1.input the data\n2.display all the data \n3.search from data \n4.copy data whose price>10 to another  \n5.exit"<<endl;
  cin>>x;
  switch (x)
 { 
   case 1:writefile();break;
   case 3:searchbyno();break;
   case 2:readfile();break;
   case 4:copy();break;
   case 5:exit(0);break;
 }
}while(x!=5);
getch();
}
