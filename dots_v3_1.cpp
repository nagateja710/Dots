#include<iostream>
#include<string>
#include<string.h>
#include<bits/stdc++.h>
#include<algorithm>
#include<windows.h>
using namespace std;
char road[10][10]={' '};
/*
hack proof :encoding added
new look : clear screen implemented
new feature: hint display after some delay
*/
//int p1=1,q1=0;
//int r1=3,s1=3;
//int p2=2,q2=2;
//int r2=4,s2=4;
int p1[4]={0};
int p2[4]={0};
int p3[4]={0};
int p4[4]={0};
int p5[4]={0};
int ch [10]={0};
int z=0,zmax=0;
int n,m;
int cl=0,level,tutorial;
string name;
/*
_ _ _ _ _
_ _ _ _ _
_ _ _ _ _
_ _ _ _ _
_ _ _ _ _

*/
void sett();
void selection (int &lv);
void tut();
void game(int tx,char m);
int playerdata(string player);
void setdata(string player,int level);

void sett(){
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
road[i][j]=' ';
}
}

}

void print(){
    // int points[10]={1,2,3,4,5,5,5,4,0,5};
    int poi[12]={0,1,3,6,10,15,20,25,29,29,34,34};
    float progress=((float)(poi[level]-zmax+z)/34)*100;
    if(level<=1)progress=0;


    system("cls");
    cout<<"<<__welcome to DOTS GAME__>>\n\n";
    cout<<"player   : "<<name<<"\nprogress : "<<(int)progress<<"%"<<endl<<endl;

if(level==0){cout<<"\n** welcome to tutorial **\n\n";cout<<"'x' is your destination\n";}
if(tutorial==1 && level==1){cout<<"\nyou have completed tutorial \n";
cout<<"\n**NOW YOUR READY TO PLAY GAME**\n\n";tutorial=0;}
if(level>0 && level<2){
cout<<"\n---join same type of numbers---\n";
cout<<"\nmake sure no blanks left\n\n";
cout<<"***press 0 to reset***\n\n";}


if(level==6 || level==10)cout<<"note: @ is obstacle \n";
if(level==7)cout<<"note: you can overlap at '+'\n";
if(level>=8 && level<11)cout<<"note: 'x' is universal destination\n";
if(level>0 && level<11)cout<<"\n>>__LEVEL "<<level<<"__<<\n";

    // selection(level);
int line=0,x;
x=m*2+4;
cl=0;
cout<<endl;
while(line<x-2){cout<<"-";line++;}
cout<<endl;
for(int i=0;i<n;i++){
cout<<"|";
for(int j=0;j<m;j++){
cout<<road[i][j]<<" ";
if(road[i][j]==' ')cl++;

}
cout<<"|"<<endl;
}
line =0;
while(line<x-2){cout<<"-";line++;}
cout<<endl;
}

//------------------------------------------main


