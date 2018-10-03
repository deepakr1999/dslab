#include<iostream>
using namespace std;
class strings{
public:
string s;
strings(){

}
strings(string x){
s=x;
}
strings(const strings &cp){
s=cp.s;
}
void print(){
cout<<s<<endl;
}
void con_cat(strings a,strings b){

s=a.s+b.s;
cout<<"Concat is : ";
}
};
int main(){
strings s("Ramaiah");
strings s1("CSE");
strings s2(s1);
strings s3;
s.print();
s1.print();
s2.print();
s3.con_cat(s,s1);
s3.print();
return 0;

}
