#ifndef LOCALDATASOURCE_H
#define LOCALDATASOURCE_H

#include "FilterRepository.h"

struct LocalDataSource {
    static void saveDataToFile();
    static void loadDataFromFile();
};

#endif // LOCALDATASOURCE_H
