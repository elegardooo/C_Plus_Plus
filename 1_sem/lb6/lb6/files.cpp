#include "files.h"

void writeToTextFile(List<Car>* list, const std::string& filename) {
	std::ofstream inFile(filename, std::ios::out | std::ios::trunc);

	if (!inFile.is_open()) {
		std::cerr << "Error writing to text file!" << std::endl;
		return;
	}


	int size = list->size();
	Node<Car>* node = list->peek_head();
	for (int i = 0; i < size; i++) {
		inFile << node->data.GetBrand() << " " << node->data.GetEnum() << " " << node->data.GetVolume() << " " <<
			node->data.GetPower() << " " << node->data.GetDoorNum() << " " << node->data.GetLength() << " " << node->data.GetWidth() << " " <<
			node->data.GetHeight() << " " << node->data.GetColor() << "\n";

		node = node->next;
	}


	inFile.close();
}

void readFromTextFile(List<Car>* list, const std::string& filename) {
	std::ifstream fromFile(filename);

	if (!fromFile.is_open()) {
		std::cerr << "Error writing to text file!" << std::endl;
		return;
	}

	Car* cr;

	char brand[20];
	int enum_index;
	double volume;
	int power;
	int door_num;
	int Len_Wid_Height[3];
	char color[20];

	while (fromFile >> brand >> enum_index >> volume >> power >> door_num >> Len_Wid_Height[0] >> Len_Wid_Height[1] >> Len_Wid_Height[2] >> color) {
		cr = new Car(brand, enum_index, volume, power, door_num, Len_Wid_Height, color);
		list->push(*cr);
		delete cr;
	}

	fromFile.close();
}

void writeToBin(List<Car>* list, const std::string& filename) {
	std::ofstream inFile(filename, std::ios::out | std::ios::trunc | std::ios::binary);

	if (!inFile.is_open()) {
		std::cerr << "Error writing to text file!" << std::endl;
		return;
	}

	int size = list->size();
	Node<Car>* node = list->peek_head();
	Car& cr = node->data;
	for (int i = 0; i < size; i++) {
		cr = node->data;
		inFile.write(reinterpret_cast<const char*>(&cr), sizeof(Car));

		node = node->next;
	}

}

void readFromBinFile(List<Car>* list, const std::string& filename) {
	std::ifstream fromFile(filename);
	if (!fromFile.is_open()) {
		std::cerr << "Error writing to text file!" << std::endl;
		return;
	}

	Car cr;

	if (fromFile.is_open()) {
		while (fromFile.read(reinterpret_cast<char*>(&cr), sizeof(cr))) {
			list ->push(cr);
		}
	}
	fromFile.close();
}