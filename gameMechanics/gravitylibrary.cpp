#include "gravitylibrary.h"

gravityLibrary::gravityLibrary(QObject *parent)
    : QObject{parent}
{
    gravForce = new forceClass(this);
    gravForce->setForce(0, DEFAULT_GRAVITY);
}

void gravityLibrary::gravityEnable(bool en)
{
    if(en == true){
        gravForce->setForce(0, DEFAULT_GRAVITY);
    }
    else{
        gravForce->setForce(0,0);
    }
}
