#include<iostream>
#include<string.h>
#include<cstdio>
#include<iomanip>
using namespace std;
const int size = 3 ;
struct Student
{
int RollNo ;
char Name[25] ;
float SGPA ;
};
class DATA
{
public:
void getdata(struct Student list[size]) ;
void display(struct Student list[100]) ;
void bubble_sort(struct Student list[size]) ;
void insertion_sort(struct Student list[size]) ;
void search(struct Student list[size]) ;
void binary_search(struct Student list[size]) ;
void quick_sort(int low , int high);
int partition(int low , int high);
void top_10_toppers(struct Student list[size]);
};
void DATA :: getdata(struct Student list[size])
{
for (int i = 0 ; i < size ; i++ )
{
cout << " Enter Roll No. : " << endl ;
cin >> list[i].RollNo ;
cout << " Enter Name : " << endl ;
cin >> list[i].Name ;
cout << " Enter SGPA : " << endl ;
cin >> list[i].SGPA ;
}
}
void DATA :: display(struct Student list[100])
{
cout<<"\n RollNo \t Name \t SGPA \n";
for(int i=0;i<size;i++)
{
cout <<"\n"<< list[i].RollNo <<"\t"<< list[i].Name <<"\t"<< list[i].SGPA;
}
}
void DATA :: bubble_sort(struct Student list[size])
{
struct Student temp ;
for(int i=0 ; i<size-1 ; i++)
{
for(int j=0 ; j<(size-i-1) ; j++)
{
if(list[j].RollNo>list[j+1].RollNo)
{
temp = list[j] ;
list[j] = list[j+1] ;
list[j+1] = temp ;
}
}
}
}
void DATA :: insertion_sort(struct Student list[size])
{
int k,j ;
struct Student temp;
for (int k = 1; k < size; k++)
{
temp = list[k];
j = k - 1 ;
while (strcmp(list[j].Name , temp.Name)>0 && j>=0)
{
list[j+1] = list[j];
--j;
}
list[j+1] = temp ;
}
}
int DATA :: partition(int low , int high)
{
struct Student list[size];
Student pivot = list[low];
int i = low + 1;
int j = high;
do
{
while(list[i].SGPA >= pivot.SGPA)
{
i++;
}
while(list[j].SGPA < pivot.SGPA)
{
j--;
}
if (i<j)
{
Student temp = list[j];
list[j] = list[i];
list[i] = temp;
}
}
while(i<j);
{
Student temp = list[low];
list[low] = list[j];
list[j] = temp;
return j;
}
}
void DATA :: quick_sort(int low , int high)
{
if (low<high)
{
int pi = partition(low,high);
quick_sort(low , pi-1);
quick_sort(pi + 1 , high);
}
}
void DATA :: top_10_toppers(struct Student list[size])
{
DATA da;
da.quick_sort(0,size-1);
cout << "RollNo" << setw(15) << "Name" << setw(22) << "SGPA"<< endl;
for (int i=0;i<size;i++)
{
cout << setw(4) << list[i].RollNo << setw(20) << list[i].Name << setw(20) << list[i].SGPA <<endl;
}
}
void DATA :: search(struct Student list[size])
{
float SGPA;
cout<<"Enter SGPA you want to search : "<<endl;
cin>>SGPA;
cout<<"\n RollNo\t Name\t SGPA\n" ;
for (int i = 0; i < size; i++)
{
if (SGPA==list[i].SGPA)
{
cout<<"\n"<<list[i].RollNo<<"\t"<<list[i].Name<<"\t"<<list[i].SGPA;
}
}
}
void DATA :: binary_search(struct Student list[size])
{
int k, top, bottom, mid ;
char name[25];
cout<<"Enter The Name Of Student You Want To Search :";
cin>>name;
bottom = 0 ;
top = size - 1 ;
mid = (top + bottom)/2 ;
while (bottom <= top)
{
if (strcmp(list[mid].Name,name)<0)
{
bottom = mid + 1 ;
}
else if (strcmp(list[mid].Name,name)==0)
{
cout<<"\n"<<list[mid].RollNo<<"\t"<<list[mid].Name<<"\t"<<list[mid].SGPA ;
break ;
}
else
{
top = mid - 1 ;
mid = (bottom + top)/2;
}
if (bottom > top)
{
cout << name <<" not found in the list";
}
}
}
int main()
{
int ch , i ;
struct Student info[25];
DATA d ;
d.getdata(info);
do
{
cout << "\n1.Bubble Sort (Sort the list by Roll No. in Ascending Order) " << endl ;
cout << "2.Insertion Sort (Arrange the students list Alphabetically) " << endl ;
cout << "3.Quick Sort (To know Toppers from a class)" << endl ;
cout << "4.Search(You can search Students according to SGPA ) " << endl ;
cout << "5.Binary Search(You can search the Student according to name) " << endl ;
cout << " Enter Your Choice : " << endl ;
cin >> ch ;
switch (ch)
{
case 1 :
d.bubble_sort(info) ;
d.display(info) ;
break;
case 2 :
d.insertion_sort(info) ;
d.display(info) ;
break;
case 3 :
d.top_10_toppers(info) ;
break;
case 4 :
d.search(info) ;
break;
case 5 :
d.binary_search(info) ;
break;
}
}
while (ch!=5);
return 0 ;
}