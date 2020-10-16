class Student{
    int *score;
    public:
        void input();
        int calculateTotalScore();
};

void Student::input(){
    int i, n;
    this->score = new int[5];
    for(i=0;i<5;i++){
        cin >> n;
        this->score[i] = n;
    }
}

int Student::calculateTotalScore(){
    int sum=0;
    for(int i=0;i<5;i++)
        sum += this->score[i];
    return sum;
}
