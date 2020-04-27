// Inaara Ahmed-Fazal   20821562
// Kayla Jetha          20822795
// Meghan LaCoste       20845775

#ifndef DRONES_MANAGER_TEST
#define DRONES_MANAGER_TEST

#include "lab2_drones_manager.hpp"

#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;

class DronesManagerTest {
public:
	// PURPOSE: New empty list is valid
    bool test1() {
    	
    	//IGOR'S TEST CASES:
    	
		DronesManager manager;
		ASSERT_TRUE(manager.get_size() == 0)
		ASSERT_TRUE(manager.empty() == true)
		ASSERT_TRUE(manager.first == NULL)
		ASSERT_TRUE(manager.last == NULL)
		
		//OUR TEST CASES:
		
		DronesManager manager2;
		ASSERT_TRUE(manager2.get_size() == 0)
		ASSERT_TRUE(manager2.empty() == true)
		ASSERT_TRUE(manager2.first == NULL)
		ASSERT_TRUE(manager2.last == NULL)
		/*ASSERT_TRUE((manager2.first)->prev == NULL)
		ASSERT_TRUE(manager2.first->next == NULL)
		ASSERT_TRUE(manager2.last -> prev == NULL)
		ASSERT_TRUE(manager2.last -> next == NULL) */
		
	    return true;
    }
	
	// PURPOSE: insert_front() and insert_back() on zero-element list
    bool test2() {
    	
    	//IGOR'S TEST CASES:
    	
		DronesManager manager1, manager2;
		manager1.insert_front(DronesManager::DroneRecord(100));
		manager2.insert_back(DronesManager::DroneRecord(100));
	    
		ASSERT_TRUE(manager1.get_size() == manager2.get_size() && manager1.get_size() == 1)
		ASSERT_TRUE(manager1.first != NULL && manager1.first == manager1.last)
		ASSERT_TRUE(manager2.first != NULL && manager2.first == manager2.last)
		ASSERT_TRUE(manager1.first->prev == NULL && manager1.last->next == NULL)
		ASSERT_TRUE(manager2.first->prev == NULL && manager2.last->next == NULL)
		ASSERT_TRUE(manager1.select(0) == manager2.select(0) && manager1.select(0) == DronesManager::DroneRecord(100))
		
		//OUR TEST CASES:
		
		DronesManager manager3, manager4;
	
		// equivalence case: test that the list no longer presents as being empty 
		// tests that adding one from front or back increases size appropriately and initialized first and last
		ASSERT_TRUE(manager3.empty() == true)
		manager3.insert_front(DronesManager::DroneRecord(100));
		ASSERT_TRUE(manager3.empty() == false)
		ASSERT_TRUE(manager3.first != NULL)
		ASSERT_TRUE(manager3.last != NULL)
		ASSERT_TRUE (manager3.first == manager3.last)
		ASSERT_TRUE(manager3.get_size() == 1)
		ASSERT_TRUE(manager3.first->prev == NULL && manager3.last->next == NULL)
		
		ASSERT_TRUE(manager4.empty() == true)
		manager4.insert_back(DronesManager::DroneRecord(100));
	    ASSERT_TRUE (manager4.empty() == false)
	    ASSERT_TRUE(manager4.first != NULL)
		ASSERT_TRUE(manager4.last != NULL)
		ASSERT_TRUE (manager4.first == manager4.last)
		ASSERT_TRUE(manager4.first->prev == NULL && manager4.last->next == NULL)
	    ASSERT_TRUE(manager4.get_size() ==1)
	  
	  	// tests that selecting the drone at index 0 will return the drone added
	  	ASSERT_TRUE(manager3.select(0) == manager4.select(0) && manager3.select(0) == DronesManager::DroneRecord(100))
		
	    return true;
    }
    
