
#include <bits/stdc++.h>
using namespace std;
struct student{
 unsigned int roll_no;
 char name[50];
 float sgpa;
};
class List{
 private:
 student a[20];
 int size;
 public:

 int get_size(){
 return size;
 }

 void create(){
 cout << "Enter the size of Array :";
 cin >> size; // Takes the size and input
 for (int i=0;i<size;i++){
 cout << "Enter the Roll No. ";
 cin >> a[i].roll_no;
 cout << "Enter the Name :";
 cin >> a[i].name;
 cout << "Enter SGPA :";
 cin >> a[i].sgpa;

 }
 }

 // This is bubble_sort to sort according to roll_no
 void bubble_sort(){
 for (int i=0;(i < size);i++){
 for (int j=0;j<size-1;j++){
 if (a[j].roll_no>a[i].roll_no){
 student temp = a[i];
 a[i] = a[j];
 a[j] = temp;
 }
 }
 }


 cout << "Roll No." << setw(15) << "Name" << setw(25) << "SGPA"<< endl;
 for (int i=0;i<size;i++){

 cout << a[i].roll_no << setw(25) << a[i].name << setw(30) << a[i].sgpa <<endl;
 }
 }
// This is insertion sort to sort according to name
void insertion()
{
 int i, j;
 student key;
 for (i = 1; i < size; i++)
 {
 key = a[i];
 j = i - 1;
 while (j >= 0 && a[j].name > key.name)
 {
 a[j + 1] = a[j];
 j = j - 1;
 }
 a[j + 1] = key;
 }

 cout << "Roll No." << setw(15) << "Name" << setw(25) << "SGPA"<< endl;
 for (int i=0;i<size;i++){

 cout << a[i].roll_no << setw(25) << a[i].name << setw(30) << a[i].sgpa <<endl;
 }
}
// this is normal function to find freq of highest marks
void find_freq(){
 int freq;
 float freq_marks;
 int max_freq = 1;
 for (int i=0;i<size;i++){
 int freq =1;
 for (int j=0;j<size;j++){
 if (a[j].sgpa == a[i].sgpa){
 freq++;
 }
 }
 if (max_freq<=freq){
 max_freq = freq;
 freq_marks = a[i].sgpa;
 }
 }
 cout << "The maximum frequency of the marks is : "<< max_freq-1 << " Which is marks" <<
freq_marks << endl;
 }
// This is linear_search to find students according to SGPA
void linear_search(int find){
 for (int i=0;i<size;i++){
 if (a[i].sgpa == find){
 cout << "Roll NO:-" << a[i].roll_no << endl;
 cout << "Name :- " << a[i].name << endl;
 cout << "SGPA :-" << a[i].sgpa << endl;
 }
 }
}
// Quick sort

 int partation(int low,int high){
 student pviot = a[low];
 int i = low+1;
 int j = high;

 do{
 while(a[i].sgpa >= pviot.sgpa){
 i++;
 }

 while(a[j].sgpa < pviot.sgpa){
 j--;
 }

 if (i<j){
 student temp = a[j];
 a[j] = a[i];
 a[i] = temp;
 }
 }while(i<j);

 student temp = a[low];
 a[low] = a[j];
 a[j] = temp;

 return j;
 }

 void quick_sort(int low,int high){
 if (low<high){
 int part = partation(low,high);

 quick_sort(low,part-1);
 quick_sort(part+1,high);
 }
 }

 // this method uses quick_sort to sort 1st 10 SGPA
 void display_top(){
 quick_sort(0,size-1);
 if (size>10){
 cout << "Roll No." << setw(15) << "Name" << setw(25) << "SGPA"<< endl;
 for (int i=0;i<10;i++){
 cout << a[i].roll_no << setw(25) << a[i].name << setw(30) << a[i].sgpa <<endl;
 }
 }
 else{
 cout << "Roll No." << setw(15) << "Name" << setw(25) << "SGPA"<< endl;
 for (int i=0;i<size;i++){
 cout << a[i].roll_no << setw(25) << a[i].name << setw(30) << a[i].sgpa <<endl;
 }
 cout << "Not enough students" << endl;
 }
 }


 void search_student(){
 char find[50];
 cout << "Enter the name :";
 cin>>find;

 for (int i=0;i<size;i++){
 if (strcmp(a[i].name,find)==0){
 cout << "Name : " << a[i].name << endl;
 cout << "Roll No : " << a[i].name << endl;
 cout << "SGPA : " << a[i].sgpa << endl;
 }
 }
 }

};
int main()
{

 List s;
 s.create();
 bool flag = true;
 while (flag){
 int ch, i;
 cout << "\n 1: Arrange list according to roll no.(bubble sort)";
 cout << "\n 2: Arrange list of students alphabetically. (Use Insertion sort)";
 cout << "\n 3: Search students according to SGPA. If more than one student having same SGPA, print list";
 cout << "\n 4: Most appeared marks \n";
 cout << "\n 5: Search Student According to name \n";
 cout << "\n 6: Exit \n";
 cout << "\n Enter your choice : ";
 cin >> ch;

 switch(ch){
 case 1:
 s.bubble_sort();
 continue;
 case 2:
 s.insertion();
 continue;
 case 3:
 s.display_top();
 continue;
 case 4:
 s.find_freq();
 continue;
 case 5:
 s.search_student();
 continue;
 case 6:
 flag = false;
 default:
 cout << "Invalid";
 }
 }
 return 0;
}