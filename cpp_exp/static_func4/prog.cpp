#include<iostream>
using namespace std;
class cube{
public :
int l,w,h;
cube(int ,int ,int );
static int count;
static int getcount();
void print();
};
int cube::count=0;
cube::cube(int x,int y,int z){
l=x;
w=y;
h=z;
count++;
}
void cube:: print(){
cout<<"The volume is : "<<l*w*h<<endl;
}

int cube:: getcount(){
return count;
}

int main(){
cube one(2,5,8);
cube two(32,54,6);
one.print();
two.print();
cout<<"Number of objects created : "<<cube::getcount()<<endl;

return 0;}

