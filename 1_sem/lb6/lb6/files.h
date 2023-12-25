#pragma once
#include "List.h"
#include "CarClass.h"

void writeToTextFile(List<Car>* list, const std::string& filename);
void readFromTextFile(List<Car>* list, const std::string& filename);
void writeToBin(List<Car>* list, const std::string& filename);
void readFromBinFile(List<Car>* list, const std::string& filename);