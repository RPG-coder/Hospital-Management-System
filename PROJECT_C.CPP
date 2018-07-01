/*  RAHUL AND KARTIK  -->      HOSPITAL MANAGEMENT


MOD  1 .PASSWORD (REGISTER OR SIGN IN(IF REGISTERED ALREADY) )    COMPLETED

PATIENT RECORD
MOD  2 .NEW PATIENT RECORD                              COMPLETED
MOD  3 .SEARCH PATIENT                                  COMPLETED
MOD  4 .DELETE PATIENT                                  COMPLETED
MOD  5 .DISPLAY PATIENT                                 COMPLETED

DOCTER RECORD
MOD  6 .NEW DOCTER RECORD                               COMPLETED
MOD  7 .SEARCH DOCTER                                   COMPLETED
MOD  8 .DELETE DOCTER                                   COMPLETED
MOD  9 .DISPLAY DOCTER                                  COMPLETED

DRUG DEPARTMENT  (SEPERATE FROM PATIENT RECORD)
MOD  10.NEW PRODUCT                                     COMPLETED
MOD  11.SEARCH PRODUCT                                  COMPLETED
MOD  12.DELETE PRODUCT                                  COMPLETED
MOD  13.DISPLAY PRODUCT                                 COMPLETED
*/

/*--------------------------------------------------------------------------*/


//HEADER FILES
#include"iostream.h"
#include"conio.h"
#include"stdio.h"
#include"string.h"
#include"graphics.h"
#include"fstream.h"
#include"process.h"


/*--------------------------------------------------------------------------*/


//CLASS

class pass                                                //MODULE 1 PASSWORD
{
char name1[40],p[40],name[40],np[40];
public:
void regis();
void sign();
};



class date
{public: int dd,yy,mm;};




//PATIENT
class pat
{
char pname[15],add[30],dis[10],gender[10],insurance[5];
date dob,doj;
int s,age,rmo;
long double serc,rmnc,opc,oc;
pat* next;
pat* prev;
public:
void pmain();
void enter();                                   //MODULE 2 NEW PATIENT RECORD
void search();                                 //MODULE 3 SEARCH PATIENT
void deletep();                               //MODULE 4 DELETE PATIENT
void display();                              //MODULE 5 DISPLAY PATIENT
};
pat* head;  //Global variables  patient
pat* tail;
pat* n;






//DOCTER
class doc
{
char dname[15],dadd[30],occ[10],gender[10]; //DOCTER DETAILS
date dob,doj;
int s,age,rmo;
long double salary;
doc* dnext;
doc* dprev;
public:
void dmain();
void enter();                                     //MODULE 6 NEW DOCTER RECORD
void search();                                   //MODULE 7 SEARCH DOCTER
void deleted();                                 //MODULE 8 DELETE DOCTER
void display();                                //MODULE 9 DISPLAY DOCTER
};
doc* dhead;  //Global variables for docter
doc* dtail;
doc* dn;





//DRUG DEPT
class drug
{
char proname[15],prouse[30],instruction[100]; //PRODUCT DETAILS
date dom,doe;
int s;
long double price;
drug* drnext;
drug* drprev;
public:
void drmain();
void enter();                              //MODULE 10 NEW PRODUCT RECORD
void search();                            //MODULE 11 SEARCH PRODUCT
void deletedr();                         //MODULE 12 DELETE PRODUCT
void display();                         //MODULE 13 DISPLAY PRODUCTS
};
drug* drhead;                           //Global variables  for drug dept
drug* drtail;
drug* drn;



//Accessing Hospital Management
class hp: public pat,public doc,public drug  //INHERITANCE  //HOSPITAL MANAGEMENT
{
int ch;
public:
void choice();
};




/*--------------------------------------------------------------------------*/

//Main Program
#define q "c:\\TC\\BGI"
void main()
{
fstream file;
int i,ch;
int gd=DETECT,gm;                                   //DETECTING GRAPHIC
pass b;


initgraph(&gd,&gm,q);                               //Initializing graphic
m:
clrscr();                                           //Clearing screen
cleardevice();
setbkcolor(BLUE);                                  //BACKGROUND COLOUR(COLOR)

setcolor(YELLOW);
settextstyle(BOLD_FONT,HORIZ_DIR,1);
outtextxy(0,300,"\t\t\tWELCOME TO\n FREEDOME PARK HOSPITAL\n");
cout<<"Press any key \n\tExcept the following keys to \n\t\tEXIT THE PROGRAM";
cout<<"\n\n\n\n\n\n\nEnter choice no\n1.Register\n2.Sign in\n";
cin>>ch;

if(ch==1)
{b.regis();
goto m;
}

else if(ch==2)
{
clrscr();
cleardevice();
b.sign();
goto m;
}

else
{file.close();
closegraph();
exit(1);}

file.close();
closegraph();
}

/*--------------------------------------------------------------------------*/




//FUNCTIONS


//@.PASSWORD FUNCTION
void pass::regis()                                   //REGISTERING ACCOUNT
{
fstream file;
cleardevice();
setcolor(GREEN);
file.open("Account.txt",ios::out);
settextstyle(BOLD_FONT,HORIZ_DIR,1);
outtextxy(10,0,"\t\t\tWELCOME TO FREEDOME PARK HOSPITAL\n");

settextstyle(BOLD_FONT,HORIZ_DIR,1);
outtextxy(10,0,"\t\t\tWELCOME TO FREEDOME PARK HOSPITAL");
line(1000, 50, 0, 50);

//REGISTERING ACCOUNT DETAILS FOR AN AUTHORISED PERSON
cout<<"Create new account";

//New Username
cout<<"\nUser Name:";
gets(name);

//New Password
//PROGRAM PASSWORD RULES(IMP)
clrscr();
cleardevice();
cout<<"\n\n-->Case Sensitive:\n";
cout<<("\n -->NO Enter,Backspace,Esc or any escape key allowed in password\n");
cout<<("\n -->PRESS ; TO COMPLETE THE PASSWORD");
cout<<endl<<endl;
cout<<"\n\nNew Password Please(enter 6 charecters max):-";
for(int i=0;i<100;i++)
{
np[i]=getch();            //Gets a charecter, That is not printed on the Screen
cout<<"*";                //Instead of the charecter entered * appears
if(np[i]==';')            //Stopping the password charecter entry using  ';'
{np[i]='\0';break;}       //And then converting it into string ending with '\0'
}                         //& loop break using keyword 'break'

cout<<"\nPress any Key";
getch();                  //For checking purpose
clrscr();
cleardevice();

file<<name<<' '<<np;
file.close();
}

