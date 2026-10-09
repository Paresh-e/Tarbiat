#include "tattami.h"

Tattami::Tattami() {}



Tattami::Tattami(QString T, QTime L ){
    this ->Last = L ;
    this ->Title = T;
}
void Tattami::set_Category(CompetitionGroup& group)
{
    int key = 0;

    while (Cat.contains(key))
        ++key;

    Cat.insert(key, group);
}
