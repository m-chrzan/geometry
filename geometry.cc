#include "geometry.h"

template class AbstractPair<Position>;
template class AbstractPair<Vector>;

template <class T>
AbstractPair<T>::~AbstractPair() {}
