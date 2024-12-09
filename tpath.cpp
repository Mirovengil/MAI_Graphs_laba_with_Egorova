#include "tpath.h"

TPath::TPath()
{

}

void TPath::addStep(TPoint step)
{
    steps.push_back(step);
}
