#include<iostream>
#include<algorithm>
#include <string>
using namespace std; 
struct student 
{
   int id;
   char name[50];
};

int main(){
    int n;
    cout<<"Enter number of students "<<endl;
    cin>>n;
    struct student student[n]; //Array of student structure object
    for (int i = 0; i < n; i++)
    { 
        cout<<"Enter Name of Student: "<<i+1<<endl;
        cin>> student[i].name;
        cout<<"Enter ID of Student: "<<i+1<<endl;
        cin>>student[i].id; 
       
    } 
  //Sorting Students by id
    for (int i = 0; i < n-1; i++)
    {
    for (int j = i+1; j < n; j++)
    {
        if(student[i].id>student[j].id){
        swap(student[i],student[j]);
        }
    }
    }
    cout<<"\n===Sorted Via ID===\n"<<endl;
   for (int i = 0; i < n; i++)
    { 
        cout<<"Student Name: "<<student[i].name<<endl;
        student[i].id;
        cout<<"ID of Student: "<<student[i].id<<endl;  
    }
    
    for (int i = 0; i < n-1; i++)
    {
    for (int j = i+1; j < n; j++)
    {
        if(student[i].name[0]>student[j].name[0]){
        swap(student[i],student[j]);
        }
    }
    }
    cout<<"\n===Sorted Via First Character===\n"<<endl;
   for (int i = 0; i < n; i++)
    { 
        cout<<"Student Name: "<<student[i].name<<endl;
        student[i].id;
        cout<<"ID of Student: "<<student[i].id<<endl;  
    }
    return 0;
}
