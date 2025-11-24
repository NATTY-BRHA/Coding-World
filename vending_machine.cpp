#include<iostream>
using namespace std;
const int Item_index = 6;
class Item{
  private:
    string Item_code;
    string Item_name;
    string Item_category;
    float Item_price;
    int stck;
  public:
  Item(){ };
  Item(string code,string name,string cat,float price,int stock){
     Item_code = code;
     Item_name = name;
     Item_category = cat;
     Item_price = price;
     stck = stock;
  }
    string getItemcode(){ return Item_code;}
    string getItemname(){ return Item_name;}
    string getItemcategory(){return Item_category;}
    float getItemprice(){ return Item_price; }
    int getstck(){return stck;}
    
    void stckmng(){
        if(stck>0){
            stck--;
        }
    }
};
class Machine{
  private:
  Item Items[Item_index];
  public:
  Machine(){
    Items[0] = Item("A1", "Coffee", "Hot Drinks", 1.50, 5);
    Items[1] = Item("A2", "Tea", "Hot Drinks", 1.20, 3);
    Items[2] = Item("B1", "Coke", "Cold Drinks", 1.00, 4);
    Items[3] = Item("B2", "Water", "Cold Drinks", 0.80, 6);
    Items[4] = Item("C1", "Chocolate Bar", "Snacks", 0.90, 5);
    Items[5] = Item("C2", "Biscuits", "Snacks", 1.10, 2);
  }
  void showmenu(){
       cout<<"\t \t \tWELCOME TO THE The Traditions Table ""\n";
       string crntct = " ";
       for (int i = 0; i < Item_index; i++) {
            if (Items[i].getItemcategory() != crntct) {
                crntct = Items[i].getItemcategory();
                cout << "\n--- " << crntct << " ---\n";
            }
            cout << Items[i].getItemcode()
                     << " - " << Items[i].getItemname()
                   << " (£" 
                   //<< fixed << setprecision(2)
                     << Items[i].getItemprice() << ")";
    
                if (Items[i].getstck() == 0)
                    cout << " - OUT OF STOCK";
    
                cout << endl;
       }
  }
  int findItem(string Itemcode) {
            for (int i = 0; i < Item_index; i++) {
                if (Items[i].getItemcode() == Itemcode) {
                    return i;
                }
            }
            return -1;
        }
  void suggession(Item &orderItem) {
            if (orderItem.getItemcategory() == "Hot Drinks") {
                cout << "Suggestion: Biscuits will taste good with hot drinks!\n";
            }
            else if (orderItem.getItemcategory() == "Snacks") {
                cout << "Suggestion: Maybe you'ld buy a drink with  snack!\n";
            }
            else if (orderItem.getItemcategory() == "Cold Drinks") {
                cout << "Suggestion: A chocolate bar could be good with drink.\n";
            }
        }
  void Order() {
            string ordercode;
            cout << "\nEnter item code: ";
            cin >> ordercode;
    
            int index = findItem(ordercode);
    
            if (index == -1) {
                cout << "Invalid ordercode.\n";
                return;
            }
    
            if (Items[index].getstck() == 0) {
                cout << "Sorry, that item is out of stock.\n"
                <<"You can order something else \n";
                return;
            }
    
            cout << "You selected: " << Items[index].getItemname()
                 << " (£" << Items[index].getItemprice() << ")\n";
    
            float money;
            cout << "Insert money: £";
            cin >> money;
    
            if (money < Items[index].getItemprice()) {
                cout << "Not enough money. Transaction cancelled.\n";
                return;
            }
    
            float change = money - Items[index].getItemprice();
    
            cout << "Dispensing " << Items[index].getItemname() << "...\n";
            cout << "Your change is: £ "<< change << endl;
    
            Items[index].stckmng();
    
            suggession(Items[index]);
        }
};
int main(){
    Machine m;
    bool run = true;
    cout<<"WELCOME TO THE The Traditions Table's Vending Machine \n";
    while(run){
        m.showmenu();
        m.Order();
        
        char gn;
        cout<<"Do you want to order again? (y/n) \n";
        cin>>gn;
        
        if(gn == 'n' || gn == 'N'){
            run = false;
        }
    }
    cout<<"Thank you! For using vending machine..";
    return 0;
}