void pass::sign()        //SIGN IN AFTER REGISTERING  IF NOT REGISTERED OR NOT VALID
{clrscr();               //IT WILL BRING US BACK TO MAIN PACE
cleardevice();
hp a;
setbkcolor(BLACK);
setcolor(BLUE);

fstream file;
file.open("Account.txt",ios::in);
cout<<"\n\n\n\n\n\t\t\t";
cout<<"NOTE :  ; (SEMICOLON) is for ending password(NOT ENTER)\n\n\t\t\t";
line(50,1000,50,0);
line(1000,50,0,50);
settextstyle(SIMPLEX_FONT,HORIZ_DIR,2);
outtextxy(100,50,"SIGN IN:");
settextstyle(BOLD_FONT,VERT_DIR,2);
outtextxy(0,100,"FREEDOME PARK");
cout<<"ENTER USER NAME:";
gets(name1);
cout<<"\n\n\t\t\tENTER PASSWORD:";
line(50,1000,50,0);
settextstyle(BOLD_FONT,VERT_DIR,2);
outtextxy(0,100,"FREEDOME PARK");
for(int i=0;i<100;i++)
{
p[i]=getch();          //GETS A CHARECTER THAT IS NOT PRINTED OR DISPLAYED
cout<<"*";             //Instead of the charecter entered * appears
if(p[i]==';')          //Stopping the password charecter entry using  ';'
{p[i]='\0';break;}     //And then converting it into string ending with '\0'
}

file>>name>>np;

settextstyle(EUROPEAN_FONT,HORIZ_DIR,2);
if(strcmp(np,p)==0 && strcmp(name,name1)==0)  //Comparing string and password
{
outtextxy(200,300,"ACCESS PERMITTED");
getch();
clrscr();
cleardevice();
a.choice();
}                                              //Securing entry

else
{
outtextxy(200,300,"ACCESS DENIED");   //Securing entry
getch();
clrscr();
cleardevice();
}
file.close();
}


//CHOICE PROGRAM
void hp::choice()
{l:
clrscr();
cleardevice();
ellipse(320,260,0,360,95,50);          // DRAWS A ELLIPSE ON OPTION
setbkcolor(RED);
setcolor(BLUE);
settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);      //SET TEXT FONT
outtextxy(100,0," WELCOMES YOU");            //DISPLAY GRAPHIC TEXT
line(1000,50,0,50);                          //DRAWS LINE
cout<<"\n\n\n\n\n\t\tENTER YOUR CHOICE NUMBER:\t";
setcolor(LIGHTRED);
ellipse(155,160,0,360,85,50);
outtextxy(75,150,"  2.DRUG DEPT");
setcolor(GREEN);                             //SET COLOUR OF ELLISPE AND PATIENT RECORD
ellipse(320,260,0,360,95,50);
outtextxy(240,250,"1.PATIENT RECORD");
setcolor(CYAN);
rectangle(500,100,100,75);                   //DRAWS RECTANGLE ON ENTER CHOICE:
setcolor(YELLOW);
ellipse(520,160,0,360,95,50);
outtextxy(490,150,"3.DOCTER");
setcolor(BLUE);
ellipse(320,400,0,360,95,50);
outtextxy(270,380,"4.EXIT");
settextstyle(TRIPLEX_FONT,VERT_DIR,4);
outtextxy(0,100,"FREEDOME PARK");
line(50,500,50,0);
cin>>ch;                                     //CHOICE NUMBER
switch(ch)                                   //DEPENDING ON CHOICE
{
case 1: pmain();break;
case 2: drmain();break;
case 3: dmain();break;
case 4: {closegraph();exit(1);}break;
default:cout<<"ENTER AGAIN,press any button";goto l;
}
goto l;
}






// @.PATIENT FUNCTIONS
void pat::pmain()
{l:
int ch1;
hp a;
clrscr();
cleardevice();
cout<<"\n\n\n\n\n\t\t\t\t\t\t";
setbkcolor(GREEN);
setcolor(RED);
settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);                 //SET TEXT FONT
outtextxy(100,0," PATIENT RECORD");                     //DISPLAY GRAPHIC TEXT
line(1000,50,0,50);                                     //DRAWS LINE
outtextxy(105,71,"\n\n\n\n\n\t\tENTER YOUR CHOICE NUMBER:\t");
setcolor(MAGENTA);
ellipse(170,200,0,360,75,25);
outtextxy(100,180,"  1.ADD PATIENT");
setcolor(BROWN);                                        //SET COLOUR OF ELLISPE AND PATIENT RECORD
rectangle(500,100,100,75);                              //DRAWS RECTANGLE ON ENTER CHOICE:
setcolor(YELLOW);
ellipse(525,200,0,360,100,25);
outtextxy(445,185,"2.SEARCH PATIENT");
setcolor(BLUE);
ellipse(525,350,0,360,100,25);
outtextxy(460,340,"3.DELETE PATIENT");
setcolor(CYAN);
ellipse(325,300,0,360,100,25);
outtextxy(260,280,"4.DISPLAY PATIENT");
setcolor(RED);
ellipse(200,400,0,360,100,50);
settextstyle(BOLD_FONT,HORIZ_DIR,1);
outtextxy(110,380,"5.MAIN PAGE");
setcolor(LIGHTMAGENTA);
settextstyle(BOLD_FONT,VERT_DIR,3);
outtextxy(0,90,"FREEDOME PARK");
line(60,500,60,0);
cin>>ch1;
switch(ch1)
{
case 1: enter();break;
case 2: search();break;
case 3: deletep();break;
case 4: display();break;
case 5: a.choice();break;
default: cout<<"\nENTER THE CHOICE AGAIN,PRESS ANY BUTTON.";getch();goto l;
}
goto l;
}

