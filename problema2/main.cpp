#include<iostream>
#include"ranked-abb.cpp"

int main(){
    RankedABB arbol; 
    if (arbol.raiz == NULL){
        std::cout<<"raiz creada"<<std::endl;
    }
    bool flag = true; int item;
    while(flag){
        std::cin>>item;
        if(item == 1){
            flag = false;
        }
        arbol.insert(item);
    }

    arbol.inOrder(arbol.raiz);

    std::cout<<"elementos menores o iguales a 6: "<<std::endl;
    std::cout<<arbol.rank(6)<<std::endl;
}
