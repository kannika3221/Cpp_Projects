// Project Currency converter						Date:-1/8/25

#include<iostream>
using namespace std;
class currency{
	private:
		double UsdToEuroRate;
		double EuroToUsdRate;
		double UsdToPakRupeeRate;
		double UsdToIndRupeeRate;	
	public:
		currency(double p,double q,double r,double s)
		{
			UsdToEuroRate=p;
			EuroToUsdRate=q;
			UsdToPakRupeeRate=r;
			UsdToIndRupeeRate=s;
		}
		//Display exchange rate method
		void display_Exchange()
		{
			cout<<"\n\t----------- Current Exchange Rate -----------\n\n";
			cout<<"1 USD to EURO : "<<UsdToEuroRate<<endl;
			cout<<"1 EURO to USD : "<<EuroToUsdRate<<endl;
			cout<<"1 USD to Pakistani Rupee : "<<UsdToPakRupeeRate<<endl;
			cout<<"1 USD to Indian Rupee : "<<UsdToIndRupeeRate<<endl;
			
		}
		// Method to convert USD to EURO
		 double UsdToEuro(double usdAmount)
		 {
		 	return usdAmount*UsdToEuroRate;
		 }
		 
		 // Method to convert EURO to USD
		 double EuroToUs(double euroAmount)
		 {
		 	return euroAmount*EuroToUsdRate;
		 }
		 
		 // Method to convert USD to Pakistani Rupee 
		 double UsdToPak(double pakiAmount)
		 {
		 	return pakiAmount*UsdToPakRupeeRate;
		 }
		 
		 // Method to convert USD to Indian Rupee
		 double UsdToInd(double indiaAmount)
		 {
		 	return indiaAmount*UsdToIndRupeeRate;
		 }
		 
};
int main()
{
const double initalUsdToEuroRate=0.85;
const double initalEuroToUsdRate=1.174;
const double initalUsdToPakRupeeRate=284.50;
const double initalUsdToIndRupeeRate=87.30;
currency convertor(initalUsdToEuroRate,initalEuroToUsdRate,initalUsdToPakRupeeRate,initalUsdToIndRupeeRate);

int choice;
double amount;
do {
	system("cls");		// it is used to clean the page after use
	convertor.display_Exchange();
	cout<<"\n\t********* Currency Convertor Main Menu ***********\n";
	cout<<"1. Convert USD to EURO : \n";
	cout<<"2. Convert EURO to USD : \n";
	cout<<"3. Convert USD to Pakistani Rupee : \n";
	cout<<"4. Convert USD to Indian Rupee : \n";
	cout<<"0. Exit\n";
	cout<<"Please Enter your choice:";
	cin>>choice;
	switch(choice)
	{
		case 1:
			cout<<"Enter the Amount of USD :";
			cin>>amount;
			cout<<amount<<" USD is Equalent to "<<convertor.EuroToUs(amount)<<" Euro\n";
			system("pause");
			break;
			
		case 2:
			cout<<"Enter the Amount of EURO :";
			cin>>amount;
			cout<<amount<<" EURO is Equalent to "<<convertor.UsdToEuro(amount)<<" USD\n";
			system("pause");
			break;
			
			case 3:
			cout<<"Enter the Amount of USD :";
			cin>>amount;
			cout<<amount<<" USD is Equalent to "<<convertor.UsdToPak(amount)<<" Pakistani\n";
			system("pause");
			break;	
			
			case 4:
			cout<<"Enter the Amount of USD :";
			cin>>amount;
			cout<<amount<<" USD is Equalent to "<<convertor.UsdToInd(amount)<<" Indian\n";
			system("pause");
			break;	
			
			case 0:
				cout<<"Exit from Currency Convertor System";
				
				break;
			
			default:
				cout<<"Plz Enter Valid Number\n";
	}
}while(choice!=0);
return 0;
}
