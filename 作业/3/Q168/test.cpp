#include <iostream>
#include <list>
using namespace std;

class food {
public:
	double carbohydrate;
	double protein;
	double DF;
	double fat;

	food(){}
};

class rice : public food {
public:
	rice(){
		carbohydrate = 16.2;
		protein = 3.7;
		DF = 0;
		fat = 0;
	}
	
};

class beef : public food {
public:
	beef(){
		carbohydrate = 1.8;
		protein = 17.5;
		DF = 0;
		fat = 7.2;
	}
};

class bro : public food {
public:
	bro(){
		carbohydrate = 0.2;
		protein = 0.4;
		DF = 3.6;
		fat = 0;
	}
	
};

class oat : public food {
public:
	oat(){
		carbohydrate = 12.3;
		protein = 5.7;
		DF = 7.3;
		fat = 3;
	}
};

class duck : public food {
public:
	duck(){
		carbohydrate = 6.9;
		protein = 9;
		DF = 0;
		fat = 9.3;
	}
};

class cab : public food {
public:
	cab(){
		carbohydrate = 2.1;
		protein = 0.8;
		DF = 4.3;
		fat = 0;
	}

};

class diet {
public:
	list<food> foodlist;

	diet(){}

	diet operator +=(const food& b) {
		foodlist.push_back(b);
		return *this;
	}
	
	bool if_heaalthy() {
		double allcarbohydrate = 0;
		double allprotein = 0;
		double allDF = 40;
		double allfat = 0;
		for (list<food>::iterator i = foodlist.begin(); i != foodlist.end(); ++i) {
			allcarbohydrate += i->carbohydrate;
			allprotein += i->protein;
			allDF += i->DF;
			allfat += i->fat;
		}
		if (allcarbohydrate < 13.3 || allprotein < 13.5 || allDF < 3.3 || allfat > 10.3) {
			return false;
		}
		else {
			return true;
		}
	}
};

int main() {
	int num = 0;
	diet mydiet = diet();
	for (int i = 0; i < 3; ++i) {
		cin >> num;
		if (num == 1) {
			rice temp = rice();
			mydiet += temp;
		}
		else if (num == 2) {
			beef temp = beef();
			mydiet += temp;
		}
		else if (num == 3) {
			bro temp = bro();
			mydiet += temp;
		}
		else if (num == 4) {
			oat temp = oat();
			mydiet += temp;
		}
		else if (num == 5) {
			duck temp = duck();
			mydiet += temp;
		}
		else if (num == 6) {
			cab temp = cab();
			mydiet += temp;
		}
		else {
			cout << -1;
			return 0;
		}
	}
	if (mydiet.if_heaalthy()) {
		cout << "healthy";
	}
	else {
		cout << "unhealthy";
	}
	return 0;
}