	// PURPOSE: select() and search() work properly
    bool test3() {
    	
    	//IGOR'S TEST CASES:
    	
		DronesManager manager3;
		 	
		const int num_elems = 5;
		for (unsigned int i = 0; i < num_elems; i++) {
			ASSERT_TRUE(manager3.insert_back(DronesManager::DroneRecord(i*100)))
		}
				
		unsigned int idx = 3;
		ASSERT_TRUE(manager3.search(manager3.select(idx)) == idx)
		ASSERT_TRUE(manager3.select(num_elems + 1) == DronesManager::DroneRecord(400))
		ASSERT_TRUE(manager3.search(DronesManager::DroneRecord(1000)) == manager3.get_size())
		
		for (unsigned int i = 0; i < num_elems; i++) {
			ASSERT_TRUE(manager3.select(i) == DronesManager::DroneRecord(i*100))
		}
		ASSERT_TRUE(manager3.first->prev == NULL && manager3.last->next == NULL)
		
		//OUR TEST CASES:
		
		//equivalence case check that returns false on empty list
		DronesManager manager4;
		ASSERT_FALSE(manager4.search(DronesManager::DroneRecord(100)))
		const int elements = 10;
		for (unsigned int index = 0; index < elements; ++index){
			ASSERT_TRUE(manager4.insert_back(DronesManager:: DroneRecord (index*2)))
			ASSERT_TRUE (manager4.select(index) == DronesManager:: DroneRecord (index*2))
		}
		ASSERT_TRUE(manager4.search(manager4.select(2)) == 2)
		ASSERT_TRUE(manager4.search(manager4.select(9)) == 9)
		ASSERT_TRUE(manager4.first-> prev == NULL && manager4.last-> next == NULL)
		
	    return true;
	     
    }
    
    // PURPOSE: remove_front() and remove_back() on one-element list
    bool test4() {
    	
    	//IGOR'S TEST CASES:
    	
		DronesManager manager1, manager2;
		ASSERT_TRUE(manager1.insert_front(DronesManager::DroneRecord(100)))
		ASSERT_TRUE(manager2.insert_front(DronesManager::DroneRecord(100)))
		ASSERT_TRUE(manager1.remove_front())
		ASSERT_TRUE(manager2.remove_back())
		
		ASSERT_TRUE(manager1.first == NULL && manager1.last == NULL)
		ASSERT_TRUE(manager2.first == NULL && manager2.last == NULL)
		ASSERT_TRUE(manager1.get_size() == manager2.get_size() && manager1.get_size() == 0)
		ASSERT_TRUE(manager1.empty() == true && manager2.empty() == true)
		
		//OUR TEST CASES:
		
		DronesManager manager3;
		//insert one element into the manager3 list 
		ASSERT_TRUE(manager3.insert_front(DronesManager::DroneRecord(42)))
		//check that the size is 1
		ASSERT_TRUE(manager3.get_size() == 1)
		//test remove front 
		ASSERT_TRUE(manager3.remove_front())
		//check size was updated to zero element list 
		ASSERT_TRUE(manager3.get_size() == 0)
		//check the list is now empty
		ASSERT_TRUE(manager3.empty())
		//try remove front again on an empty list
		
		ASSERT_FALSE(manager3.remove_front())
		//check the size is still 0
		ASSERT_TRUE(manager3.get_size()==0)
		//add 1 element to the list using insert back
		ASSERT_TRUE(manager3.insert_back(DronesManager::DroneRecord(4242)))
		//check that the size is 1
		ASSERT_TRUE(manager3.get_size()==1)
		//test remove back 
		ASSERT_TRUE(manager3.remove_back());
		//check the list has size 0
		ASSERT_TRUE(manager3.get_size()==0)
		//check the list is empty 
		ASSERT_TRUE(manager3.empty())
		//try to use remove back on an empty list
		ASSERT_FALSE(manager3.remove_back())
		//check the list size remains 0
		ASSERT_TRUE(manager3.get_size() == 0)
		//check the list is empty
		ASSERT_TRUE(manager3.empty())
	
	    return true;
    }
	
