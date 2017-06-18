#include "Product.h"

Product::Product(
	size_t productCode,
	string productName,
	size_t unitCentPrice,
	size_t weightNet,
	bool soldByWeight)
	:
	productCode(productCode),
	productName(productName),
	unitCentPrice(unitCentPrice),
	weightNet(weightNet),
	soldByWeight(soldByWeight)
{
	manufacturer = "";
	width = 0;
	height = 0;
	length = 0;	
	if (soldByWeight) {
		weightGross = weightNet;
	} 
	else {
		weightGross = 0;
	}

	/*clog << "New product added:\n" << 
		"Code:           " << to_string(product_id) << "\n" <<
		"Name:           " << product_name << "\n" <<
		"Unit price:     " << MoneyToString(unit_price) << " RUB\n" <<
		"Net weight:     " << WeightToString(weight_net) << " kg\n";
	if (soldByWeight) {
		clog <<	"Sold by weight: Yes\n";
	}*/
}

void Product::SetManufacturer(string manufacturer) 
{
	this->manufacturer = manufacturer;
}

void Product::SetWeightGross(size_t weight_gross)
{
	this->weightGross = weight_gross;
}

void Product::SetDimensions(size_t width, size_t height, size_t length)
{
	this->width = width;
	this->height = height;
	this->length = length;
}

size_t Product::GetCode()
{
	return productCode;
}

string Product::GetFullDetails()
{
	string result =
		"Code:               " + to_string(productCode) + "\n" +
		"Name:               " + productName + "\n" +
		"Manufacturer:       " + manufacturer + "\n" +
		"Unit price:         " + MoneyToString(unitCentPrice) + " RUB\n" +
		"Net weight:         " + WeightToString(weightNet) + " kg\n";
	if (soldByWeight) {
		result += 
			"Sold by weight:     Yes\n";
	} 
	else {
		result +=
			"Gross weight:       " + WeightToString(weightGross) + " kg\n" +
			"Dimensions (WxHxL): " + to_string(width) + " mm x "
			+ to_string(height) + " mm x " + to_string(length) + " mm\n";
	}
	result +=
		"Produced on:        " + GetProductionDate() + "\n" +
		"Expires on:         " + GetExpirationDate() + "\n";
	
	if (IsExpired())
		result += "EXPIRED!\n";
	
	return result;
}

string Product::GetCodeName()
{
	return "(" + to_string(productCode) + ") \"" + productName + "\"";
}

size_t Product::GetWidth()
{
	return this->width;
}

size_t Product::GetHeight()
{
	return this->height;
}

size_t Product::GetLength()
{
	return this->length;
}

void Product::SetProductionDate(int prod_mday, int prod_month, int prod_year) 
{
	productionDate.tm_mday = prod_mday;
	productionDate.tm_mon = prod_month - 1;
	productionDate.tm_year = prod_year - 1900;
}

void Product::SetExpirationDate(int exp_mday, int exp_mon, int exp_year)
{
	expirationDate.tm_mday = exp_mday;
	expirationDate.tm_mon = exp_mon - 1;
	expirationDate.tm_year = exp_year - 1900;
}

string Product::GetProductionDate() 
{
	return TmToString(productionDate);
}

string Product::GetExpirationDate()
{
	return TmToString(expirationDate);;
}

bool Product::IsExpired()
{
	// TODO!
//	time_t current_time = time(NULL);
//	if (expiration_date < *localtime(&current_time))
		return false;
//	else
//		return true;
}