void pat::enter()
{
clrscr();
cleardevice();
setbkcolor(BLUE);
char save,c,k,p[100];                    //p[100] FOR Defining file name
int m=0;
long double R,T,O,OP,S;

fstream file1;

cout<<"CREATE NEW/EXISTING FILE NAME:";
gets(p);

cout<<"\nDO YOU WANT TO DELETE ALL PREVIOUS FILE CONTENT(IF PRESENT IN IT)?\nPRESS(Y/N)!";
cin>>save;
if(save=='Y'||save=='y')
file1.open(p,ios::out |ios::in);
else
file1.open(p,ios::app |ios::in |ios::out);


l:
clrscr();
cleardevice();
setcolor(BLACK);
cout<<"USE _(under_score) INSTEAD OF SPACE";
cout<<"\n\n\n\n";

n= new pat;
cout<<"\nPATIENT NO:"; cin>>n->s;
cout<<"ENTER THE PATIENT NAME:"; gets(n->pname);
cout<<"ENTER THE PATIENT AGE: "; cin>>n->age;
cout<<"ENTER THE PATIENT GENDER: "; cin>>n->gender;
cout<<"ENTER THE PATIENT ADDRESS:"; gets(n->add);
cout<<"DISEASES SUFFERED:"; gets(n->dis);
cout<<"DATE OF BIRTH( dd\\ mm\\ yy):";
cin>>n->dob.dd;
cin>>n->dob.mm;
cin>>n->dob.yy;
cout<<"DATE OF JOIN( dd\\ mm\\ yy):";
cin>>n->doj.dd>>n->doj.mm>>n->doj.yy;

cout<<"ROOM NO:";cin>>n->rmo;
cout<<"CHARGES:\n1.ROOM CHARGES: ";cin>>n->rmnc;
cout<<"SERVICE CHARGES:"; cin>>n->serc;
cout<<"OPERATION CHARGES:";cin>>n->opc;
cout<<"OTHER CHARGES(INCLUDES DRUG,DOCTER,TOOLS IN TOTAL):";cin>>n->oc;
cout<<"INSURANCE(YES/NO):";gets(n->insurance);

R=n->rmnc;
S=n->serc;
O=n->opc;
OP=n->oc;
T=R+S+O+OP;

cout<<"\nDO YOU WANT TO RETYPE? (Y/N):";
cin>>save;
if(save=='Y'||save=='y')
{
clrscr();
goto l;
}

cout<<"DO YOU WANT TO SAVE? (Y/N):";
cin>>save;
if(save=='Y'||save=='y')
{
file1<<'|'<<"PATIENT_NO:"<<n->s<<';'<<'\n';
file1<<"PATIENT_NAME:"<<n->pname<<';'<<'\n';
file1<<"PATIENT_AGE:"<<n->age<<';'<<'\n';
file1<<"PATIENT_GENDER:"<<n->gender<<';'<<'\n';
file1<<"PATIENT_ADDRESS:"<<n->add<<';'<<'\n';
file1<<"DISEASES_SUFFERED:"<<n->dis<<';'<<'\n';
file1<<"DATE_OF_BIRTH(dd\\mm\\yy):"<<n->dob.dd<<'/'<<n->dob.mm<<'/'<<n->dob.yy<<';'<<'\n';
file1<<"DATE_OF_JOIN(dd\\mm\\yy):"<<n->doj.dd<<'/'<<n->doj.mm<<'/'<<n->doj.yy<<';'<<'\n';
file1<<"ROOM_NO.:"<<n->rmo<<';'<<'\n';
file1<<"INSURANCE:"<<n->insurance<<';'<<'\n';
file1<<"TOTAL_CHARGES:"<<T<<';'<<'\n';
}



{
if(m==0)
{
n->prev=NULL;
tail=n;
head=n;
}

else
{
n->prev=tail;
tail->next=NULL;
tail=n;
}
}

cout<<"DO YOU WANT ENTER MORE PATIENTS?(Y/N)";
cin>>save;
if(save=='Y'||save=='y')
goto l;

file1.close();
clrscr();
cleardevice();
}

void pat::display()
{clrscr();
cleardevice();
char p[100],c;
int l=0,ch,last=0;
fstream file1;

cout<<"\nENTER DESIRED PATIENT FILE NAME(EX:- NO_SPACES.TXT ):";
gets(p);
file1.open(p,ios::in);
l:
if(file1.fail())
{cout<<"FILE DOESNOT EXIST";getch(); }
else
{
while(!file1.eof())
{file1>>c;
if(c=='|')
last++;}

file1.clear();
file1.seekp(0,ios::beg);

if(last!=0)
{while(!file1.eof())
{
file1>>c;
l++;
if(c=='|')
{cout<<"\nPRESS ANY KEY";
getch();clrscr();
cleardevice();}
else if(c==';')
cout<<endl;
else
{cout<<c;}
}
cout<<"\n1<-TOP\t\t\t\t\t\t\tPATIENT MAIN PAGE->2 \n";
cout<<"\t\t\t ENTER ABOVE CHOICE = ";

m:
cin>>ch;
switch (ch)
{
case 1:
{file1.clear();
file1.seekg(0);
l=0;goto l;}
case 2:
{file1.close();pmain();break;}
default:
{cout<<"\n\t\t\tENTER AGAIN:";goto m;}}
}
else
{cout<<"NO RECORD PRESENT,PRESS ANY KEY";getch();}
}
}