    // PURPOSE: replace() and reverse_list() work properly
    bool test5() {
    	
    	//IGOR'S TEST CASES:
    	
    	DronesManager manager;
		const int num_elems = 8;
		for (unsigned int i = 0; i < num_elems; i++) {
			ASSERT_TRUE(manager.insert_back(DronesManager::DroneRecord(i)))
		}
	
		ASSERT_TRUE(manager.replace(0, DronesManager::DroneRecord(8)))
		ASSERT_TRUE(manager.replace(3, DronesManager::DroneRecord(9)))
		ASSERT_TRUE(manager.replace(7, DronesManager::DroneRecord(10)))
	
		ASSERT_TRUE(*manager.first == DronesManager::DroneRecord(8))
		ASSERT_TRUE(*manager.last == DronesManager::DroneRecord(10))
		ASSERT_TRUE(*(manager.first->next->next->next) == DronesManager::DroneRecord(9))
	
		int test_values[8] = {10, 6, 5, 4, 9, 2, 1, 8};
		ASSERT_TRUE(manager.reverse_list());
		for (unsigned int i = 0; i < num_elems; i++) {
			ASSERT_TRUE(manager.select(i) == DronesManager::DroneRecord(test_values[i]))
		}
	
		ASSERT_TRUE(manager.first->prev == NULL && manager.last->next == NULL)
		
		//OUR TEST CASES:
		
		//create an empty list
		DronesManager manager2;
		//check the list is empty 
		ASSERT_TRUE(manager2.empty())
		//try to reverse an empty list 
		ASSERT_FALSE(manager2.reverse_list())
		//add one element to the list
		ASSERT_TRUE(manager2.insert_front(DronesManager :: DroneRecord(42)))
		ASSERT_TRUE(manager2.get_size() == 1)
		//reverse a one element list 
		ASSERT_TRUE(manager2.reverse_list())
		ASSERT_TRUE(manager2.first->prev == NULL && manager2.last->next == NULL)
		ASSERT_TRUE(*manager2.first == *manager2.last)
		
		//create an empty list 
		DronesManager manager3;
		ASSERT_TRUE(manager3.empty())
		//try to replace elements in an empty list
		ASSERT_FALSE(manager3.replace(0, DronesManager::DroneRecord(1)))
		// add one element to the list
		ASSERT_TRUE(manager3.insert_front(DronesManager::DroneRecord(42)))
		ASSERT_TRUE(manager3.get_size()==1)
		//use replace on a one element list
		ASSERT_TRUE(manager3.replace(0, DronesManager::DroneRecord(24)))
	    //insert more elements into the list 
	    ASSERT_TRUE(manager3.insert_front(DronesManager::DroneRecord(42)))
	    ASSERT_TRUE(manager3.insert_front(DronesManager::DroneRecord(9)))
	    ASSERT_TRUE(manager3.insert_front(DronesManager::DroneRecord(67)))
	    //check the size is 4
	    ASSERT_TRUE(manager3.get_size() == 4)
	    //replace the first and last values
	    ASSERT_TRUE(manager3.replace(0, DronesManager::DroneRecord(10)))
	    ASSERT_TRUE(manager3.replace(3, DronesManager::DroneRecord(11)))
	    //check replace worked
	    ASSERT_TRUE(*manager3.first == DronesManager::DroneRecord(10))
	    ASSERT_TRUE(*manager3.last == DronesManager::DroneRecord(11))
	    //try to replace with an invalid index
	    ASSERT_FALSE(manager3.replace(4, DronesManager::DroneRecord(40)))
		return true;
    }
	
