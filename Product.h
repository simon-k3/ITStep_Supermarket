#pragma once
#include <ctime>
#include <string>
#include <iostream>
using namespace std;
#include "Utilities.h"

class Product 
{
private:
	size_t productCode;
	string productName;
	size_t unitCentPrice; // price of one item of the product WITH cents/copeiks (*100)
	string manufacturer;  // name of the manufacturer of the product
	size_t weightNet;     // net weight of one item of the product IN GRAMS
	size_t weightGross;   // gross weight of one item of the product IN GRAMS
	size_t width, height, length;   // dimensions in millimiters; initialized as 0
	//bool soldByWeight;    // shows if the product is sold by weight (without fixed package)
	//tm productionDate;    // date of manufacturing
	//tm expirationDate;    // expiry date

public:
	Product(   // constructor
		size_t productCode,
		string productName,
		size_t unitCentPrice,
		string manufacturer = "",
		size_t weightNet = 0,
		size_t weightGross = 0,
		size_t width = 0,
		size_t height = 0, 
		size_t length = 0
		);
	size_t GetCode();  // returns productCode
	string GetFullDetails();  // returns all fields of an object (full details of a product)
	string GetCodeAndName();  // returns productCode and productName as a string looking like '(code) "name"'
	size_t GetWidth();
	size_t GetHeight();
	size_t GetLength();
	
	//void SetManufacturer(string manufacturer);
	//void SetWeightGross(size_t weightGross);
	//void SetDimensions(size_t width, size_t height, size_t length);
	//void SetProductionDate(int prod_mday, int prod_month, int prod_year); // takes: day of month from 1 to 31, month of year from 1 to 12, year
	//void SetExpirationDate(int exp_mday, int exp_mon, int exp_year); // takes: day of month from 1 to 31, month of year from 1 to 12, year
	//string GetProductionDate();  // returns a string "DD/MM/YYYY"
	//string GetExpirationDate();  // returns a string "DD/MM/YYYY"
	//bool IsExpired();

	friend class StockDB;
};

