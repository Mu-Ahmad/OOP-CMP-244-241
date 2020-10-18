class Student {
    private:
    int scores[5];
    public: 
    void input() {
        int i;
        for (i = 0 ; i < 5 ; i++) {
            cin >> scores[i];
        }
    }
    int calculateTotalScore() {
        int i, sum = 0;
        for (i = 0 ; i < 5 ; i++) {
            sum = sum + scores[i];
        }
        return sum;
    }
};