void pat::search()
{
clrscr();
cleardevice();
setcolor(BLACK);

int i=0,k=0,f=0,w=0,index=0,last=0;
char p[100],c,m,search[100];
fstream file;
cout<<"\n Enter the file name:";
gets(p);
file.open(p,ios::in);

fstream temp;
temp.open("SEARCH.txt",ios::out|ios::trunc|ios::in);


if(!file.fail())
{
while(!file.eof())
{file>>c;
if(c=='|')
last++;
}
cout<<"TOTAL RECORD:"<<last<<"\nPRESS ANY KEY";getch();
file.clear();
file.seekp(0,ios::beg);
temp.seekp(0,ios::beg);

if(last!=0)
{
cout<<"\nEnter the WHAT U WANNA SEARCH.\nEX-\n\n\n";
cout<<"PATIENT_NO:(ENTER_THE_PATIENT_NO);\nPATIENT_NAME:(ENTER_NAME)\nPATIENT_AGE:(ENTER_AGE)";
cout<<"\nPATIENT_ADDRESS:(ENTER_ADDRESS)\nROOM_NO.:(ENTER_ROOM_NO)";
cout<<"\nENTER THE SEARCH:";
gets(search);
l:
for(i=0;!file.eof();i++)
{
file>>c;
if(c=='|')
{index++;}
else if(search[0]==c)
{
for(k=0,w=0;search[k]!='\0';k++,i++)
if(search[k]==c)
{file>>c;
w++;}

if(w==strlen(search))
{cout<<"PATIENT ENTERY NO:"<<index;f=1;getch();break;}
}
}

clrscr();
cleardevice();
if(f==1)
{cout<<"\nDO YOU WANT TO DISPLAY DETAILS?(Y/N)";
cin>>c;
if(c=='y'||c=='Y')
{file.seekp(0,ios::beg);
for(i=0,w=0;!file.eof();i++)
{file>>c;
if(c=='|')
{w++;
if(index==w)
file>>c;

for(i=0;c!='|';i++)
{if(i==0)
temp<<'P';
file>>c;
if(file.eof())
{getch();break;}
temp<<c;}
}}}
temp.seekg(0,ios::beg);
for(i=0;!temp.eof();i++)
{temp>>c;
if(c==';')
cout<<'\n';
else
cout<<c;}
getch();
}
else
{cout<<"\nRECORD NOT FOUND,Press any KEY\n";getch();}
}
else
{cout<<"\nNO RECORD PRESENT,Press any KEY\n";getch();}
}

else
{cout<<"File NOT FOUND:\n\t\tPRESS ANY KEY";getch();
}

file.close();
temp.close();
pmain();
}


void pat::deletep()
{clrscr();
cleardevice();

int k=0,f=0,w=0,index=0,last=0;
long int i=0;
char p[100],c,m,search[100];
fstream file;
cout<<"\n Enter the file name:";
gets(p);
file.open(p,ios::in);

fstream temp;
temp.open("TEMP.txt",ios::out|ios::trunc);


if(!file.fail())
{
while(!file.eof())
{file>>c;
if(c=='|')
last++;
}
cout<<"TOTAL RECORD:"<<last<<"\nPRESS ANY KEY";getch();
file.clear();
file.seekp(0,ios::beg);
temp.seekp(0,ios::beg);
if(last!=0)
{
cout<<"\nEnter the WHAT U WANNA DELETE.\nEX-\n\n\n";
cout<<"PATIENT_NO:(ENTER_THE_PATIENT_NO);\nPATIENT_NAME:(ENTER_NAME)\nPATIENT_AGE:(ENTER_AGE)";
cout<<"\nPATIENT_ADDRESS:(ENTER_ADDRESS)\nROOM_NO.:(ENTER_ROOM_NO)\n\nANYTHING!!!!";
cout<<"\nENTER THE SEARCH:";
gets(search);
l:
for(i=0;!file.eof();i++)
{
file>>c;
if(c=='|')
{index++;}
else if(search[0]==c)
{
for(k=0,w=0;search[k]!='\0';k++,i++)
if(search[k]==c)
{file>>c;
w++;}

if(w==strlen(search))
{cout<<"PATIENT ENTERY NO:"<<index;f=1;getch();break;}
}
}

if(f==1)
{cout<<"DO YOU WANT TO DELETE DETAILS?(Y/N)";
cin>>m;
if(m=='y'||m=='Y')
{
file.clear();
file.seekp(0,ios::beg);
for(i=0,w=0;!file.eof();i++)
{file>>c;
if(c=='|')
w++;
if(index!=w)
{temp<<c;
if(c==';')
temp<<'\n';}
}
}
}

else
{cout<<"\nRECORD NOT FOUND,Press any KEY\n";getch();}
}
else
{cout<<"\nRECORD NOT PRESENT,FILE EMPTY,Press any KEY\n";getch();}
}


else
{cout<<"File NOT FOUND:\n\t\tPRESS ANY KEY";getch();
}
file.close();
temp.close();

//DELETING  AND COPYING TO FILE USING ANOTHER TEMPARY FILE
if(m=='y'||m=='Y')
{
index=0;
temp.open("TEMP.txt",ios::in);
file.open(p,ios::out);
remove(p);                        //DELETING FILE
rename("TEMP.TXT",p);  //RENAMING THE FILE TEMP AS PATIENT

cout<<"RECORD DELETED,PRESS ANY KEY";getch();
}
pmain();
}