    // PURPOSE: insert_front() keeps moving elements forward
    bool test6() {
    	
    	//IGOR'S TEST CASES:
    	
    	DronesManager manager;
		const int num_elems = 5;
		for (unsigned int i = 0; i < num_elems; i++) {
			ASSERT_TRUE(manager.insert_front(DronesManager::DroneRecord(i)))
			ASSERT_TRUE(manager.get_size() == (i + 1))
			ASSERT_TRUE(*manager.first == DronesManager::DroneRecord(i))
	        
			DronesManager::DroneRecord* n = manager.first;
			for (unsigned int j = 0; j <= i; j++) {
				DronesManager::DroneRecord expected_value = DronesManager::DroneRecord(i - j);
				ASSERT_TRUE(n != NULL && *n == expected_value)
				n = n->next;
			}
		}	
		ASSERT_TRUE(manager.first->prev == NULL && manager.last->next == NULL)
		
		//OUR TEST CASES:
		
		//create a new list
		DronesManager manager2;
		ASSERT_TRUE(manager2.insert_front(DronesManager::DroneRecord(0)))
		ASSERT_TRUE(manager2.get_size()==1)
		ASSERT_TRUE(*manager2.first == DronesManager::DroneRecord(0))
		//add another element to the list, check that first, size and last have been updated
		ASSERT_TRUE(manager2.insert_front(DronesManager::DroneRecord(1)))
		ASSERT_TRUE(manager2.get_size()==2)
		ASSERT_TRUE(*manager2.first == DronesManager::DroneRecord(1))
		ASSERT_TRUE(*manager2.last == DronesManager::DroneRecord(0))
		ASSERT_TRUE(*manager2.first->next == *manager2.last)
		//add a third element to the list
		//add another element to the list, check that first, size and last have been updated
		ASSERT_TRUE(manager2.insert_front(DronesManager::DroneRecord(2)))
		ASSERT_TRUE(manager2.get_size()==3)
		ASSERT_TRUE(*manager2.first == DronesManager::DroneRecord(2))
		ASSERT_TRUE(*manager2.first->next == DronesManager::DroneRecord(1))
		ASSERT_TRUE(*manager2.last == DronesManager::DroneRecord(0))
		//add 5 more elements to the list
		ASSERT_TRUE(manager2.insert_front(DronesManager::DroneRecord(3)))
		ASSERT_TRUE(manager2.insert_front(DronesManager::DroneRecord(4)))
		ASSERT_TRUE(manager2.insert_front(DronesManager::DroneRecord(5)))
		ASSERT_TRUE(manager2.insert_front(DronesManager::DroneRecord(6)))
		ASSERT_TRUE(manager2.insert_front(DronesManager::DroneRecord(7)))
		ASSERT_TRUE(manager2.get_size() == 8)
		ASSERT_TRUE(*manager2.first == DronesManager::DroneRecord(7))
		ASSERT_TRUE(*manager2.last == DronesManager::DroneRecord(0))
	    return true;
    }
	
    // PURPOSE: inserting at different positions in the list
    bool test7() {
    	
    	//IGOR'S TEST CASES:
    	
    	DronesManager manager;
		for (unsigned int i = 0; i < 4; i++) {
			ASSERT_TRUE(manager.insert_back(DronesManager::DroneRecord(i)))
		}
		ASSERT_TRUE(manager.insert(DronesManager::DroneRecord(4), 1))
		ASSERT_TRUE(manager.insert(DronesManager::DroneRecord(5), 1))
		ASSERT_TRUE(manager.insert(DronesManager::DroneRecord(6), 5))
		ASSERT_TRUE(manager.insert(DronesManager::DroneRecord(7), 7))
	
		// Check that the list has the right values
		int expected_values[] = {0, 5, 4, 1, 2, 6, 3, 7};
		ASSERT_TRUE(manager.get_size() == 8)
		DronesManager::DroneRecord* n = manager.first;
		for (unsigned int i = 0; i < manager.get_size(); i++) {
			ASSERT_TRUE(n != NULL && *n == DronesManager::DroneRecord(expected_values[i]))
			n = n->next;
		}
		ASSERT_TRUE(manager.first->prev == NULL && manager.last->next == NULL)
		
		//OUR TEST CASES:
		
		//Check that inserting at position 0 correctly calls insert_front()
		
		ASSERT_TRUE(manager.insert(DronesManager::DroneRecord(8), 0))
		ASSERT_TRUE(*manager.first == DronesManager::DroneRecord(8))
		ASSERT_TRUE(manager.get_size() == 9)
		ASSERT_TRUE(manager.first -> prev == NULL)
		ASSERT_TRUE(*(manager.first -> next) == DronesManager::DroneRecord(0))
		
		//Check that inserting at position size correctly calls insert_back()
		
		ASSERT_TRUE(manager.insert(DronesManager::DroneRecord(9), manager.get_size()))
		ASSERT_TRUE(*manager.last == DronesManager::DroneRecord(9))
		ASSERT_TRUE(manager.get_size() == 10)
		ASSERT_TRUE(manager.last -> next == NULL)
		ASSERT_TRUE(*(manager.last -> prev) == DronesManager::DroneRecord(7))
		
		//Check that inserting at position size-1 works correctly and does not change manager.last
		
		ASSERT_TRUE(manager.insert(DronesManager::DroneRecord(10), manager.get_size()-1))
		ASSERT_FALSE(*manager.last == DronesManager::DroneRecord(10))
		ASSERT_TRUE(manager.get_size() == 11)
		ASSERT_TRUE(*(manager.last -> prev) == DronesManager::DroneRecord(10))
		
 	    return true;
    }
	
