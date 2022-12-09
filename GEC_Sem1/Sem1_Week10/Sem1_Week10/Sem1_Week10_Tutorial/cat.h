#ifndef CAT_H
#define CAT_H

class cat
{
public:
	cat(int initial_age);
	~cat();

	int GetAge();
	void SetAge(int age);

private:
	int itsAge;
};

#endif //CAT_H