// @.DOCTER FUNCTIONS
void doc::dmain()
{l:
int ch1;
hp a;
clrscr();
cleardevice();
cout<<"\n\n\n\n\n\t\t\t\t\t\t";
setbkcolor(BLACK);
setcolor(GREEN);
settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);   //SET TEXT FONT
outtextxy(100,0," DOCTER RECORD");  //DISPLAY GRAPHIC TEXT
line(1000,50,0,50);    //DRAWS LINE
outtextxy(105,71,"\n\n\n\n\n\t\tENTER YOUR CHOICE NUMBER:\t");
setcolor(MAGENTA);
ellipse(170,200,0,360,75,25);
outtextxy(100,180,"  1.ADD DOCTER");
setcolor(BROWN);    //SET COLOUR OF ELLISPE AND PATIENT RECORD
rectangle(500,100,100,75); //DRAWS RECTANGLE ON ENTER CHOICE:
setcolor(YELLOW);
ellipse(525,200,0,360,100,25);
outtextxy(445,185,"2.SEARCH DOCTER");
setcolor(GREEN);
ellipse(525,350,0,360,100,25);
outtextxy(460,340,"3.DELETE DOCTER");
setcolor(CYAN);
ellipse(325,300,0,360,100,25);
outtextxy(260,280,"4.DISPLAY DOCTER");
setcolor(RED);
ellipse(200,400,0,360,100,50);
settextstyle(BOLD_FONT,HORIZ_DIR,1);
outtextxy(110,380,"5.MAIN PAGE");
setcolor(BLUE);
settextstyle(BOLD_FONT,VERT_DIR,3);
outtextxy(0,90,"FREEDOME PARK");
line(60,500,60,0);
cin>>ch1;
switch(ch1)
{
case 1: enter();break;
case 2: search();break;
case 3: deleted();break;
case 4: display();break;
case 5: a.choice();break;
default: cout<<"\nENTER THE CHOICE AGAIN,PRESS ANY BUTTON.";getch();goto l;
}
goto l;
}



void doc::enter()
{
clrscr();
cleardevice();
setbkcolor(BLUE);
char save,c,k; //defines new file name
int m=0;

fstream file1;


cout<<"\nDO YOU WANT TO DELETE ALL PREVIOUS FILE CONTENT(IF PRESENT IN IT)?\nPRESS(Y/N)!";
cin>>save;
if(save=='Y'||save=='y')
file1.open("DOCTER.txt",ios::out);
else
file1.open("DOCTER.txt",ios::app);


l:
clrscr();
cleardevice();
setcolor(BLACK);
cout<<"USE _(under_score) INSTEAD OF SPACE";
cout<<"\n\n\n\n";


dn= new doc;
cout<<"\nDOCTER NO:"; cin>>dn->s;
cout<<"ENTER THE DOCTER NAME:"; gets(dn->dname);
cout<<"ENTER THE DOCTER AGE: "; cin>>dn->age;
cout<<"ENTER THE DOCTER GENDER: "; cin>>dn->gender;
cout<<"ENTER THE DOCTER ADDRESS:"; gets(dn->dadd);
cout<<"OCCUPATION(.ie. DOCTER FOR):"; gets(dn->occ);
cout<<"DATE OF BIRTH( dd\\ mm\\ yy):";
cin>>dn->dob.dd;
cin>>dn->dob.mm;
cin>>dn->dob.yy;
cout<<"DATE OF JOIN( dd\\ mm\\ yy):";cin>>dn->doj.dd>>dn->doj.mm>>dn->doj.yy;
cout<<"ROOM NO:";cin>>dn->rmo;
cout<<"SALARY:";cin>>dn->salary;

cout<<"\nDO YOU WANT TO RETYPE? (Y/N):";
cin>>save;
if(save=='Y'||save=='y')
{
clrscr();
goto l;
}

cout<<"DO YOU WANT TO SAVE? (Y/N):";
cin>>save;
if(save=='Y'||save=='y')
{
file1<<'|'<<"DOCTER_NO:"<<dn->s<<';'<<'\n';
file1<<"DOCTER_NAME:"<<dn->dname<<';'<<'\n';
file1<<"DOCTER_AGE:"<<dn->age<<';'<<'\n';
file1<<"DOCTER_GENDER:"<<dn->gender<<';'<<'\n';
file1<<"DOCTER_ADDRESS:"<<dn->dadd<<';'<<'\n';
file1<<"OCCUPATION(DOCTER_FOR):"<<dn->occ<<';'<<'\n';
file1<<"DATE_OF_BIRTH(dd\\mm\\yy):"<<dn->dob.dd<<'/'<<dn->dob.mm<<'/'<<dn->dob.yy<<';'<<'\n';
file1<<"DATE_OF_JOIN(dd\\mm\\yy):"<<dn->doj.dd<<'/'<<dn->doj.mm<<'/'<<dn->doj.yy<<';'<<'\n';
file1<<"ROOM_NO.:"<<dn->rmo<<';'<<'\n';
file1<<"SALARY:"<<dn->salary<<';'<<'\n';
}



{
if(m==0)
{
dn->dprev=NULL;
dtail=dn;
dhead=dn;
}

else
{
dn->dprev=dtail;
dtail->dnext=NULL;
dtail=dn;
}
}

cout<<"DO YOU WANT ENTER MORE DOCTERS?(Y/N):";
cin>>save;
if(save=='Y'||save=='y')
goto l;

file1.close();
clrscr();
cleardevice();
}


