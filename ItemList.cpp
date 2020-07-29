#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<stdio.h>
class item
{
int itemno;
char iname[30];
float price;
int qty;
public:void getdata()
       {
       cout<<"\nenter item no:";
       cin>>itemno;
       cout<<"\nenter item name:";
       gets(iname);
       cout<<"\nenter the price:";
       cin>>price;
       }
       void showdata()
       {
       cout<<"\nitem no:"<<itemno<<"\nitem name:"<<iname<<"\nprice:"<<price;
       }
       int getitemno()
       {
	return itemno;
       }
       char* getiname()
       {
	return iname;
       }
};
void writefile()
{
 item i;
 ofstream fout("sitem.dat",ios::binary|ios::app);
 i.getdata();
 fout.write((char*)&i,sizeof(i));
 fout.close();
}
void readfile()
{
 item i;
 ifstream fin("sitem.dat",ios::binary|ios::in);
 while(fin.read((char*)&i,sizeof(i)))
{
 i.showdata();
 if(fin.eof())
 break;
}
fin.close();
}
void searchbyno()
{
 ifstream fin("sitem.dat",ios::binary|ios::in);
 int no;
 cout<<"\ninput item no to be searched=";
 cin>>no;
 item i;
 while (!fin.eof())
{
  fin.read((char*)&i,sizeof(i));
  if(i.getitemno()==no)
  i.showdata();
 else
  cout<<"\nitem not found";
 if(fin.eof())
 break;
}
fin.close();
}
void searchbyname()
{
  ifstream fin("sitem.dat",ios::binary|ios::in);
  char ch[20],name[20];
  cout<<"\ninput item no to be searched=";
  gets(ch);
  item i;
  int count=0;
   while (!fin.eof())
   {
      fin.read((char*)&i,sizeof(i));
      strcpy(name,i.getiname());
      if(strcmpi(name,ch)==0)
      {
        i.showdata();
         count=1;
      }
     if(fin.eof())
     break;
  }
 if(count==0)
cout<<"\nitem not found";
fin.close();
}
void main()
{
clrscr();
int x;
do
{
 cout<<"\n1.write in the string\n2.read the string \n3.search by no \n4.search by name  \n5.exit"<<endl;
 cin>>x;
 switch (x)
 {
  case 2:readfile();break;
  case 3:searchbyno();break;
  case 1:writefile();break;
  case 4:searchbyname();break;
  case 5:exit(0);break;
}
}while(x!=5);
getch();
}
