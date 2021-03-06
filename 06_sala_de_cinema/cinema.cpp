#include <iostream>
#include <vector>

struct Cliente{
    std::string id;
    std::string fone;
    bool livre;
    Cliente(std::string id = "", std::string fone = "", bool livre = true):
        id(id), fone(fone), livre(livre){
    }
    std::string toString(){
        if(livre)
            return "-";
        return id + ":" + fone;
    }
};

struct Sala{
    std::vector<Cliente> cadeiras;
    Sala(int lotacao):
        cadeiras(lotacao){
    }

    bool ingressar(std::string id, std::string fone, int indice){
        bool exists = true;
        if(-1 < indice && indice < cadeiras.size()){
            if (cadeiras[indice].livre){
                for(auto cliente : cadeiras)
                    if(cliente.id == id)
                        exists = false;
                if(exists){
                    cadeiras[indice] = Cliente(id, fone, false);
                    return true;
                }else{
                    std::cout << "fail: cliente já está no cinema" << std::endl;
                    return false;
                }
            }else{
                std::cout << "fail: cadeira ocupada" << std::endl;
                return false;
            }
        }
        std::cout << "fail: out of index" << std::endl;

        return false;
    }

    std::string toString(){
        std::string saida;
        for(auto cliente : cadeiras){
            saida += cliente.toString() + " ";
        }
        return saida;
    }
};

int main(){
    Sala sala(5);
    //sala.cadeiras[3] = Cliente("Elvis", "88", false);
    sala.ingressar("Elvis", "8899", 2); // entra
    sala.ingressar("Elvis", "8898", 2); // cadeira ocupada
    sala.ingressar("Elvis", "8899", 1); // já está no cinema

    sala.ingressar("Bia", "8897", 8); // out of index
    sala.ingressar("bia", "8897", 4); // entra


    std::cout << sala.toString() << "\n";
}