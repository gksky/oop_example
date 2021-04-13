#include <stdio.h>
#include <conio.h>
#include <iostream.h>

class line{
public:
	line();
	int getline(void){ return l;};
	virtual double sof(void){ return 0;};
private:
	int l;
};

line::line(){
	cout << "Enter line: ";
	scanf("%d",&l);
};

class square:public line{
public:
	square(){ cout << "Enter height: "; scanf("%d",&h);};
	double sof(void){ return h*getline();};
private:
	int h;
};



class triangle:public line{
public:
	triangle(){ cout << "Enter height: "; scanf("%d",&h);};
	double sof(void){ return 0.5*h*getline();};
private:
	int h;
};

class circle: public line{
public:
	circle(){ cout << "Diameter of circle = " << getline() << "\n";};
	double sof(void){ return 3.14*0.25*getline()*getline();};
	friend double operator+(circle,circle);
private:
};

double operator+(circle x,circle y){
	return x.sof()+y.sof();
}

void main(void){
   clrscr();
   cout << "Enter size of Square: \n";
   square B;
   cout << "\nEnter size of Triangle: \n";
   triangle C;
   cout << "\nEnter size of Circle: \n";
   circle A;
   cout << "\n  Square of square = " << B.sof() <<"\n";
   cout << "  Square of triangle = " << C.sof() <<"\n";
   cout << "  Square of circle = " << A.sof() <<"\n";
   cout << "  Summ of two circles = " << A+A;
   getch();
}