int main()
{char w=w,s=s,a=a,d=d;
int error=0;
int temp1,temp2;
int nn=0;
char input,mark='x';
int px,ps=-1,p,q,r,ss,ps1=1;
char px_copy;
int again;
char lv_c;
//tut();
cout<<"<<__welcome to DOTS GAME__>>\n\n";
cout<<"enter your name :";
cin>>name;
level=playerdata(name);
// if(level!=0)cout<<"\n>>welcome back "<<name<<" <<\n";
selection(level);
print();
for( z;z<zmax;z++){
nn=0;
cout<<"select a point :";
if(level==1)cout<<"\nhint: press 1\n";
cin>>px_copy;
px=px_copy-'0';

if(ch[px]==1){z--;cout<<"choose other point stupid!!\n"; continue;}//-------point matching completed

if(px>zmax || px<=0){z--;cout<<"noobie...try again\n";continue;}
if(px==1){p=p1[0];q=p1[1];r=p1[2];ss=p1[3];}
if(px==2){p=p2[0];q=p2[1];r=p2[2];ss=p2[3];}
if(px==3){p=p3[0];q=p3[1];r=p3[2];ss=p3[3];}
if(px==4){p=p4[0];q=p4[1];r=p4[2];ss=p4[3];}
if(px==5){p=p5[0];q=p5[1];r=p5[2];ss=p5[3];}

if(px==0){selection(level);z=-1;print(); continue;}
cout<<"\nyour at point "<<px<<endl;
//cout<<"\npress W/S/A/D to move :";
temp1=p;temp2=q;
road[p][q]='o';
road[r][ss]='x';


while(nn<100){
if(error==0){print();}
else if(error==1){cout<<"don't cross border\n";}
else if(error==2){cout<<"you cannot overlap\n";}

error=0;
cout<<"w/s/a/d/0 :";
cin>>input;

switch(input){

case 'w':

if(road[p-1][q]=='+')p=p-1;
if(road[p-1][q]==' ' || road[p-1][q]==mark){

if(p-1==r && q==ss){road[p][q]='^';ps1=0;break;}
else if(road[p-1][q]=='x'){road[p][q]='^';ps1=0;error=3;break;}

road[p-1][q]='^';
//if(p-1==r){ps1=0;break;}
p=p-1;
}
else if(p-1<=0){error=1;continue;}
else{error=2;continue;}

break;
case 's':
if(road[p+1][q]=='+')p=p+1;
if(road[p+1][q]==' ' ||road[p+1][q]==mark){
if(p+1==r && q==ss){road[p][q]='v';ps1=0;break;}
else if(road[p+1][q]=='x'){road[p][q]='v';ps1=0;error=3;break;}

road[p+1][q]='v';
p=p+1;
}
else if(p+1>=n){error=1;continue;}
else{error=2;continue;}

//if(1+p==r){ps1=0;break;}
break;
case 'a':
if(road[p][q-1]=='+')q=q-1;
if(road[p][q-1]==' '|| road[p][q-1]==mark){

if(p==r && q-1==ss){road[p][q]='<';ps1=0;break;}
else if(road[p][q-1]=='x'){road[p][q]='<';ps1=0;error=3;break;}

road[p][q-1]='<';
//if(q-1==ss){ps1=0;break;}
q=q-1;
}
else if(q-1<=0){error=1;continue;}
else{error=2;continue;}
break;

case 'd':
if(road[p][q+1]=='+')q=q+1;
if(road[p][q+1]==' ' || road[p][q+1]==mark){

if(p==r && q+1==ss){road[p][q]='>';ps1=0;break;}
else if(road[p][q+1]=='x'){road[p][q]='>';ps1=0;error=3;break;}

road[p][q+1]='>';
//if(q+1==ss){ps1=0;break;}
q=q+1;
}
else if(q+1>=n){error=1; continue;}
else{error=2;continue;}

break;
case '0':
ps=0;
/*cout<<"are you sure you want to RESET\n";
cout<<"press 0 to RESET , else press 1 to continue"<<endl;
cin>>ps; */
break;
default:
cout<<"wrong input"<<endl;
error=3;
continue;
}

if(ps==0){ps=1;selection(level);z=-1; break;}
//print();

if(ps1==0){
ch[px]=1;ps1=1;
road[temp1][temp2]='0'+px;

if(error==3)road[r][ss]='@';
else 
road[r][ss]='0'+px;

error=0;
break;}

nn++;
}

print();

if(z==zmax-1){

 if(cl==0){
 cout<<"***CONGRATULATIONS..!***\n\n     >>LEVEL PASSED<< \n";}
else{
 cout<<"**all blanks are not filled***\n";
 cout<<"\n   >>LEVEL FAILED<< \n";
 }

cout<<"\n_______press e to exit________";
cout<<"\n_______press r to retry______";
if(cl==0)cout<<"\n___press n to play next level__";

cout<<"\ninput :";
char rlv;
 cin>>rlv;
   if(rlv=='e'){if(cl==0)setdata(name,++level);break;}
else if(rlv=='n' && cl==0)level++;
  else if(rlv!='r'){cin>>level;}
  if(level==11){z=0;selection(level);print();break;}
  selection(level);print();z=-1;
 }
  
}
cout<<"\n\n<<THANK YOU FOR PLAYING>>";
char end;
cin>>end;
    return 0;
}

