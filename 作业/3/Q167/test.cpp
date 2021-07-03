#include <iostream>
using namespace std;

class Operation {
public:
	double NumberA;
	double NumberB;

	Operation(){}

	virtual double GetResult() {
		return 0;
	}

	double getA(){
		return NumberA;
	}

	void setA(double a) {
		NumberA = a;
	}

	double getB() {
		return NumberB;
	}

	void setB(double b) {
		NumberB = b;
	}
};

class OperationAdd : public Operation {
public:
	OperationAdd() {}

	double GetResult() {
		return NumberA + NumberB;
	}
};

class OperationSub : public Operation {
public:
	OperationSub(){}

	double GetResult() {
		return NumberA - NumberB;
	}
};

class OperationMul : public Operation {
public:
	OperationMul(){}

	double GetResult() {
		return NumberA * NumberB;
	}
};

class OperationDiv : public Operation {
public:
	OperationDiv(){}

	double GetResult() {
		if (NumberB == 0) {
			return -1;
		}
		return NumberA / NumberB;
	}
};

class OperationFactory {
public:
	OperationFactory() {}

	Operation* CreateOperation(char Operator) {
		Operation* op = &Operation();
		if (Operator == '+') {
			op = &OperationAdd();
		}
		else if (Operator == '-') {
			op = &OperationSub();
		}
		else if (Operator == '*') {
			op = &OperationMul();
		}
		else if (Operator == '/') {
			op = &OperationDiv();
		}
		return op;
	}
};

int main() {
	char Operator;
	int a, b;
	cin >> Operator >> a >> b;
	OperationFactory opf = OperationFactory();
	Operation* op = opf.CreateOperation(Operator);
	op->setA(a);
	op->setB(b);
	cout << op->GetResult();
	return 0;
}