#include <iostream>

void f(int&& x) {

}

void functorTest() {
	f(22);
}