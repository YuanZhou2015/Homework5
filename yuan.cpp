/*Homework 5
*

* https://github.com/YuanZhou2015/Homework5
* by Yuan Zhou
* February 25 2015
*/
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


void date_check(string date, stringstream & slog){
    string sout;
    ofstream outputfile, logfile;
    if (date.size()!=10){
        sout ="Invalid date.\n";
        slog << sout;
        int F=2;
        print_output(outputfile, logfile, slog.str(), sout, F);
        exit (0);
    }
    if (!isdigit(date[0])||!isdigit(date[1])||!isdigit(date[3])||!isdigit(date[4])
        ||!isdigit(date[6])||!isdigit(date[7])||!isdigit(date[8])||!isdigit(date[9])){
        sout ="Invalid date. (The date should be numbers.)\n";
        slog << sout;
        int F=2;
        print_output(outputfile, logfile, slog.str(), sout, F);
        exit(0);
    }   
    if((date[2] != '-' || date[5] != '-')&&(date[2] != '/' || date[5] != '/')){
        sout ="Invalid fomat of date.\n";
        slog << sout;
        int F=2;
        print_output(outputfile, logfile, slog.str(), sout, F);
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

void time_check(string time, stringstream & slog){
    string sout;
    ofstream outputfile, logfile;
    if (time.size()!=12){
        sout = "Invalid format of time.\n";
        slog << sout;
        int F=2;
        print_output(outputfile, logfile, slog.str(), sout, F);
        exit (0);
    }
    if (!isdigit(time[0])||!isdigit(time[1])
        ||!isdigit(time[3])||!isdigit(time[4])
        ||!isdigit(time[6])||!isdigit(time[7])
        ||!isdigit(time[9])||!isdigit(time[10])||!isdigit(time[11])){
        sout = "Invalid time. (The time should be numbers.)\n";
        slog << sout;
        int F=2;
        print_output(outputfile, logfile, slog.str(), sout, F);
        exit(0);
    }   
    if(time[2] != ':' || time[5] != ':'||time[8] != '.' ){
        sout = "Invalid fomat of time.\n";
        slog << sout;
        int F=2;
        print_output(outputfile, logfile, slog.str(), sout, F);
        exit(0);
    }

    return;
}

void timezone_check(string timezone, stringstream &slog){
    string sout;
    ofstream outputfile, logfile;
    if (timezone.size()!=3){
        sout = "Invalid format of timezone.\n";
        slog << sout;
        int F=2;
        print_output(outputfile, logfile, slog.str(), sout, F);
        exit (0);
    }
    if (!isalpha(timezone[0])||!isalpha(timezone[1])||!isalpha(timezone[2])){
        sout = "Invalid format of timezone. \n";
        slog << sout;
        int F=2;
        print_output(outputfile, logfile, slog.str(), sout, F);
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

string itos(int i) {
    stringstream s;
    s << i;
    return s.str();
}

void networkcode_check(string networkcode, stringstream &slog, stringstream &ss, int &i, int &flag){
    string sout;
    ofstream outputfile, logfile;
    int F;
    flag = 0;
    if (networkcode.size()!=2){
        sout = "Entry # ";
        slog << sout;
        F=2;
        print_output(outputfile, logfile, slog.str(), sout, F);
        sout = itos(i);
        slog << sout;
        F=2;
        print_output(outputfile, logfile, slog.str(), sout, F);
        sout = " ignored. Invalid network. \n";
        slog << sout;
        F=2;
        print_output(outputfile, logfile, slog.str(), sout, F);
        flag=1;
    }

    if (networkcode!= "CE" && networkcode!= "CI" && networkcode!="FA" 
        && networkcode!="NP" && networkcode!="WR"){
        sout = "Entry # ";
        slog << sout;
        F=2;
        print_output(outputfile, logfile, slog.str(), sout, F);
        sout =itos (i);
        slog << sout;
        F=2;
        print_output(outputfile, logfile, slog.str(), sout, F);
        sout = " ignored. Invalid network. \n";
        slog << sout;
        F=2;
        print_output(outputfile, logfile, slog.str(), sout, F);
        flag=1;
    }

   /* if (flag==0){
        F=1;
        sout = '\0';
        ss << networkcode<<'.';
        print_output(outputfile, logfile,ss.str(),sout,F);
    }*/
    return;
}

void stationcode_check(string stationcode,stringstream &slog,stringstream &ss, int &i, int &flag){
    string sout;
    ofstream outputfile, logfile;
    int F;
    flag=0;
    if (stationcode.size()!=3 && stationcode.size()!=5){
        sout = "Entry # ";
        slog << sout;
        F=2;
        print_output(outputfile, logfile, slog.str(), sout, F);
        sout = itos(i);
        slog << sout;
        F=2;
        print_output(outputfile, logfile, slog.str(), sout, F);
        sout = " ignored. Invalid station code. \n";
        slog << sout;
        F=2;
        print_output(outputfile, logfile, slog.str(), sout, F);
        flag=1;
    }

    if (stationcode.size()==3){
        if (!isupper(stationcode[0])||!isupper(stationcode[1])||!isupper(stationcode[2])){
            sout = "Entry # ";
            slog << sout;
            F=2;
            print_output(outputfile, logfile, slog.str(), sout, F);
            sout =itos (i);
            slog << sout;
            F=2;
            print_output(outputfile, logfile, slog.str(), sout, F);
            sout = " ignored. Invalid station code. \n";
            slog << sout;
            F=2;
            print_output(outputfile, logfile, slog.str(), sout, F);
            flag=1;
        }
    }

    if (stationcode.size()==5){
        if (!isdigit(stationcode[0])||!isdigit(stationcode[1])||!isdigit(stationcode[2])
            ||!isdigit(stationcode[3])||!isdigit(stationcode[4])){
            sout = "Entry # ";
            slog << sout;
            F=2;
            print_output(outputfile, logfile, slog.str(), sout, F);
            sout =itos (i);
            slog << sout;
            F=2;
            print_output(outputfile, logfile, slog.str(), sout, F);
            sout = " ignored. Invalid network. \n";
            slog << sout;
            F=2;
            print_output(outputfile, logfile, slog.str(), sout, F);
            flag=1;
        }
    }

   /* if (flag==0){
        F=1;
        sout = '\0';
        ss << stationcode<<'.';
        print_output(outputfile, logfile,ss.str(),sout,F);
    }*/
    return;
}

bool is_valid_typeofband (string s) {
    string ss = uppercase(s);
    return((ss=="LONG-PERIOD")||(ss=="SHORT-PERIOD")||(ss=="VROADBAND"));
}
void typeofband_check(string &typeofband,stringstream &slog,stringstream &ss, int &i, int flag){
    string sout;
    ofstream outputfile, logfile;
    int F;
    flag=0;
    if (!is_valid_typeofband(typeofband)){
        sout = "Entry # ";
        slog << sout;
        F=2;
        print_output(outputfile, logfile, slog.str(), sout, F);
        sout =itos (i);
        slog << sout;
        F=2;
        print_output(outputfile, logfile, slog.str(), sout, F);
        sout = " ignored. Invalid band type. \n";
        slog << sout;
        F=2;
        print_output(outputfile, logfile, slog.str(), sout, F);
        flag=1;    
    }
    if (flag==0){
        if (uppercase(typeofband)=="LONG-PERIOD"){
            /*F=1;
            sout = '\0';
            ss << "L";
            print_output(outputfile, logfile,ss.str(),sout,F);   */
            typeofband = "L";
        }
        if (uppercase(typeofband)=="SHORT-PERIOD"){
            /*F=1;
            sout = '\0';
            ss << "B";
            print_output(outputfile, logfile,ss.str(),sout,F);   */
            typeofband = "B";
        }
        if (uppercase(typeofband)=="BROADBAND"){
           /* F=1;
            sout = '\0';
            ss << "H";
            print_output(outputfile, logfile,ss.str(),sout,F);   */
            typeofband = "H";
        }
    }

}

bool is_valid_typeofinstru (string s) {
    string ss = uppercase(s);
    return((ss=="HIGH-GAIN")||(ss=="LOW-GAIN")||(ss=="ACCELEROMETER"));
}
void typeofinstru_check(string &typeofinstru,stringstream &slog, stringstream &ss, int&i, int &flag){
    string sout;
    ofstream outputfile, logfile;
    int F;
    flag=0;
    if (!is_valid_typeofinstru(typeofinstru)){
        sout = "Entry # ";
        slog << sout;
        F=2;
        print_output(outputfile, logfile, slog.str(), sout, F);
        sout =itos (i);
        slog << sout;
        F=2;
        print_output(outputfile, logfile, slog.str(), sout, F);
        sout = " ignored. Invalid type of instrument. \n";
        slog << sout;
        F=2;
        print_output(outputfile, logfile, slog.str(), sout, F);
        flag=1;    
    }
    if (flag==0){
        if (uppercase(typeofinstru)=="HIGH-GAIN"){
           /* F=1;
            sout = '\0';
            ss << "H";
            print_output(outputfile, logfile,ss.str(),sout,F);*/  
            typeofinstru = "H";
        }
        if (uppercase(typeofinstru)=="LOW-GAIN"){
           /* F=1;
            sout = '\0';
            ss << "L";
            print_output(outputfile, logfile,ss.str(),sout,F);   */
            typeofinstru = "L";
        }
        if (uppercase(typeofinstru)=="ACCELEROMETER"){
            /*F=1;
            sout = '\0';
            ss << "N";
            print_output(outputfile, logfile,ss.str(),sout,F);   */
            typeofinstru = "N";
        }
    }
}

void orientation_check(string orientation,stringstream &slog,stringstream &ss, int &i, int &flag){
    string sout;
    ofstream outputfile, logfile;
    int F,n,j;
    flag=0;
    if (orientation.size()>3||orientation.size()<1){
        sout = "Entry # ";
        slog << sout;
        F=2;
        print_output(outputfile, logfile, slog.str(), sout, F);
        sout = itos(i);
        slog << sout;
        F=2;
        print_output(outputfile, logfile, slog.str(), sout, F);
        sout = " ignored. Invalid orientation. \n";
        slog << sout;
        F=2;
        print_output(outputfile, logfile, slog.str(), sout, F);
        flag=1;
    }
    else{
        j=0;
        n=orientation.size();
        orientation = uppercase (orientation);
        while(j<n){
            if (orientation[j]!= '1' && orientation[j]!='2' && orientation[j]!= '3'){
                while (j<n){
                    if (orientation[j]!='N' && orientation[j]!='E' && orientation[j]!= 'Z'){
                        sout = "Entry # ";
                        slog << sout;
                        F=2;
                        print_output(outputfile, logfile, slog.str(), sout, F);
                        sout = itos(i);
                        slog << sout;
                        F=2;
                        print_output(outputfile, logfile, slog.str(), sout, F);
                        sout = " ignored. Invalid orientation. \n";
                        slog << sout;
                        F=2;
                        print_output(outputfile, logfile, slog.str(), sout, F);
                        flag=1;
                        j++;
                    }
                    else
                        j++;
                }
            }
            else{
                j++;
                while(j<n){
                    if (orientation[j]!= '1' && orientation[j]!='2' && orientation[j]!= '3'){
                        sout = "Entry # ";
                        slog << sout;
                        F=2;
                        print_output(outputfile, logfile, slog.str(), sout, F);
                        sout = itos(i);
                        slog << sout;
                        F=2;
                        print_output(outputfile, logfile, slog.str(), sout, F);
                        sout = " ignored. Invalid orientation. \n";
                        slog << sout;
                        F=2;
                        print_output(outputfile, logfile, slog.str(), sout, F);
                        flag=1;
                        j++;
                    }
                    else
                        j++;
                }
            }
        }
    }
}

struct Signal {
    string NT;
    string STN;
    string B;
    string I;
    string O;
};

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
    logfile.close();

    open_input(inputfilename,inputfile, flag);
    inputfile >> EventID;
    inputfile >> date;
    date_check(date,slog);  
    inputfile >> time;
    time_check(time,slog);
    inputfile >> timezone;
    timezone_check(timezone,slog);

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
        sout = "Invalid magnitude.\n";
        slog << sout;
        F=2;
        print_output(outputfile, logfile, slog.str(), sout, F);
        flag = 1;
        return 0;
    }

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

    if (flag == 0)
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
    ss << "(" << longitude << ", " << latitude << ", " << depth << ")\n";
    F=1;
    print_output(outputfile, logfile,ss.str(),sout, F);

    // Reading the table of earthquake information. The number of valid information will not more than 300.
    const int MAXSIZE = 300;
    Signal Signaldata[MAXSIZE];
    int size = 0, i=1,m=0, flag1=0,flag2=0,flag3=0,flag4=0,flag5=0;
    string networkcode, stationcode, typeofband, typeofinstru, orientation;
    while (!inputfile.eof() && size < MAXSIZE ){              
        inputfile >> networkcode;
        networkcode_check(networkcode,slog,ss,i,flag1);
        inputfile >> stationcode;
        stationcode_check(stationcode,slog,ss,i,flag2);
        inputfile >> typeofband;
        typeofband_check(typeofband,slog,ss,i,flag3);
        inputfile >> typeofinstru;
        typeofinstru_check(typeofinstru,slog,ss,i,flag4);
        inputfile >> orientation;
        int n = orientation.size(), j=0;
        orientation_check(orientation,slog,ss,i,flag5);

        if(flag1==0 && flag2==0 && flag3==0 && flag4==0 && flag5==0){
            while (j<n){
                Signaldata[size].NT = networkcode;
                Signaldata[size].STN = stationcode;
                Signaldata[size].B = typeofband;
                Signaldata[size].I = typeofinstru;
                Signaldata[size].O = orientation[j];
                //ss<< Signaldata[size].NT << "." << Signaldata[size].STN << "." << Signaldata[size].B << Signaldata[size].I << Signaldata[size].O <<"\n"; 
                size++;
                j++;
                if (size == 300)
                    break;
            }
        }
        if(flag1!=0 || flag2!=0 || flag3!=0 || flag4!=0 || flag5!=0)
            m++;    
        i++;
    }
    int k=i;

    F=2;
    sout ="\nTotal invalid entries igored: ";
    slog << sout;
    print_output(outputfile, logfile,slog.str(),sout,F); 
    sout =itos(m);
    slog << sout; 
    print_output(outputfile, logfile,slog.str(),sout,F); 
    sout ="\nTotal valid entries read: ";
    slog << sout;
    print_output(outputfile, logfile,slog.str(),sout,F);
    sout =itos(k-m-1);
    slog << sout; 
    print_output(outputfile, logfile,slog.str(),sout,F);
    sout ="\nSignal names produced: ";
    slog << sout;
    print_output(outputfile, logfile,slog.str(),sout,F);
    sout = itos(size);
    slog << sout <<"\n";
    print_output(outputfile, logfile,slog.str(),sout,F);
    F=1;
    sout = '\0';
    ss << itos(size) <<"\n";
    print_output(outputfile, logfile,ss.str(),sout,F); 
    
    for (int j=0; j< size; j++){
        F=1;
       // sout = '\0';
        ss << Signaldata[j].NT << "." << Signaldata[j].STN << "." << Signaldata[j].B << Signaldata[j].I << Signaldata[j].O <<"\n"; 
        print_output(outputfile, logfile,ss.str(),sout,F); 
    }
    F=2;
    sout = "\nFinished!\n";
    slog << sout;
    print_output(outputfile, logfile,slog.str(),sout,F);

    return 0;
}