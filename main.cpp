#include <iostream>
#include <cmath>

using namespace std;

class Field {

	protected:
		double *value;

	public:

		//Constructors
		Field() {value = new double[3];
						 value[0] = 0;
						 value[1] = 0;
						 value[2] = 0;}

		Field(double vx, double vy, double vz) {value = new double[3];
																										 value[0] = vx;
																										 value[1] = vy;
																										 value[2] = vz;}
		
		// Deconstructor
		//~Field() {delete[] value; cout << "Destructor called for Field()" << endl;}

		// Getters
    double getV_X() {return value[0];}
    double getV_Y() {return value[1];}
    double getV_Z() {return value[2];}

    // Setters
    void setV_X(double vx) {value[0] = vx;}
    void setV_Y(double vy) {value[1] = vy;}
    void setV_Z(double vz) {value[2] = vz;}

		void printMagnitude() {
			cout << "Components(X,Y,Z): " << value[0] << ", " << value[1] << ", " << value[2] << endl;
		}

};

class Electric_Field : public Field {

	private:
		double E;

	public:

		//Constructors
		Electric_Field() : Field(){}
		Electric_Field(double vx, double vy, double vz) : Field(vx, vy, vz){}
		
		// Deconstructor
		~Electric_Field() {cout << "Destructor called for E_Field" << endl;}

		double get_E() {return E;}

		void calcElectricField(double r, double Q) {E = Q / (4 * M_PI * pow(r, 2) * 8.85e-12);}

		Electric_Field operator+(const Electric_Field& eField) const {
			
			Electric_Field result;

			result.value[0] = this->value[0] + eField.value[0];
			result.value[1] = this->value[1] + eField.value[1];
			result.value[2] = this->value[2] + eField.value[2];

			return result;
		}
		
		friend ostream &operator<<(ostream &os, const Electric_Field &eField) {
			os << "Field: " << eField.E << "\nX: " << eField.value[0] << "\nY: " <<  eField.value[1] << "\nZ: " << eField.value[2];
			return os;
		}

};

class Magnetic_Field : public Field {


	private:
		double B;

	public:

		//Constructors
		Magnetic_Field() : Field(){}
		Magnetic_Field(double vx, double vy, double vz) : Field(vx, vy, vz){}
		
		// Deconstructor
		~Magnetic_Field() {cout << "Destructor called for M_Field" << endl;}

		double get_B() {return B;}

		void calcMagneticField(double r, double I) {B = I / (2 * M_PI * r * 1.26e-6);}
		
		Magnetic_Field operator+(const Magnetic_Field& mField) const {
			
			Magnetic_Field result;

			result.value[0] = this->value[0] + mField.value[0];
			result.value[1] = this->value[1] + mField.value[1];
			result.value[2] = this->value[2] + mField.value[2];

			return result;
		}
		
		friend ostream &operator<<(ostream &os, const Magnetic_Field &mField) {
			os << "Field: " << mField.B << "\nX: " << mField.value[0] << "\nY: " <<  mField.value[1] << "\nZ: " << mField.value[2];
			return os;
		}

};


int main() {

	Electric_Field e1(1e5, 10.9, 1.7e2), e2(1e5, 10.9, 1.7e2), e3;
	e3 = e1 + e2;

	Magnetic_Field m1(1e5, 10.9, 1.7e2), m2(1e5, 10.9, 1.7e2), m3;
	m3 = m1 + m2;

	e1.calcElectricField(2, 5);
	e2.calcElectricField(4, 7);
	e3.calcElectricField(5, 2);

	m1.calcMagneticField(2, 5);
	m2.calcMagneticField(4, 7);
	m3.calcMagneticField(5, 2);

	e1.printMagnitude();
	e2.printMagnitude();
	e3.printMagnitude();
	
	m1.printMagnitude();
	m2.printMagnitude();
	m3.printMagnitude();
	
	cout << e1 << "\n" << e2 << "\n" << e3 << endl;
	cout << m1 << "\n" << m2 << "\n" << m3 << endl;

	return 0;

}
