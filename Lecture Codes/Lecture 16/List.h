class List{
	int *data;
	const int SIZE;
public:
	List(int=10);
	void setValuesRandomly();
	void show() const;
	~List(){	delete []data;	}
};

