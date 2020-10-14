#include<iostream>
#include<iomanip>
#define SIZE 4
using namespace std;
class Time12Hours
{
    int hours,minutes,seconds;
    char timeFormat;
    public:
        void setAttribute_4(char a_p,int h,int m,int s)
        {
            if(a_p=='A' || a_p=='P')
            timeFormat = a_p;
            else
            {
                timeFormat = 'A';   
            }

            if(h<=12 && h>=1)    
                hours = h;
            else
            {
                h=1;
            }

            if(m<=59 && m>=0)
                minutes = m;
            else
            {
                minutes = 0;
            }

            if(s<=59 && s>=0)
                seconds = s;
            else
            {
                seconds = 0;
            }
        }
        void setAttribute_3(char a_p,int h,int m)
        {
            if(a_p=='A' || a_p=='P')
                timeFormat = a_p;
            else
            {
                timeFormat = 'A';
            }

            if(h<=12 && h>=1)    
                hours = h;
            else
            {
                h=1;
            }

            if(m<=59 && m>=0)
                minutes = m;
            else
            {
                minutes = 0;
            } 
            seconds = 0;
        } 
        void setAttribute_2(char a_p,int h)
        {
            if(a_p=='A' || a_p=='P')
                timeFormat = a_p;
            else
            {
                timeFormat = 'A';
            }

            if(h<=12 && h>=1)    
                hours = h;
            else
            {
                h=1;
            }
            minutes = 0;
            seconds = 0;
        }
        void setAttribute_1(char a_p)
        {
            if(a_p=='A' || a_p=='P')
                timeFormat = a_p;
            else
            {
                timeFormat = 'A';
            }
            hours = 1;
            minutes = 0;
            seconds = 0;
        }
        void show()
        {
            cout << hours << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds <<" ";
            if(timeFormat == 'A')
                cout << "AM" << endl;
            else
            {
                cout << "PM" << endl;
            } 
        }
        void addHours(int value)
        {
                hours +=value;
                //transition from AM --> PM and PM -->AM
                if(hours > 12)
                {
                    hours = hours-12;
                    if(timeFormat == 'A')
                        timeFormat = 'P';
                    else if(timeFormat == 'P')
                        timeFormat = 'A';
                }
        }
        void addMinutes(int value)
        {
            minutes +=value;
            if(minutes>=60)
            {
                addHours(minutes/60);
                minutes = minutes-60;
            }                   
        }
        void addSeconds(int value)
        {
                seconds +=value;
                if(seconds>=60)
                {
                    addMinutes(seconds/60);
                    seconds = seconds-60;
                }
        }
};

int main()
{
    //Array of objects
    Time12Hours t[SIZE];
    int i;
    for(i=0;i<SIZE;i++)
    {
        char am_pm;
        int no_of_inputs,hours,minutes,seconds;
        cin >> no_of_inputs;
        //setting four values
        if(no_of_inputs == 4)
        {
            cin >> am_pm >> hours >> minutes >> seconds;
            t[i].setAttribute_4(am_pm,hours,minutes,seconds); 
        }
        //setting three values
        else if(no_of_inputs == 3)
        {
            cin >> am_pm >> hours >> minutes;
            t[i].setAttribute_3(am_pm,hours,minutes); 
        }
        //setting two values
        else if(no_of_inputs == 2)
        {
            cin >> am_pm >> hours;
            t[i].setAttribute_2(am_pm,hours); 
        }
        //setting one values
        else if(no_of_inputs == 1)
        {
            cin >> am_pm;
            t[i].setAttribute_1(am_pm);
        }
    }

    int no_of_increments;
    cin >> no_of_increments;
    //total no. of increments/changes
    while(no_of_increments != 0)
    {
        int objNo,incrementerNo,value;
        cin >> objNo;
        if(objNo<=4 && objNo >=1)
        {
            //which thing you want to change
            cin >> incrementerNo;
            if(incrementerNo<=3 && incrementerNo >=1)
            {
                cin >> value;
                if(value>0)
                {
                    //adding hours
                    if(incrementerNo == 1)
                    {
                        
                        t[objNo].addHours(value);
                        //displaying changed time  
                        t[objNo].show();                  
                    }
                    //adding minutes
                    else if(incrementerNo == 2)
                    {
                        t[objNo].addMinutes(value);
                        //displaying changed time
                        t[objNo].show();    
                        
                    }
                    //adding seconds
                    else
                    {
                        t[objNo].addSeconds(value);
                        //displaying changed time
                        t[objNo].show();        
                    }
                }
            }
        }
        no_of_increments -= 1;
    }
    //showing the objects after taking input without 
    //adding anything
    for(i=0;i<SIZE;i++)
    {
        t[i].show();
    }
    return 0;
}