void doc::display()
{clrscr();
cleardevice();
char c;
int l=0,ch,last=0;
fstream file1;


file1.open("DOCTER.TXT",ios::in);
l:
if(file1.fail())
{cout<<"DOCTER FILE DOESNOT EXIST";getch();}
else
{
while(!file1.eof())
{file1>>c;
if(c=='|')
last++;}

file1.clear();
file1.seekp(0,ios::beg);

if(last!=0)
{while(!file1.eof())
{
file1>>c;
l++;
if(c=='|')
{cout<<"\nPRESS ANY KEY";
getch();
clrscr();
cleardevice();}
else if(c==';')
cout<<endl;
else
{cout<<c;}
}
cout<<"\n1<-TOP\t\t\t\t\t\t\tDOCTER MAIN PAGE->2 \n";
cout<<"\t\t\t ENTER ABOVE CHOICE = ";

m:
cin>>ch;
switch (ch)
{
case 1:
{file1.clear();
file1.seekg(0);
l=0;goto l;}
case 2:
{file1.close();dmain();break;}
default:
{cout<<"\n\t\t\tENTER AGAIN:";goto m;}}
}
else
{cout<<"NO RECORD PRESENT,PRESS ANY KEY";getch();}
}
}


void doc::search()
{
clrscr();
cleardevice();
setcolor(BLACK);

int i=0,k=0,f=0,w=0,index=0,last=0;
char c,search[100];
fstream file;
file.open("DOCTER.txt",ios::in);

fstream temp;
temp.open("SEARCH.txt",ios::out|ios::trunc|ios::in);


if(!file.fail())
{
while(!file.eof())
{file>>c;
if(c=='|')
last++;
}
cout<<"TOTAL RECORD:"<<last<<"\nPRESS ANY KEY";getch();
file.clear();
file.seekp(0,ios::beg);
temp.seekp(0,ios::beg);

cout<<"\nEnter the WHAT U WANNA SEARCH.\nEX-\n\n\n";
cout<<"DOCTER_NO:(ENTER_THE_DOCTER_NO);\nDOCTER_NAME:(ENTER_NAME)\n\nANYTHING!!!";
cout<<"\nENTER THE SEARCH:";
gets(search);
l:
for(i=0;!file.eof();i++)
{
file>>c;
if(c=='|')
{index++;}
else if(search[0]==c)
{
for(k=0,w=0;search[k]!='\0';k++,i++)
if(search[k]==c)
{file>>c;
w++;}

if(w==strlen(search))
{cout<<"DOCTER ENTERY NO:"<<index;f=1;getch();break;}
}
}
clrscr();
cleardevice();
if(f==1)
{cout<<"\nDO YOU WANT TO DISPLAY DETAILS?(Y/N)";
cin>>c;
if(c=='y'||c=='Y')
{file.seekp(0,ios::beg);
for(i=0,w=0;!file.eof();i++)
{file>>c;
if(c=='|')
{w++;
if(index==w)
file>>c;

for(i=0;c!='|';i++)
{if(i==0)
temp<<'D';
file>>c;
if(file.eof())
{getch();break;}
temp<<c;}
}}}
temp.seekg(0,ios::beg);
for(i=0;!temp.eof();i++)
{temp>>c;
if(c==';')
cout<<'\n';
else
cout<<c;}
getch();
}
else
{cout<<"\nRECORD NOT FOUND,Press any KEY\n";getch();}
}

else
{cout<<"File NOT FOUND:\n\t\tPRESS ANY KEY";getch();
}

file.close();
temp.close();
dmain();
}

void doc::deleted()
{clrscr();
cleardevice();

int k=0,f=0,w=0,index=0,last=0;
long int i=0;
char c,m,search[100];
fstream file;
file.open("DOCTER.TXT",ios::in);

fstream temp;
temp.open("TEMP.txt",ios::out|ios::trunc);


if(!file.fail())
{
while(!file.eof())
{file>>c;
if(c=='|')
last++;
}
cout<<"TOTAL RECORD:"<<last<<"\nPRESS ANY KEY";getch();
file.clear();
file.seekp(0,ios::beg);
temp.seekp(0,ios::beg);
if(last!=0)
{
cout<<"\nEnter the WHAT U WANNA DELETE.\nEX-\n\n\n";
cout<<"DOCTER_NO:(ENTER_THE_DOCTER_NO);\nDOCTER_NAME:(ENTER_NAME)\nDOCTER_AGE:(ENTER_AGE)";
cout<<"\nDOCTER_ADDRESS:(ENTER_ADDRESS)\n\nANYTHING!!!!";
cout<<"\nENTER THE SEARCH:";
gets(search);
l:
for(i=0;!file.eof();i++)
{
file>>c;
if(c=='|')
{index++;}
else if(search[0]==c)
{
for(k=0,w=0;search[k]!='\0';k++,i++)
if(search[k]==c)
{file>>c;
w++;}

if(w==strlen(search))
{cout<<"DOCTER ENTERY NO:"<<index;f=1;getch();break;}
}
}

if(f==1)
{cout<<"\nDO YOU WANT TO DELETE DETAILS?(Y/N)";
cin>>m;
if(m=='y'||m=='Y')
{
file.clear();
file.seekp(0,ios::beg);
for(i=0,w=0;!file.eof();i++)
{file>>c;
if(c=='|')
w++;
if(index!=w)
{temp<<c;
if(c==';')
temp<<'\n';}
}
}
}

else
{cout<<"\nRECORD NOT FOUND,Press any KEY\n";getch();}
}
else
{cout<<"\nRECORD NOT PRESENT,FILE EMPTY,Press any KEY\n";getch();}
}


else
{cout<<"File NOT FOUND:\n\t\tPRESS ANY KEY";getch();
}
file.close();
temp.close();

//DELETING  AND COPYING TO FILE USING ANOTHER TEMPARY FILE
if(m=='y'||m=='Y')
{
index=0;
temp.open("TEMP.txt",ios::in);
file.open("DOCTER.txt",ios::out);
remove("DOCTER.TXT");                        //DELETING FILE
rename("TEMP.TXT","DOCTER.TXT");  //RENAMING THE FILE TEMP AS DOCTER

cout<<"RECORD DELETED,PRESS ANY KEY";getch();
}
dmain();
}




