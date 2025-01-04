#include "Aktivitet.h"
Aktivitet::Aktivitet() {}

Aktivitet::Aktivitet(int e, string t, int d)
{
	event = e;
	task = t;
	duration = d;
}

int Aktivitet::getEvent()
{
	return event;
}

string Aktivitet::getTask()
{
	return task;
}

int Aktivitet::getDuration()
{
	return duration;
}

int main(){

	Aktivitet akt(1, "A", 3);


}