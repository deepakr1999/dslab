#include<iostream>
using namespace std;
class time1{
public :
int m,h,s;
time1();
time1(int h,int m,int s);
void add(time1 a,time1 b);
void print();
};

time1::time1(){
}
time1::time1(int h,int m,int s){
this->h=h;
this->m=m;
this->s=s;
}
void time1:: add(time1 a,time1 b){
this->h=a.h+b.h;
this->m=a.m+b.m;
this->s=a.s+b.s;
}
void time1:: print(){
cout<<h+m/60<<":"<<m%60+s/60<<":"<<s%60<<endl;
}

int main(){
time1 t1(5,62,50);
time1 t2(6,75,45);
cout<<"Original : "<<endl;
cout<<"5:62:50"<<endl<<"6:75:45"<<endl<<"Formatted"<<endl;
t1.print();
t2.print();
time1 t3;
t3.add(t1,t2);
t3.print();
return 0;
}
