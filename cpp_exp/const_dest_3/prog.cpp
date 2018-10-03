#include<iostream>
using namespace std;
class test{
public :
static int con,des;
test();
~test();
};
test::test(){
cout<<"Constructor called :"<<con<<" times"<<endl;
con+=1;
}
test::~test(){
cout<<"Destructor calles :"<<des<<" times"<<endl;
des++;
}
int test::con=1;
int test::des=1;
int main()
{
test t1,t2;
{
cout<<"Entered a block "<<endl;
test t3;
}
return 0;
}