//-----------------------------------------------tutorial
void game(int tx,char mv){
int p,q,r,ss,nn=0;
int ps1=2;
char in;
char mark1='x';

for(int count=0;count<1;count++){
//tx++;
if(tx==1){p=4;q=2;r=0;ss=2;}
if(tx==2){p=0;q=2;r=4;ss=2;}
if(tx==3){p=2;q=0;r=2;ss=4;}
if(tx==4){p=2;q=4;r=2;ss=0;}


while(nn<50){
print();
cout<<"press "<<mv<<" :";
cin>>in;
while(in!=mv){if(in=='0')break;
cout<<"press "<<mv<<" :";
cin>>in;}
switch(in){
case 'w':
if(p-1==r && q==ss){road[p][q]='^';ps1=0;break;}
road[p-1][q]='^';
p=p-1;


break;
case 's':
if(p+1==r && q==ss){road[p][q]='v';ps1=0;break;}

road[p+1][q]='v';
p=p+1;

break;
case 'a':
if(p==r && q-1==ss){road[p][q]='<';ps1=0;break;}
road[p][q-1]='<';
q=q-1;

break;

case 'd':
if(p==r && q+1==ss){road[p][q]='>';ps1=0;break;}
road[p][q+1]='>';

q=q+1;


break;
case '0':
return;
default:
cout<<"error 404"<<endl;
continue;
}

if(ps1==0){ps1=1;break;}

nn++;

}
}
cout<<"\ncongratulation your skill improved \n\n ";
}

void tut(){
char x;
int tx=0;
n=5;
m=5;
zmax=4;
sett();
road[0][2]='x';
road[4][2]='o';
game(1,'w');
sett();
road[4][2]='x';
road[0][2]='o';
game(2,'s');
sett();
road[2][4]='x';
road[2][0]='o';
game(3,'d');
sett();
road[2][0]='x';
road[2][4]='o';
game(4,'a');

tutorial=1;
//press any key to continue :" cin>>x;
//print();

}//-------------------------------------------------decode
void enncode(char c){
    int e=1;
    char x;
    string y;
    int l=-1;
    vector<char> v;
     ofstream oo("dots_data.txt",ios::app);oo.close();
    ifstream in("dots_data.txt");
    int i=0;
    while(in.eof()==0){
       in>>y;
       if(c=='e')v.push_back('%');
       for(int i=0;i<y.size();i++){
        if(c=='e')v.push_back(y[i]+3);
        else v.push_back(y[i]-3);
       }
       
    }
    in.close();
    auto va=v.begin();
    ofstream out("dots_data.txt");
    for(auto i=0;i<v.size();i++){

        if(v[i]=='"'){out<<' ';continue;}
        
         out<<v[i]; 
        // e++;
    }
}