    // PURPOSE: try to remove too many elements, then add a few elements
    bool test8() {
    	
    	//IGOR'S TEST CASES:
    	
    	DronesManager manager;
		for (unsigned int i = 0; i < 4; i++) {
			ASSERT_TRUE(manager.insert_back(DronesManager::DroneRecord(i)))
		}
    	
    	for (unsigned int i = 0; i < 4; i++) {
			ASSERT_TRUE(manager.remove_back())
		}
    	
		// Try a bunch of invalid commands.
		ASSERT_FALSE(manager.remove_front())
		ASSERT_FALSE(manager.remove_front())
		ASSERT_FALSE(manager.remove(0))
		ASSERT_TRUE(manager.empty() && manager.get_size() == 0)
	
		int expected_value = 1234;
		ASSERT_TRUE(manager.insert(DronesManager::DroneRecord(expected_value), 0))
		ASSERT_TRUE(*manager.first == DronesManager::DroneRecord(expected_value) &&
	                *manager.last == DronesManager::DroneRecord(expected_value))
	                
	    ASSERT_TRUE(manager.first->prev == NULL && manager.last->next == NULL)
	    ASSERT_TRUE(manager.first == manager.last)
	    
	    //OUR TEST CASES:
	    
	    //Try to remove from a new empty list
	    
	    DronesManager manager2;
	    ASSERT_FALSE(manager2.remove(1))
	    ASSERT_FALSE(manager2.remove_front())
	    ASSERT_FALSE(manager2.remove_back())
	    ASSERT_FALSE(manager2.remove(0))
	    ASSERT_TRUE(manager2.empty())
	    ASSERT_TRUE(manager2.get_size() == 0)
	    
	    //Try to now insert into the empty list
	    const int elements = 5;
	    for(int index = 0; index < elements; index++)
	    	ASSERT_TRUE(manager2.insert_back(DronesManager::DroneRecord(index)))
	    
	    //Check that elements have been correctly inserted
	    for(int index = 0; index < elements; index++)
	    	ASSERT_TRUE(manager2.search(DronesManager :: DroneRecord(index)) == index)
	    
	    return true;
    }
	
 	// PURPOSE: lots of inserts and deletes, some of them invalid
	bool test9() {
		
		//IGOR'S TEST CASES:
		
		DronesManager manager;
		ASSERT_FALSE(manager.remove(0))
		ASSERT_TRUE(manager.insert_back(DronesManager::DroneRecord(32)))
		ASSERT_TRUE(manager.insert_front(DronesManager::DroneRecord(44)))
		ASSERT_FALSE(manager.insert(DronesManager::DroneRecord(12),3))
		ASSERT_TRUE(manager.insert(DronesManager::DroneRecord(12),2))
		ASSERT_TRUE(manager.remove_back())
		ASSERT_FALSE(manager.remove(5))
		ASSERT_TRUE(manager.remove_front())
		ASSERT_TRUE(manager.insert_back(DronesManager::DroneRecord(88)))
		ASSERT_FALSE(manager.insert(DronesManager::DroneRecord(12345),6))
		ASSERT_TRUE(manager.remove(1))
		ASSERT_TRUE(manager.insert(DronesManager::DroneRecord(99),0))
		
		// Check that the manager has the right values
		ASSERT_TRUE(manager.select(0) == DronesManager::DroneRecord(99) && *manager.first == DronesManager::DroneRecord(99))
		ASSERT_TRUE(manager.select(1) == DronesManager::DroneRecord(32) && *manager.last == DronesManager::DroneRecord(32))

		ASSERT_TRUE(manager.first->next == manager.last && manager.last->prev == manager.first)
		ASSERT_TRUE(manager.first->prev == NULL && manager.last->next == NULL)
		
		//OUR TEST CASES:
		
		DronesManager manager2;
		
		//Valid insert_front(), insert_back() and insert()
		ASSERT_TRUE(manager2.insert_back(DronesManager::DroneRecord(-42)))
		ASSERT_TRUE(manager2.insert_front(DronesManager::DroneRecord(4)))
		ASSERT_TRUE(manager2.insert(DronesManager::DroneRecord(2), 1))
		
		//Invalid insert()s
		ASSERT_FALSE(manager2.insert(DronesManager::DroneRecord(24), 7))
		ASSERT_FALSE(manager2.insert(DronesManager::DroneRecord(24), 42))
		
		//Valid remove_front(), remove_back(), remove()
		ASSERT_TRUE(manager2.remove_front())
		ASSERT_TRUE(manager2.remove_back())
		ASSERT_TRUE(manager2.remove(0))
		
		//Invalid remove_front(), remove_back(), remove()
		ASSERT_FALSE(manager2.remove_front())
		ASSERT_FALSE(manager2.remove_back())
		ASSERT_FALSE(manager2.remove(42))
		
		//Check that list is empty
		ASSERT_FALSE(manager2.first)
		ASSERT_TRUE(manager2.empty())
		ASSERT_TRUE(manager2.get_size() == 0)

		return true;
	}      
	    	
