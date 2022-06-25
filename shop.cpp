#include<bits/stdc++.h>
using namespace std;
#include "shopping.h"
vector<Product>allProducts ={
    Product(1,"shoes",26),
    Product(2,"lipstick",45),
    Product(3,"mouse",769),
    Product(4,"cover",145),
    Product(5,"bucket",99),
    Product(6,"apple",65),
};
Product* chooseProduct(){
    string ProductList;
    cout<<"Available Products: "<<endl;

    for(auto product: allProducts){
        ProductList.append(product.getDisplayName());
    }
    cout<<ProductList<<endl;
    cout<<"-----------------------"<<endl;

    string choice;
    cin>>choice;
    for(int i=0;i<allProducts.size();i++){
        if(allProducts[i].getName()==choice){
            return &allProducts[i];
        }
    }
    cout<<"Sorry, Product not found!"<<endl;
    return NULL;
}

bool checkout(Cart &cart){
    if(cart.isEmpty()){
        return false;
    }

    int total = cart.getTotal();
    cout<<"pay in cash";
    int paid;
    cin>>paid;
    if(paid>=total){
        cout<<"Change "<<paid-total <<endl;
        cout<<"Thanks for shopping with us";
        return true;
    }
    else {
        cout<<"not enough cash"<<endl;
        return false;
    }
}
int main(){
    char command;
    Cart cart;
    while(true){
        cout<<"Select an command - (a)add item, (v)view cart , (c)checkout"<<endl;
        cin>>command;
        if(command =='a'){
            //to add product to the cart
            //display all products;
            //choose product
            //add that product
            Product * product = chooseProduct();
            if(product!=NULL){
                cout<<"Added to the cart"<<" "<<product->getDisplayName()<<endl;
                cart.addProduct(*product);
            }
        }else if(command =='v'){
            //view the cart
            cout<<"---------------------"<<endl;
            cout<<cart.viewCart();
            cout<<"---------------------"<<endl;
        }else{
            //checkout
            cart.viewCart();
            if(checkout(cart)){
                break;
            }
        }
    }
    return 0;
}