//--------------------------------------------player data
int playerdata(string player){
    enncode('d');
    int i=0,level=0;
    string c;
    ofstream neww("dots_data.txt",ios::app);neww.close();
    ifstream iz("dots_data.txt");
    while(iz.eof()==0){
        iz>>c;
        if(c==player){i++;}
        if(i==1){iz>>level;break;}
        
    }
    iz.close(); 

    if(i==0){
         ofstream out("dots_data.txt",ios ::app);
         out<<endl<<player<<" 00";
    }
enncode('e');
    return level;
}
void setdata(string player,int level){
    enncode('d');
    int i=0;
    vector<string> v;
    string t;

ifstream in("dots_data.txt");
while(in.eof()==0){
in>>t;
if(player==t)i=2;
if(player!=t && i<=0){v.push_back(t);}
i--;
}
in.close();
ofstream out("dots_data.txt");
for(auto val=v.begin();val<v.end();val++){
   out<<*val<<" ";
   val++;
   out<<*val<<endl;
}
out<<player<<" "<<level;
out.close();
enncode('e');
}
//_--_--------------------------------------------levels------
void selection (int &lv){
    // int er=0;

setdata(name,lv);
for(int ret=0;ret<10;ret++){ch[ret]=0;}
switch(lv){
case 0:
tut();
lv=1;
setdata(name,lv);
selection (lv);
break;
case 1:

p1[0]=0;p1[1]=0;p1[2]=2;p1[3]=2;
zmax=1;
n=3;
m=3;
sett();
road[p1[0]][p1[0]]='1';
road[p1[2]][p1[3]]='1';

break;
case 2:
p1[0]=2;p1[1]=1;p1[2]=2;p1[3]=3;
p2[0]=1;p2[1]=1;p2[2]=3;p2[3]=3;
//p2[4]={2,2,4,4};
zmax=2;
n=4;
m=4;
sett();
road[p1[0]][p1[1]]='1';
road[p1[2]][p1[3]]='1';
road[p2[0]][p2[1]]='2';
road[p2[2]][p2[3]]='2';
break;
case 3:
p1[0]=2;p1[1]=0;p1[2]=0;p1[3]=3;
p2[0]=3;p2[1]=3;p2[2]=0;p2[3]=4;
p3[0]=3;p3[1]=0;p3[2]=2;p3[3]=2;
//p2[4]={2,2,4,4};
zmax=3;
n=5;
m=5;
sett();
road[p1[0]][p1[1]]='1';
road[p1[2]][p1[3]]='1';
road[p2[0]][p2[1]]='2';
road[p2[2]][p2[3]]='2';
road[p3[0]][p3[1]]='3';
road[p3[2]][p3[3]]='3';
break;
case 4:
p1[0]=0;p1[1]=0;p1[2]=0;p1[3]=4;
p2[0]=1;p2[1]=1;p2[2]=1;p2[3]=3;
p3[0]=3;p3[1]=1;p3[2]=1;p3[3]=2;
p4[0]=4;p4[1]=3;p4[2]=1;p4[3]=4;
//p2[4]={2,2,4,4};
zmax=4;
n=5;
m=5;
sett();
road[p1[0]][p1[1]]='1';
road[p1[2]][p1[3]]='1';
road[p2[0]][p2[1]]='2';
road[p2[2]][p2[3]]='2';
road[p3[0]][p3[1]]='3';
road[p3[2]][p3[3]]='3';
road[p4[0]][p4[1]]='4';
road[p4[2]][p4[3]]='4';
break;
case 5:
p1[0]=2;p1[1]=0;p1[2]=0;p1[3]=2;
p2[0]=4;p2[1]=0;p2[2]=1;p2[3]=4;
p3[0]=1;p3[1]=1;p3[2]=4;p3[3]=4;
p4[0]=5;p4[1]=0;p4[2]=4;p4[3]=1;
p5[0]=1;p5[1]=2;p5[2]=2;p5[3]=5;
//p2[4]={2,2,4,4};
zmax=5;
n=6;
m=6;
sett();
road[p1[0]][p1[1]]='1';
road[p1[2]][p1[3]]='1';
road[p2[0]][p2[1]]='2';
road[p2[2]][p2[3]]='2';
road[p3[0]][p3[1]]='3';
road[p3[2]][p3[3]]='3';
road[p4[0]][p4[1]]='4';
road[p4[2]][p4[3]]='4';
road[p5[0]][p5[1]]='5';
road[p5[2]][p5[3]]='5';
break;
case 6:

p1[0]=3;p1[1]=1;p1[2]=1;p1[3]=4;
p2[0]=5;p2[1]=1;p2[2]=1;p2[3]=5;
p3[0]=5;p3[1]=4;p3[2]=4;p3[3]=5;
p4[0]=2;p4[1]=5;p4[2]=5;p4[3]=2;

zmax=4;
n=6;
m=6;
sett();
road[p1[0]][p1[1]]='1';
road[p1[2]][p1[3]]='1';
road[p2[0]][p2[1]]='2';
road[p2[2]][p2[3]]='2';
road[p3[0]][p3[1]]='3';
road[p3[2]][p3[3]]='3';
road[p4[0]][p4[1]]='4';
road[p4[2]][p4[3]]='4';
//road[1][4]='@';
road[4][1]='@';
road[4][4]='@';
road[5][5]='@';

break;
/*
6*6
+--2,1;3,4;
1-4,0;2,3;
2-1,2;4,3;
3-1,0;0,4;
4-1,1;5,0;
5-0,5;4,5;

*/
case 7:
p1[0]=4;p1[1]=0;p1[2]=2;p1[3]=3;
p2[0]=1;p2[1]=2;p2[2]=4;p2[3]=3;
p3[0]=1;p3[1]=0;p3[2]=0;p3[3]=5;
p4[0]=1;p4[1]=1;p4[2]=5;p4[3]=0;
p5[0]=1;p5[1]=5;p5[2]=4;p5[3]=5;
//p2[4]={2,2,4,4};
zmax=5;
n=6;
m=6;
sett();
road[p1[0]][p1[1]]='1';
road[p1[2]][p1[3]]='1';
road[p2[0]][p2[1]]='2';
road[p2[2]][p2[3]]='2';
road[p3[0]][p3[1]]='3';
road[p3[2]][p3[3]]='3';
road[p4[0]][p4[1]]='4';
road[p4[2]][p4[3]]='4';
road[p5[0]][p5[1]]='5';
road[p5[2]][p5[3]]='5';
road[2][1]='+';
road[3][4]='+';
break;
/*

*/
case 8:

p1[0]=0;p1[1]=0;p1[2]=10;p1[3]=10;
p2[0]=0;p2[1]=4;p2[2]=10;p2[3]=10;
p3[0]=4;p3[1]=0;p3[2]=10;p3[3]=10;
p4[0]=4;p4[1]=4;p4[2]=10;p4[3]=10;

zmax=4;
n=5;
m=5;
sett();
road[p1[0]][p1[1]]='1';
road[p2[0]][p2[1]]='2';
road[p3[0]][p3[1]]='3';
road[p4[0]][p4[1]]='4';
road[2][2]='x';

break;
case 9:
p1[0]=0;p1[1]=0;p1[2]=2;p1[3]=2;
p2[0]=0;p2[1]=3;p2[2]=4;p2[3]=5;
p3[0]=0;p3[1]=2;p3[2]=3;p3[3]=2;
p4[0]=1;p4[1]=0;p4[2]=3;p4[3]=1;
p5[0]=5;p5[1]=0;p5[2]=5;p5[3]=5;
//p2[4]={2,2,4,4};
zmax=5;
n=6;
m=6;
sett();
road[p1[0]][p1[1]]='1';
road[p1[2]][p1[3]]='1';
road[p2[0]][p2[1]]='2';
road[p2[2]][p2[3]]='2';
road[p3[0]][p3[1]]='3';
road[p3[2]][p3[3]]='3';
road[p4[0]][p4[1]]='4';
road[p4[2]][p4[3]]='4';
road[p5[0]][p5[1]]='5';
road[p5[2]][p5[3]]='5';
road[2][4]='x';
//road[3][1]='@';

break;
case 11:
n=0;m=0;zmax=0;
sett();
break;
default:
// er=1;
cout<<"**new levels comming soon**\n";
cout<<"  _select low levels_ :";
cin>>lv;
selection (lv);
}
if(lv>=0)cout<<"\n>>__LEVEL "<<lv<<"__<<\n";
}
//-----------------------------------------return

    