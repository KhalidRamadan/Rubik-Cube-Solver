#include "vision/Scanner.h"
#include<iostream>

int main()
{
	vision::Scanner scan("Hello");

	scan.Update();

	return 0;
}