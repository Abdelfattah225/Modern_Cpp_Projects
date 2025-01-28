// dependencies
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>


int NoOfPreparedItems = 10 ;
constexpr int DefaultPreparedItemsValue = 0;

struct Order
{
	std::string ItemName;
	int Quantity;

	Order(const std::string &name , const int qun)
	:ItemName(name) , Quantity(qun) {}
	Order() : ItemName("Unnamed"), Quantity(0) {}

	 // Define operator==
    bool operator==(const Order &other) const {
        return ItemName == other.ItemName && Quantity == other.Quantity;
    }
};

using namespace std;
	int main()
	{

		Order specficOrder = Order("Lemon Tart",1);




		// 1. Vector Definition and Initialization:

		
		/* a. Create an Empty Vector
		 Represents today's orders (dynamic and grows as needed) */

		std::vector<Order> TodayOrders ;

		/** b. Use a fill constructor to create a vector of pre-prepared items */

		std::vector<Order> PreparedItems ( NoOfPreparedItems , Order() ) ;

		/*c. Initialize a vector with a customer's order using braced initialization.*/

		std::vector<Order> CustomerOrder1 {Order("Chocolate Croissants",6) , Order("Whole Wheat Bread",2) };
		std::vector<Order> CustomerOrder2 {Order("Red Velvet Cupcakes",12), Order("Bagels (Assorted)",8) } ; 
		std::vector<Order> CustomerOrder3 {Order("Lemon Tart",1) , Order("Custom Cake (Vanilla with Fruit Filling)",1)};


		/*d. Use `insert()` to combine customer orders into the main list
			○ Copy the customer's order into the main order list.
		*/

		TodayOrders.insert(TodayOrders.end(), CustomerOrder1.begin(), CustomerOrder1.end()) ;
		TodayOrders.insert(TodayOrders.end(), CustomerOrder2.begin(), CustomerOrder2.end()) ;
		TodayOrders.insert(TodayOrders.end(), CustomerOrder3.begin(), CustomerOrder3.end()) ;

/**************************************************************************************************************************************** */
/**************************************************************************************************************************************** */
/**************************************************************************************************************************************** */
		/*
		2. Accessing elements:
			 Print the first, last, and third orders using appropriate vector functions
		*/

		std::cout << "First Order : " << TodayOrders.front().ItemName
				  << ", First Qunatity : "<< TodayOrders.front().Quantity << "\n";

		std::cout << "Last Order : " << TodayOrders.back().ItemName
				  << ", Last Qunatity : "<< TodayOrders.back().Quantity << "\n";

		std::cout << "Third Order : " << TodayOrders.at(2).ItemName
				  << ", Third Qunatity : "<< TodayOrders.at(2).Quantity << "\n";

		std::cout << "##################################################################\n";

/**************************************************************************************************************************************** */
/**************************************************************************************************************************************** */
/**************************************************************************************************************************************** */
		
		/*
		3. Modifying the vector:
		a. Add new orders to the end of the list.
		*/

		TodayOrders.push_back(Order("Cinnamon Rolls	",5));
		
		// b. Find and remove a specific order.

		if(std::find(TodayOrders.begin(), TodayOrders.end() , specficOrder )== TodayOrders.end())
		{
			std::cout << "Order not contain " << specficOrder.ItemName << " with quantity  " << specficOrder.Quantity << "\n";
			std::cout << "##################################################################\n";
			
		}
		else
		{
			std::cout << "Order contain " << specficOrder.ItemName << " and its quantity is " << specficOrder.Quantity << "\n";
			std::remove(TodayOrders.begin(), TodayOrders.end(), specficOrder);
			std::cout << "Order removed successfully. \n"; 
			std::cout << "##################################################################\n";

		}

		// c. Insert pre-prepared items at the beginning of the order list.
		// let say that prepared items is  Order("Bagels (Assorted)",8) and Order("Whole Wheat Bread",2)

		PreparedItems = {Order("Whole Wheat Bread",2), Order("Bagels (Assorted)",8)};
		TodayOrders.insert(TodayOrders.begin(), PreparedItems.begin() , PreparedItems.end());

		// d. Add a large catering order, resizing the vector if necessary.

		Order cateringOrder = Order("Large Catering Order ",100);
		TodayOrders.push_back(cateringOrder);

		// print all order after adding large order 

		std::cout << "Orders after adding large catering order:\n";
   		for (const auto &order : TodayOrders)
		{
        std::cout << "Item: " << order.ItemName << ", Quantity: " << order.Quantity << "\n";
    	}
		std::cout << "##################################################################\n";


		// compelete some order remove it (reomve the order prepared)
		
		TodayOrders.erase(TodayOrders.begin(), TodayOrders.begin()+ 2 );

		// e. Optimize the list 

		TodayOrders.shrink_to_fit();

		std::cout << "\nVector storage optimized using shrink_to_fit().\n";
		std::cout << "##################################################################\n";

		// print all order after optimization large order 

		std::cout << "Orders after Optimizations:\n";
   		for (const auto &order : TodayOrders)
		{
        std::cout << "Item: " << order.ItemName << ", Quantity: " << order.Quantity << "\n";
		}
		std::cout << "##################################################################\n";


/**************************************************************************************************************************************** */
/**************************************************************************************************************************************** */
/**************************************************************************************************************************************** */

		/*4. Vector Size Operaions:
			○ Print the current size, capacity, and maximum possible size of the vector.*/

		std::cout << "current size = " << TodayOrders.size() << "\n";

		std::cout << "Capacity     = " << TodayOrders.capacity() << "\n";

		std::cout << "Max size     = " << TodayOrders.max_size() << "\n";

		std::cout << "##################################################################\n";

		/*
		5. Max and Min Elements:
		○ (Optional) Find and print the least and most complex items in the order list,
		assuming you have a way to compare their complexity.
		*/

		// first we will sort the vector according number of pieces
		
		std::sort(TodayOrders.begin(), TodayOrders.end(), [](const Order &a, const Order &b) {return a.Quantity < b.Quantity; // Ascending order
 });

		std::cout << "Orders after Sorting according to quantity :\n";
		for (const auto &order : TodayOrders)
		{
        std::cout << "Item: " << order.ItemName << ", Quantity: " << order.Quantity << "\n";
		}
		std::cout << "##################################################################\n";

		auto leastComplexItem = *std::min_element(TodayOrders.begin(), TodayOrders.end(), [](const Order &a, const Order &b) {
        return a.Quantity < b.Quantity;
    });

    auto mostComplexItem = *std::max_element(TodayOrders.begin(), TodayOrders.end(), [](const Order &a, const Order &b) {
        return a.Quantity < b.Quantity;
    });

    std::cout << "Least complex item: " << leastComplexItem.ItemName << ", Quantity: " << leastComplexItem.Quantity << "\n";
    std::cout << "Most complex item: " << mostComplexItem.ItemName << ", Quantity: " << mostComplexItem.Quantity << "\n";
		std::cout << "##################################################################\n";

/**************************************************************************************************************************************** */
/**************************************************************************************************************************************** */
/**************************************************************************************************************************************** */


	/*
	6. Iterators:
	○ Iterate through the orders using normal, reverse, const, and auto iterators
	*/
	
	// Noromal iterator

		std::cout << "  Noromal iterator :\n";

	for(std::vector<Order>::iterator it = TodayOrders.begin() ; it != TodayOrders.end(); ++it)
	{
		std::cout << "Item: " << it->ItemName <<", Quantity: "<< it->Quantity << "\n";
	}
		std::cout << "##################################################################\n";

	// reverse iterator

			std::cout << "  reverse iterator :\n";

	for(std::vector<Order>::reverse_iterator rev = TodayOrders.rbegin() ; rev != TodayOrders.rend(); ++rev)
	{
		std::cout << "Item: " << rev->ItemName <<", Quantity: "<< rev->Quantity << "\n";
	}
		std::cout << "##################################################################\n";

	// const iterator
			std::cout << "  const iterator :\n";
	
	for(std::vector<Order>::const_iterator con = TodayOrders.cbegin() ; con != TodayOrders.cend(); ++con)
	{
		std::cout << "Item: " << con->ItemName <<", Quantity: "<< con->Quantity << "\n";
	}
			std::cout << "##################################################################\n";

	// auto iterator
	
			std::cout << "  auto iterator :\n";

	for(auto it = TodayOrders.begin() ; it != TodayOrders.end(); ++it)
	{
		std::cout << "Item: " << it->ItemName <<", Quantity: "<< it->Quantity << "\n";
	}
			std::cout << "##################################################################\n";

/**************************************************************************************************************************************** */
/**************************************************************************************************************************************** */
/**************************************************************************************************************************************** */

	/**
	 * 	 	 7. Clearing the vector:
			○ Clear all orders at the end of the day.
			○ Check if the vector is empty.
	 */
	
	TodayOrders.erase(TodayOrders.begin() , TodayOrders.end());
	std::cout << "today's order become empty\n";

	if(TodayOrders.empty()==true)
	{
		std::cout << "today's order is empty\n";
	}
	else
	{
		std::cout << "today's order is not empty\n";

	}

		std::cout << "##################################################################\n";






    return 0;
	}