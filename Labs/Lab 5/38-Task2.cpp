// Write your Student class here
class Student{
    int score;
    int Size=5;
    int scores[5];
    public:
    void input (){
        for(int i=0;i<Size;i++)
            cin >> scores[i];
    }
    int calculateTotalScore(){
        int sum=0;
        for(int i=0;i<Size;i++)
            sum += scores[i];
        return sum;
    }
    
    
};

