#include <stdio.h>
#include <iostream>
#include <string>
#include <ctype.h>
#include <fstream>
#include <sstream>

using namespace std;

void print_output(ofstream &outputfile, ofstream &logfile,string str,string termina, int &F){    
    if (F==1){
        outputfile.open("yuan.out");
        outputfile << str;
        outputfile.close();
    }
    if (F==2){
        logfile.open("yuan.log");
        cout << termina;
        logfile << str;
        logfile.close();
    }        
}

void open_log( string logfilename, ofstream &logfile){
    //stringstream ss;
    string information;
    ofstream outputfile;
    logfile.open(logfilename.c_str());
    if (!logfile.is_open() ){
        cout<< "Cannot open log file: "
            << logfilename
            << endl;
        int flag = 1;
        return;
    }
}

void open_input(string inputfilename,ifstream &inputfile,int &flag){

    ofstream outputfile, logfile;
    stringstream ss;
    string information,termina;

    inputfile.open(inputfilename.c_str());
    if (!inputfile.is_open()){
        ss << "Cannot open input file: "
           << inputfilename
           << endl;
        information = ss.str();
        int F = 1;
        print_output(outputfile,logfile,information,termina,F);
        flag = 1;
        return;
    } 
    return;
}

void open_output( string outputfilename, ofstream &outputfile){
    ofstream logfile;
    stringstream ss;
    string information,termina;

    outputfile.open(outputfilename.c_str());
    logfile.open("yuan.log");
    if (!outputfile.is_open() ){
        ss << "Cannot open output file: "
             << outputfilename
             << endl;
        information = ss.str();
        int F=2;
        print_output(outputfile,logfile,information,termina,F);
        int flag = 1;
        return;
    }
}


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

string print_out_month(string date){
    if ((date[0]==48) && (date[1]==49))
        return "January ";
    if ((date[0]==48) && (date[1]==50))
        return "February ";
    if ((date[0]==48) && (date[1]==51))
        return "March ";
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

void timezone_check(string timezone){
    if (timezone.size()!=3){
        cout <<"Invalid format of timezone.\n";
        exit (0);
    }
    if (!isalpha(timezone[0])||!isalpha(timezone[1])||!isalpha(timezone[2])){
        cout <<"Invalid format of timezone. \n";
        exit(0);
    }
    return;
}

enum magnitude{ 
    Ml, 
    Ms, 
    Mb, 
    Mw 
};
// useful function to convert a string to uppercase 
string uppercase (string &s){
    string result = s;
    for (int i=0; i<(int)result.size(); i++)
        result[i] = toupper(result[i]);
    return result;
}

bool is_valid_magnitude (string s) {
    string ss = uppercase(s);
    return((ss=="ML")||(ss=="MS")||(ss=="MB")||(ss=="MW"));
}

int main(){
    ifstream inputfile;
    ofstream logfile, outputfile;
    string inputfilename, logfilename, outputfilename;
    string sout, EventID, date, time, timezone,information;
    stringstream slog;
  
    int flag=0,F;

    open_log("yuan.log",logfile);
    logfile.close();
    sout = "> Enter input file name: ";
    //slog << sout;
    F=2;
    print_output(outputfile, logfile,slog.str(), sout, F);
    cin >> inputfilename;
    if (flag ==1)
    return 0;
    sout = "Opening file: ";
    slog << sout;
    F=2;
    print_output(outputfile, logfile, slog.str(), sout, F);
    sout =inputfilename;
    slog << sout;
    F=2;
    print_output(outputfile, logfile, slog.str(),sout, F);
    sout = "\nProcessing input...\n";
    slog << sout;
    F=2;
    print_output(outputfile, logfile, slog.str(),sout, F);
    open_input(inputfilename,inputfile, flag);
    inputfile >> EventID;
    inputfile >> date;
    date_check(date);  
    inputfile >> time;
    time_check(time);
    inputfile >> timezone;
    timezone_check(timezone);

    string name;
    for ( int i=0; getline(inputfile,name); i++ ){   
        if (i==1)
        break;
    }
    double longitude, latitude,depth;
    inputfile >> longitude >> latitude >> depth;
    string magnitude;
    inputfile >> magnitude;
    if(!is_valid_magnitude (magnitude)){
        sout = "invalid magnitude.\n";
        slog << sout;
        F=2;
        print_output(outputfile, logfile, slog.str(), sout, F);
        flag = 1;
        return 0;
    }
 /*   else
        cout << magnitude;*/

    float magnitudevalue;
    inputfile >> magnitudevalue;
    if (magnitudevalue<0){
        sout =  "invalid magnitudevalue.\n";
        slog << sout;
        F=2;
        print_output(outputfile, logfile, slog.str(),sout,F);
        flag = 1;
        return 0;
    }

    // If the header read successfully, then open the output file.

    //if (flag == 0)
        open_output("yuan.out",outputfile);
    outputfile.close();
    sout = "Header read correctly!\n";
    slog << sout;
    F=2;
    print_output(outputfile, logfile, slog.str(),sout, F);
    stringstream ss;
    ss << "# " << date[3] << date[4]<<' ';
    ss << print_out_month(date);
    ss << date[6] << date[7] << date[8] << date[9] <<' ';
    ss << time << ' ' << timezone << ' ';
    ss << magnitude << ' ' << magnitudevalue << ' ';
    ss << name << "\n";
    ss << "[" << EventID <<"] ";
    ss << "(" << longitude << ", " << latitude << ", " << depth << ")";
    F=1;
    print_output(outputfile, logfile,ss.str(),sout, F);


    return 0;
}