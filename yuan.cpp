#include <stdio.h>
#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;


void date_check(string date){
    if (date.size()!=10){
        cout <<"Invalid date.\n";
        exit (0);
    }
    if (!isdigit(date[0])||!isdigit(date[1])||!isdigit(date[3])||!isdigit(date[4])
        ||!isdigit(date[6])||!isdigit(date[7])||!isdigit(date[8])||!isdigit(date[9])){
        cout <<"Invalid date. (The date should be numbers.)\n";
        exit(0);
    }   
    if((date[2] != '-' || date[5] != '-')&&(date[2] != '/' || date[5] != '/')){
        cout<<"Invalid fomat of date.\n";
        exit(0);
    }

    return;
}

void print_out_month(string date){
    if ((date[0]==48) && (date[1]==49))
        cout << "January ";
    if ((date[0]==48) && (date[1]==50))
        cout << "February ";
    if ((date[0]==48) && (date[1]==51))
        cout << "March ";
    if ((date[0]==48) && (date[1]==52))
        cout << "April ";
    if ((date[0]==48) && (date[1]==53))
        cout << "May ";
    if ((date[0]==48) && (date[1]==54))
        cout << "June ";
    if ((date[0]==48) && (date[1]==55))
        cout << "July ";
    if ((date[0]==48) && (date[1]==56))
        cout << "August ";
    if ((date[0]==48) && (date[1]==57))
        cout << "September ";
    if ((date[0]==49) && (date[1]==48))
        cout << "Ocotobor ";
    if ((date[0]==49) && (date[1]==49))
        cout << "November ";
    if ((date[0]==49) && (date[1]==50))
        cout << "December ";
}

void time_check(string time){
    if (time.size()!=12){
        cout <<"Invalid format of time.\n";
        exit (0);
    }
    if (!isdigit(time[0])||!isdigit(time[1])
        ||!isdigit(time[3])||!isdigit(time[4])
        ||!isdigit(time[6])||!isdigit(time[7])
        ||!isdigit(time[9])||!isdigit(time[10])||!isdigit(time[11])){
        cout <<"Invalid time. (The time should be numbers.)\n";
        exit(0);
    }   
    if(time[2] != ':' || time[5] != ':'||time[8] != '.' ){
        cout<<"Invalid fomat of time.\n";
        exit(0);
    }

    return;
}


int main(){
    string date;
    cin >> date;
    date_check(date);
    print_out_month(date);
   /* string time;
    cin >> time;
    time_check(time);
    cout << time;*/
    return 0;
}