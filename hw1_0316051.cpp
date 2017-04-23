#include<iostream>
#include<time.h>
#include<fstream>
#include <sstream>
using namespace std;

void failureFunction(string& p);
int f[1000000];   //failure function�s��a 
int main(int argc,char* argv[]){

	stringstream ss;  //�B�z magic_number���L�� �ɶ� �����D ->��time�নstring��_��->�]����fout<<�ɶ�->fout<< magic_number
    ifstream fin;
    ofstream fout;
    string in;    //.txt Ū�i�Ӫ��r 
    int time;		//�p��ĴX�� 
    string pat;		
    string magic_number;   //�ǻ��������X 
//test1 *********************************************************
    fin.open("test1.txt",ifstream::in);
    fout.open("test1out.txt",ofstream::out);
    clock_t t=clock();  //process start
    fin>>in;
    time=1;
    magic_number="1";
    //fout<<endl<<time;
    pat=in;
    failureFunction(pat); // ->f[1000000]
    // �Q�� failureFunction 
    while(fin>>in)
    {
        time++;
        //fin>>c;
        int i=0;
        for(int a=0;a<in.length();)
        {
            while(in[a]==pat[i] && pat.length() != i)
            {
                a++;
                i++;
            }
            if(pat.length() == i)
            {
                i=f[i-1]+1;
                ss<<time;
                magic_number = magic_number + ss.str();
                ss.str("");
				ss.clear();
                //fout<<time;
            }else if(i==0)
            {
                a++;
            }else
            {
                i=f[i-1]+1;
            }
        }
    }
    t=clock()-t; // process end
    fout<<((float)t)/CLOCKS_PER_SEC*1000<<"ms"<<endl;
    fout<<magic_number;
    fin.close();
    fout.close();
//test2 *********************************************************
    fin.open("test2.txt",ifstream::in);
    fout.open("test2out.txt",ofstream::out);
    t=clock();  //process start
    fin>>in;
    time=1;
    magic_number="1";
    //fout<<time;
    pat=in;
    failureFunction(pat); // ->f[1000000]
    while(fin>>in)
    {
        time++;
        //fin>>c;
        int i=0;
        for(int a=0;a<in.length();)
        {
            while(in[a]==pat[i] && pat.length() != i)
            {
                a++;
                i++;
            }
            if(pat.length() == i)
            {
                i=f[i-1]+1;
                ss<<time;
                magic_number = magic_number + ss.str();
                ss.str("");
				ss.clear();
            }else if(i==0)
            {
                a++;
            }else
            {
                i=f[i-1]+1;
            }
        }
    }
    t=clock()-t; // process end
    fout<<((float)t)/CLOCKS_PER_SEC*1000<<"ms"<<endl;
    fout<<magic_number;
    fin.close();
    fout.close();
//test3 *********************************************************
    fin.open("test3.txt",ifstream::in);
    fout.open("test3out.txt",ofstream::out);
    t=clock();  //process start
    fin>>in;
    time=1;
    magic_number="1";
   // fout<<time;
    pat=in;
    failureFunction(pat); // ->f[1000000]
    while(fin>>in)
    {
        time++;
        //fin>>c;
        int i=0;
        for(int a=0;a<in.length();)
        {
            while(in[a]==pat[i] && pat.length() != i)
            {
                a++;
                i++;
            }
            if(pat.length() == i)
            {
                i=f[i-1]+1;
                ss<<time;
                magic_number = magic_number + ss.str();
                ss.str("");
				ss.clear();
            }else if(i==0)
            {
                a++;
            }else
            {
                i=f[i-1]+1;
            }
        }
    }
    t=clock()-t; // process end
    fout<<((float)t)/CLOCKS_PER_SEC*1000<<"ms"<<endl;
    fout<<magic_number;
    fin.close();
    fout.close();
}





//***********************************************
//failure function
void failureFunction(string& p)
{
    f[0]=-1;
    int size=p.length();
    for(int j=1;j<size;j++)
    {
        int i=f[j-1];
        while(p[j]!=p[i+1] && i>=0)i=f[i];
        if(p[j]==p[i+1])f[j]=i+1;
        else f[j]=-1;
    }
}
