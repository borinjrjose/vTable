#include "Base.h"
#include "Derivated.h"

int main()
{
    Base b = newBase(10);
    say(b);

    Derivated d = newDerivated(11, 12);
    say((Base) d);

    return 0;
}
