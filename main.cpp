#include<iostream>
#include <cstdlib>
#include<string>
#include<iomanip>
#include<fstream>
#include <conio.h>
using namespace std;



//subject claas

class Subject{
protected:
    int id;
    string name;
    float fee;

public:



    addSubject(){
        cout<<"enter subject id : ";cin>>id;
        cout<<"enter subject name : ";cin>>name;
        cout<<"enter subject fee : ";cin>>fee;

    }

    void getanykey(){
        cout<<"\n\n\ press any key to back";getch();
    }

    void save(){
        ofstream alsub;
        alsub.open("alsub.txt",ios::app);
        alsub<<setw(3)<<id<<setw(20)<<name<<setw(5)<<fee<<endl;
        alsub.close();
    }

    void showAll(){

        ifstream alsub;
        alsub.open("alsub.txt",ios::in);
        cout<<setw(3)<<"id"<<setw(20)<<"name"<<setw(5)<<"fee"<<endl<<endl;
        while(true){
            alsub>>id>>name>>fee;
            if(alsub.good()){

                cout<<setw(3)<<id<<setw(20)<<name<<setw(5)<<fee<<endl;
            }else{
                break;
            }



        }
        alsub.close();



    }


};




class Student:Subject{
    int stuid;
    string stuname;
    int stuage;
    string stuaddress;
    string subject;


public:
    addNew(){
        cout<<"enter id : ";cin>>stuid;
        cout<<"enter name : ";cin>>stuname;
        cout<<"enter age : ";cin>>stuage;
        cout<<"enter address : ";cin>>stuaddress;

    }

    void save(){

        ofstream alstu;
        alstu.open("alstu.txt",ios::app);
        alstu<<setw(5)<<stuid<<setw(20)<<stuname<<setw(3)<<stuage<<setw(30)<<stuaddress<<endl;
        alstu.close();

    }

    void addSubject(){
        int subid;
        int sid;

        cout<<"enter student id : ";cin>>sid;
        cout<<"select subject  \n\n"<<endl;
        showAll();
        cout<<"\n\n enter subject id : ";cin>>subid;

        ofstream student_subject;
        student_subject.open("stu_sub.txt",ios::app);
        student_subject<<setw(5)<<sid<<setw(3)<<subid<<endl;
        student_subject.close();

    }

    void getStudentSubjects(int s_id){
        int subid;
        int sid;
        ifstream stu_sub;
        stu_sub.open("stu_sub.txt",ios::in);

        while(true){
            stu_sub>>sid>>subid;
            if(stu_sub.good()){

                if(s_id == sid){

                    ifstream subs;
                    subs.open("alsub.txt",ios::in);

                    while(true){
                        subs>>id>>name>>fee;
                        if(subs.good()){
                           if(id == subid){
                            cout<<setw(85)<<name<<endl;
                           }
                        }else{
                            break;
                        }

                    }
                }

            }else{
                break;
            }

        }


    }



    void showStudent(){

        ifstream allstu;
        allstu.open("alstu.txt",ios::in);
        cout<<setw(5)<<"id"<<setw(20)<<"name"<<setw(5)<<"age"<<setw(30)<<"address"<<endl<<endl;
        while(true){
            allstu>>stuid>>stuname>>stuage>>stuaddress;
            if(allstu.good()){
                cout<<setw(5)<<stuid<<setw(20)<<stuname<<setw(5)<<stuage<<setw(30)<<stuaddress<<endl;
                cout<<setw(75)<<" subjects : "<<endl;
                getStudentSubjects(stuid);
                cout<<"----------------------------------------------------------------------------------"<<endl;


            }else{
                break;
            }


        }

        getanykey();


    }


    void showStudent(int s_id){

        ifstream allstu;
        allstu.open("alstu.txt",ios::in);
        cout<<setw(5)<<"id"<<setw(20)<<"name"<<setw(5)<<"age"<<setw(30)<<"address"<<endl<<endl;
        while(true){
            allstu>>stuid>>stuname>>stuage>>stuaddress;
            if(allstu.good()){
                if(s_id == stuid){

                    cout<<setw(5)<<stuid<<setw(20)<<stuname<<setw(5)<<stuage<<setw(30)<<stuaddress<<endl;
                    cout<<setw(75)<<" subjects : "<<endl;
                    getStudentSubjects(stuid);
                    cout<<"----------------------------------------------------------------------------------"<<endl;

                }

            }else{
                break;
            }


        }

        getanykey();


    }

    void deleteStudent(int s_id){

    }

};



//menu class
// this class use for menu

class Menu{
public:

    void subManage(){

        while(true){
        system("cls");
        int choice;
        cout<<"\n\n 1.add subject \n 2.delete  subject "<<endl;
        cout<<" 3.show all subjects"<<endl;
        cout<<"\n\n 0.to exit"<<endl;
        cout<<"\n\n choice >>";cin>>choice;
        if(choice == 0){
            break;
        }else if(choice == 1){
            system("cls");
            Subject sub;
            sub.addSubject();
            sub.save();

        }else if(choice == 3){
            Subject sub;
            sub.showAll();
            sub.getanykey();
        }

        }

    }



    void stuManage(){

        while(true){
        system("cls");
        int choice;
        cout<<"\n\n 1.add new student\n 2.find student \n 3.delete student \n";
        cout<<" 4.add new subject to student\n";
        cout<<" 5.show all student \n ";
        cout<<"\n\n0.to exit"<<endl;
        cout<<"\n\n choice >>";cin>>choice;
        if(choice == 0){
            break;
        }else if(choice == 1){
            system("cls");
            Student stu;
            stu.addNew();
            stu.save();

        }else if(choice == 4){
            Student stu;
            stu.addSubject();
        }else if(choice == 5){
            Student stu;
            stu.showStudent();
        }else if(choice == 2){
            int s_id;
            cout<<"enter student id :";cin>>s_id;
            cout<<endl;
            Student stu;
            stu.showStudent(s_id);
        }

        }

    }


    mainMenu(){

        while(true){
            system("cls");
            int choice;
            cout<<"welcome to management system !!!"<<endl;
            cout<<"\n\n menu \n\n 1.Student management \n 2.subject managrment \n 3.Reports \n\n[enter 0 to exit]\n\n[*]choice >>";
            cin>>choice;
            if(choice == 0){
                break;
            }else if(choice == 1){
                stuManage();
            }else if(choice == 2){
                subManage();
            }

        }
    }

};

//student class
//this class use for student data


//classes



int main(){
    Menu menu;
    menu.mainMenu();
return 0;
}
