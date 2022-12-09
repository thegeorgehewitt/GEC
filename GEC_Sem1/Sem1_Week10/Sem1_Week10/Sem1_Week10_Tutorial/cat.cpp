#include "cat.h"

cat::cat(int initial_age)
{
    itsAge = initial_age;
}
cat::~cat()
{

}
int cat::GetAge()
{
    return itsAge;
}
void cat::SetAge(int age)
{
    itsAge = age;
}