	// PURPOSE: lots of inserts, reverse the list, and then lots of removes until empty
	bool test10() {
		
		//IGOR'S TEST CASES:
		
    	DronesManager manager;
	   	ASSERT_TRUE(manager.insert_back(DronesManager::DroneRecord(25)))
	   	ASSERT_TRUE(manager.insert_front(DronesManager::DroneRecord(45)))   
	   	ASSERT_TRUE(manager.insert(DronesManager::DroneRecord(11),2))
	   	ASSERT_TRUE(manager.insert_front(DronesManager::DroneRecord(15)))
	   	ASSERT_TRUE(manager.insert(DronesManager::DroneRecord(72),3))
	   	ASSERT_TRUE(manager.insert_front(DronesManager::DroneRecord(52)))   
	   	ASSERT_TRUE(manager.insert(DronesManager::DroneRecord(75),2))
	   	ASSERT_TRUE(manager.insert_back(DronesManager::DroneRecord(82)))
	   	ASSERT_TRUE(manager.insert(DronesManager::DroneRecord(43),3))
	   	ASSERT_TRUE(manager.insert(DronesManager::DroneRecord(21),1))

		ASSERT_TRUE(manager.first->prev == NULL && manager.last->next == NULL)
	
		int test_values[10] = {52, 21, 15, 75, 43, 45, 25, 72, 11, 82};
		ASSERT_TRUE(manager.reverse_list());
		for (unsigned int i = 0; i < 10; i++) {
			ASSERT_TRUE(manager.select(i) == DronesManager::DroneRecord(test_values[9-i]))
		}

    	for (unsigned int i = 0; i < 10; i++) {
			ASSERT_TRUE(manager.remove_back())
		}

		ASSERT_TRUE(manager.get_size() == 0)
		ASSERT_TRUE(manager.empty() == true)
		ASSERT_TRUE(manager.first == NULL)
		ASSERT_TRUE(manager.last == NULL)	
		
		//OUR TEST CASES:
		
		DronesManager manager2;
		
		//Insert elements
		int elements = 10;
		for(int index = 0; index < elements; index++) {
			ASSERT_TRUE(manager2.insert_back(DronesManager::DroneRecord(index)))
		}
		
		ASSERT_TRUE(manager2.get_size() == 10)
		ASSERT_TRUE(*manager2.first == DronesManager::DroneRecord(0))
		ASSERT_TRUE(*manager2.last == DronesManager::DroneRecord(9))
		
		//Reverse list and check that it was done correctly
		ASSERT_TRUE(manager2.reverse_list())
		
		for(int index = elements-1; index <= 0; index--) {
			ASSERT_TRUE(manager2.select(index) == DronesManager::DroneRecord(index))
		}
		
		//Remove all elements
		for(int index = 0; index < elements; index++) {
			ASSERT_TRUE(manager2.remove_back())
		}
		
		ASSERT_TRUE(manager2.get_size() == 0)
		ASSERT_TRUE(manager2.empty())
		ASSERT_TRUE(manager2.first == NULL)
		ASSERT_TRUE(manager2.last == NULL)
		
	   	return true;
	} 
};

#endif