//@.DRUG DEPT FUNCTIONS
void drug::drmain()
{l:
int ch1;
hp a;
clrscr();
cleardevice();
cout<<"\n\n\n\n\n\t\t\t\t\t\t";
setbkcolor(WHITE);
setcolor(RED);
settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);   //SET TEXT FONT
outtextxy(100,0," WELCOME TO DRUG DEPARTMENT");  //DISPLAY GRAPHIC TEXT
line(1000,50,0,50);    //DRAWS LINE
outtextxy(105,71,"\n\n\n\n\n\t\tENTER YOUR CHOICE NUMBER:\t");
setcolor(BROWN);
ellipse(190,200,0,360,110,25);
outtextxy(100,180,"  1.ADD NEW PRODUCT");
setcolor(LIGHTMAGENTA);    //SET COLOUR OF ELLISPE AND PATIENT RECORD
rectangle(500,100,100,75); //DRAWS RECTANGLE ON ENTER CHOICE:
setcolor(BLUE);
ellipse(525,200,0,360,100,25);
outtextxy(450,185,"2.SEARCH PRODUCT");
setcolor(GREEN);
ellipse(525,350,0,360,100,25);
outtextxy(460,340,"3.DELETE PRODUCT");
setcolor(MAGENTA);
ellipse(330,300,0,360,105,25);
outtextxy(260,280,"4.DISPLAY PRODUCT");
setcolor(RED);
ellipse(200,400,0,360,100,50);
settextstyle(BOLD_FONT,HORIZ_DIR,1);
outtextxy(110,380,"5.MAIN PAGE");
setcolor(BROWN);
settextstyle(BOLD_FONT,VERT_DIR,3);
outtextxy(0,90,"FREEDOME PARK");
line(60,500,60,0);
cin>>ch1;
switch(ch1)
{
case 1: enter();break;
case 2: search();break;
case 3: deletedr();break;
case 4: display();break;
case 5: a.choice();break;
default: cout<<"\nENTER THE CHOICE AGAIN,PRESS ANY BUTTON.";getch();goto l;
}
goto l;
}

void drug::enter()
{
clrscr();
cleardevice();
setbkcolor(BLUE);
char save,c,k;
int m=0;

fstream file1;


cout<<"\nDO YOU WANT TO DELETE ALL PREVIOUS FILE CONTENT(IF PRESENT IN IT)?\nPRESS(Y/N)!";
cin>>save;
if(save=='Y'||save=='y')
file1.open("DRUG.txt",ios::out |ios::in);
else
file1.open("DRUG.txt",ios::app |ios::in |ios::out);


l:
clrscr();
cleardevice();
setcolor(BLACK);
cout<<"USE _(under_score) INSTEAD OF SPACE";
cout<<"\n\n\n\n";


drn= new drug;
cout<<"\nPRODUCT NO:"; cin>>drn->s;
cout<<"ENTER THE PRODUCT NAME:"; gets(drn->proname);
cout<<"ENTER THE PRODUCT USE: "; cin>>drn->prouse;
cout<<"INTRUCTION:"; gets(drn->instruction);
cout<<"MANUFACTURE_DATE( dd\\ mm\\ yy):";
cin>>drn->dom.dd;
cin>>drn->dom.mm;
cin>>drn->dom.yy;
cout<<"EXPIRE DATE( dd\\ mm\\ yy):";
cin>>drn->doe.dd>>drn->doe.mm>>drn->doe.yy;
cout<<"PRICE:";cin>>drn->price;

cout<<"\nDO YOU WANT TO RETYPE? (Y/N):";
cin>>save;
if(save=='Y'||save=='y')
{
clrscr();
goto l;
}

cout<<"DO YOU WANT TO SAVE? (Y/N):";
cin>>save;
if(save=='Y'||save=='y')
{
file1<<'|'<<"PRODUCT_NO:"<<drn->s<<';'<<'\n';
file1<<"PRODUCT_NAME:"<<drn->proname<<';'<<'\n';
file1<<"PRODUCT_USE:"<<drn->prouse<<';'<<'\n';
file1<<"INSTRUCTIONS:"<<drn->instruction<<';'<<'\n';
file1<<"MANUFACTURE_DATE(dd\\mm\\yy):"<<drn->dom.dd<<'/'<<drn->dom.mm<<'/'<<drn->dom.yy<<';'<<'\n';
file1<<"EXPIRE_DATE(dd\\mm\\yy):"<<drn->doe.dd<<'/'<<drn->doe.mm<<'/'<<drn->doe.yy<<';'<<'\n';
file1<<"PRICE:"<<drn->price<<';'<<'\n';
}



{
if(m==0)
{
drn->drprev=NULL;
drtail=drn;
drhead=drn;
}

else
{
drn->drprev=drtail;
drtail->drnext=NULL;
drtail=drn;
}
}

cout<<"DO YOU WANT ENTER MORE PRODUCTS?(Y/N):";
cin>>save;
if(save=='Y'||save=='y')
goto l;

file1.close();
clrscr();
cleardevice();
}



