#include<iostream>

using namespace std;

class Date
{
    private:
        int month, year, day;
    public:
        Date(const int day = 0, const int month = 0, const int year = 0)
        {
            set_date(day, month, year);
        }
        
        void set_date(const int day, const int month, const int year)
        {
           set_month(month);
           set_year(year);
           set_day(day);
        }
        
        void set_month(const int month)
        {
            this->month = month;
        }

        void set_day(const int day)
        {
            this->day = day;
        }
        
        void set_year(const int year)
        {
            this->year = year;
        }

        int get_month(void) const
        {
            return month;
        }

        int get_day(void) const
        {
            return day;
        }

        int get_year(void) const
        {
            return year;
        }

        Date& operator = (const Date& date)
        {
            this->year = date.year;
            this->month = date.month;
            this->day = date.day;
            return *this;
        }

        friend ostream& operator<<(ostream &os, const Date& d);
};
ostream& operator <<(ostream &os, const Date& d)
{
    os<<d.day<<'/'<<d.month<<'/'<<d.year<<'\n';
    return os;
}

class Employee
{
    protected:
        static unsigned int employee_number;
        Date hiring_date;
    public:
        Employee()
        {
            employee_number++;
        }
        Employee(const Date hiring_date)
        {
            employee_number++;
            set_date(hiring_date);
        }

        void set_date(const Date& date)
        {
            this->hiring_date = date;
        }

        Date get_date(void) const
        {
            return hiring_date;
        }
        friend ostream& operator <<(ostream &os, const Employee& e);
};
ostream& operator <<(ostream &os, const Employee& e)
{
    os<<"Employee Number: "<<e.employee_number<<'\n';
    os<<"Hiring Date: "<<e.hiring_date<<'\n';
    return os;
}

class ProductionWorker:public Employee
{
    private:
        unsigned int shift = 0; // 1 or 2.. 1 is Day and 2 is Night..
        float hourly_rate; // Should be Positive..
    public:
        ProductionWorker()
        {

        }
        ProductionWorker(const Date hiring_date, const int shift, const float hourly_rate = 0.0):Employee(hiring_date)
        {
            set_shift(shift);
            set_hourly_rate(hourly_rate);
        }

        void set_shift(const int shift)
        {
            this->shift = shift;
        }
        
        void set_hourly_rate(const float hourly_rate = 0.0)
        {
            this->hourly_rate = hourly_rate;
        }

        int get_shift() const
        {
            return this->shift;
        }

        int get_hourly_rate() const
        {
            return this->hourly_rate;
        }
friend ostream& operator <<(ostream &os, const ProductionWorker& p);
};
ostream& operator <<(ostream &os, const ProductionWorker& p)
{
    os << (Employee)p<<'\n';
    if(p.shift == 1)
        os<<"Shift: Day"<<'\n';
    else
        os<<"Shift: Night"<<'\n';
    os << "Hourly Rate: "<<p.hourly_rate<<" $"<<'\n';

    return os;
}
unsigned int Employee::employee_number = 0; // Static variable of Employee..

int main(void)
{
    Date d(12, 12, 2020);
    ProductionWorker p1 (d, 1, 13.5f);
    cout << p1;
    return 0;
}