// Inaara Ahmed-Fazal   20821562
// Kayla Jetha          20822795
// Meghan LaCoste       20845775

#include "lab2_drones_manager.hpp"

#include <iostream>

using namespace std;

// TODO: Implement all of the listed functions below

DronesManager :: DronesManager() {
	first = NULL;
	last = NULL;
	size = 0;
}

bool operator==(const DronesManager::DroneRecord& lhs, const DronesManager::DroneRecord& rhs) {
	if(lhs.droneID == rhs.droneID
	&& lhs.range == rhs.range
	&& lhs.yearBought == rhs.yearBought
	&& lhs.droneType == rhs.droneType
	&& lhs.manufacturer == rhs.manufacturer
	&& lhs.description == rhs.description
	&& lhs.batteryType == rhs.batteryType)
		return true;
	return false;
}

unsigned int DronesManager::get_size() const {
	return size;
}

bool DronesManager::empty() const {
	if(!first)
		return true;
	return false;
}

DronesManager::DroneRecord DronesManager::select(unsigned int index) const {
	DroneRecord* cur = first;
	unsigned int counter = 0; 
	if(first == NULL)
		return DroneRecord(0);
	if(index < 0 || index >= size) return *last;
	//if list is empty return DroneRecord(0);
	for(unsigned int i = 0; i < index; i++) {
		cur = cur -> next;
	}
	return *cur;
	/*while(cur){ //iterate untill NULL
		if(counter == index)
			return *cur;
		cur = cur->next;
		++counter;	
	}
 */
}
unsigned int DronesManager::search(DroneRecord value) const {
	if(!first) return 0;
	DroneRecord* end = first;
	unsigned int index = 0;
	
	while(end){ //iterate untill NULL
		if(*end == value) //return the index
			return index;
		end = end->next;
		++index;	
	}
	return index;
}

void DronesManager::print() const {
	DroneRecord* cur = first; //initialize pointer 
	
	while(cur) { //iterate untill end of the list
		cout << "Drone ID: " << cur -> droneID << endl; //printing the value in the node
		cout << "Range: " << cur -> range << endl;
		cout << "Year Bought: " << cur -> yearBought << endl;
		cout << "Drone Type: " << cur -> droneType << endl;
		cout << "Manufacturer: " << cur -> manufacturer << endl;
		cout << "Description: " << cur -> description << endl;
		cout << "Battery Type: " << cur -> batteryType << endl;
		cout << endl << endl;
		cur = cur->next;
	}
}


bool DronesManager::insert(DroneRecord value, unsigned int index) {
	DroneRecord* cur = first;
	DroneRecord* before = NULL;
	DroneRecord* to_insert = new DroneRecord(value);
	if(index < 0 || index > size) return false;
	else if (index == 0) {
		insert_front(value);
		return true;
	}
	else if (index == size) {
		insert_back(value);
		return true;
	}
	else {
		for(unsigned int count = 0; count < index; count++) {
			before = cur;
			cur = cur -> next;
		}
		to_insert -> prev = before;
		before -> next = to_insert;
		to_insert -> next = cur;
		cur -> prev = to_insert;
		size++;	
	}
	
	return true;
}

bool DronesManager::insert_front(DroneRecord value) {
	DroneRecord* to_insert = new DroneRecord(value);
	if(!first) {
		first = to_insert;
		last = to_insert;
		to_insert -> next = NULL;
		to_insert -> prev = NULL;  
	}
	else {
		to_insert -> next = first;
		to_insert -> prev = NULL;
		first -> prev = to_insert;
		first = to_insert;
	}
	size++;
	return true;
}

bool DronesManager::insert_back(DroneRecord value) {
	DroneRecord* to_insert = new DroneRecord(value);
	if(!first) {
		first = to_insert;
		last = to_insert;
		to_insert -> next = NULL;
		to_insert -> prev = NULL;
	}
	else {
		to_insert -> prev = last;
		to_insert -> next = NULL;
		last -> next = to_insert; 
		last = to_insert;
	}
	size++;
	return true;
}
bool DronesManager::remove(unsigned int index) {
	
	DroneRecord *curr = first;
	DroneRecord *prev1 = first;
	if (index >= size) return false;
	if (index == 0) {
		remove_front();
		return true;	
	} 
	if (index == size-1) {
		remove_back();
		return true;	
	} 

	unsigned int count = 0;
	while (count < size && count < index) {
		prev1 = curr;
		curr = curr -> next;
		count ++;
	}
	
	prev1 -> next = curr -> next;
	DroneRecord * temp = curr -> next;
	temp -> prev = prev1;
	curr -> next = NULL;
	curr -> prev = NULL;
	delete curr;
	curr = NULL;
	
	size--;
	return true;
}

bool DronesManager::remove_front() {
	if(!first) return false;
	DroneRecord * remove = first;
	if(remove -> next) {
		first = remove -> next;
		first -> prev = NULL;
		remove -> next = NULL;
	}
	else {
		last = NULL;
		first = NULL;
	}	
	
	delete remove;
	remove = NULL;
	
	size--;
	return true;
}

bool DronesManager::remove_back() {
	if(!first) return false;
	DroneRecord * remove = last;
	if(last -> prev) {
		last =  last -> prev;
		last -> next = NULL;
	}
	else {
		first = NULL;
		last = NULL;
	}
	remove -> prev = NULL;
	remove -> next = NULL;
	delete remove;
	remove = NULL;
	
	size--;
	return true;
}

bool DronesManager::replace(unsigned int index, DroneRecord value) {
	if(index >= size) return false;
	else {
		remove(index);
		insert(value, index);
	}
	return true;
}

bool DronesManager::reverse_list() {
	if(!first)
		return false;
		
	DroneRecord* cur = first; 
	DroneRecord* after = NULL;
	DroneRecord* before = NULL;
	last = first;
	while(cur){
		after = cur->next;
		cur-> next = before;
		cur -> prev = after;
		before = cur;
		cur = after;
	}
	first = before;
	return true;
}

DronesManager::~DronesManager() {
	// [droneID = 100] -> [droneID = 200] ->  [droneID = 300] -> NULL
	DroneRecord * cur = first;
	while (cur) {
		cur = cur -> next;
		delete first;
		first = cur;
		
	}
	first = last = NULL;
	size = 0;
}