void drug::display()
{clrscr();
cleardevice();
setbkcolor(BROWN);
char p[100],c;
int l=0,ch,last=0;
fstream file1;

file1.open("DRUG.TXT",ios::in);
l:
if(file1.fail())
{cout<<"DRUG FILE DOESNOT EXIST";getch();}
else
{
while(!file1.eof())
{file1>>c;
if(c=='|')
last++;}

file1.clear();
file1.seekp(0,ios::beg);

if(last!=0)
{while(!file1.eof())
{
file1>>c;
l++;
if(c=='|')
{cout<<"\nPRESS ANY KEY";
getch();clrscr();
cleardevice();}
else if(c==';')
cout<<endl;
else
{cout<<c;}
}
cout<<"\n1<-TOP\t\t\t\t\t\t\tDRUG DEPT MAIN PAGE->2 \n";
cout<<"\t\t\t ENTER ABOVE CHOICE = ";

m:
cin>>ch;
switch (ch)
{
case 1:
{file1.clear();
file1.seekg(0);
l=0;goto l;}
case 2:
{file1.close();drmain();break;}
default:
{cout<<"\n\t\t\tENTER AGAIN:";goto m;}}
}
else
{cout<<"NO RECORD PRESENT,PRESS ANY KEY";getch();}
}
}


void drug::search()
{
clrscr();
cleardevice();

setbkcolor(BLACK);

int i=0,k=0,f=0,w=0,index=0,last=0;
char c,search[100];
fstream file;
file.open("DRUG.txt",ios::in);

fstream temp;
temp.open("SEARCH.txt",ios::out|ios::trunc|ios::in);


if(!file.fail())
{
while(!file.eof())
{file>>c;
if(c=='|')
last++;
}
cout<<"TOTAL RECORD:"<<last<<"\nPRESS ANY KEY";getch();
file.clear();
file.seekp(0,ios::beg);
temp.seekp(0,ios::beg);

if(last!=0)
{cout<<"\nEnter the WHAT U WANNA SEARCH.\nEX-\n\n\n";
cout<<"PRODUCT_NO:(ENTER_THE_PRODUCT_NO);\nPRODUCT_NAME:(ENTER_NAME)\n\nANYTHING!!!";
cout<<"\nENTER THE SEARCH:";
gets(search);
l:
for(i=0;!file.eof();i++)
{
file>>c;
if(c=='|')
{index++;}
else if(search[0]==c)
{
for(k=0,w=0;search[k]!='\0';k++,i++)
if(search[k]==c)
{file>>c;
w++;}

if(w==strlen(search))
{cout<<"PRODUCT ENTERY NO:"<<index;f=1;getch();break;}
}
}


clrscr();
cleardevice();
if(f==1)
{cout<<"\nDO YOU WANT TO DISPLAY DETAILS?(Y/N)";
cin>>c;
if(c=='y'||c=='Y')
{file.seekp(0,ios::beg);
for(i=0,w=0;!file.eof();i++)
{file>>c;
if(c=='|')
{w++;
if(index==w)
file>>c;

for(i=0;c!='|';i++)
{if(i==0)
temp<<'P';
file>>c;
if(file.eof())
{getch();break;}
temp<<c;}
}}}
temp.seekg(0,ios::beg);
for(i=0;!temp.eof();i++)
{temp>>c;
if(c==';')
cout<<'\n';
else
cout<<c;}
getch();
}
else
{cout<<"\nRECORD NOT FOUND,Press any KEY\n";getch();}
}
else
{cout<<"\nRECORDS NOT PRESENT,ENTER NEW RECORD,PRESS ANY KEY";getch();}
}

else
{cout<<"File NOT FOUND:\n\t\tPRESS ANY KEY";getch();
}

file.close();
temp.close();
drmain();
}
void drug::deletedr()
{clrscr();
cleardevice();
setbkcolor(BLUE);
int k=0,f=0,w=0,index=0,last=0;
long int i=0;
char c,m,search[100];
fstream file;
file.open("DRUG.TXT",ios::in);

fstream temp;
temp.open("TEMP.txt",ios::out|ios::trunc);


if(!file.fail())
{
while(!file.eof())
{file>>c;
if(c=='|')
last++;
}
cout<<"TOTAL RECORD:"<<last<<"\nPRESS ANY KEY";getch();
file.clear();
file.seekp(0,ios::beg);
temp.seekp(0,ios::beg);
if(last!=0)
{
cout<<"\nEnter the WHAT U WANNA DELETE.\nEX-\n\n\n";
cout<<"PRODUCT_NO:(ENTER_THE_PATIENT_NO);\nPATIENT_NAME:(ENTER_NAME)\n\nANYTHING!!!!";
cout<<"\nENTER THE SEARCH:";
gets(search);
l:
for(i=0;!file.eof();i++)
{
file>>c;
if(c=='|')
{index++;}
else if(search[0]==c)
{
for(k=0,w=0;search[k]!='\0';k++,i++)
if(search[k]==c)
{file>>c;
w++;}

if(w==strlen(search))
{cout<<"PRODUCT ENTERY NO:"<<index;f=1;getch();break;}
}
}

if(f==1)
{cout<<"\nDO YOU WANT TO DELETE DETAILS?(Y/N)";
cin>>m;
if(m=='y'||m=='Y')
{
file.clear();
file.seekp(0,ios::beg);
for(i=0,w=0;!file.eof();i++)
{file>>c;
if(c=='|')
w++;
if(index!=w)
{temp<<c;
if(c==';')
temp<<'\n';}
}
}
}

else
{cout<<"\nRECORD NOT FOUND,Press any KEY\n";getch();}
}
else
{cout<<"\nRECORD NOT PRESENT,FILE EMPTY,Press any KEY\n";getch();}
}


else
{cout<<"File NOT FOUND:\n\t\tPRESS ANY KEY";getch();
}
file.close();
temp.close();

//DELETING  AND COPYING TO FILE USING ANOTHER TEMPARY FILE
if(m=='y'||m=='Y')
{
index=0;
temp.open("TEMP.txt",ios::in);
file.open("DRUG.txt",ios::out);
remove("DRUG.TXT");                        //DELETING FILE
rename("TEMP.TXT","DRUG.TXT");  //RENAMING THE FILE TEMP AS DRUG

cout<<"RECORD DELETED,PRESS ANY KEY";getch();
}
drmain();
}

